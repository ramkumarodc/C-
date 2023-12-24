#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void helper(vector<vector<int>> &graph, vector<int> &res,vector<int> &visited, vector<int> indegree)
{
    int n = graph.size();
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        if(indegree[i]==0 && visited[i]==false)
        {
            res.push_back(i);
            visited[i]= true;
            for(auto v : graph[i])
            {
                indegree[v]--;
            }
            helper(graph, res, visited, indegree);

            res.pop_back();
            visited[i] = false;
            for(auto v : graph[i])
            {
                indegree[v]++;
            }

            flag = true;
        }
    }
    if(flag == false)
    {
        for(int v: res)
        cout<<v<<" ";
        cout<<endl;
    }
}
void alltopologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> indegree(n,0);
    for(int i=0; i<graph.size(); i++)
    {
        for(auto j : graph[i])
        {
            indegree[j]++;
        }
    }
    vector<int> res;
    helper(graph, res, visited, indegree);
}

int main()
{
    vector<vector<int>> graph(6);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    alltopologicalSort(graph);
}