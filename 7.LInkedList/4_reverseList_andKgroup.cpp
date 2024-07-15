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
    while(temp->next != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
    
}

void printList(Node * &head){
    if(head == NULL){
        cout<<"Empty List";
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\tLength : "<<listLength(head);
    cout<<endl;   
}
void insertAtHead(Node * &head , int data){
    Node* newNode = new Node(data);
    if(head == NULL)
        head = newNode;
    else{
        newNode->next = head;
        head = newNode;
    }

}

Node* reverseList(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node *current = head , *prev = NULL ,*next =NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node* reverseKGroup(Node* head, int k) {
    if(head == NULL || head->next == NULL)
        return head;
    Node * current = head , *prev = NULL , *next =NULL;
    int cnt = 0 , len = 0;
    while(current!=NULL){
        len++; current = current->next;
    }
    current = head;
    if(len < k)
        return head;
    while(cnt<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }
    head->next = reverseKGroup(next , k);
    return prev;
}

int main()
{
    Node* head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    printList(head);
    head = reverseList(head);
    printList(head);

    return 0;
}