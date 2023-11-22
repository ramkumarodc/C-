#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class Heap
{
    vector<int> arr;
    int pos;
    int capacity;

    public:
        Heap(int max)
        {
            capacity = max;
            arr.resize(capacity);
            pos =0;

        }

        int left(int idx)
        {
            return  2*idx+1;
        }

        int right(int idx)
        {
            return 2*idx+2;
        }

        int parent(int idx)
        {
            return (idx-1)/2;
        }

        void insertKey(int val)
        {
            if(pos<capacity)
            {
                int i=pos;
                while(i>0 && arr[parent(i)]<val)
                {
                    arr[i] = arr[parent(i)];
                    i= parent(i);
                }
                arr[i] = val;
                pos++;
            }
        }

        int currSize()
        {
            return pos;
        }

        void deletemax()
        {
            if(pos>0)
            {
                int lastElement = arr[pos-1];

                int childidx,i;
                for( i=0; left(i)<pos; i=childidx)
                {
                    childidx = left(i);
                    //pos-1 is the last element in the array
                    if((childidx!=pos-1) && arr[right(i)]>arr[left(i)])
                    {
                        childidx = right(i);
                    }

                    if(lastElement<arr[childidx])
                    {
                        arr[i] = arr[childidx];
                    }
                    else
                    {
                        break;
                    }
                }
                arr[i]=lastElement;
                arr[pos-1] =0;
                pos--;
            }
        }

        int getMax()
        {
            return arr[0];
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

    cout<<"Current heap size:"<< heap.currSize()<<endl;
    cout<<"Maximum: "<<heap.getMax()<<endl;
    heap.deletemax();
    cout<<"Current heap size:"<< heap.currSize()<<endl;
    cout<<"Maximum: "<<heap.getMax()<<endl;
    return 0;
}