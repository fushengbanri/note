#include<stdio.h>

void binary_to_ascii();
long factorial();

int main()
{
    int a = 4267;
    int b = 10;
    binary_to_ascii(a);
    b=factorial(b);
    printf("b=%d\n",b);
}


void binary_to_ascii(unsigned int value)
{
    unsigned int quotient;
    quotient=value/10;
    if(quotient!=0){
        printf("begin... \n");
        binary_to_ascii(quotient);
    }
    putchar(value % 10 + '0');
    printf("\n");
}

long factorial(int n)
{
    if (n <=0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}




