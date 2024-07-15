class node {
    public : 
    int data;
    int row;
    int col;
    
    node(int a , int b , int c){
        data = a; row = b ; col = c;
    }
};
class compare{
    public:
    bool operator()(node *a , node * b){
        return a->data > b->data;
    }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        priority_queue<node * , vector<node * > , compare> minh;
        int mini = INT_MAX , maxi = INT_MIN ;
        for(int i=0 ; i< k ; i++){
            maxi = max(maxi , KSortedArray[i][0]);
            mini = min(mini , KSortedArray[i][0]);
            
            minh.push(new node(KSortedArray[i][0] , i , 0));
        }
        int start = mini , end = maxi;
        
        while(minh.size() > 0){
            node * top = minh.top();
            minh.pop();
            mini = top->data;
            
            if(maxi - mini < end - start){
                end = maxi;
                start = mini;
            }
            
            if(top->col + 1 <n){
                maxi = max(maxi , KSortedArray[top->row][top->col+1]);
                minh.push(new node(KSortedArray[top->row][top->col+1] , top->row , top->col +1));
            }
            else
                break;
        }
        return {start , end};
    }
};