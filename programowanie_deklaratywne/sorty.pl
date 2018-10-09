polowki([], [], []).
polowki([X | Rest], [X | Left], NRight) :- append(Cos, [Last], Rest), polowki(Cos, Left, Right), append(Right, [Last], NRight).

sum([], 0).
sum([N | T], Sum) :- sum(T, Subsum), Sum is Subsum + N.

pnp([], [], []).
pnp([N | T], Even, [N | Odd]) :- N mod 2 =\= 0, !, pnp(T, Even, Odd).
pnp([N | T], [N | Even], Odd) :- pnp(T, Even, Odd).

rosnaca([_]).
rosnaca([First, Second | T]) :- First < Second, rosnaca([Second | T]).

arytmetyczny([_, _]).
arytmetyczny([A, B, C | T]) :- C - B =:= B - A, arytmetyczny([B, C | T]).

npoczatek(0, _, []) :- !.
npoczatek(N, [H | T], [H | Subresult]) :- N1 is N - 1, npoczatek(N1, T, Subresult).

nprzeplot(_, [], [], []) :- !.
nprzeplot(N, List1, List2, Result) :- npoczatek(N, List1, HList1),
	npoczatek(N, List2, HList2), append(HList1, NList1, List1),
	append(HList2, NList2, List2), nprzeplot(N, NList1, NList2, Subresult),
	append(HList2, Subresult, Almost), append(HList1, Almost, Result).

doposort(X, [], [X]) :- !.
doposort(X, [H | T], [X, H | T]) :- H > X, !.
doposort(X, [H | T], [H | Subresult]) :- doposort(X, T, Subresult).

wstawsort([], []).
wstawsort([H | T], Result) :- wstawsort(T, Subresult), doposort(H, Subresult, Result).

podzial([], [], []).
podzial(List, [H | Tail], [Pocz | Subresult]) :- npoczatek(H, List, Pocz), append(Pocz, Res, List), podzial(Res, Tail, Subresult).

zamiana([], []).
zamiana([First, Second | Tail], [Second, First | Tail]) :- First > Second, !.
zamiana([First | Tail], [First | Subresult]) :- zamiana(Tail, Subresult).

babel(In, Out) :- zamiana(In, Subresult), In \= Subresult, babel(Subresult, Out), !.
babel(In, In).

rozbij([], _, [], []).
rozbij([H | Tail], X, [H | Subless], Submore) :- H < X, !, rozbij(Tail, X, Subless, Submore).
rozbij([H | Tail], X, Subless, [H | Submore]) :- rozbij(Tail, X, Subless, Submore).

kwiksort([], []).
kwiksort([H | Tail], Result) :- rozbij(Tail, H, Less, More), kwiksort(Less, Sortedless), kwiksort(More, Sortedmore), append(Sortedless, [H | Sortedmore], Result).

rozbijlen([], _, [], []).
rozbijlen([H | Tail], X, [H | Subless], Submore) :- length(H, HLength), length(X, XLength), HLength < XLength, !, rozbijlen(Tail, X, Subless, Submore).
rozbijlen([H | Tail], X, Subless, [H | Submore]) :- rozbijlen(Tail, X, Subless, Submore).

kwiksortlen([], []).
kwiksortlen([H | Tail], Result) :- rozbijlen(Tail, H, Less, More), kwiksortlen(Less, Sortedless), kwiksortlen(More, Sortedmore), append(Sortedless, [H | Sortedmore], Result).

rozbijabs([], _, [], [], _).
rozbijabs([H | Tail], X, [H | Subless], Submore, Cos) :- HLength is abs(H - Cos), XLength is abs(X - Cos), HLength < XLength, !, rozbijabs(Tail, X, Subless, Submore, Cos).
rozbijabs([H | Tail], X, Subless, [H | Submore], Cos) :- rozbijabs(Tail, X, Subless, Submore, Cos).

distsort(_, [], []).
distsort(X, [H | Tail], Result) :- rozbijabs(Tail, H, Less, More, X), distsort(X, Less, Sortedless), distsort(X, More, Sortedmore), append(Sortedless, [H | Sortedmore], Result).
