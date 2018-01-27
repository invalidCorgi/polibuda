#include <stdio.h>
#include <stdlib.h>

long long silnia(long long liczba)
{
    if(liczba<2) return 1;
    int i;
    for(i=liczba-1;i>1;i--)
    {
        liczba*=i;
    }
    return liczba;
}

long long newton(long long n, long long k)
{
    return silnia(n)/(silnia(k)*silnia(n-k));
}

int main()
{
    long long n=6, k=4;
    long long i=1;
    for(;i<=k;i++)
    {
        printf("%I64d po %I64d = %I64d\n",n,i,newton(n,i));
    }
    return 0;
}
