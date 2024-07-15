#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class minheap{
    public:
        int heapsize;
        vector<int> v;
        minheap(){
            heapsize = 0;
            v.push_back(-1);
        }
        void heapifyDown(int i){
            int left = 2*i , right = 2*i+1 , smallest;

            if(left <= heapsize && v[left] < v[i])
                smallest = left;
            else 
                smallest = i;

            if(right <= heapsize && v[right] < v[smallest])
                smallest = right;

            if(smallest != i){
                swap(v[i] , v[smallest]);
                heapifyDown(smallest);
            }
        }
        void heapifyUp(int i){
            if(i <= 0)
                return ;
            int left = 2*i , right = 2*i+1 , smallest;

            if(left <= v.size() && v[left] < v[i])
                smallest = left;
            else 
                smallest = i;

            if(right <= v.size() && v[right] < v[smallest])
                smallest = right;

            if(smallest != i){
                swap(v[i] , v[smallest]);
                heapifyUp(i/2);
            }
        }
        void insertMinHeap(int k){
            v.push_back(k);
            heapsize++;
            heapifyUp(heapsize/2);
        }
        void deleteMinHeap(){
            swap(v[heapsize] , v[1]);
            heapsize--;
            heapifyDown(1);
        }
        void printHeap(){
            for(int i:v){
                cout <<i<<" ";
            }
            cout<<endl;
        }
}; 
//heapsort




// similarly for max heap



//stl
priority_queue<int> pq;
priority_queue<int , vector<int> , greater<int> > mh;

int main()
{
    minheap h;
    h.insertMinHeap(50);
    h.insertMinHeap(54);
    h.insertMinHeap(53);
    h.insertMinHeap(57);
    h.insertMinHeap(52);
    h.deleteMinHeap();
    h.printHeap();

    return 0;
}