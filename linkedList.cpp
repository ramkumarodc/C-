#include<iostream>
#include "linkedList.h"
#include <vector>

using namespace std;

linkedList::linkedList()
{
    cout<<"***********************************************************LinkedList***********\n";
    list = nullptr;
}

Node * linkedList::getNewNode(int val)
{
    Node* tnode = new Node;
    tnode->data = val;
    tnode->next = nullptr;
    return tnode;
}

int linkedList::IsLast(Node* list)
{
    if(list->next == NULL)
        return true;
    else
        return false;
}

void linkedList::addNode(int val)
{
    Node* tnode = getNewNode(val);

    if(list == nullptr)
    {
        list = tnode;   
    }
    else
    {
        Node* curr = list;
        while(curr)
        {
            if(curr->next == nullptr)
            {
                curr->next = tnode;
                break;
            }
            curr = curr->next;
        }
    }
    cout<<"***added***"<<endl;
}

void linkedList::printList()
{
    if(!list)
        cout<<"***Empty list***"<<endl;

    Node* curr = list;
    while(curr)
    {
        cout<<curr->data<<"-->";
        curr = curr->next;
    }
    cout<<endl;
}

void linkedList::insertAtFirst(int val)
{
    Node* tnode = getNewNode(val);
    tnode->next = list;
    list = tnode;
    cout<<"***Inserted at first***"<<endl;
}

void linkedList::insertAtLast(int val)
{
    Node* tnode =  getNewNode(val);
    Node* curr = list;
    while(curr)
    {
        if(curr->next == nullptr)
        {
            curr->next = tnode;
            break;
        }
        curr = curr->next;
    }
    cout<<"***Inserted at last***"<<endl;
}

void linkedList::insertAtPos(int val, int pos)
{
    Node* tnode =  getNewNode(val);
    Node* curr = list;
    Node* prev = nullptr;
    int i=1;
    while(curr)
    {
        if(i==pos)
        {
            if(prev)//insert from 2nd position
            {
                prev->next = tnode;
                tnode->next= curr;
            }
            else//insert at first position
            {
                tnode->next = list;
                list = tnode;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    cout<<"***Inserted at pos:"<<pos<<"***"<<endl;
}

void linkedList::deleteNode(int val)
{
    Node* curr = list;
    Node *prev = nullptr;
    Node* dnode =nullptr;
    while(curr)
    {
        if(curr->data == val)
        {
            dnode = curr;
            if(prev)
                prev->next = curr->next;
            else
                list = curr->next;
            delete dnode;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    cout<<"***deleted***"<<endl;
}

void linkedList::reverseIterative()
{
    Node* prev = nullptr;
    Node *next = nullptr;

    Node* curr = list;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list = prev;
    cout<<"***reversed iteratively***"<<endl;
}

void linkedList::reverseRecursive()
{
    recursiveReverse(list);
    cout<<"***reversed recursively***"<<endl;
}

Node* linkedList::recursiveReverse(Node* currNode)
{
    if((currNode==nullptr) || (currNode->next == nullptr))
    {
        list = currNode;
        return currNode;
    }   
    Node* nextNode = recursiveReverse(currNode->next);
    nextNode->next = currNode;
    currNode->next = nullptr;
    return currNode;
}

void linkedList::middleNode_ArrayMethod()
{
    int mVal = 0;
    vector<Node*> lstVec;
    Node* curr = list;
    while(curr)
    {
        lstVec.push_back(curr);
        curr = curr->next;
    }
    
    int mIdx = lstVec.size()/2;
    if(mIdx)
        mVal = lstVec[mIdx]->data;
    cout<<"Value of Middle Node:"<< mVal << endl;
}

void linkedList::middleNode_slowFastPtr()
{
    Node *slow = list, *fast = list;
    while(fast  && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Value of Middle Node:"<< slow->data << endl;
}


void linkedList::getDecimalValue_ArrayMethod()
{
    Node* curr = list;
    int sum = 0;
    while(curr)
    {
        sum = 2*sum+curr->data;
        curr = curr->next;
    }
    cout<<"Decimal Val:"<<sum<<endl;
}

void linkedList::getDecimalValue_BinaryMethod()
{
    Node* curr = list;
    int sum = 0;
    while(curr)
    {
        sum = sum<<1|curr->data;
        curr = curr->next;
    }
    cout<<"Decimal Val:"<<sum<<endl;
}

void linkedList::delete_N_nodes_After_M_nodes(int n, int m)
{
    int no_of_nodes= n;
    int position = m;

    Node* curr = list;
    Node* prev = nullptr;
    while(curr && position>0)
    {
        position--;
        prev = curr;
        curr = curr->next;
    }

    while(curr && no_of_nodes>0)
    {
        Node* dnode = curr;
        no_of_nodes--;
        curr = curr->next;
        delete dnode;
    }
    prev->next = curr;
}

int main()
{
    linkedList *linkedlist = new linkedList();
    while(1)
    {
        cout<<"0. Exit 1. printList 2. addNode 3. insertAtFirst 4. insertAtLast ";
        cout<<"5. insertAtPos 6. deleteNode 7. reverseIterative 8. reverseRecursive ";
        cout<<"9. middleNode_ArrayMethod 10.middleNode_slowFastPtr 11. getDecimalValue_ArrayMethod ";
        cout<<"12. getDecimalValue_BinaryMethod 13. delete_N_nodes_After_M_nodes"<<endl;

        cout<<"Enter the choice:";
        int choice=0, val=0, pos=0;
        cin>>choice;
        switch(choice)
        {
            case 1:
                linkedlist->printList();
                break;
            case 2:
                cout<<"Enter the Value:";
                cin>>val;
                linkedlist->addNode(val);
                break;
            case 3:
                cout<<"Enter the Value:";
                cin>>val;
                linkedlist->insertAtFirst(val);
                break;
            case 4:
                cout<<"Enter the Value:";
                cin>>val;
                linkedlist->insertAtLast(val);
                break;
            case 5:
                cout<<"Enter the Value:";
                cin>>val;
                cout<<"\nEnter the position:";
                cin>>pos;
                linkedlist->insertAtPos(val, pos);
                break;
            case 6:
                cout<<"Enter the Value:";
                cin>>val;
                linkedlist->deleteNode(val);
                break;
            case 7:
                 linkedlist->reverseIterative();
                 break;
            case 8:
                linkedlist->reverseRecursive();
                break;
            case 9:
                linkedlist->middleNode_ArrayMethod();
                break;
            case 10:
                linkedlist->middleNode_slowFastPtr();  
                break;
            case 11:
                linkedlist->getDecimalValue_ArrayMethod();
                break;
            case 12:
                linkedlist->getDecimalValue_BinaryMethod();
                break;
            case 13:
                int n, m;
                cout<<"Enter number of nodes to delete:";
                cin>>n;
                cout<<"Enter the position to delete:";
                cin>>m;
                linkedlist->delete_N_nodes_After_M_nodes(n,m);
                break;
            case 0:
                return 0;
        }
    }
}