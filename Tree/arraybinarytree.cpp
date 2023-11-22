//complete binary tree implementation using Array

#include<iostream>
#include<vector>
using namespace std;

class solution
{
    public:
        vector<int> arr;
        void insert(int data)
        {
            arr.push_back(data);
        }
        void printlevelorder()
        {
            for(int i=0; i<arr.size(); i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        int getLeftChild(int idx)
        {
            return  2*idx+1;
        }
        int getRightChild(int idx)
        {
            return 2*idx+2;
        }
        void preorder(int idx)
        {

            if(idx!=-1&& idx<arr.size())
            {
                cout<<arr[idx]<<" ";
                preorder(getLeftChild(idx));
                preorder(getRightChild(idx));
            }
        }
        void inorder(int idx)
        {

            if(idx<arr.size())
            {
                inorder(2*idx+1);
                cout<<arr[idx]<<" ";
                inorder(2*idx+2);
            }
        }
        void postorder(int idx)
        {
            if(idx<arr.size())
            {
                postorder(2*idx+1);
                postorder(2*idx+2);
                cout<<arr[idx]<<" ";
            }
        }

        void deleteNode(int val)
        {
            int n = arr.size();
            for(int i=0; i<n; i++)
            {
                if(arr[i]==val)
                {
                    if(arr[i]!=arr[n-1])
                        arr[i] = arr[n-1];
                    arr.pop_back();
                }
            }
        }

};
int main()
{
    cout<<"*****complete binary tree implementation using Array*****\n";
    solution sol;
    sol.insert(1);
    sol.insert(2);
    sol.insert(3);
    sol.insert(4);
    sol.insert(5);
    sol.insert(6);
    sol.insert(7);
    cout<<"Level-Order:"; sol.printlevelorder(); cout<<endl;
    sol.deleteNode(3);
    cout<<"Level-Order:"; sol.printlevelorder(); cout<<endl;
    sol.deleteNode(6);
    cout<<"Level-Order:"; sol.printlevelorder(); cout<<endl;
    //cout<<"Pre-Order: "; sol.preorder(0); cout<<endl;
    //cout<<"In-Order: "; sol.inorder(0); cout<<endl;
    //cout<<"Post-Order: "; sol.postorder(0); cout<<endl;

}