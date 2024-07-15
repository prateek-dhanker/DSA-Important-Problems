#include <iostream>
using namespace std;

class stack{
    private:
        int top , size;
        int* arr;
    public:
        stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1; 
        }
        bool isEmpty(){
            if(this->top == -1)
                return true;
            return false;
        }
        bool isFull(){
            if(this->top == size-1)
                return true;
            return false;
        }
        void push(int data){
            if(isFull())
                cout<<"Stack underflow";
            else{
                top++;
                arr[top] = data;
            }
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack overflow";
                return -1;
            }
            else{
                int var = arr[top];
                top--;
                return var;
            }
        }
        int peek(){
            if(!isEmpty())
                return arr[top];
            return -1;
        }
};
class doubleStack{
    private:
        int top1 , top2 , size;
        int* arr;
    public:
        doubleStack(int size){
            this->size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size-1; 
        }
        bool isEmpty(){
            if(top1 == -1 && top2 == size-1)
                return true;
            return false;
        }
        bool isFull(){
            if(top1+1 == top2)
                return true;
            return false;
        }
        void push1(int data){
            if(isFull())
                cout<<"Stack underflow";
            else{
                top1++;
                arr[top1] = data;
            }
        }
        void push2(int data){
            if(isFull())
                cout<<"Stack underflow";
            else{
                top2--;
                arr[top2] = data;
            }
        }
        int pop1(){
            if(isEmpty()){
                cout<<"Stack overflow";
                return -1;
            }
            else{
                int var = arr[top1];
                top1--;
                return var;
            }
        }
        int pop2(){
            if(isEmpty()){
                cout<<"Stack overflow";
                return -1;
            }
            else{
                int var = arr[top2];
                top2++;
                return var;
            }
        }
        int peek1(){
            if(!isEmpty())
                return arr[top1];
            return -1;
        }
        int peek2(){
            if(!isEmpty())
                return arr[top2];
            return -1;
        }
};

int main()
{
    doubleStack* st = new doubleStack(5);
    st->push1(5);
    st->push2(4);
    st->push1(3);

    cout<<st->peek2();
    cout<<st->pop1();
    cout<<st->peek1();

    return 0;
}