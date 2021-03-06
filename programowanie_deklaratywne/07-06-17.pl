%sum([],_,Klucz,[Klucz]) :- !.
%sum([H|T],Klucz,Count,[Count|T2]) :- H=\=Klucz,!,sum(T,H,1,T2).
%sum([_|T],Klucz,Count,W) :- Count2 is Count+1, sum(T,Klucz,Count2,W).

%podrzad([H|T],Lwy) :- sum(T,H,1,Lwy).

%sklej([],0).
% sklej([H|T],L) :-length(T,D), Y is 10^D, H2 is H*Y, sklej(T,L2),L is
% H2+L2.

%dzielniki(_,1,[1]):-!.
% dzielniki(X,Count1,[Count1|T1]):-X mod Count1=:=0,!,Count2 is
% Count1-1,dzielniki(X,Count2,T1).
%dzielniki(X,Count1,T1):-Count2 is Count1-1,dzielniki(X,Count2,T1).

dzielniki(_,1,[1]) :- !.
dzielniki(X,D,[D|T]) :- X mod D =:= 0, D2 is D-1, dzielniki(X,D2,T),!.
dzielniki(X,D,L) :- D2 is D-1, dzielniki(X,D2,L).

parzyste([],[]).
parzyste([H|T],[H|T2]) :- H mod 2 =:= 0, parzyste(T,T2),!.
parzyste([_|T],L) :- parzyste(T,L).

parzysteLista([],[]):-!.
parzysteLista([H1|T1],[H2|T2]):-parzyste(H1,H2),parzysteLista(T1,T2).

nieparzyste([],[]).
nieparzyste([H|T],[H|T2]) :- H mod 2 =:= 1, nieparzyste(T,T2),!.
nieparzyste([_|T],L) :- nieparzyste(T,L).

nieparzysteLista([],[]):-!.
nieparzysteLista([H1|T1],[H2|T2]):-nieparzyste(H1,H2),nieparzysteLista(T1,T2).

%lista1([],[]).
%lista1([H|T],[H2|T2]) :- dzielniki(H,H,H2), lista1(T,T2).

suma([],0):-!.
suma([H1|T1],Result):-suma(T1,Subres),Result is H1+Subres.

bla([],[]):-!.
bla([H1|T1],[H2|T2]):-bla2(H1,H2),bla(T1,T2).

bla2([],[]):-!.
bla2([H1|T1],W):-H1 mod 2 =:= 0,!,parzyste(T1,Sub),suma(Sub,W).
bla2([_|T1],W):-nieparzyste(T1,Sub),suma(Sub,W).

lista2(Lista,Lwy) :- lista1(Lista,ListaDzielnikow),bla(ListaDzielnikow,Lwy).%,parzysteLista(ListaDzielnikow,LDP).%,nieparzysteLista(ListaDzielnikow,LDNP).

wstaw(X,[],[X]):-!.
wstaw(X,[H1|T1],[X,H1|T1]):-klucz(X,W1),klucz(H1,W2),W1=<W2,!.
wstaw(X,[H1|T1],[H1|T2]):-wstaw(X,T1,T2).

wstawSort([],[]):-!.
wstawSort([H1|T1],Result):-wstawSort(T1,Subres),wstaw(H1,Subres,Result).

klucz(X,W):-dzielniki(X,X,LDziel),bla2(LDziel,W).


%zamiana([X],[X]).
%zamiana([H,H2|T],[H2,H|T]) :- klucz(H,X),klucz(H2,Y),X>Y,!.
%zamiana([H1|T1],[H1|T2]) :- zamiana(T1,T2).

%b�bel(X,Y) :- zamiana(X,Y), X=Y,!.
%b�bel(X,Y) :- zamiana(X,Z), X\=Z, b�bel(Z,Y).

zamiana([X],_,[X],_).
zamiana([H,H2|T],[H3,H4|T2],[H2,H|T],[H4,H3|T2]) :- klucz(H,X),klucz(H2,Y),X>Y,!.
zamiana([H1|T1],[H1|T2]) :- zamiana(T1,T2).

b�bel(X,Y) :- zamiana(X,Y), X=Y,!.
b�bel(X,Y) :- zamiana(X,Z), X\=Z, b�bel(Z,Y).


main(Lista,W) :-  b�bel(Lista,W).

lista1([],[]).
lista1([H|T],[H2|T2]) :- H mod 2 =:= 0,dzielniki(H,H,H3), parzyste(H3,H4), sumuj(H4,H2), lista1(T,T2),!.
lista1([H|T],[H2|T2]) :- dzielniki(H,H,H3), nieparzyste(H3,H4), sumuj(H4,H2), lista1(T,T2).

sumuj([],0).
sumuj([H|T],C) :- sumuj(T,C1), C is C1+H.
