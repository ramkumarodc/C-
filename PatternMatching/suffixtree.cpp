#include<iostream>
#include<cstring>
using namespace std;

#define MAX_CHAR  256

struct   SuffixTreeNode
{
    SuffixTreeNode* children[MAX_CHAR];
    SuffixTreeNode* suffixLink;
    int start;
    int *end;
    int suffixIndex;
};


char text[100] = {};
SuffixTreeNode *root;
int size1 = -1;
int count =0;
int *rootend =nullptr;

SuffixTreeNode* newNode(int start, int *end)
{
    count++;
    SuffixTreeNode* node = new SuffixTreeNode;
    for(int i=0; i<MAX_CHAR; i++)
    {
        node->children[i]= nullptr;
    }
    node->start = start;
    node->end = end;
    node->suffixLink = root;
    node->suffixIndex = -1;
    return node;
}

int leafEnd = -1;
int remainingSuffixCount = 0;
SuffixTreeNode* lastnewnode = nullptr;
SuffixTreeNode* activeNode = nullptr;
int activeEdge = -1;
int activeLength = 0;

int edgeLength(SuffixTreeNode* node)
{
    return *(node->end) - (node->start) +1;
}
bool walkDown(SuffixTreeNode* node)
{
    if(activeLength >= edgeLength(node))
    {
        activeEdge = (int)text[activeEdge+edgeLength(node)] -(int)' ';
        activeLength -=edgeLength(node);
        activeNode = node;
        return true;
    }
    return false;
}

void extendSuffixTree(int pos)
{
    leafEnd = pos;
    remainingSuffixCount++;
    lastnewnode = nullptr;

    while(remainingSuffixCount>0)
    {
        if(activeLength ==0)
        {
            activeEdge = (int)text[pos] - (int)' ';
        }

        if(activeNode->children[activeEdge]==nullptr)
        {
            activeNode->children[activeEdge] = newNode(pos, &leafEnd);

            if(lastnewnode!= nullptr)
            {
                lastnewnode->suffixLink = activeNode;
                lastnewnode = nullptr;
            }
        }
        else
        {
            SuffixTreeNode* next = activeNode->children[activeEdge];
            if(walkDown(next))
            {
                continue;
            }
        }

    }
}

void buildSuffixTree()
{
    rootend = new int;
    *rootend = -1;

    root = newNode(-1, rootend);
    activeNode = root;

    for(int i =0;i<strlen(text); i++)
    {
        extendSuffixTree(i);
    }
}

int main()
{
    strcpy(text, "abbc");
    buildSuffixTree();
    return 0;
}