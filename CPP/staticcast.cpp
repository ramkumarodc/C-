#include<iostream>
#include<memory>
using namespace std;

//program1
// int main()
// {
//      double doubleValue = 3.14;
//      int intValue = doubleValue; // Error: narrowing conversion
//      char ch = 'G';
//      int val = ch;
//      //int* pvl = &ch; //Error
//      int* pvl1 = (int*)&ch; //C style casting allows it , bit it corrupt the memeory
//      //int *pvl2 = static_cast<int*>(&doubleValue); //, Here c++ casting throws error
//      return 0;
// }

//Program 2
// class Int
// {
//      int x;
//      public:
//           Int(int a): x(a) {cout<<"Constructor Int(a)\n";}
//           operator string()
//           {
//                cout<<"operator string()\n";
//                return to_string(x);
//           }
// };
// int main()
// {
//      Int obj(5);
//      string str = obj;
//      obj =10;

//      string str1 = static_cast<string> (obj);
//      obj = static_cast<Int>(30);
// }

//program 3
// class Base
// {
// };
// class Derived: private Base
// {
// };
// int main()
// {
//      Derived d1;
//      //Base* bp1 = &d1;
//      Base* bp2 = (Base*)&d1;//c-style cast is wrong here, but below c++ cast provides strong type checking
//      //Base* bp3 = static_cast<Base*>(&d1);
// }

//program 4
class Base
{
};
class Derived1: public Base
{
     public:
          void func()
          {
               cout<<"Derived1::func()\n";
          }
};
class Derived2: public Base
{
};

int main()
{
     Derived1 d1;
     Derived2 d2;

     Base* bp1 = static_cast<Base*>(&d1); //upcasting is ok
     Base* bp2 = static_cast<Base*>(&d2); //upcasting is ok

     //Derived1* dp1 = (Derived1*)bp2; //No Error  but c-style casting performs wrong casting
     Derived1* dp1 = static_cast<Derived1*>(bp2); //No Error  but c++-style casting also worng here , instead have to use dynamic casting
     dp1->func();
     return 0;
}


//prgram 5
// int main()
// {
//      int v = 5;
//      void* vpv = static_cast<void*> (&v);
//      int* ipv = static_cast<int*> (vpv);
//      cout<<*ipv<<endl;
// }