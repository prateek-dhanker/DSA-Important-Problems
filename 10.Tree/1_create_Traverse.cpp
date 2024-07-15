#include <iostream>
#include <queue>
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