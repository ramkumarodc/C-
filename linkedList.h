#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node
{
    int data;
    Node * next;
};
class linkedList
{
    private:
        Node *list;
    public:
        linkedList();
        Node* getNewNode(int val);
        int IsLast(Node* list);
        void addNode(int val);
        void printList();
        void insertAtFirst(int val);
        void insertAtLast(int val);
        void insertAtPos(int val, int pos);
        void deleteNode(int val);
        void reverseIterative();
        void reverseRecursive();
        Node* recursiveReverse(Node* currNode);
        void middleNode_ArrayMethod();
        void middleNode_slowFastPtr();
        void getDecimalValue_ArrayMethod();
        void getDecimalValue_BinaryMethod();
        void delete_N_nodes_After_M_nodes(int n, int m);
};
int binaryToDecimal();
int middleOfList();
#endif