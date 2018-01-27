wstaw(X,[],[X]):-!.
wstaw(X,[H1|T1],[X,H1|T1]):-klucz(X,W1),klucz(H1,W2),W1=<W2,!.
wstaw(X,[H1|T1],[H1|T2]):-wstaw(X,T1,T2).

wstawSort([],[]).
wstawSort([H1|T1],Res1):-wstawSort(T1,Subres1),wstaw(H1,Subres1,Res1).

wybierzSkrajne([Mniejszy|T1],Mniejszy,Wiekszy):-append(_,[Wiekszy],T1),Mniejszy<Wiekszy,!.
wybierzSkrajne([Wiekszy|T1],Mniejszy,Wiekszy):-append(_,[Mniejszy],T1),!.

min([X],X):-!.
min([H1|T1],H1):-min(T1,X1),H1<X1,!.
min([_|T1],X1):-min(T1,X1).

max([X],X):-!.
max([H1|T1],H1):-max(T1,X1),H1>X1,!.
max([_|T1],X1):-max(T1,X1).

listaMniejszych(_,[],[]):-!.
listaMniejszych(X,[H1|T1],[H1|T2]):-H1<X,!,listaMniejszych(X,T1,T2).
listaMniejszych(X,[_|T1],T2):-listaMniejszych(X,T1,T2).

listaMniejszychSafe(X,Lwe,Lwy):-listaMniejszych(X,Lwe,Lwy),length(Lwy,Dlug),Dlug>0,!.
listaMniejszychSafe(X,_,[X]).

listaWiekszych(_,[],[]):-!.
listaWiekszych(X,[H1|T1],[H1|T2]):-H1>X,!,listaWiekszych(X,T1,T2).
listaWiekszych(X,[_|T1],T2):-listaWiekszych(X,T1,T2).

listaWiekszychSafe(X,Lwe,Lwy):-listaWiekszych(X,Lwe,Lwy),length(Lwy,Dlug),Dlug>0,!.
listaWiekszychSafe(X,_,[X]).


klucz(Lwe,Res):-wybierzSkrajne(Lwe,Mniejszy,Wiekszy),listaMniejszychSafe(Mniejszy,Lwe,LMin),listaWiekszychSafe(Wiekszy,Lwe,LMax),max(LMin,Min2),min(LMax,Max2),Res is abs(Mniejszy-Min2)+abs(Max2-Wiekszy).

wynik(Lwe,Lwy):-wstawSort(Lwe,Lwy).
