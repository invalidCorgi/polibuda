%wstaw(X,[],[X]):-!.
%wstaw(X,[H|T],[X,H|T]):-X=<H,!.
%wstaw(X,[H|T1],[H|T2]):-wstaw(X,T1,T2).

wstaw(X,Y,[],[],[X],[Y]):-!.
wstaw(X,Y,[H|T],[H2|T2],[X,H|T],[Y,H2|T2]):-Y=<H2,!.
wstaw(X,Y,[H|T1],[H2|T3],[H|T2],[H2|T4]):-wstaw(X,Y,T1,T3,T2,T4).

wstawsort([],[],[],[]).
wstawsort([H|T],[H2|T2],Result,Result2):-wstawsort(T,T2,Subres,Subres2),wstaw(H,H2,Subres,Subres2,Result,Result2).

binarnie(0,[]):-!.
binarnie(X1,Res):-X1 mod 2 =:= 0, !, X2 is X1 div 2, binarnie(X2,T), append(T,[0],Res).
binarnie(X1,Res):-X2 is X1 div 2, binarnie(X2,T), append(T,[1],Res).

listaBinarnie([],[]):-!.
listaBinarnie([H1|T1],[H2|T2]):-binarnie(H1,H2),listaBinarnie(T1,T2).

jedynki([],0):-!.
jedynki([H|T],Res):-H=:=1,!,jedynki(T,SubRes),Res is SubRes+1.
jedynki([_|T],Res):-jedynki(T,Res).

zera([],0):-!.
zera([H|T],Res):-H=:=0,!,zera(T,SubRes),Res is SubRes+1.
zera([_|T],Res):-zera(T,Res).

stosunekJedynek([],[]):-!.
stosunekJedynek([H1|T1],[H2|T2]):-jedynki(H1,X1),zera(H1,X2),H2 is X1-X2,stosunekJedynek(T1,T2).

sortuj(Lwe,Lwy):-listaBinarnie(Lwe,LBin),stosunekJedynek(LBin,LStos),wstawsort(Lwe,LStos,Lwy,_).
