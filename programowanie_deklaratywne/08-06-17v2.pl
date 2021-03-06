alfabet([a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]).

poz(X,[X|_],1):-!.
poz(X,[_|T],W):-poz(X,T,SubW),W is SubW+1.

pozycja(X,W):-alfabet(A),poz(X,A,W).

dec2bin(0,[0]):-!.
dec2bin(1,[1]):-!.
dec2bin(X1,R):-X2 is X1 mod 2, X3 is X1 div 2, dec2bin(X3,SubR),append(SubR,[X2],R).

wyrownaj(X1,X2,X1,X2):-length(X1,D1),length(X2,D2),D1=:=D2,!.
wyrownaj(X1,X2,W1,W2):-length(X1,D1),length(X2,D2),D1<D2,!,wyrownaj([0|X1],X2,W1,W2).
wyrownaj(X1,X2,W1,W2):-wyrownaj(X1,[0|X2],W1,W2).

xor(X,X,0):-!.
xor(_,_,1).

xorL([],[],[]):-!.
xorL([H1|T1],[H2|T2],[H3|T3]):-xor(H1,H2,H3),xorL(T1,T2,T3).

bin2dec([0],0):-!.
bin2dec([1],1):-!.
bin2dec([H1|T1],R):-length(T1,D1),X1 is H1*(2^D1),bin2dec(T1,SubR),R is SubR+X1.

wstaw(X,_,[],[X]):-!.
wstaw(X,M,[H1|T1],[X,H1|T1]):-klucz(X,M,W1),klucz(H1,M,W2),W1=<W2,!.
wstaw(X,M,[H1|T1],[H1|T2]):-wstaw(X,M,T1,T2).

wstawSort([],_,[]):-!.
wstawSort([H1|T1],M,R):-wstawSort(T1,M,SubR),wstaw(H1,M,SubR,R).

klucz(X,Maska,R):-dec2bin(X,BX),dec2bin(Maska,MX),wyrownaj(BX,MX,BX2,MX2),xorL(BX2,MX2,XOR),bin2dec(XOR,R).
