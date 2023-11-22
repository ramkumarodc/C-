#include<iostream>
#include<vector>
using namespace std;


void union1(vector<int> &parent, vector<int> &rnk, int src, int dest)
{
    if(rnk[src] > rnk[dest])
    {
        parent[dest] = src;
    }
    else if(rnk[src] <rnk[dest])
    {
        parent[src] = dest;
    }
    else
    {
        parent[src] = dest;
        rnk[src] +=1;
    }
}

int find (vector<int> &parent, int child)
{
    if(parent[child]== -1)
    {
        return child;
    }
    return  parent[child] = find(parent, parent[child]);
}

bool isCycle(vector<vector<int>> g)
{
    int n = g.size();
    vector<int> parent(n, -1);
    vector<int> rnk(n,1);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            int src = find(parent, i);
            int dest = find(parent, g[i][j]);

            if(src == dest)
                return true;
            
            union1(parent, rnk, src, dest);
        }
    }
    return false;
}

int main()
{
    /*
    0-1
    1-2
    2-3*/
    vector<vector<int>> graph(9);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[4].push_back(5);
    graph[5].push_back(6);
    graph[6].push_back(7);
    graph[7].push_back(8);
    cout<<isCycle(graph);
    return 0;
}