#include<iostream>
using namespace std;

struct AdjListNode
{
    int vertex;
    int cost;
    AdjListNode* next;
};

struct AdjList
{
    AdjListNode* head;
};

struct Graph
{
    int count;
    AdjList* array;
};

Graph* createGraph(int cnt)
{
    Graph *graph = new Graph;
    graph->count = cnt;
    graph->array  = new AdjList[cnt];
    for(int i=0; i<cnt; i++)
    {
        graph->array[i].head = nullptr;
    }
    return graph;
}

AdjListNode*  newAdjListNode(int vert, int cost)
{
    AdjListNode* adjlistnode = new AdjListNode;
    adjlistnode->cost = cost;
    adjlistnode->vertex = vert;
    adjlistnode->next = nullptr;
    return adjlistnode;
}

void addEdge(Graph* graph, int src, int dest, int cost)
{
    AdjListNode* adjlistnode = newAdjListNode(dest, cost);
    adjlistnode->next = graph->array[src].head;
    graph->array[src].head = adjlistnode;

    adjlistnode = newAdjListNode(src, cost);
    adjlistnode->next = graph->array[dest].head;
    graph->array[dest].head = adjlistnode;
}


struct MinHeapNode
{
    int key;
    int vertex;
};


struct MinHeap
{  
    int capacity;
    int size;
    int* pos;
    MinHeapNode** heaparray;

};

MinHeap* createHeap(int count)
{
    MinHeap* minheap= new MinHeap;
    minheap->capacity = count;
    minheap->size = 0;
    minheap->pos = new int[count];
    minheap->heaparray = new MinHeapNode*[count];
    return minheap;
}

MinHeapNode* newMinheapNode(int vertex, int cost)
{
    MinHeapNode* heapnode = new MinHeapNode;
    heapnode->key = cost;
    heapnode->vertex = vertex;
    return heapnode;
}

bool isEmpty(MinHeap* heap)
{
    bool ret = true;

    if(heap->size > 0)
        return false;

    return ret;
}

void swapHeapNodes(MinHeapNode** node1, MinHeapNode** node2)
{
    MinHeapNode* tmpnode = *node1;
    *node1 = *node2;
    *node2 = tmpnode;
}

void minHeapify(MinHeap* heap, int idx)
{
    int small = idx;
    int left = 2*idx+1;
    int right = left+1;

    if(left < heap->size && heap->heaparray[left]->key < heap->heaparray[small]->key)
    {
        small = left;
    }
    else if (right < heap->size && heap->heaparray[right]->key < heap->heaparray[small]->key)
    {
        small = right;
    }

    if(small != idx)
    {
        heap->pos[heap->heaparray[small]->vertex] = idx;
        heap->pos[heap->heaparray[idx]->vertex] = small;
        swapHeapNodes(&heap->heaparray[small], &heap->heaparray[idx]);
        minHeapify(heap, small);
    }
}
MinHeapNode* extractMin(MinHeap* heap)
{
    MinHeapNode* root = heap->heaparray[0];
    MinHeapNode* lastnode = heap->heaparray[heap->size-1];
    heap->heaparray[0] = lastnode;

    heap->pos[root->vertex] = heap->size-1;
    heap->pos[lastnode->vertex] = 0;

    --heap->size;

    minHeapify(heap, 0);

    return root;
}

bool isInMinHeap(MinHeap* heap, int V)
{
    bool ret = false;
    if( heap->pos[V] < heap->size)
    {
        ret = true;
    }
    return ret;
}

void decreaseKey(MinHeap* heap, int vertex, int cost)
{
    if(!isEmpty(heap))
    {
        int idx = heap->pos[vertex];
        heap->heaparray[idx]->key = cost;

        while(idx && heap->heaparray[idx]->key < heap->heaparray[(idx-1)/2]->key)
        {
            heap->pos[heap->heaparray[idx]->vertex] = (idx-1)/2;
            heap->pos[heap->heaparray[(idx-1)/2]->vertex] = idx;
            swapHeapNodes(&heap->heaparray[idx], &heap->heaparray[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }
}

void printMST(int parent[], int key[], int count)
{
    for(int i=1; i<count; i++)
    {
        cout<<parent[i]<<" - "<<i<<" - "<< key[i]<<endl;
    }
}
void PrimMST(Graph* graph)
{
    int count = graph->count;
    int parent[count];
    int key[count];

    MinHeap* heap =  createHeap(count);
    key[0] = 0;
    heap->heaparray[0] = newMinheapNode(0,key[0]);
    heap->pos[0] = 0;

    for(int i=1; i<count; i++)
    {
        parent[i] = -1;
        key[i]=INT_MAX;
        heap->heaparray[i] = newMinheapNode(i, key[i]);
        heap->pos[i] = i;
    }
    heap->size = count;

    while(!isEmpty(heap))
    {
        MinHeapNode* minnode = extractMin(heap);
        int u = minnode->vertex;
        AdjListNode* adjnode = graph->array[u].head;
        while(adjnode != nullptr)
        {
            if(isInMinHeap(heap, adjnode->vertex) && adjnode->cost < key[adjnode->vertex])
            {
                key[adjnode->vertex] = adjnode->cost;
                parent[adjnode->vertex] = u;
                decreaseKey(heap, adjnode->vertex, key[adjnode->vertex]);
            }
            adjnode = adjnode->next;
        }
    }
    printMST(parent, key, count);
}

int main()
{
    int V=9;
    Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    PrimMST(graph);
    return 0;
}