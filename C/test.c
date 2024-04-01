#include<stdio.h>

#define swap(a, b, c) {c t; t=a; a=b; b =t;}
int main()
{
	int a =5;
	int b=4;
	swap(a, b, int);
	printf("%d %d",a,b);
	//printf("%d",(void*)0);
	return 0;
}
