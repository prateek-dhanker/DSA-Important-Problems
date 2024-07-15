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
void insertAtEnd(Node * &head , int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node * temp = head;
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}
void insertAtPos(Node * &head , int pos , int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    if(pos == 1){
        insertAtHead(head , data);
        return;
    }
    Node * current = head ;
    int cnt = 1;
    while(cnt < pos-1){
        current = current->next;
        cnt++;
    }
    newNode->next = current->next;
    current->next = newNode;
    
}
void deleteAtPos(Node * &head , int pos){
    if(pos == 1){
        Node * current = head;
        head = head->next;
        delete current;
        return;
    }
    Node * current = head , *prev = NULL;
    int cnt = 1;
    while(cnt<pos){
        prev = current;
        current = current->next;
        cnt++;
    }
    prev->next = current->next;
    delete current;
}
void deleteElem(Node *&head , int key){
    if(head->data == key){
        Node * current = head;
        head = head->next;
        delete current;
        return;
    }
    Node * current = head , *prev = NULL;
    while(current!=NULL && current->data != key){
        prev = current;
        current = current->next;
    }
    if(current==NULL){
        cout<<"NO such element exist ("<<key<<")."<<endl;
        return;
    }
    prev->next = current->next;
    delete current;
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head , 10);
    printList(head);
    insertAtEnd(head , 20);
    printList(head);
    insertAtEnd(head , 30);
    printList(head);
    insertAtPos(head , 4 , 40);
    printList(head);
    deleteElem(head , 410);
    printList(head);

    return 0;
}