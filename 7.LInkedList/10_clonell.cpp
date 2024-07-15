private:
    void insertAtTail(Node * &head , Node * &tail , int data){
        Node * newNode = new Node(data);
        if(head == NULL)
            tail = head = newNode;
            
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        if(head==NULL)
            return head;
        Node * temp = head , *clonehead = NULL ,*clonetail = NULL;
        
        while(temp){
            insertAtTail(clonehead , clonetail , temp->data);
            temp = temp->next;
        }
        temp = head;
        Node *clonetemp = clonehead;
        
        // map<Node* , Node*>match;
        // while(temp){
        //     match[temp] = clonetemp;
        //     temp = temp->next;
        //     clonetemp = clonetemp ->next;
        // }
        
        // temp = head;
        // clonetemp = clonehead;
        // while(temp){
        //     clonetemp->arb = match[temp->arb];
        //     temp = temp->next;
        //     clonetemp = clonetemp ->next;
        // }
        
        while(temp){
            Node*next = temp->next;
            temp->next = clonetemp;
            temp = next;
            Node* clonenext = clonetemp->next;
            clonetemp->next = temp;
            clonetemp = clonenext;
        }
        clonehead = head->next;
        clonetemp = clonehead;
        temp = head;
        while(temp && temp->next){
            if(temp->arb)
                temp->next->arb = temp->arb->next;
            temp = temp->next->next;
        }
        temp = head;
        while (temp)
        {
            temp->next = temp->next->next;
            temp = temp->next;
            if (clonetemp->next)
            {
                clonetemp->next = clonetemp->next->next;
                clonetemp = clonetemp->next;
            }
        }
        return clonehead;
        
    }