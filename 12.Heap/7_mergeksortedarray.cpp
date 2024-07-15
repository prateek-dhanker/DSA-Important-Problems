class node{
    public:
        int data ;
        int arrno;
        int index;
        
        node(int a , int b , int c){
            this->data = a;
            this->arrno = b;
            this->index = c;
        }
};
class compare{
    public:
        bool operator()(node * a , node* b){
            return a->data > b->data;
        }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue <node * , vector<node *> , compare > minheap;
        
        for(int i=0 ; i<K ; i++){
            node * temp = new node(arr[i][0] , i, 0);
            minheap.push(temp);
        }
        vector<int> ans;
        while(!minheap.empty()){
            node * top = minheap.top();
            ans.push_back(top->data);
            minheap.pop();
            if(top->index + 1 < arr[top->arrno].size()){
                node * tmp = new node(arr[top->arrno][top->index+1] , top->arrno , top->index+1);
                minheap.push(tmp);
            }
        }
        return ans;
    }
};