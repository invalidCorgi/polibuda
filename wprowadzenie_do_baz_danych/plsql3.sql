/*declare 
    v_etat pracownicy.etat%TYPE := '&etat';
    cursor c_etat (p_etat pracownicy.etat%type) is
        select nazwisko from pracownicy
        where etat = p_etat;
    v_liczba etaty%ROWTYPE;
begin
    select * into v_liczba from etaty where nazwa=v_etat;

    for r_prac in c_etat(v_etat) loop
        DBMS_OUTPUT.PUT_LINE (r_prac.nazwisko);
    end loop;
    
    exception
        when NO_DATA_FOUND then
            DBMS_OUTPUT.PUT_LINE('Nie istnieje etat o nazwie ' || v_etat);
end;*/

/*select nazwisko, placa_pod
from pracownicy
where ETAT='PROFESOR'
order by nazwisko asc;

declare
    cursor c_prof is
        select * from pracownicy where etat='PROFESOR' for update;
    v_pensja NUMBER;
begin

    for r_prof in c_prof loop
        update pracownicy
        set placa_pod=placa_pod+0.1*
        coalesce((select sum(placa_pod) from pracownicy p where p.id_szefa=r_prof.id_prac 
        group by id_szefa),0)
        where current of c_prof;
        select placa_pod into v_pensja from pracownicy where id_prac=r_prof.id_prac;
        if (v_pensja > 2000) then
            raise_application_error(-20010,'Pensja po podwyżce przekroczyła 2000!');
        end if;
    end loop;
    
end;*/

/*select * from pracownicy;

declare
    cursor c_prac is
        select * from pracownicy for update;
    v_id_prac pracownicy.id_prac%TYPE := '&id_prac';
    v_nazwisko pracownicy.nazwisko%TYPE := '&nazwisko';
    v_id_zesp pracownicy.id_zesp%TYPE := '&id_zesp';
    v_placa_pod pracownicy.placa_pod%TYPE := '&placa_pod';
begin

    insert into pracownicy(id_prac,nazwisko,id_zesp,placa_pod)
    VALUES(v_id_prac,v_nazwisko,v_id_zesp,v_placa_pod);
    
    exception
        when others then
            if(SQLCODE = -1400) then
                dbms_output.put_line('nie podano wartości identyfikatora');
            ELSIF(SQLCODE = -1) then
                dbms_output.put_line('podany identyfikator użytkownika jest już używany');
            ELSIF(SQLCODE = -2290) then
                dbms_output.put_line('pensja musi być większa niż 100');
            ELSIF(SQLCODE = -2291) then
                dbms_output.put_line('nie istnieje zespół o podanym identyfikatorze');
            end if;
end;*/

/*select * from pracownicy;

select count(*) from pracownicy where nazwisko='MORZ';

select count(*)
from pracownicy 
where id_szefa=(select id_prac from pracownicy where nazwisko='WEGLARZ');

declare
    cursor c_prac is
        select * from pracownicy for update;
    v_nazwisko pracownicy.nazwisko%TYPE := '&nazwisko';
    v_liczba NUMBER;
    ex_pracownicy_w_zespole EXCEPTION;
    PRAGMA EXCEPTION_INIT(ex_pracownicy_w_zespole, -2292);
begin

    select count(*) into v_liczba
    from pracownicy where nazwisko=v_nazwisko;
    
    if(v_liczba = 0) then
        raise_application_error(-20020,'Nie istnieje taki pracownik');
    ELSIF(v_liczba > 1) then
        raise_application_error(-20030,'Niejednoznaczne wskazanie pracownika');
    end if;
    
    delete from pracownicy
    where NAZWISKO=v_nazwisko;
    
    exception
        when ex_pracownicy_w_zespole then
            raise_application_error(-20040,'Nie możesz usunąć przełożonego');

end;*/