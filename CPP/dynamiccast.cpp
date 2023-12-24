#include<iostream>
using namespace std;
class Base
{
    public:
    virtual ~Base(){}
};

class Derived1 : public Base
{

};
class Derived2: public Base
{

};
int main()
{
    Derived1 d1;
    Derived2 d2;

    Base *bp1 = dynamic_cast<Base*> (&d1);

    Derived1 *dp1 = dynamic_cast<Derived1*>(&d1);
    if(dp1)
    {
        cout<<"dp1 is not null"<<endl;
    }
    else
    {
        cout<<"dp1 is null"<<endl;
    }

    Derived1 *dp2 = dynamic_cast<Derived1*>(&d2);
    if(dp2)
    {
        cout<<"dp2 is not null"<<endl;
    }
    else
    {
        cout<<"dp2 is null"<<endl;
    }

    try
    {
        Derived1 &dr1 = dynamic_cast<Derived1&>(d2);
    }
    catch(std::bad_cast& e)
    {
        std::cerr << "dynamic cast failed: "<<e.what() << '\n';
    }
    

    return 0;
}