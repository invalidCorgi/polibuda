function F = fibonacci(n)
    if n<1 then
        F=[0]
        return
    end
    if n==1 then
        F=[1]
        return
    end
    F=[1 1]
    j=3
    while(j<=n)
        F(1,j)=F(1,j-1)+F(1,j-2)
        j=j+1
    end
endfunction
