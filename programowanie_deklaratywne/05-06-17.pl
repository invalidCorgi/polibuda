wstaw2(X,[],[X]):-!.
wstaw2(X,[H1|T1],[X,H1|T1]):-X=<H1,!.
wstaw2(X,[H1|T1],[H1|T2]):-wstaw2(X,T1,T2).

wstawSort([],[]):-!.
wstawSort([H1|T1],Result):-wstawSort(T1,Subres),wstaw2(H1,Subres,Result).

pk([H1|T1],H1,K):-append(_,[K],T1),!.

genArytm(Ostatni,1,_,[Ostatni]):-!.
genArytm(Ostatni,Dlugosc,Krok,[H|T]):-H is Ostatni-((Dlugosc-1)*Krok),
	D2 is Dlugosc-1,genArytm(Ostatni,D2,Krok,T).

roznicaList([],[],[]):-!.
roznicaList([H1|T1],[H2|T2],[H3|T3]):-H3 is abs(H1-H2),roznicaList(T1,T2,T3).

sumaListy([],0):-!.
sumaListy([H1|T1],Suma):-sumaListy(T1,Subres),Suma is H1+Subres.

klucz(Lwe,Res):-wstawSort(Lwe,Lsort),pk(Lsort,P,K),length(Lsort,Dlugosc),
	Krok is (K-P)/(Dlugosc-1),genArytm(K,Dlugosc,Krok,Larytm),
	roznicaList(Lsort,Larytm,Lroz),sumaListy(Lroz,Res).

wstaw(X,[],[X]):-!.
wstaw(X,[H1|T1],[X,H1|T1]):-klucz(X,W1),klucz(H1,W2),W1=<W2,!.
wstaw(X,[H1|T1],[H1|T2]):-wstaw(X,T1,T2).

wynik([],[]):-!.
wynik([H1|T1],Result):-wynik(T1,Subres),wstaw(H1,Subres,Result).



