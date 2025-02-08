int countSetBits(int n)
    {
        // Your logic here
        int cnt = 0;
        
        while(n){
            cnt += n&1;
            n = n>>1;
        }
        return cnt;
    }

    int countSetBits(int n)
    {
        // Your logic here
        int cnt = 0;
        
        while(n&(n-1)){
            cnt ++;
            n &= n-1;
        }
        return cnt;
    }