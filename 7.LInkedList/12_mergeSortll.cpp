node* findMid(node*head){
    node*fast = head->next;
    node*slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node* merge(node *left , node *right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    
    node* newListHead = new node(-1);
    node* temp = newListHead;

    while(left && right){
        if(left->data <= right->data){
            node* newNode = new node(left->data);
            temp->next = newNode;
            left = left->next;
            temp = newNode;
        }
        else{
            node* newNode = new node(right->data);
            temp->next = newNode;
            right = right->next;
            temp = newNode;
        }
    }
    while(left){
        node* newNode = new node(left->data);
        temp->next = newNode;
        left = left->next;
        temp = newNode;
    }
    while(right){
        node* newNode = new node(right->data);
        temp->next = newNode;
        right = right->next;
        temp = newNode;
    }
    return newListHead->next;

}

node* mergeSort(node *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL)
        return head;

    node *mid = findMid(head);
    node* mnext = mid->next;
    mid->next = NULL;

    node *left = mergeSort(head);
    node* right = mergeSort(mnext);

    node *ans = merge(left , right);
    return ans;

}
