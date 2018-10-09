F=[1 1]
i=0.5
j=3
while(modulo(i,1)<>0)
i=input("Podaj n:")
end
while(j<=i)
    F(1,j)=F(1,j-1)+F(1,j-2)
    j=j+1
end
