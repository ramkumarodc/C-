#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int,int> intpair;

class Heap
{
    public:
        int heapcapacity;
        int heapsize;
        vector<intpair> arr;
        vector<int> pos;

        Heap(int n)
        {
            heapcapacity = n;
            heapsize = 0;
            arr.resize(heapcapacity);
            pos.resize(heapcapacity);
        }

        bool isempty()
        {
            if(heapsize==0)
                return true;
            return false;
        }
        
        int left(int i)
        {
            return 2*i+1;
        }

        int right(int i)
        {
            return 2*i+2;
        }

        int parent(int i)
        {
            return (i-1)/2;
        }

        void swap(intpair &p1, intpair& p2)
        {
            intpair tm= p1;
            p1 = p2;
            p2= tm;
        }

        void perculate_up(int i)
        {
            while(i>0 && arr[i].second < arr[parent(i)].second)
            {
                swap(arr[i], arr[parent(i)]);
                pos[arr[i].first] = i;
                pos[arr[parent(i)].first] = parent(i);
                i = parent(i);
            }
        }

        void perculate_down(int i)
        {
            int l = left(i);
            int r = right(i);
            int small = i;

            if( l < heapsize && arr[l].second < arr[small].second )
            {
                small = l;
            }

            if(r<heapsize && arr[r].second < arr[small].second)
            {
                small = r;
            }
            if(i!=small)
            {
                swap(arr[i], arr[small]);
                pos[arr[i].first]= i;
                pos[arr[small].first] = small;
                perculate_down(small);
            }   
        }

        intpair extractMin()
        {
            intpair p1 = arr[0];
            arr[0] = arr[heapsize-1];
            heapsize--;
            pos[arr[0].first] = 0;
            perculate_down(0);
            return p1;
        }

        void decreaseKey(int i , int key)
        {
            int p = pos[i];
            arr[p].second = key;
            perculate_up(p);
        }
};
void prims_heap(vector<vector<intpair>> &g)
{
    int n = g.size();
    int parent[n];
    int key[n];

    Heap h(n);

    for(int i=1; i<n; i++)
    {
        parent[i] = -1;
        key[i] = INT_MAX;
        h.arr[i].first =i;
        h.arr[i].second = key[i];
        h.pos[i]=i;
    }

    key[0] = 0;
    parent[0] =0;
    h.arr[0] = make_pair(0,0);
    h.pos[0] = 0;
    h.heapsize = n;
    while(!h.isempty())
    {
        intpair p = h.extractMin();
        for(int i=0; i<g[p.first].size(); i++)
        {
            int ver = g[p.first][i].first;
            int val = g[p.first][i].second;
            if(val < key[ver])
            {
                key[ver] = val;
                parent[ver] = p.first;
                h.decreaseKey(ver, key[ver]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<parent[i] <<" "<<i <<" "<<key[i]<<endl;
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

    prims_heap(g);
    return 0;
}