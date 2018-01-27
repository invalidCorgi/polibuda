licznik=1
mianownik=1
i=2
while (i<=n)
    licznik=licznik*i
    i=i+1
end
i=2
while (i<=k)
    mianownik=mianownik*i
    i=i+1
end
i=2
while (i<=(n-k))
    mianownik=mianownik*i
    i=i+1
end
wynik=licznik/mianownik
disp(wynik)
