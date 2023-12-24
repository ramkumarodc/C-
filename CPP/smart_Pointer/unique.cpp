#include<iostream>
#include <fstream>
#include <cassert>
#include<memory>
using namespace std;

struct B
{
    virtual ~B() = default;
    virtual void bar() 
    {
        cout<<"B::bar"<<endl;
    }
};

struct D: B
{
    D()
    {
        cout<<"D::D"<<endl;
    }

    ~D()
    {
        cout<<"D::~D"<<endl;
    }

    void bar() override
    {
        cout<<"D::bar"<<endl;
    }
};
   
unique_ptr<D> pass_through(unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(FILE *fp)
{
    cout<<"closing demo.txt"<<endl;
    fclose(fp);
}


struct List
{
    struct Node
    {
        int data;
        unique_ptr<Node> next;
    };

    unique_ptr<Node> head;

    ~List()
    {
        while(head)
        {
            auto next = move(head->next);
            head = move(next);
        }
    }

    void push(int data)
    {
        head = unique_ptr<Node>(new Node{data, move(head)});
    }
};

int main()
{
     std::cout << "1) Unique ownership semantics demo\n";
     {
        std::unique_ptr<D> p = make_unique<D>();
        unique_ptr<D> q= pass_through(move(p));
        assert(!p);
     }

     cout<<"2)  Runtime polymorphism demo\n";
     {
        unique_ptr<B> p = make_unique<D>();
        p->bar();
     }

     cout<<"3) custom deleter demo\n";
     ofstream("demo.txt")<<'x';
     {
        using unique_file_t = unique_ptr<FILE, decltype(&close_file)>;
        unique_file_t fp(fopen("demo.txt", "r"), &close_file);
        if(fp)
        {
            cout<<char(getc(fp.get()))<<endl;
        }
     }

    cout<<"4) custom lamda expression  deleter and exception safety demo"<<endl;
    try
    {
        unique_ptr<D, void(*)(D*)> p(new D, [](D* ptr)
        {
            cout<<"Destrying from custom deleter"<<endl;
            delete ptr;
        });

        throw runtime_error("");
    }
    catch(const std::exception& e)
    {
        std::cerr << "caught exception" << '\n';
    }
     

    cout<<"5) Array form of unique_ptr\n";
    {
        unique_ptr<D[]> p = make_unique<D[]>(2);
    }


    cout<<"6) Linked List Demo\n";
    {
        List wall;
        const int enough{1'000'000};
        for (int beer = 0; beer != enough; ++beer)
            wall.push(beer);
    }
}