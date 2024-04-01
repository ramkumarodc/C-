#include<iostream>
#include<cstring>
#include<thread>
#include<mutex>
using namespace std;

namespace myutil
{
    string gen_sec_key()
    {
        return "ram";
    }
    template<typename T>
    class lockguard
    {
        mutex &m1;
        public:
            lockguard(mutex &m):m1(m)
            {
                m1.lock();
            }
            ~lockguard()
            {
                m1.unlock();
            }
    };
    class AuthKey
    {
        private:
            string key;
            mutable int accessCounter;
            mutable mutex m1;
        public:
            AuthKey():accessCounter(0),key(gen_sec_key())
            {
            }
            AuthKey(const AuthKey& obj)
            {
                accessCounter=0;
                key =obj.key;
            }
            const string &getKey() const
            {
               lockguard<mutex> lc(m1); 
                ++accessCounter;
                return key;
            }
    };
}
int main()
{
    myutil::AuthKey k1;
    const myutil::AuthKey k2(k1);
    const string &s1 = k2.getKey();
   //s1.append("s");

    return 0;
}