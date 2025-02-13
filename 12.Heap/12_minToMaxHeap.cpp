void maxHeapify(vector<int>& arr,int n,int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    int largest = i;
    
    if(left<n && arr[left]>arr[i])
        largest = left;
        
    if(right<n && arr[right]>arr[largest])
        largest = right;
    
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}
void convertMinToMaxHeap(vector<int> &arr, int N){
    for(int i=N/2;i>=0;i--){
        maxHeapify(arr,N,i);
    }
}