#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node * next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

int listLength(Node* &head){
    if(head == NULL)
        return 0;
    Node* temp = head;
    int cnt = 1;
    while(temp->next != head){
        cnt++;
        temp = temp->next;
    }
    return cnt;
    
}

void printList(Node * &head){
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<"\tLength : "<<listLength(head);
    cout<<endl;   
}
void insertAtEnd(Node * &head , int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    Node * temp = head;
    while(temp->next!=head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}
Node * splitList(Node * head){
    if(head == NULL || head->next == NULL)
        return NULL;
    int len = listLength(head);
    int firstHalfLen;
    if(len&1)
        firstHalfLen = len/2 + 1;
    else
        firstHalfLen = len/2;
    
    int cnt= 1;
    Node * temp =head;
    while(cnt < firstHalfLen){
        temp = temp->next;
        cnt++;
    }
    Node* nextHead = temp->next;
    temp->next = head;
    temp = nextHead;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = nextHead;
    return nextHead;
}
int main()
{
    Node *head= NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    printList(head);
    Node *nextHead = splitList(head);
    printList(head);
    printList(nextHead);


    return 0;
}