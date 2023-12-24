#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

//Depth-first search (visited)
class Graph
{
    private: 
        int V;
        list<int> *hashlist;
    public:
        Graph(int val)
        {
            this->V = val;
            hashlist = new list<int>[V];
        }
        void addEdge(int v1, int v2)
        {
            hashlist[v1].push_back(v2);
        }

        void topologicalSort_DFS()
        {
            cout<<"topologicalSort_DFS: ";
            stack<int> Stack;
            bool *visited = new bool[this->V];
            for( int i=0; i<this->V; i++)
            {
                visited[i] = false;
            }

            for(int i=0; i<this->V; i++)
            {
                if((visited[i]==false))
                {
                    topologicalSortUtil_DFS(i, visited, Stack);
                }
            }

            while(Stack.empty()==false)
            {
                cout<<Stack.top()<< " ";
                Stack.pop();
            }
            cout<<endl;
        }

        void topologicalSortUtil_DFS(int index, bool visited[], stack<int>& Stack)
        {
            visited[index] = true;

            for(list<int>::iterator it = hashlist[index].begin();
                    it != hashlist[index].end(); it++)
            {
                if(visited[*it]==false)
                {
                    topologicalSortUtil_DFS(*it, visited, Stack);
                }
            }
            Stack.push(index);
        }

        void topologicalSort_kahn()
        {
            cout<<"topologicalSort_kahn: ";
            vector<int> indegree(V,0);
            for(int i=0; i<indegree.size(); i++)
            {
                list<int>::iterator it;
                for(it=hashlist[i].begin(); it!=hashlist[i].end(); it++)
                {
                    indegree[*it]++;
                }
            }
            
            queue<int> q;
            for(int i=0; i<indegree.size(); i++)
            {
                if(indegree[i]==0)
                q.push(i);
            }
            
            queue<int> toporder;
            int visitedcnt =0;
            while(!q.empty())
            {
                int val = q.front();
                q.pop();
                toporder.push(val);

                list<int>::iterator it;
                for(it=hashlist[val].begin(); it!=hashlist[val].end(); it++)
                {
                    indegree[*it]--;
                    if(indegree[*it]==0)
                    q.push(*it);
                }
                visitedcnt++;
            }

            if(visitedcnt!=V)
            {
                cout<<"graph  has cycle:"<< visitedcnt<<" " <<V<<endl;
            }
            else
            {
                while(toporder.empty()==false)
                {
                    cout<<toporder.front()<<" ";
                    toporder.pop();
                }
            }
            
        }

        void print()
        {
            for(int i=0; i<this->V; i++)
            {
                cout<<i<< " ";
                for(list<int>::iterator it =hashlist[i].begin(); it!= hashlist[i].end(); it++ )
                {
                    cout<<*it<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.print();
    g.topologicalSort_DFS();
    g.topologicalSort_kahn();
}