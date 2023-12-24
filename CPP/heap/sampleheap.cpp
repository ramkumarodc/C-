#include<iostream>
#include<vector>
using namespace std;

class Heap
{
    int heapcapacity;
    int heapsize;
    vector<int> arr;
    public:
    Heap(int n)
    {
        heapcapacity = n;
        heapsize =0;
        arr.resize(heapcapacity);
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

    void insertKey(int val)
    {
        if(heapsize<heapcapacity)
        {
            arr[heapsize] = val;
            heapsize++;
            perculate_up(heapsize-1);
        }
    }

    void perculate_up(int i)
    {
        while(i>0 && arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void perculate_Down(int i)
    {
        int l= left(i);
        int r = right(i);
        int maximum = i;
        if(l<heapsize && arr[l]>arr[maximum])
        {
            arr[maximum] = arr[l];
        }
        if(r<heapsize && arr[r]> arr[maximum])
        {
            arr[maximum] = arr[r];
        }
        if(i !=maximum)
        {
            swap(arr[i], arr[maximum]);
            perculate_Down(maximum);
        }
    }

    int extractMax()
    {
        int ret =-1;
        if(heapsize>0)
        {
            ret = arr[0];
            arr[0] = arr[heapsize-1];
            heapsize--;
            perculate_Down(0);

        }
        return ret;
    }

    void printheap()
    {
        for(int i=0; i<heapsize; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Heap heap(15);
    heap.insertKey(12);
    heap.insertKey(3);
    heap.insertKey(10);
    heap.insertKey(8);
    heap.insertKey(2);
    heap.insertKey(14);
    heap.printheap();
    heap.extractMax();
    heap.printheap();
    return 0;
}