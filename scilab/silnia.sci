function N = silnia(n)
    N=1
    while (modulo(n,1)<>0) | (n<1)
        n=input("Podaj n:")
    end
    while(n>=2)
        N=N*n
        n=n-1
    end
endfunction
