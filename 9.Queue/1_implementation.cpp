#include <iostream>
#include <queue>
using namespace std;

//Linear Queue
class Queue{
    public:
    int front , rear,size;
    int * arr;

    Queue(int size){
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }
    bool isEmpty(){
        if(rear == front)
            return true;
        return false;
    }
    bool isFull(){
        if(rear == size-1)
            return true;
        return false;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Beep";
            return;
        }
        rear++;
        arr[rear] = x;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Beep";
            return;
        }
        front++;
        if(rear == front){
            rear = front = -1;
        }
    }
};
class CircularQueue{
    public:
    int front , rear,size;
    int * arr;
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        front = -1;
        rear = -1;
        size = n;
        arr = new int[size];
    }
    bool isEmpty(){
        if(rear == -1 && front ==-1)
            return true;
        return false;
    }
    bool isFull(){
        if(rear == front&& rear !=-1)
            return true;
        return false;
    }
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(isFull()){
            return false;
        }
        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        front = (front+1)%size;
        int val = arr[front];
        if(front == rear){
            front = -1;rear =-1;
        }
        return val;
    }
};

int main()
{
    //stl
    queue<int> q;
    q.push(5);
    cout<<q.front()<<q.back();
    q.pop();
    
    
    // CircularQueue *q = new CircularQueue(2);
    // q->enqueue(1);
    // q->dequeue();
    // q->enqueue(1);
    // q->dequeue();
    // q->dequeue();

    // if(q->isEmpty())
    //     cout<<"Empty"<<endl;
    // else
    //     cout<<"Front : "<<q->arr[q->front+1]<<" Rear : "<<q->arr[q->rear]<<endl;

    return 0;
}