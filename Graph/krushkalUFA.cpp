#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class DSU
{
    int* parent;
    int* rank;

    public:
        DSU(int n)
        {
            parent = new int[n];
            rank = new int[n];

            for(int i=0; i<n; i++)
            {
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        int find(int i)
        {
            if(parent[i]==-1)
            {
                return i;
            }

            parent[i] = find(parent[i]);

            return parent[i];
        }

        void Union(int u, int v)
        {
            int set1 = find(u);
            int set2 = find(v);

            if(set1!=set2)
            {
                if(rank[set1] < rank[set2])
                {
                    parent[set1] = set2;
                }
                else if(rank[set2] < rank[set1])
                {
                    parent[set2] = set1;
                }

                if(rank[set1] == rank[set2])
                {
                    parent[set2] = set1;
                    rank[set2]++;
                }
            }
        }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

    public:
        Graph(int nov)
        {
            this->V = nov;
        }

        void addEdge(int u, int  v, int w)
        {
            edgelist.push_back({w, u, v});
        }

        void krushkalMST()
        {
            sort(edgelist.begin(), edgelist.end());

            DSU s(V);
            int ans = 0;

            for(auto edge: edgelist)
            {
                int w = edge[0];
                int u = edge[1];
                int v = edge[2];

                if(s.find(u)!=s.find(v))
                {
                    s.Union(u, v);
                    ans += w;
                     cout << u << " -- " << v << " == " << w <<endl;
                }
            }
            cout<<" Minimum cost spaning tree:"<<ans<<endl;
        }
};
int main()
{
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.addEdge(2,0,6);
    g.addEdge(0,3,5);

    g.krushkalMST();
    return 0;
}