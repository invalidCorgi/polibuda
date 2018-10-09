dzielniki(_,1,[1]) :- !.
dzielniki(X,D,[D|T]) :- X mod D =:= 0, D2 is D-1, dzielniki(X,D2,T),!.
dzielniki(X,D,L) :- D2 is D-1, dzielniki(X,D2,L).


parzyste([],[]).
parzyste([H|T],[H|T2]) :- H mod 2 =:= 0, parzyste(T,T2),!.
parzyste([_|T],L) :- parzyste(T,L).

nieparzyste([],[]).
nieparzyste([H|T],[H|T2]) :- H mod 2 =:= 1, nieparzyste(T,T2),!.
nieparzyste([_|T],L) :- nieparzyste(T,L).

sumuj([],0).
sumuj([H|T],C) :- sumuj(T,C1), C is C1+H.

lista1([],[]).
lista1([H|T],[H2|T2]) :- H mod 2 =:= 0,dzielniki(H,H,H3), parzyste(H3,H4), sumuj(H4,H2), lista1(T,T2),!.
lista1([H|T],[H2|T2]) :- dzielniki(H,H,H3), nieparzyste(H3,H4), sumuj(H4,H2), lista1(T,T2).

zamiana([X],[X2],[X],[X2]).
zamiana([H,H2|T],[H3,H4|T2],[H2,H|T],[H4,H3|T2]) :- H3>H4,!.
zamiana([H1|T1],[H2|T3],[H1|T2],[H2|T4]) :- zamiana(T1,T3,T2,T4).

b¹bel(X,X2,Y,Y2) :- zamiana(X,X2,Y,Y2), X2=Y2,!.
b¹bel(X,X2,Y,Y2) :- zamiana(X,X2,Z,Z2), X2\=Z2, b¹bel(Z,Z2,Y,Y2).

main(Lista,W) :-lista1(Lista,Lista1), b¹bel(Lista,Lista1,W,_).
