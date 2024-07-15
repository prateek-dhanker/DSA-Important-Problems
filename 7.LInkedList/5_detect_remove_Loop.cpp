/*
1.detect loop
2.find node at starting of loop
3.remove loop
*/
#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        Node(int data , Node*next){
            this->data = data;
            this->next = next;
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
bool detectList(Node *head){
    map<Node* , bool> visited;
    Node * temp = head;
    while(temp!=NULL){
        if(visited[temp] == true)
            return 1;
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}
Node * floydsCycleDetec(Node* head){
    if(head == NULL)
        return NULL;
    Node *fast = head ,*slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        slow = slow->next;
        if(fast == slow)
            return fast;
    }
    return NULL;
}
Node* startingOfLoop(Node* head){
    Node *fast = floydsCycleDetec(head);
    Node* slow = head;
    if(slow == NULL || fast == NULL)
        return NULL;
    while(slow!=fast){
        slow = slow->next;
        fast =fast->next;
    }
    return fast;
}
void removeLoop(Node * head){
    if(head == NULL)
        return;
    Node * start = startingOfLoop(head);
    Node * temp = start;
    while(temp->next != start)
        temp = temp->next;
    temp->next = NULL;

}

int main()
{
    Node* head = NULL;
    Node * n1 = new Node(1);
    Node * n2 = new Node(2,n1);
    Node * n3 = new Node(3,n2);
    Node * n4 = new Node(4,n3);
    Node* n5 = new Node(5,n4);
    head = n5;
    n1->next = n3;
    removeLoop(head);
    printList(head);
    cout<<detectList(head);

    floydsCycleDetec(head) ? cout<<"1" : cout<<"0";

    startingOfLoop(head)?cout<<startingOfLoop(head)->data : cout<<"dharr";
    return 0;
}