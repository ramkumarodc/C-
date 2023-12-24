#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preorder_recursive(Node* node)
{
    if(node)
    {
        cout<<node->data<<" ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }
}
void inorder_recursive(Node* node)
{
    if(node)
    {
        inorder_recursive(node->left);
        cout<<node->data<<" ";
        inorder_recursive(node->right);
    }
}

void postorder_recursive(Node* node)
{
    if(node)
    {
        postorder_recursive(node->left);
        postorder_recursive(node->right);
        cout<<node->data<<" ";
    }
}

void Ipreorder(Node* node)
{
    if(node)
    {
        Node* curr = node;
        stack<Node*> s;
        while(curr|| s.empty()==false)
        {
            while(curr)
            {
                cout<<curr->data<<" ";
                if(curr->right)
                {
                    s.push(curr->right);
                }
                curr = curr->left;
            }
            if(s.empty()== false)
            {
                curr = s.top();
                s.pop();
            }

        }
    }
}

void Iinorder(Node* node)
{
    if(node)
    {
        Node* curr = node;
        stack<Node*> s;
        while(curr || s.empty()==false)
        {
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            if(s.empty()==false)
            {
                curr = s.top();
                cout<<curr->data<<" ";
                s.pop();
            }
            curr = curr->right;
        }
    }
}

void Ipostorder(Node* node)
{
    if(node)
    {
        stack<Node*> s;
        s.push(node);
        Node* op = nullptr;
        Node* prev = nullptr;
        Node* curr = nullptr;
        while(s.empty()==false)
        {
            curr = s.top();
            if(prev == nullptr || prev->left == curr || prev->right == curr)
            {     
                if(curr->left)
                {
                    s.push(curr->left);
                }
                else if(curr->right)
                {
                    s.push(curr->right);
                }
                else
                {
                    cout<<curr->data<<" ";
                    s.pop();
                }
            }
            else if( curr->left == prev)
            {
                if(curr->right)
                {
                    s.push(curr->right);
                }
                else
                {
                    cout<<curr->data<<" ";
                    s.pop();
                }
            }
            else if(curr->right == prev)
            {
                cout<<curr->data<<" ";
                s.pop(); 
            }
            prev = curr;
        }
    }
}

/*
    1
    /\
   2  3
  /\  /\
 4  5 6 7 */
int main()
{
    Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    cout<<"recursion"<<endl;
    cout<<"preorder:"; preorder_recursive(node); cout<<endl;
    cout<<"inorder:"; inorder_recursive(node); cout<<endl;
    cout<<"postorder:"; postorder_recursive(node); cout<<endl;
    cout<<"iterative"<<endl;
    Ipreorder(node); cout<<endl;
    Iinorder(node); cout<<endl;
    Ipostorder(node); cout<<endl;
    return 0;
}