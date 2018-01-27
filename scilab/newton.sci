function wynik=newton(n,k)
    while (modulo(n,1)<>0) | (n<1) | (modulo(k,1)<>0) | (k<0) | (k>n)
        n=input("Podaj n:")
        k=input("Podaj k:")
    end
    if (k==0) | (k==n) then
        wynik=1
        return
    end
    wynik=silnia(n)/(silnia(k)*silnia(n-k))
endfunction
