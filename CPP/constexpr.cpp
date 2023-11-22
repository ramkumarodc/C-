#include<iostream>
#include<array>
using namespace std;

constexpr int func(int a, int b)
{
    return a+b;
}
int main()
{
    const int a=10;
    const int b=20;
    constexpr int res = func(a,b);
    cout<<res<<endl;
    int c, d;
    cin>>c;
    cin>>d;
    int res1 = func(c, d);
    cout<<res1<<endl;
    return 0;
}