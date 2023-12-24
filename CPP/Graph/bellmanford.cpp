#include<iostream>
#include<list>
#include<vector>
using namespace std;

struct Edge
{
    int dest;
    int weight;
};

class Graph
{
    int V;
    list<Edge>* adj;

    public:
        Graph(int cnt)
        {
            this->V = cnt;
            adj = new list<Edge>[V];
        }

        void addEdge(int src, int vertex, int weight)
        {
            Edge obj;
            obj.dest = vertex;
            obj.weight  = weight;
            adj[src].push_back(obj);
        }

        void BellmanFord()
        {
            vector<int> dist(V, INT_MAX);

            dist[0]=0;
            
            for(int i=0; i<V; i++)
            {
                for(int i=0; i<V; i++)
                {
                    list<Edge>::iterator it = adj[i].begin();
                    for(it; it!=adj[i].end();it++)
                    {
                        if((dist[i]+it->weight) < dist[it->dest])
                        {
                            dist[it->dest] = dist[i]+it->weight;
                        }
                    }
                }
            }
            
            for(int i=0; i<V; i++)
            {
                list<Edge>::iterator it = adj[i].begin();
                for(it; it!=adj[i].end();it++)
                {
                    if((dist[i]+it->weight) < dist[it->dest])
                    {
                        cout<<"Graph contains negative cycle";
                    }
                }
            }

            for(int i=0; i<V; i++)
            {
                cout<<i<<"\t"<<dist[i]<<endl;
            }
        }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);

    g.BellmanFord();
    return 0;
}