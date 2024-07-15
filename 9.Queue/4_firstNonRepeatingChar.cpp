string FirstNonRepeating(string A){
		    // Code here
		    vector<int>count(26,0);
		    queue<char> q;
		    
		    string ans;
		    
		    for(int i=0;i<A.length();i++){
		        int ind = A[i]-'a';
	            count[ind]++;
		        if(count[ind] == 1){
		            q.push(A[i]);
		        }
		        
                while(!q.empty()){
                    if(count[int(q.front()-'a')] == 1){
                        ans.push_back(q.front());
                        break;
                    }
                    else{
                        q.pop();
                    }
                }
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		    
		}