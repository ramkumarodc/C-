#include<stdio.h>

int rangeBitwiseAnd(int m, int n)
{
    int shift =0;
    while(m<n)
    {
        m>>=1;
        n>>=1;
        shift++;
    }
    m<<=shift;
    return m;
}


int main()
{
    puts("Bitwise AND of Numbers Range:");
    printf("%d\n", rangeBitwiseAnd(5,7));
    return 0;
}