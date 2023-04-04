//https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
int AlternatingaMaxLength(vector<int>&a)
		{
		    int i=0,cnt=1,n=a.size();
		    while(i<n-1)
		    {
		        int j=i;
		        bool f=false;
		        while(i+1<n && a[i+1]>=a[i])
		        {
		            f=true;
		            i++;
		        }
		        
		        if(a[i]>a[j])
		        cnt++;

                j = i;
		        while(i+1<n && a[i+1]<=a[i])
		        {
		            f=true;
		            i++;
		        }
		        
		        if(a[i]<a[j])
		        cnt++;
		        
		        if(f==false)
		        i++;
		        
		    }
		    return cnt;
		}
