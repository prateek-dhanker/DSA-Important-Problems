// for both sorted and unsorted list 
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
Node* deleteDuplicatesSorted(Node* head) {
        if(head == NULL)
            return NULL;

        Node* temp = head ;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->data == temp->data){
                Node * deli = temp->next;
                temp->next = temp->next->next;
                delete deli;
            }
            else
                temp = temp->next;
        }
        return head;
}
//Unsorted 
// 1.2loops - O(n^2)
// 2.sort and then apply above fn for sorted lists - O(nlogn)
// 3. map approach O(n)
void deleteDuplicatesUnsorted2Loops(Node *& head){
    Node * current = head;
    while(current!=NULL){
        Node * temp = current->next , *prev =current;
        while(temp!=NULL){
            if(temp->data == current->data){
                prev->next = temp->next;
                Node * deli = temp;
                delete deli;
                temp = prev->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
void deleteDuplicatesUnsortedMapApproach(Node * head){
    map<int , bool>visited;
    Node * temp = head , *prev=NULL;
    while(temp!=NULL){
        if(visited[temp->data]){
            prev->next = temp->next;
            Node * deli = temp;
            delete deli;
            temp = prev->next;
        }
        else{
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }

    }
}

int main()
{
    Node * n5 = new Node(2);
    Node * n4 = new Node(4,n5);
    Node * n3 = new Node(2,n4);
    Node * n2 = new Node(2,n3);
    Node * n1 = new Node(1,n2);
    Node * head = n1;
    printList(head);
    // deleteDuplicatesUnsorted2Loops(head);
    deleteDuplicatesUnsortedMapApproach(head);
    printList(head);

    return 0;
}