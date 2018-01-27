cos(0):-!.
cos(N):- N1 is N-1, cos(N1), write(N).

cos2(0):-!.
cos2(N):- write(N), N1 is N-1, cos2(N1).

%wstaw(X,[],[X]):-!.
%wstaw(X,[H|T],[X,H|T]):-X=<H,!.
%wstaw(X,[H|T1],[H|T2]):-wstaw(X,T1,T2).

%wstawSort([],[]):-!.
%wstawSort([H|T],Lwy):-wstawSort(T,Subres),wstaw(H,Subres,Lwy).

wstaw(X,Y,[],[],[X],[Y]):-!.
wstaw(X,Y,[H1|T1],[H2|T2],[X,H1|T1],[Y,H2|T2]):-Y=<H2,!.
wstaw(X,Y,[H1|T1],[H2|T3],[H1|T2],[H2|T4]):-wstaw(X,Y,T1,T3,T2,T4).

wstawSort([],[],[],[]):-!.
wstawSort([H1|T1],[H2|T2],Lwy,LPomoc):-wstawSort(T1,T2,Subres1,Subres2),wstaw(H1,H2,Subres1,Subres2,Lwy,LPomoc).

srodekMasy([[A,B,C]],[A,B,C],A,B,C,1):-!.
srodekMasy([[A,B,C]|T],[X,Y,Z],SumX,SumY,SumZ,N):-srodekMasy(T,_,SubSumX,SubSumY,SubSumZ,N1),N is N1+1,SumX is SubSumX+A,SumY is SubSumY+B,SumZ is SubSumZ+C,X is SumX/N,Y is SumY/N,Z is SumZ/N.

odlOdSrodka([X1,Y1,Z1],[X2,Y2,Z2],Odleglosc):-Odleglosc is (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)+(Z1-Z2)*(Z1-Z2).

odlOdSrodkaLista([],_,[]):-!.
% odlOdSrodkaLista([[X,Y,Z]|T1],Srodek,Wyjscie):-odlOdSrodka([X,Y,Z],Srodek,H2),odlOdSrodkaLista(T1,Srodek,T2),append(H2,T2,Wyjscie).
%
odlOdSrodkaLista([H1|T1],Srodek,[H2|T2]):-odlOdSrodka(H1,Srodek,H2),odlOdSrodkaLista(T1,Srodek,T2).

wynik(Lwe,Lwy):-srodekMasy(Lwe,Srodek,_,_,_,_),odlOdSrodkaLista(Lwe,Srodek,LPomoc),wstawSort(Lwe,LPomoc,Lwy,_).
