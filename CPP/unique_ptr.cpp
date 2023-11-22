#include<iostream>
#include<memory>

using namespace std;

class widget
{
    public:
        widget()
        {
            cout<<"widget ctor..\n"<<endl;
        }
        ~widget()
        {
            cout<<"widget dtor..\n"<<endl;
        }
        int val =0;
};


void customdel(widget* obj)
{
    if(obj!=nullptr)
    {
        delete obj;
    }
}
int main()
{

    // auto custom = [](widget* obj){ if(obj) delete obj; };   
    // //unique_ptr<widget,void(*)(widget*)> uptr(new widget, customdel);
    // unique_ptr<widget,decltype(custom)> uptr(nullptr, custom);
    // uptr.reset(new widget);
    // uptr->val =10;


    shared_ptr<widget> sptr = make_shared<widget>();
    shared_ptr<widget> sptr1(new widget, customdel);
    shared_ptr<widget> sptr2;
    sptr2 = sptr;
    cout<<sptr.use_count()<<endl;

    return 0;
}