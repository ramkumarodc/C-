#include<iostream>
#include<list>
using namespace std;

template<typename T>
struct MyAlloc: public allocator<T>
{
};

template<typename T>
struct MyAllocList
{
    typedef std::list<T,MyAlloc<T>> type;
};

template<typename T>
class widget
{
    typename MyAllocList<T>::type lista;
};

int main()
{
    cout<<"Starting myalloc"<<endl;
    MyAllocList<int>::type alist;
    
    return 0;
}