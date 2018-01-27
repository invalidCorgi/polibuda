wstaw(_,X,[],[X]):-!.
wstaw(Srodek,X,[H|T],[X,H|T]):-odlOdSrodka(X,Srodek,L1),odlOdSrodka(H,Srodek,L2),L1=<L2,!.
wstaw(Srodek,X,[H|T1],[H|T2]):-wstaw(Srodek,X,T1,T2).

wstawSort(_,[],[]):-!.
wstawSort(Srodek,[H|T],Lwy):-wstawSort(Srodek,T,Subres),wstaw(Srodek,H,Subres,Lwy).

srodekMasy([],[],0,0,0,0):-!.
srodekMasy([[A,B,C]|T],[X,Y,Z],SumX,SumY,SumZ,N):-srodekMasy(T,_,SubSumX,SubSumY,SubSumZ,N1),N is N1+1,SumX is SubSumX+A,SumY is SubSumY+B,SumZ is SubSumZ+C,X is SumX/N,Y is SumY/N,Z is SumZ/N.

odlOdSrodka([X1,Y1,Z1],[X2,Y2,Z2],Odleglosc):-Odleglosc is (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2)+(Z1-Z2)*(Z1-Z2).

wynik(Lwe,Lwy):-srodekMasy(Lwe,Srodek,_,_,_,_),wstawSort(Srodek,Lwe,Lwy).
