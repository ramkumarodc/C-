#include<iostream>
using namespace std;

class sample
{
    public:
        sample()
        {
            cout<<"sample ctor\n";
        }
        sample (const sample &sam)
        {
            cout<<"Called sample copy ctr\n";
        }

        sample& operator=(const sample& sam)
        {
            cout<<"assignment operator called\n";
            return *this;
        }
};
class widget
{
    public:
        using sam = sample;
        widget()
        {
            cout<<"Widget ctor\n";
        }
    
        sam& data() &
        {
            cout<<"called lvalue reference\n";
            return obj;

        }

        auto data() &&
        {
            cout<<"called rvalue refernce\n";
            return std::move(obj);
        }
    private:
        sam obj;
};
widget makewidget()
{
    widget w;
    return w;
}
int main()
{
    //widget w;
    //auto& obj = w.data();
    makewidget().data();
    return 0;
}