#include<iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
};


class queue
{
        Node* head;
        Node * tail;
    public:
	    queue()
	    {
            head = tail = nullptr;
        }
        void push(int val)  // 5 6 7 -> 9
        {
            //push in the back
            if(tail == nullptr)
            {
               tail = getNewNode(val);
               head = tail;
            }
            else
            {
                tail->next = getNewNode(val); // node 6
                tail = tail->next;
            }
        }

        void pop()
        {
            //pop in the front
            if(head!=nullptr)
            {
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
            
        Node* getNewNode(int data)
        {
            Node* tmp = nullptr;
            try
            {
                tmp = new Node;
                tmp->val = data;
                tmp->next = nullptr;
            }
            catch(...)
            { 
                return nullptr;
            }
            return tmp;
        }
};

int main()
{
    queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.pop();
    return 0;
}