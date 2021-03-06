next(�winouj�cie,ko�obrzeg,118).
next(�winouj�cie, szczecin,106).
next(ko�obrzeg,ustka,117).
next(ustka, gda�sk,136).
next(gda�sk,toru�,170).
next(gda�sk,olsztyn,136).
next(olsztyn,toru�, 176).
next(olsztyn,bia�ystok,238).
next(szczecin,bydgoszcz,257).
next(szczecin, gorz�w-wlkp,111).
next(bydgoszcz,toru�,45).
next(bydgoszcz,pozna�,142).
next(pozna�,toru�,161).
next(gorz�w-wlkp,pozna�,170).
next(gorz�w-wlkp,zielona-g�ra,119).
next(zielona-g�ra,pozna�,155).
next(zielona-g�ra,wroc�aw,156).
next(toru�,warszawa,210).
next(toru�,��d�,179).
next(bia�ystok, warszawa,199).
next(bia�ystok,lublin,252).
next(pozna�,��d�,202).
next(warszawa,radom,102).
next(warszawa,��d�,128).
next(radom,lublin,116).
next(radom,kielce,77).
next(wroc�aw,��d�,219).
next(��d�,radom,136).
next(��d�,cz�stochowa, 124).
next(cz�stochowa,kielce,132).
next(cz�stochowa,katowice,73).
next(katowice,krak�w,80).
next(kielce,krak�w, 115).
next(kielce,rzesz�w,163).
next(lublin,kielce,176).
next(lublin,rzesz�w,168).
next(krak�w,rzesz�w,176).
% Pytanie: Jakie s� po��czenia miedzy �winouj�ciem a Rzeszowem?

%odcinek

droga(X,Y) :- next(X,Y,_).
droga(X,Y) :- next(X,Z,_),droga(Z,Y).

przez(A,B,A) :- next(A,B,_).
przez(A,B,P) :- next(A,C,_),przez(C,B,P).

droga2(X,Y,odcinek(X,Y)) :- next(X,Y,_).
droga2(X,Y,odcinek(X,Q)) :- next(X,Z,_),droga2(Z,Y,Q).

droga3(X,Y,[X,Y]) :- next(X,Y,_).
droga3(X,Y,[X|Q]) :- next(X,Z,_),droga3(Z,Y,Q).

odleglosc(X,Y,Q) :- next(X,Y,Q).
odleglosc(X,Y,W) :- next(X,Z,A),odleglosc(Z,Y,B), W is A+B.

ostatni([X],X).
ostatni([_|Y],M) :- ostatni(Y,M).

przedostatni([X,_],X).
przedostatni([_|Y],M) :- przedostatni(Y,M).

%kopiowanie list

kopia([X],[X]).
kopia([X|T],[X|Y]) :- kopia(T,Y).

kopiaParz([X],[X]):-X mod 2=:=0.
kopiaParz([X],[]):-X mod 2=\=0.
kopiaParz([H1|T1],[H1|T2]):-H1 mod 2=:=0,kopiaParz(T1,T2).
kopiaParz([H1|T1],T2):-H1 mod 2=\=0,kopiaParz(T1,T2).

%todo: bezostatniego

nakoniec(X,[],[X]).
nakoniec(A,[B|C],[B|D]) :- nakoniec(A,C,D).

napocz(X,[],X).
napocz(A,B,[A|B]).

bezostatniego([A,_],[A]).
bezostatniego([A|B],[A|C]) :- bezostatniego(B,C).

pokrycie(kura,piora).
pokrycie(wrobel,piora).
pokrycie(sep,piora).
chodzenie(kura).
latanie(wrobel).
latanie(sep).
ptak(X):-pokrycie(X,piora),latanie(X).

nakoniec2(X,Lwe,Lwy):-append(Lwe,[X],Lwy).

odwracaj([],[]).
odwracaj([H|T],L):-odwracaj(T,OT),append(OT,[H],L).

srodkowy([A],A):-!.
srodkowy([A,_],A):-!.
srodkowy([_|T],S):-append(L,[_],T),srodkowy(L,S).

%codrugi([A,_],A).
codrugi([],[]):-!.
codrugi([A],[A]):-!.
codrugi([A,_|T],[A|B]) :- codrugi(T,B).

podziel([H,T],[H],[T]).
podziel([H|T],[H|T2],P):-append(L,[X],T),podziel(L,T2,T3),append(T3,[X],P).

pivoting(_,[],[],[]):-!.
pivoting(H,[A|T1],[A|B],C):-A=<H,pivoting(H,T1,B,C),!.
pivoting(H,[A|T1],B,[A|C]):-pivoting(H,T1,B,C).

qs([],[]).
qs([H|T],Sorted):-pivoting(H,T,L1,L2),qs(L1,Sorted1),qs(L2,Sorted2),append(Sorted1,[H|Sorted2],Sorted).
