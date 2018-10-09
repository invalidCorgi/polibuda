sublist(S,L):- append(_,L2,L),append(S,_,L2).
:- op(100,xfy,^).
:- op(100,fy,~).
add1(X,L,L):- member(X,L),!.
add1(X,L,[X|L]).
count(_,[],0).
count(A,[B|L],N):- atom(B), A=B,!,count(A,L,N1),N is N1+1.
count(A,[_|L],N):- count(A,L,N).
p(N):-N=1 ; N=2, ! ; N=3,!.
kot.
maketable:-
L=[0,1,2,3,4,5,6,7,8,9],
member(X,L),member(Y,L),
Z is X*Y,
assert(product(X,Y,Z)),
fail;true.
makesqr:- repeat, read(X),proc(X).
proc(stop):- !.
proc(X):- Y is X*X,
write(Y), nl,
fail.
age(peter,7).
age(ann,5).
age(pat,8).
age(tom,5).

imie(kulawy).
imie(chuj).

pisz(X):-repeat,write(X).

