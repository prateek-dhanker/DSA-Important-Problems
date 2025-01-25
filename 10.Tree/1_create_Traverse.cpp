#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * left , *right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* createTree(Node * &root){
    int data;
    cout<<"Enter data for node : ";
    cin>>data;

    if(data == -1)
        return NULL;
    root = new Node(data);
    
    cout<<"Now enter for left of "<<data<<endl;
    createTree(root->left);
    
    cout<<"Now enter for right of "<<data<<endl;
    createTree(root->right);

    return root;
}

void preOrderTraversal(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(Node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(Node *root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
}
vector<int> IterpostorderTraversal(Node* root) {
    if(root == NULL)
        return {};
    vector<int> post;

    stack<Node *> st1,st2;

    st1.push(root);
    while(st1.size()){
        auto node = st1.top();
        st1.pop();

        st2.push(node);
        
        if(node->left)
            st1.push(node->left);

        if(node->right)
            st1.push(node->right);            
    }

    while(st2.size()){
        post.push_back(st2.top()->data);
        st2.pop();
    }

    return post;
}

//all in one
void allOrder(Node* node) {
    // code here
    vector<int> pre,post,in;
    
    stack<pair<Node*,int>> st;
    st.push({node,1});
    
    while(st.size()){
        auto curr = st.top().first ;int num = st.top().second;
        st.pop();
        
        if(num==1){
            st.push({curr,2});
            pre.push_back(curr->data);
            
            if(curr->left)
                st.push({curr->left,1});
        }
        else if(num == 2){
            st.push({curr,3});
            in.push_back(curr->data);
            
            if(curr->right)
                st.push({curr->right,1});
        }
        else
            post.push_back(curr->data);
    }
}

void levelOrderTraversal(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{

        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
            
        if(temp->right)
            q.push(temp->right);
        }
    }

}
// 5 3 1 -1 -1 4 -1 -1 6 -1 7 -1 -1
int main()
{
    Node * root = NULL;
    root = createTree(root);
    
    cout<<"Level order traversal : ";
    levelOrderTraversal(root);

    cout<<"Pre order traversal : ";
    preOrderTraversal(root);
    
    cout<<"Post order traversal : ";
    postOrderTraversal(root);
    
    cout<<"In order traversal : ";
    inOrderTraversal(root);



    return 0;
}