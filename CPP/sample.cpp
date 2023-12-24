#include<iostream>
#include<cstring>
using namespace std;

//case 1:
// int main()
// {
//     int value1 = 5;
//     int value2 = 6;
//     int* const ptr = &value1;
//     cout<<*ptr<<endl;
//     //ptr = &value2; //compilation error
//     return 0;
// }

//case  2:
// int main()
// {
//     int value1 = 5;
//     const int* ptr = &value1;
//     //*ptr = 6; //compilation error
//     cout<<*ptr<<endl;
//     return 0;
// }

//case 3:
class sample
{
    public:
        int *iptr;
        int val;
    
        sample()
        {
            val = 10;
            iptr = new int(20);
        }
        void display()
        {
            cout<<"Hi from sample..\n";
        }
};
int main()
{
    // const sample s2;
    // //s2.display();  //compilation error
    const sample s1;
    
    
    // const sample s3(s1);
    // s3.display();

     sample s4(s1);
    cout<<"S4:"<<*(s4.iptr)<<endl;
    cout<<"S1:"<<*(s4.iptr)<<endl;
    *(s4.iptr) = 6;
     cout<<"S4:"<<*(s4.iptr)<<endl;
    cout<<"S1:"<<*(s4.iptr)
    <<endl;
    return 0;
}

// std::string gen_sec_key() 
// { 
//     // ...
//     string rand_str = "abc";
//     return rand_str;
// }
// class AuthKey
// {
//     string key;
//     int accessCounter;
//     public:
//         AuthKey():key(gen_sec_key()),accessCounter(0)
//         {}
//         // AuthKey(const AuthKey& K)
//         // {
//         //     key = K.key;
//         //     accessCounter = K.accessCounter;
//         // }
//         AuthKey& getAuthKey()
//         {
//             return *this;
//         }

// };

// int main(int argc, char** argv)
// {
//     // AuthKey K1;
//     // const AuthKey K2 = K1.getAuthKey();
//     // return 0;

