wynik = 2
i = 3
while i <= 100
    j=1;
    while j <= i-1
        j=j+1;
        if modulo(i,j)==0 then
            break
        end
        if j == i-1 then
            wynik = wynik + i
        end
    end
    i=i+1;
end
