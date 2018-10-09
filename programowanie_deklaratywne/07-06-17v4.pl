binarnie(0,[0]):-!.
binarnie(1,[1]):-!.
binarnie(X,W) :- A is X mod 2, B is X div 2, binarnie(B,C), append(C,[A],W).

dec([0],0):-!.
dec([1],1):-!.
dec([H1|T1],Dec) :- dec(T1,Nowa), length(T1,D), Dec is Nowa+H1*2^D.

maksimum([X],X):-!.
maksimum([H|T],H) :- maksimum(T,H2), H>H2,!.
maksimum([_|T],H) :- maksimum(T,H).

zera(Y,X,X,Y).
zera(L,D1,D2,L) :- D1=:=D2,!.
zera(L,D1,D2,Lw) :- D2<D1, D is D2+1, zera([0|L],D1,D,Lw).

lista([],_,[]).
lista([H|T],L,[H2|W]) :- maksimum(L,Maks), binarnie(Maks,Maks2), length(Maks2,D), length(H,D2), zera(H,D,D2,H2), lista(T,L,W).

blista2([],[]).
blista2([H|T],[H1|W]) :- binarnie(H,H1), blista2(T,W).

list(L,W) :- blista2(L,X), lista(X,X,W).
