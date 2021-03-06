del(X,[X|T],T).
del(X,[H|T1],[H|T2]) :- del(X,T1,T2).

add(A,B,[A|B]).

ostatni([X],[X]).
ostatni([_|T],X):-ostatni(T,X).

przedostatni([X,_],X).
przedostatni([_|T],X):-przedostatni(T,X).

licz(X,[X],Licz):-Licz is 1.
licz(X,[Y],Licz):-X\=Y, Licz is 0.
licz(X,[X|T],L1):-licz(X,T,L2), L1 is 1+L2.
licz(X,[Y|T],L1):-X\=Y,licz(X,T,L2), L1 is 0+L2.

conc([],Y,Y).
conc([H|T],Y,[H|X]):-conc(T,Y,X).

%suma([],0).
%suma([H|T],X):-suma(T,Y), X is H+Y.

%ileElem([],L):-L is 0.
%ileElem([_|T],L1):-ileElem(T,L2), L1 is 1+L2.

%srednia(X,W):-suma(X,W1),ileElem(X,W2),W is W1/W2.

srednia([X],W,S,D):-S is X, D is 1, W is S/D.
srednia([H|T],W1,S1,D1):-srednia(T,_,S2,D2),S1 is H+S2, D1 is 1+D2, W1 is S1/D1.

liczisumuj([], 0, 0).
liczisumuj([H|T], L, S) :- liczisumuj(T, L1, S1), L is L1+1, S is S1+H.
srednia(A, B) :- liczisumuj(A, L, S), B is S/L.

liczisumuj([],[], 0, 0).
liczisumuj([H|T],[H2|T2], L, S) :- liczisumuj(T,T2, L1, S1), L is L1+H2, S is S1+H*H2.
srednia(A, B, C) :- liczisumuj(A, B, L, S), C is S/L.

codrugi([_], []).
codrugi([_,B], [B]).
codrugi([_,H2|T1], [H2|T2]) :- codrugi(T1, T2).

insert(A, Lin, Lout) :- del(A, Lout, Lin).

member(X, [X]).
member(X, [X|_]).
member(X, [_|T]) :- member(X, T).

sublist(X, L) :- conc(X, _, L2), conc(_, L2, L).

usunpodliste(L, PL, Lout) :- conc(L1, PL, X), conc(X, L2, L), conc(L1, L2, Lout).

bezostatniego([_], []).
bezostatniego([H|T], [H|T2]) :- bezostatniego(T, T2).

odwroc([X], [X]).
odwroc([A,B], [B,A]).
odwroc(L, [H|T]) :- ostatni(L, H), bezostatniego(L, X), odwroc(X, T).

srodkowy([_,B,_], B).
srodkowy([_|T], X) :- srodkowy(L, X), bezostatniego(T, L).

licz2(_, [], 0).
licz2(A, [H|T], N) :- licz(A, T, N), H\=A.
licz2(A, [A|T], N) :- licz(A, T, N1), N is N1+1.

ntyElement([H|_],1,H):-!.
ntyElement([_|T],N,X):-N1 is N-1,ntyElement(T,N1,X).

poteguj(X, 1, X).
poteguj(L, P, X) :- poteguj(L, P1, X1), P is P1+1, X is X1*L.
