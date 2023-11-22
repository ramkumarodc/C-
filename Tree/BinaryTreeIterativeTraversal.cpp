#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<stack>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// void iterativePreorder(node* root)
// {
//     if(root== nullptr)
//     {
//         return;
//     }

//     stack<node*> nodeStack;
//     nodeStack.push(root);

//     vector<int> ans;
//     while(!nodeStack.empty())
//     {
//         node* tmp = nodeStack.top();
//         ans.push_back(tmp->data);
//         nodeStack.pop();

//         if(tmp->right)
//         {
//             nodeStack.push(tmp->right);
//         }
//         if(tmp->left)
//         {
//             nodeStack.push(tmp->left);
//         }
//     }
// }

void preorder(node* node1, vector<int>& ans)
{
    if(node1 == nullptr)
    {
        return;
    }

    node* curr = node1;
    stack<node*> stk;
    while(curr || !stk.empty())
    {
        while(curr)
        {
            ans.push_back(curr->data);
            if(curr->right)
            {
                stk.push(curr->right);
            }
            curr = curr->left;
        }

        if(!stk.empty())
        {
            curr = stk.top();
            //ans.push_back(curr->data);
            stk.pop();
        }
    }
}

void inorder(node* node1, vector<int>& ans)
{
    if(node1==nullptr)
    {
        return;
    }

    node* curr = node1;
    stack<node*> stk;
    while(curr|| !stk.empty())
    {
        while(curr)
        {
            stk.push(curr);
            curr= curr->left;
        }

        curr = stk.top();
        ans.push_back(curr->data);
        stk.pop();
        curr= curr->right;
    }
}

void postorder(node* node1, vector<int>& ans)
{
    if(node1==nullptr)
    {
        return;
    }

    stack<node*> s;
    s.push(node1);

    node* prev = nullptr;
    while(!s.empty())
    {
        node* curr = s.top();

        if(prev==nullptr || prev->left == curr || prev->right == curr)
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
                s.pop();
                ans.push_back(curr->data);                
            }
        }
        else if(curr->left == prev)
        {
            if(curr->right)
            {
                s.push(curr->right);
            }
            else{
                s.pop();
                ans.push_back(curr->data);
            }
        }
        else if(curr->right = prev)
        {
            s.pop();
            ans.push_back(curr->data);
        }
        prev = curr;
    }
}
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  1

preorder: 10 8 3 5 2 1
inorder: 3 8 5 10 1 2
postorder: 3 5 8 10 1 2
  */
    struct node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(1);
    vector<int> ans;
    //iterativePreorder(root);
    //preorder(root, ans);
    vector<int> ans1;
    //inorder(root, ans1);
    vector<int> ans2;
    postorder(root,ans2);

    return 0;
}