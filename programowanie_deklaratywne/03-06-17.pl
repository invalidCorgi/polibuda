wstaw(X,[],[X]):-!.
wstaw(X,[H|T],[X,H|T]):-minWSrodku(X,L1),maxWSrodku(X,L2),minWSrodku(H,L3),maxWSrodku(H,L4),suma(L1,L2,W1),suma(L3,L4,W2),W1=<W2,!.
wstaw(X,[H|T1],[H|T2]):-wstaw(X,T1,T2).

wstawSort([],[]):-!.
wstawSort([H1|T1],Lwy):-wstawSort(T1,Subres),wstaw(H1,Subres,Lwy).

min([X],X):-!.
min([H|T],H):-min(T,X),H<X,!.
min([_|T],X):-min(T,X).

max([X],X):-!.
max([H|T],H):-max(T,X),H>X,!.
max([_|T],X):-max(T,X).

minWSrodku(L,L):-min(L,Min),append(L1,[Min|L2],L),length(L1,B),length(L2,B),!.
minWSrodku(Lwe,Lwy):-append(T,[H],Lwe),minWSrodku([H|T],Lwy).

maxWSrodku(L,L):-max(L,Max),append(L1,[Max|L2],L),length(L1,B),length(L2,B),!.
maxWSrodku(Lwe,Lwy):-append(T,[H],Lwe),maxWSrodku([H|T],Lwy).

suma([],[],0):-!.
suma([H1|T1],[H2|T2],Result):-suma(T1,T2,Subres),Result is Subres+abs(H1-H2).

wynik(Lwe,Lwy):-wstawSort(Lwe,Lwy).
