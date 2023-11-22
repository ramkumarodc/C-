/*Topological sort using kahns algorithm - BFS - indegree*/
#include<iostream>
#include<list>
#include<queue>
using namespace std;

void toposort(list<int>* adj, int cnt)
{
    int indegere[cnt] = {};
    
    for(int i=0; i<cnt; i++)
    {
        for(auto it = adj[i].begin(); it!=adj[i].end(); it++)
        {
            indegere[*it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<cnt; i++)
    {
        if(indegere[i]==0)
        {
            q.push(i);
        }
    }

    queue<int> opq;
    while(q.empty()==false)
    {
        int u = q.front();
        opq.push(u);
        q.pop();

        for(auto it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(--indegere[*it] == 0)
            {
                q.push(*it);
            }
        }
    }

    while(opq.empty() == false)
    {
        cout<<opq.front()<<' ';
        opq.pop();
    }
}

int main()
{
    int V = 6;
    list<int>* adj = new list<int>[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    toposort(adj,V);
    return 0;
}