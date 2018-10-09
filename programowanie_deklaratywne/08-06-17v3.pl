wstaw(X,[],[X]):-!.
wstaw(X,[H|T],[X,H|T]):-X=<H,!.
wstaw(X,[H|T1],[H|T2]):-wstaw(X,T1,T2).

wstawSort([],[]):-!.
wstawSort([H|T],R):-wstawSort(T,SubR),wstaw(H,SubR,R).

rozbij(0,[]):-!.
rozbij(X,R):-H is X mod 10, X3 is X div 10,rozbij(X3,T),append(T,[H],R).

monot([X1,X2],[X1,X2]):-X1<X2,!.
monot([X1,_],[X1]):-!.
monot([X1,X2|T1],[X1|T2]):-X1<X2,!,monot([X2|T1],T2).
monot([X1,_|T1],T2):-monot([X1|T1],T2).

polacz([],0).
polacz([H1|T1],R):-length(T1,D),X2 is H1*(10^D),polacz(T1,SubR),R is X2+SubR.

klucz(X,R):-rozbij(X,Roz),monot(Roz,Mon),polacz(Mon,R).
