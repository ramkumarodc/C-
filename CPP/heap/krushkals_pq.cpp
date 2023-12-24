#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
typedef pair<int,int> intpair;
typedef tuple<int,int,int> inttuple;

int find(vector<int> &parent, int i)
{
    if(parent[i] ==-1)
    {
        return i;
    }

    return find(parent, parent[i]);
}

void union1(vector<int> &parent, int src, int dest)
{
    parent[dest] = src;
}

void krushkal(vector<vector<intpair>> &g)
{
    int n = g.size();
    vector<vector<intpair>> parent(n);

    auto cmp = [](inttuple a, inttuple b)
    {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<inttuple, vector<inttuple>, decltype(cmp)> q(cmp);


    vector<int> dsuparent(n,-1);

    for(int i=0; i<g.size(); i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            q.push(make_tuple(g[i][j].second, i, g[i][j].first));
        }
    }
        
    while(!q.empty())
    {
        inttuple p = q.top(); q.pop();
        int dest = get<2>(p);
        int wt = get<0>(p);
        int src = get<1>(p);

        int x = find(dsuparent, src);
        int y = find(dsuparent, dest);
        if(x!=y)
        {
            union1(dsuparent, x, y);
            parent[dest].push_back(make_pair(src, wt));
        }
    }
    
    int total =0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<parent[i].size(); j++)
        {
            //if(parent[i] >=0)
            {
                cout<<parent[i][j].first<<' '<<i<<' '<<parent[i][j].second<<endl;
                total +=parent[i][j].second;
            }
        }
    }
    cout<<"Total:"<<total<<endl;
}
int main()
{
    vector<vector<intpair>> g(9);
    g[7].push_back(make_pair(6,1));
    g[8].push_back(make_pair(2,2));
    g[6].push_back(make_pair(5,2));
    g[0].push_back(make_pair(1,4));
    g[2].push_back(make_pair(5,4));
    g[8].push_back(make_pair(6,6));
    g[2].push_back(make_pair(3,7));
    g[7].push_back(make_pair(8,7));
    g[0].push_back(make_pair(7,8));
    g[1].push_back(make_pair(2,8));
    g[3].push_back(make_pair(4,9));
    g[5].push_back(make_pair(4,10));
    g[1].push_back(make_pair(7,11));
    g[3].push_back(make_pair(5,14));

    krushkal(g);

    return  0;
}