#include<iostream>
using namespace std;

class RC
{
    int count =0;
    public:
        RC():count(0)
        {

        }
        void AddRef()
        {
            count++;
        }
        int removeRef()
        {
            return --count;
        }
        int use_count()
        {
            return count;
        }
};
class sample
{
    public:
        sample()
        {
            cout<<"sample ctor"<<endl;
        }
        ~sample()
        {
            cout<<"sample dtor"<<endl;
        }
        void display()
        {
            cout<<"sample::display"<<endl;
        }
};

template<typename T>
class smart
{
    private:
        T *sptr;
        RC* reference;
    public:
        smart():sptr(nullptr)
        {
            reference = new RC;
            reference->AddRef();
        }
        smart(T* ptr)
        {
            sptr = ptr;
            reference = new RC();
            reference->AddRef();
        }
        smart(const smart<T>& sp):sptr(sp->sptr),reference(sp->reference)
        {
            reference->AddRef();
        }
        ~smart()
        {
            if(reference->removeRef()==0)
            {
                delete sptr;
                delete reference;
            }
        }

        T* operator->()
        {
            return sptr;
        }
        T& operator*()
        {
            return *sptr;
        }
        int use_count()
        {
            return reference->use_count();
        }
        smart<T>& operator=(const smart<T>& obj)
        {
            if(this !=&obj)
            {
                if(reference->removeRef()==0)
                {
                    delete reference;
                    delete sptr;    
                }
                reference = obj.reference;
                sptr=obj.sptr;
                reference->AddRef();
            }
            return *this;
        }
};
int main()
{
    smart<sample> sp(new sample);
    sp->display();
    (*sp).display();
    cout<<"\n"<<sp.use_count()<<endl;
    smart<sample> sp1;
    cout<<"\n"<<sp1.use_count()<<endl;
    sp1=sp;
    cout<<"\n"<<sp1.use_count()<<endl;
    cout<<"\n"<<sp.use_count()<<endl;
    return 0;
}
