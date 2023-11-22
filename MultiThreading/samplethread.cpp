#include<iostream>
#include<thread>
#include <unistd.h>
#include<mutex>
using namespace std;
std::mutex m;
void print(char c)
{

        for(int i=0; i<50000; i++)       
        {
            if(m.try_lock())
            {
                cout<<c;
                m.unlock();
            }
            else
            {
                cout <<c<<" - lock not acquired"<<endl;
            }
        }
}   

void star()
{
    for(int i=0; i<50000; i++)
    {
        cout<<"*";
    }
}
int main()
{
    thread w1(print, '=');

    thread w2(print, '+');
    w1.join();
    w2.join();
    return 0;
}