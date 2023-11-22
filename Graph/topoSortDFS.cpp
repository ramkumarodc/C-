/*topological sort using DFS*/
#include<iostream>
#include<list>
#include<stack>
using namespace std;

void DFSUtil(list<int>* adj, int cnt, bool* visited, stack<int>& op, int ver)
{
    visited[ver] = true;

    for(auto it = adj[ver].begin(); it!=adj[ver].end(); it++)
    {
        if(visited[*it] == false)
        {
            DFSUtil(adj, cnt, visited, op, *it);
        }
    }
    op.push(ver);

}
void topoSort(list<int>*adj, int cnt)
{
    bool visited[cnt] = {0};
    stack<int> op;

    for(int i =0; i<cnt; i++)
    {
        if(visited[i] == false)
        {
            DFSUtil(adj, cnt, visited, op,  i);
        }
    }
    
    while(op.empty()==false)
    {
        cout<<op.top()<<' ';
        op.pop();
    }
}

int main()
{
    int V = 6;
    list<int>*adj = new list<int>[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    topoSort(adj, V);

    return 0;
}