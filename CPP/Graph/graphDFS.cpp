#include<iostream>
#include<list>
#include<stack>
using namespace std;

// void DFS_recursive(list<int> *adj, bool *visited, int v, int src)
// {
    
//     visited[src] = true;

//     cout<<src<<" ";
//     list<int>::iterator it;
//     for(it=adj[src].begin(); it!=adj[src].end(); it++)
//     {
//         if(visited[*it]==false)
//         {
//              DFS_recursive(adj, visited,  v, *it);
//         }
//     }
// }

void DFS_Iterative(list<int> *adj, bool *visited, int v, int src)
{
    stack<int> s;
    s.push(src);
    while(s.empty()== false)
    {
        int val = s.top();
        s.pop();
       // if(visited[val] == false)
        {
            cout<<val<<" ";
            visited[val] = true;
        }
              
        for(auto it = adj[val].begin(); it!=adj[val].end(); it++)
        {
            if(visited[*it]==false)
            {
                s.push(*it);
            }
        }
    }
}

int main()
{
    int no_of_ver = 4;
    list<int> *adj = new list<int>[no_of_ver];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    bool visited[no_of_ver] = {};
    DFS_Iterative(adj, visited, no_of_ver, 2);

}