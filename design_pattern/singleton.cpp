#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

// class singleton
// {
//     public: 
//     static singleton* createinstance()
//     {
//         if(!instance)
//             instance = new singleton;
//         return instance;
//     }

//     singleton(const singleton&) = delete;
//     private:
//         static singleton* instance;
//         static int val;
//         singleton() {}
// };

// singleton* singleton::instance = nullptr;
// int singleton::val = 0;

// int main()
// {
//     singleton *p1 = singleton::createinstance();  
//     return 0;
// }


/*************************singleton in multitheading*/
// static mutex m;
// class singleton
// {
//     static singleton* instance;
//     singleton(){}

//     public:

//     static singleton* createonstance()
//     {
//         //lock_guard<mutex> lock(m);
//         m.lock();
//         if(!instance)
//         {
//             cout<<"new instnace created"<<endl;
//             instance = new singleton;
//         }
//         m.unlock();
//         return instance;

//     }
// };

// singleton* singleton::instance = nullptr;

// int main()
// {
//     thread t1([](){singleton::createonstance(); } );
//     thread t2([](){singleton::createonstance(); } );
//     thread t3([](){singleton::createonstance(); } );
//     if(t1.joinable())
//         t1.join();
//     if(t2.joinable())
//         t2.join();
//     if(t3.joinable())
//         t3.join();                
//     return 0;
// }

/****************************Modern c++*****************/
class singleton
{
    private:
        singleton()
        {
            cout<<"new instance created"<<endl;
        }
        singleton(const singleton&) = delete;
        singleton& operator=(const singleton&) = delete;
    public:
        static singleton& createInstance()
        {
            
            static singleton obj;
            return obj;
        }

};

int main()
{
    thread t1([](){singleton::createInstance();});
    thread t2([](){singleton::createInstance();});
    thread t3([](){singleton::createInstance();});

    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    if(t3.joinable())
        t3.join();                
    return 0;
}