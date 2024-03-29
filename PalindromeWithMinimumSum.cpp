//https://practice.geeksforgeeks.org/problems/32dc957908c2eb8beeeaeedf81f37df20d37c308/1
 int low = 0, high = s.size()-1;
        int sum = 0;
        while(low<high){
            if(s[low]!=s[high]){
                if(s[low]=='?'){
                    s[low]=s[high];
                }
                else if(s[high]=='?'){
                    s[high]=s[low];
                }
                else return -1;
            }
            low++, high--;
        }
        
        char x = '?';
        int n = s.size();
        for(int i = 0; i < n; i++){
           if(s[i]!='?'){
               if(x=='?'){
                   x=s[i];
               }
               else{
                   sum += abs(int(s[i]-x));
                   x=s[i];
               }
           } 
        }
        return sum;
