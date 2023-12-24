#include<iostream>
using namespace std;

class product
{
    public:
        virtual void getProduct() = 0;
};


class productA: public product
{
    public:
        void getProduct()
        {
            cout<<"product-A"<<endl;
        }
};

class productB: public product
{
    public:
        void getProduct()
        {
            cout<<"product-B"<<endl;
        }
};


class creator
{
    public:
    virtual product* createProduct() = 0;

    void solution()
    {
        product* obj = this->createProduct();
        obj->getProduct();
    }
};

class createrProductA: public creator
{
    public:
        product* createProduct()
        {
            return new productA;
        }
};

class creatorProductB: public creator
{
    public:
        product* createProduct()
        {
            return new productB;
        }
};

int main()
{
    creator* p_crea = new creatorProductB;
    p_crea->solution();
    return 0;
}