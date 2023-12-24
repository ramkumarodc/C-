#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> intpair;

void prims_pq(vector<vector<intpair>> &g)
{
    int n = g.size();
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<int> inMST(n,false);

    auto cmp = [](intpair a, intpair b)
    {
        return a.second > b.second;
    };
    priority_queue<intpair, vector<intpair>, decltype(cmp)> pq(cmp);

    parent[0] = 0;
    key[0] = 0;
    pq.push(make_pair(0,key[0]));

    while(!pq.empty())
    {
        intpair p = pq.top(); pq.pop();
        if(inMST[p.first])
        {
            continue;
        }
        else
        {
            inMST[p.first] = true;
        }

        for(int i=0; i<g[p.first].size(); i++)
        {
            int vertex = g[p.first][i].first;
            int val = g[p.first][i].second;
            if(inMST[vertex] == false)
            {
                if(val < key[vertex])
                {
                    key[vertex] = val;
                    pq.push(make_pair(vertex, key[vertex]));
                    parent[vertex] = p.first;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<parent[i]<<' '<<i<<' '<<key[i]<<endl;
    }
}

int main()
{
    vector<vector<intpair>> g(9);
    g[0].push_back({1,4});
    g[0].push_back({7,8});
    g[1].push_back({2,8});
    g[1].push_back({7,11});
    g[2].push_back({3,7});
    g[2].push_back({8,2});
    g[2].push_back({5,4});
    g[3].push_back({4,9});
    g[3].push_back({5,14});
    g[4].push_back({5,10});
    g[5].push_back({6,2});
    g[6].push_back({7,1});
    g[6].push_back({8,6});
    g[7].push_back({8,7});

    prims_pq(g);
    return 0;
}