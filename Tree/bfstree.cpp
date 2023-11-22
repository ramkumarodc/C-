#include<iostream>
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

void bfstree(Node* node)
{
    if(node)
    {
        Node* curr = nullptr;
        queue<Node*> q;
        q.push(node);
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size; i++)
            {
                curr = q.front();
                cout<<curr->data<<" ";
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
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
    bfstree(node);
    return 0;
}