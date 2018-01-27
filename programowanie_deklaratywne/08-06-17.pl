srodek([X1,X2],S):-S is (X1+X2)/2.

listaSrodek([],[]):-!.
listaSrodek([H1|T1],[H2|T2]):-srodek(H1,H2),listaSrodek(T1,T2).

del(H,[H|T],T):-!.
del(X,[H|T],Lwyj):-del(X,T,LW),append([H],LW,Lwyj).

minOdl(X1,[X2],W):-W is abs(X1-X2),!.
minOdl(X1,[H1|T1],W):-minOdl(X1,T1,SubW),abs(X1-H1)<SubW,!,W is abs(X1-H1).
minOdl(X1,[_|T1],W):-minOdl(X1,T1,W).

minOdlS(X,Lwe,R):-del(X,Lwe,LbezX),minOdl(X,LbezX,R).

wstaw(X,_,[],[X]):-!.
wstaw(X,LS,[H1|T1],[X,H1|T1]):-srodek(X,X2),minOdlS(X2,LS,W1),srodek(H1,X3),minOdlS(X3,LS,W2),W1=<W2,!.
wstaw(X,LS,[H1|T1],[H1|T2]):-wstaw(X,LS,T1,T2).

wstawSort([],_,[]):-!.
wstawSort([H1|T1],LS,R):-wstawSort(T1,LS,SubR),wstaw(H1,LS,SubR,R).

main(Lwe,Lwy):-listaSrodek(Lwe,LS),wstawSort(Lwe,LS,Lwy).
