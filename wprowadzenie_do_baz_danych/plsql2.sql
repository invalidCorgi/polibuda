declare 
    cursor c_asystenci is
        select nazwisko, ZATRUDNIONY from pracownicy
        where etat='ASYSTENT';
    v_nazwisko pracownicy.nazwisko%TYPE;
    v_zatrudniony pracownicy.zatrudniony%TYPE;
begin
    open c_asystenci;
    loop
        fetch c_asystenci into v_nazwisko, v_zatrudniony;
        exit when c_asystenci%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE(v_nazwisko || ' pracuje od ' || v_zatrudniony );
    end loop;
    close c_asystenci;
end;

declare
    cursor c_najlepiej_zarabiajacy is
        select nazwisko from pracownicy
        order by PLACA_POD desc;
    v_nazwisko pracownicy.nazwisko%TYPE;
begin
    open c_najlepiej_zarabiajacy;
    loop
        fetch c_najlepiej_zarabiajacy into v_nazwisko;
        exit when c_najlepiej_zarabiajacy%NOTFOUND;
        exit when c_najlepiej_zarabiajacy%ROWCOUNT = 4;
        DBMS_OUTPUT.PUT_LINE(c_najlepiej_zarabiajacy%ROWCOUNT || ' : ' || v_nazwisko);
    end loop;
    close c_najlepiej_zarabiajacy;
end;

select * from pracownicy
        where to_char(zatrudniony,'D') = 2;

declare
    cursor c_poniedzialkowi is
        select * from pracownicy
        where to_char(zatrudniony,'D') = 2
        for UPDATE;
begin
    for r_prac in c_poniedzialkowi loop
        update pracownicy set placa_pod = 1.2 * placa_pod
        where CURRENT of c_poniedzialkowi;
    end loop;
end;

select * from pracownicy join zespoly using(id_zesp) order by nazwisko;

declare
    cursor c_prac_zesp is
        select * from pracownicy join zespoly using(id_zesp)
        for UPDATE of nazwisko;
begin
    for r_prac in c_prac_zesp loop
        if(r_prac.nazwa = 'ALGORYTMY') then
            update pracownicy set placa_dod = coalesce(placa_dod,0)+100
            where current of c_prac_zesp;
        elsif(r_prac.nazwa='ADMINISTRACJA') then
            update pracownicy set placa_dod = coalesce(placa_dod,0)+150
            where current of c_prac_zesp;
        elsif(r_prac.etat='STAZYSTA') then
            delete pracownicy where current of c_prac_zesp;
        end if;
    end loop;
end;

declare
    v_etat pracownicy.etat%TYPE := '&etat';
    cursor c_etat (p_etat pracownicy.etat%type) is
        select nazwisko from pracownicy
        where etat = p_etat;
begin
    for r_prac in c_etat(v_etat) loop
        DBMS_OUTPUT.PUT_LINE (r_prac.nazwisko);
    end loop;
end;

insert into etaty values('LEL',100,200);
delete etaty where nazwa='LEL';
declare
    cursor c_etat is
        select nazwa, count(placa_pod) as liczba_prac, avg(placa_pod) as srednia_pensja
        from etaty left join pracownicy on nazwa=etat
        group by nazwa order by nazwa asc;
    cursor c_prac (p_etat pracownicy.etat%type) is
        select nazwisko, placa_pod from pracownicy
        where etat = p_etat;
begin
    for r_etat in c_etat loop
        dbms_output.put_line('Etat: ' || r_etat.nazwa );
        dbms_output.put_line('Liczba pracowników: ' || r_etat.liczba_prac );
        for r_prac in c_prac(r_etat.nazwa) loop
            dbms_output.put_line(c_prac%ROWCOUNT || ' ' || r_prac.nazwisko || ', pensja: ' || r_prac.placa_pod);
        end loop;
        if(r_etat.srednia_pensja is not null) then
            dbms_output.put_line('Średnia pensja: ' || r_etat.srednia_pensja );
        else
            dbms_output.put_line('Średnia pensja: brak');
        end if;
    end loop;
end;
