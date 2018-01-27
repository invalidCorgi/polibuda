npoczatek(0, _, []) :- !.
npoczatek(N, [H | T], [H | Subresult]) :- N1 is N - 1, npoczatek(N1, T, Subresult).

podzial([],[],[]).
podzial(L,[H2|T2],[X|SubRes]):-npoczatek(H2,L,X),append(X,X2,L),podzial(X2,T2,SubRes).

doposort(X,[],[X]):-!.
doposort(X,[H|T],[X,H|T]):-H>X,!.
doposort(X,[H|T],[H|SubRes]):-doposort(X,T,SubRes).

insertSort([],[]).
insertSort([H|T],Lwy):-insertSort(T,SubRes),doposort(H,SubRes,Lwy).

zamien([],[]).
zamien([H1,X1|T1],[X1,H1|T1]):-H1>X1,!.
zamien([H1|T1],[H1|T2]):-zamien(T1,T2).

bubbleSort(Lwe,Lwy):-zamien(Lwe,X1),Lwe\=X1,!,bubbleSort(X1,Lwy).
bubbleSort(Lwy,Lwy).

lenZamien([],[]).
lenZamien([H1,X1|T1],[X1,H1|T1]):-length(H1,L1),length(X1,L2),L1>L2,!.
lenZamien([H1|T1],[H1|T2]):-lenZamien(T1,T2).

lenSort(Lwe,Lwy):-lenZamien(Lwe,X1),Lwe\=X1,!,lenSort(X1,Lwy).
lenSort(Lwy,Lwy).

absZamien(_,[],[]).
absZamien(X,[H1,X1|T1],[X1,H1|T1]):-abs(H1-X,Abs1),abs(X1-X,Abs2),Abs1>Abs2,!.
absZamien(X,[H1|T1],[H1|T2]):-absZamien(X,T1,T2).

distSort(X,Lwe,Lwy):-absZamien(X,Lwe,X1),Lwe\=X1,!,distSort(X,X1,Lwy).
distSort(_,Lwy,Lwy).


