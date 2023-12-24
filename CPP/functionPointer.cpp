#include<iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

typedef int (*fp)(int ,int);

int func(int a, int b, fp op)
{
    int c = op(a,b);
    return c;
}


fp func1(int type)
{
    if (type==1)
        return add;
    else 
        return subtract;
}

int main()
{
    //int (*functionpointer)(int,int);
    // functionpointer= add;
    // cout<<functionpointer(5,4)<<endl;
    // functionpointer = substract;
    //cout<<functionpointer(7,5)<<endl;
    cout<<func(5,6, func1(1))<<endl;
    cout<<func(5,3, func1(2))<<endl;
    return 0;
}