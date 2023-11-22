#include<iostream>
#include<memory>
using namespace std;

class B
{
    public:
    B()
    {
        cout<<"constructor B"<<endl;
    }
    ~B()
    {
        cout<<"Destructor B"<<endl;
    }
};

class D: public B
{
    public:
    D()
    {
        cout<<"constructor D"<<endl;
    }
    ~D()
    {
        cout<<"Destructor D"<<endl;
    }
};
int main()
{
    shared_ptr<B> p = make_shared<D>();
    cout<<"p.get(): "<< p.get()<<endl;
    cout<<"p.use_count(): "<< p.use_count()<<endl;
    shared_ptr<B> q(move(p));
     cout<<"q.get(): "<< q.get()<<endl;
    cout<<"q.use_count(): "<< q.use_count()<<endl;
    return 0;
}