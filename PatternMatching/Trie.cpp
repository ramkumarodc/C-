/* Trie*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct TrieNode
{
    TrieNode* childnode[26];
    bool isEnd = false;
};


TrieNode* getNode()
{
    TrieNode* tmp = new TrieNode;
    for(int i=0; i<26; i++)
    {
        tmp->childnode[i] = nullptr;
    }
    return tmp;
}

void insertKey(TrieNode * node, string word)
{
    TrieNode* curr = node;
    for(int i=0; i<word.size(); i++)
    {
        int idx = word[i]-'a';
        if(curr->childnode[idx]==nullptr)
        {
            curr->childnode[idx] = getNode();
        }
        curr  =  curr->childnode[idx];
    }
    curr->isEnd = true;
}

bool search(TrieNode* node, string pattern)
{
    TrieNode* curr = node;
    for(int i=0; i<pattern.size(); i++)
    {
        int idx = pattern[i] -'a';
        if(curr->childnode[idx] == nullptr)
        {
            return false;
        }
        curr = curr->childnode[idx];
    }

    return true;
}

int main()
{
    TrieNode* root = getNode();
    vector<string> keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    
    for(int i=0; i<keys.size(); i++)
    {
        insertKey(root, keys[i]);
    }

    char output[][32] = {"Not Present in Trie.", " Presnt in Trie."};

    cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
    cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
    cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
    cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;
   cout<<"an"<<" --- "<<output[search(root, "an")]<<endl;
}