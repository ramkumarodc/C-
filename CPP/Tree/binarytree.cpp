
//Dynamic code for complete binary tree

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
    public:
        Node* root = nullptr;

        Node * getNewNode(int data)
        {
            Node * node = new Node;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }

        Node* insert(Node* node, int data)
        {
            if(node==nullptr)
            {
                node = getNewNode(data);
            }
            else if(balance(node)==0)
            {
                if(check(node->right))
                {
                    node->right = insert(node->right, data);
                }
                else
                {
                    node->left = insert(node->left, data);
                }
            }
            else if(balance(node)==1)
            {
                if(check(node->left))
                {
                    node->left = insert(node->left, data);
                }
                else
                {
                    node->right = insert(node->right, data);
                }
            }
            return node;
        }

        int height(Node* node)
        {
            int ret_height =0;
            if(node!=nullptr)
            {
                int left_height = height(node->left)+1;
                int right_height = height(node->right)+1;
                if(left_height > right_height)
                {
                    ret_height = left_height;
                }
                else
                {
                    ret_height = right_height;
                }
            }
            return ret_height;
        }

        int balance(Node* node)
        {
            int ret_balance = 0;
            int left_height = height(node->left)+1;
            int right_height = height(node->right)+1;
            ret_balance = left_height - right_height;
            return ret_balance;
        }

        bool check(Node* node)
        {
            if(node==nullptr)
            {
                return false;
            }
            if(balance(node))
            {
                return true;
            }
            bool left = check(node->left);
            bool right = check(node->right);
            return  (left|| right);
        }

        void preorder(Node * node)
        {
            if(node!= nullptr)
            {
                cout<<node->data <<" ";
                preorder(node->left);
                preorder(node->right);
            }
        }
        void inorder(Node * node)
        {
            if(node!= nullptr)
            {
                inorder(node->left);
                cout<<node->data <<" ";
                inorder(node->right);
            }
        }
        void postorder(Node * node)
        {
            if(node!= nullptr)
            {
             
                postorder(node->left);
                postorder(node->right);
                cout<<node->data <<" ";
            }
        }
        void levelorder(Node* node)
        {
            int h = height(node)+1;
            for(int i=1; i<=h; i++)
            {
                printlevelorder(node , i);
            }
        }
        void printlevelorder(Node* node, int level)
        {
            if(node != nullptr)
            {
                if(level == 1)
                {
                    cout<<node->data<<" ";
                }
                else
                {
                    printlevelorder(node->left, level-1);
                    printlevelorder(node->right, level-1);
                }
            }
        }
        void queueLevelOrder(Node* node)
        {
            queue<Node*> q;
            q.push(node);

            while(q.empty()==false)
            {
                Node* node1 = q.front();
                cout<<node1->data<<" ";
                q.pop();

                if(node1->left != nullptr)
                {
                    q.push(node1->left);
                }

                if(node1->right != nullptr)
                {
                    q.push(node1->right);
                }
            }
        }

        void deletenode(Node* node, int val)
        {
            queue<Node*> q;
            q.push(node);

            Node* curr = nullptr;
            Node* keynode = nullptr;
            Node* last = nullptr;
            Node* pl = nullptr;
            Node* pr = nullptr;
            while(!q.empty())
            {
                curr = q.front();
                q.pop();
                if(curr->data == val)
                {
                    keynode = curr;
                }

                if(curr->left)
                {
                    q.push(curr->left);
                    pl = curr;
                    pr = nullptr;
                }

                if(curr->right)
                {
                    q.push(curr->right);
                    pr = curr;
                    pl = nullptr;
                }
            }
            last = curr;

            if(keynode)
            {
                keynode->data = last->data;
                delete last;
                
                if(pr)
                {
                    pr->right = nullptr;
                }
                if(pl)
                {
                    pl->left = nullptr;
                }
            }
        }

        int depth(Node* node, int val)
        {
            
            int dist = -1;
            if(node)
            {
                if(node->data == val )
                {
                    dist+=1;
                }
                else 
                {
                    int dl = depth(node->left, val);
                    int dr = depth(node->right, val);
                    if(dl>dr)
                    {
                        dist = dl+1;
                    }
                    if(dr>dl)
                    {
                        dist = dr+1;
                    }
                }
            }
            return dist;
        }
};

int main()
{

    Solution sol;
    Node* root  = nullptr;
    root = sol.insert(root, 1);
    root = sol.insert(root, 2);
    root = sol.insert(root, 3);
    root = sol.insert(root, 4);
    root = sol.insert(root, 5);
    root = sol.insert(root, 6);
    root = sol.insert(root, 7);
    //cout<<"Pre-Order: "; sol.preorder(root); cout<<endl;
    //cout<<"In-Order: "; sol.inorder(root);cout<<endl;
    //cout<<"Post-Order: "; sol.postorder(root); cout<<endl;
    //cout<<"Level-Order: "; sol.levelorder(root); cout<<endl;
    cout<<"Queue-Level-Order: "; sol.queueLevelOrder(root); cout<<endl;
    cout<<sol.depth(root, 1)<<endl;

    //sol.deletenode(root, 3);
    //cout<<"Queue-Level-Order: "; sol.queueLevelOrder(root); cout<<endl;
    //sol.deletenode(root, 6);
    //cout<<"Queue-Level-Order: "; sol.queueLevelOrder(root); cout<<endl;
    return 0;
}

