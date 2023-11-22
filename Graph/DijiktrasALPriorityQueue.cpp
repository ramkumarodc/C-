#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

struct Graph 
{
    int cnt;
    list<pair<int,int>>* adj;

    public:

        Graph(int num)
        {
            cnt = num;
            adj = new list<pair<int,int>>[cnt];
        }

        void addEdge(int u, int v, int w)
        {
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        void shortestPath(int src)
        {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

            vector<int> dist(cnt, INT_MAX);
            q.push(make_pair(0, src));
            dist[src] = 0;


            while(!q.empty())
            {
                pair<int,int> ver = q.top();
                int u = ver.second;
                q.pop();
                
                list<pair<int,int>>::iterator it = adj[u].begin();
                for(; it!=adj[u].end(); it++)
                {
                    int v = it->first;
                    int weight = it->second;
                    if(dist[v]> (dist[u] + weight))
                    {
                        dist[v] = (dist[u] + weight);
                        q.push(make_pair(dist[v], v));
                    }
                }            
            }
            printf("Vertex Distance from Source\n");
            for(int i=0; i<cnt; i++)
            {
                cout<<i<<"\t"<<dist[i]<<endl;
            }
        }
};
/*
0 - (1,4) (7,8)
1 - (0,4) (2,8) (7,11)
2 - (1,8) (3,7) (8,2) (5,4)
3 - (2,7) (4,9) (5,14)
4 - (3,9) (5,10)
5 - (2,4) (3,14) (4,10) (6,2)
6 - (5,2) (7,1) (8,6)
7 - (0,8) (1,11) (6,1) (8,7)
8 - (2,2) (6,6) (7,7)
*/
int main()
{
    int vertex_cnt = 9;
    Graph g(vertex_cnt);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7); 
    
    g.shortestPath(0);
    return 0;
}