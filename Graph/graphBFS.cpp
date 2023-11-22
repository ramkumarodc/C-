/* Breadth First Search in Graph*/
#include<iostream>
#include<list>
#include<queue>

using namespace std;

void BFS(list<int> *adj, int cnt, int src)
{
    bool visited[cnt] = {0};
    queue<int> q;
    q.push(src);

    while(q.empty() == false)
    {
        int u = q.front();
        visited[u] = true;
        q.pop();

        cout<<u<<' ';

        for(auto it= adj[u].begin(); it!=adj[u].end(); it++)
        {
            int val = *it;
            if(visited[*it]==false)
            {
                //visited[*it] = true;
                q.push(*it);
            }
        }
    }
    cout<<endl;
}

int main()
{
    int vertexCnt = 4;
    list<int>* adj = new list<int>[vertexCnt];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    BFS(adj, vertexCnt, 2);

    return 0;
}