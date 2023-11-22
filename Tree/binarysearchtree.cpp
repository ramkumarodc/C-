#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class solution
{
    public:
        Node* getnewnode(int val)
        {
            Node* node = new Node;
            node->data = val;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }

        Node* insert(Node* node, int val)
        {
            if(node==nullptr)
            {
                node = getnewnode(val);
            }
            else
            {
                if(node->data > val)
                {
                    node->left = insert(node->left, val);
                }
                else if(node->data <val)
                {
                    node->right = insert(node->right, val);
                }
            }
            return node;
        }

        void preorder(Node* node)
        {
            if(node)
            {
                cout<<node->data<<" ";
                preorder(node->left);
                preorder(node->right);
            }
        }

        void deletenode(Node* node, int val)
        {
            if(node->data == val)
            {

            }
        }
        int findmin(Node* node)
        {
            if(node)
            {
                while(node->left)
                {
                    node = node->left;
                }
                return node->data;
            }
            return -1;
        }

        int findmax(Node* node)
        {
            if(node==nullptr)
                return 0;

            if(node->right==nullptr)
            {
                return node->data;
            }
            else
            {
                return findmax(node->right);
            }
        }

        Node* deleteNode(Node* node, int val)
        {
            if(node)
            {
                if(node->data < val)
                {
                    node->right = deleteNode(node->right, val);
                }
                else if(node->data > val)
                {
                    node->left = deleteNode(node->left, val);
                }
                else if(node->left==nullptr && node->right==nullptr)
                {
                    delete node;
                    node = nullptr;
                }
                else if(node->left == nullptr)
                {
                    Node* tmp = node;
                    node = node->right;
                    delete tmp;
                }
                else if(node->right == nullptr)
                {
                    Node* tmp= node;
                    node = node->left;
                    delete tmp;
                }
                else
                {
                    node->data = findmin(node->right);
                    node->right = deleteNode(node->right, node->data);
                }
            }
            return node;
        }
};

int main()
{
    solution sol;
    Node* root = nullptr;
    root = sol.insert(root, 8);
    root = sol.insert(root, 3);
    root = sol.insert(root, 10);
    root = sol.insert(root, 1);
    root = sol.insert(root, 6);
    root = sol.insert(root, 14);
    root = sol.insert(root, 4);
    root = sol.insert(root, 7);
    root = sol.insert(root, 13);
    cout<<"PreOrder: "; sol.preorder(root); cout<<endl;
    cout<<"Min Value:" <<sol.findmin(root)<<endl;
    cout<<"Max Value:" <<sol.findmax(root)<<endl;
    cout<<"Delete 7:"; sol.deleteNode(root, 7);
    cout<<"PreOrder: "; sol.preorder(root); cout<<endl;
    cout<<"Delete 3:"; sol.deleteNode(root, 3);
    cout<<"PreOrder: "; sol.preorder(root); cout<<endl;
    
    return 0;
}