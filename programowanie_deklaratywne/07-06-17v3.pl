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

test(A,B) :- lista1(A,C), C=[H|_], B=H.


zamiana([X],[X]).
zamiana([H,H2|T],[H2,H|T]) :- test([H],X),test([H2],Y), X>Y,!.
%zamiana([H1|T1],[H1,T2]) :- zamiana(T1,T2).
% zamiana([H,H2|T],[H2,H|T]) :- lista1([H],X),lista1([H2],Y),X=[A|_],
% Y=[B|_], A>B,!.
zamiana([H,H1|T1],[H|T2]) :- zamiana([H1|T1],T2).

b�bel(X,Y) :- zamiana(X,Y), X=Y,!.
b�bel(X,Y) :- zamiana(X,Z), X\=Z, b�bel(Z,Y).


main(Lista,W) :-  b�bel(Lista,W).

zera(L,X,X,L):-!.
zera(L,D1,D2,Lwy) :- D is D2+1, zera([0|L],D1,D,Lwy).
