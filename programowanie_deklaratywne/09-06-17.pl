wstaw(X,[],[X]):-!.
wstaw(X,[H|T],[X,H|T]):-X=<H,!.
wstaw(X,[H|T1],[H|T2]):-wstaw(X,T1,T2).

wstawSort([],[]):-!.
wstawSort([H|T],R):-wstawSort(T,SubR),wstaw(H,SubR,R).

min([X],X):-!.
min([H|T],H):-min(T,Sub),H<Sub,!.
min([_|T],Sub):-min(T,Sub).

max([X],X):-!.
max([H|T],H):-max(T,Sub),H>Sub,!.
max([_|T],Sub):-max(T,Sub).

arytm(H,_,1,[H]):-!.
arytm(H,K,C,[H2|T2]):-C2 is C-1,arytm(H,K,C2,T2),H2 is H-(K*(C-1)).

roznica([],[],[]).
roznica([H1|T1],[H2|T2],[H3|T3]):-H3 is abs(H1-H2),roznica(T1,T2,T3).

sum([],0):-!.
sum([H|T],R):-sum(T,SubR),R is H+SubR.

klucz(Lwe,R):-wstawSort(Lwe,LS),min(Lwe,Min),max(Lwe,Max),length(Lwe,D),K is (Max-Min)/(D-1),arytm(Max,K,D,LA),roznica(LS,LA,LR),sum(LR,R).
