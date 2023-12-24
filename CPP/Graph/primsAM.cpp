#include<iostream>
#include<vector>

using namespace std;

#define V 5

void printMST(int parent[V], int graph[V][V])
{
    cout<<"Edge \tWegith\n";
    for(int i=1; i<V; i++)
    {
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<endl;
    }
}
int getMin(int key[V], bool visited[V])
{
    int min = INT_MAX;
    int min_index =-1;

    for(int i=0; i<V; i++)
    {
        if(visited[i]==false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primsMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];

    for(int i=0; i<V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;


    for(int cnt=0; cnt<V-1; cnt++)
    {
        int u = getMin(key, visited);
        visited[u] = true;
        for(int v =0; v<V; v++)
        {
            if(graph[u][v] && visited[v]==false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(parent,graph);
}

int main()
{

    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primsMST(graph);
    return 0;
}