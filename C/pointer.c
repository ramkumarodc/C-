#include<stdio.h>

void func(int *ptr)
{
	*ptr = 7;
}

void func1(int &ref)
{
	ref = 1;
}

void func2(int * &refPtr)
{
	*refPtr = 2;
}

/*void func3(int &*ptrRef)
{
	*ptrRef = 3;
}
Error:
======
pointer.c:18:18: error: cannot declare pointer to ‘int&’
   18 | void func3(int &*ptrRef)
      |                  ^~~~~~
*/

int main()
{
	int val =5;
	int *ptr = &val;
	int **dptr = &ptr;

	func(*dptr);
	printf("%p - %d\n", *dptr,*ptr);

        *ptr = 3;
	func(ptr);
        printf("%p - %d\n", *dptr,*ptr);

	val = 9;
	func(&val);//Note: func is called in 3 ways
	printf("%p - %d\n", *dptr,*ptr);
//**********************************************************************
	int &ref = val;
	func1(val);
	printf("Value of val:%d\n", val);
	func1(ref); 
	printf("Value of ref:%d\n", ref);
	func1(**dptr);
	func1(*ptr); //func1 called in 4 ways
//**********************************************************************
	
	func2(ptr);
	printf("Value of val:%d\n", val);
	func2(*dptr);
//**********************************************************************
        int *refPtr = &ref;  
       	/*int& *refptr = &ref; 
pointer.c:18:18: error: cannot declare pointer to ‘int&’
   18 | void func3(int &*ptrRef)
      |                  ^~~~~~*/

	return 0;
}	
