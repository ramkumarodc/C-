#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int bf;
};

class solution
{
    public:
        solution(){}
        Node* getnewnode(int val)
        {
            Node* node = new Node;
            node->data = val;
            node->left = nullptr;
            node->right = nullptr;
            node->bf = 0;
            return node;
        }

        Node* insert(Node* node, int val)
        {
            if(node==nullptr)
            {
                node = getnewnode(val);
            }
            else if(val < node->data)
            {
                node->left = insert(node->left, val);
            }
            else if(val > node->data)
            {
                node->right = insert(node->right, val);
                
            }
            node = selfbalance(node);
            return node;
        }

        Node* selfbalance(Node* node)
        {
            node->bf = balance(node);

            //balannce the tree
            if( node->bf > 1)
            {
                if(node->left->bf > 0)
                {
                    node = ll_rotate(node);
                }
                else
                {
                    node = lr_rotate(node);
                }
            }
            else if(node->bf < -1)
            {
                if(node->right->bf < 0)
                {
                    node = rr_rotate(node);
                }
                else
                {
                    node = rl_rotate(node);
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

        int height(Node* node)
        {
            int hgt =-1;
            if(node)
            {
                int hgt_left=0;
                int hgt_right=0;
                hgt_left = height(node->left)+1;
                hgt_right = height(node->right)+1;
                if(hgt_left < hgt_right)
                {
                    hgt = hgt_right;
                }
                else
                {
                    hgt = hgt_left;
                }
            }
            return hgt;
        }

        int balance(Node* node)
        {
            int bf=0;
            if(node)
            {
                int left = height(node->left) + 1;
                int right = height(node->right)  +1;
                bf = left - right;
            }
            return bf;
        }

        void levelorder(Node* node)
        {
            queue<Node*> q;
            q.push(node);

            while(!q.empty())
            {
                Node* tmp = q.front();
                q.pop();
                cout<<tmp->data<<" ";
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
            }
        }

        Node* ll_rotate(Node* node)
        {
            Node* tmp = node->left;
            node->left = tmp->right;
            tmp->right = node;
            return tmp;
        }

        Node* rr_rotate(Node* node)
        {
            Node* tmp = node->right;
            node->right = tmp->left;
            tmp->left = node;
            return tmp; 
        }

        Node* lr_rotate(Node* node)
        {
            Node* tmp = node->left;
            node->left =  rr_rotate(tmp);
            return ll_rotate(node);

        }

        Node* rl_rotate(Node* node)
        {
            Node* tmp = node->right;
            node->right = ll_rotate(tmp);
            return rr_rotate(node);
        }

        Node* deleteNode(Node* node)
        {
            
        }
};
int main()
{
    Node* root = nullptr;
    solution sol;
    root = sol.insert(root, 14); 
    
    root = sol.insert(root, 17); 
    root = sol.insert(root, 11); 
    
    root = sol.insert(root, 7); 
    root = sol.insert(root, 53); 
    root = sol.insert(root, 4); 

    root = sol.insert(root, 13); 
    root = sol.insert(root, 12); 
    root = sol.insert(root, 8); 
    root = sol.insert(root, 60); 
    root = sol.insert(root, 19); 
    root = sol.insert(root, 16); 
    root = sol.insert(root, 20); 
    sol.levelorder(root); 
    return 0;
}