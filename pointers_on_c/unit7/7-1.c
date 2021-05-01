#include<stdio.h>
#include<string.h>

int hermite();

int main()
{
    
}

int hermite(int n, int x)
{
    if(n<0)
        return 1;
    else if(n=1)
        return 2*x;
    else
        return (2*x*(hermite((n-1),x)- 2*(n-1)*(hermite((n-2),x))));
}

int gcd(int m, int n)
{
    int r;
    if(m<=0||n<=0)
        return 0;
    r=m%n;
    return r>0?gcd(m,r):n;
}
