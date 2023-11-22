#include<iostream>
using namespace std;

void func(int val)
{

}
int main()
{
    enum class color {black, white, red};

    auto white = false;
    color c = color::white;

    enum col{cr, gt,ot};
    
    col cl = gt;
    if(cl<12){ 
        func(cl);
    }

    if(static_cast<int>(c)<12)
    {
        func(static_cast<int>(c));
    }

    return 0;
}