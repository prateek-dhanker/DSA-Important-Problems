void merge(long long arr[] , int p , int q , int r ,long long int &ans){
        int l1 = q-p+1 , l2 = r-q;
        
        vector<long long> left(l1);
        int k=0;
        for(int i=p;i<=q;i++)
            left[k++] = arr[i];
        
        vector<long long> right(l2);
        k=0;
        for(int i=q+1;i<=r;i++)
            right[k++] = arr[i];
            
        int i = 0 , j=0;
        k=p;
        while(i<l1 && j<l2){
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else{
                ans += l1-i;
                arr[k++] = right[j++];
            }
        }
        while(i<l1)
            arr[k++] = left[i++];
        while(j<l2)
            arr[k++] = right[j++];
    }
    void mergeSort(long long arr[] , int p ,int r ,long long int & ans){
        if(p>=r)
            return;
        
        int q = (p+r)/2;
        mergeSort(arr, p ,q ,ans);
        mergeSort(arr , q+1,r,ans);
        merge(arr , p,q , r ,ans);
    }
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        long long int ans = 0;
        mergeSort(arr ,0, n-1 , ans);
        return ans;
    }