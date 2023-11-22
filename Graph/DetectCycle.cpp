#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *hashlist;

    public:
        Graph(int ver)
        {
            this->V = ver;
            hashlist = new list<int>[V];
        }
    
        void addEdge(int v1, int v2)
        {
            hashlist[v1].push_back(v2);
        }

        bool isCyclic()
        {
            bool *visited = new bool[V];

            for(int i=0; i<V; i++)
            {
                visited[i]= false;
            }

            for(int i=0; i<V; i++)
            {
                if(visited[i]==false)
                {
                    return isCyclicUtil(i, visited);
                }
            }
            return false;
        }
        
        bool isCyclicUtil(int idx, bool visited[])
        {
            if(visited[idx] == false)
            {
                visited[idx] = true;

                list<int>::iterator it;
                for(it=hashlist[idx].begin(); it!=hashlist[idx].end(); it++)
                {
                    if(visited[*it] == false)
                    {
                        return isCyclicUtil(*it, visited);
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};


int main()
{
    cout<<"Detecting cycle in graph"<<endl;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    //g.addEdge(3, 3);

    if(g.isCyclic())
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph do not has cycle"<<endl;
    
}