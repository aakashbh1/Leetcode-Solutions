// Brute Force 
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), mini = 101;
        string ans = "{";
        for(int i = 0 ; i < n ; i++){
            string g = "";
            int cnt = 0;
            for(int j = i ; j < n ; j++){
                g += s[j];
                if(s[j] == '1')
                    cnt++;
                if(cnt == k){
                    if(g.size() <= mini){
                        mini = g.size();
                        if(g.size() == ans.size()){
                            if(g < ans)
                                ans = g;
                        }
                        else
                            ans = g;
                    }
                    break;
                }
            }
        }
        
        return ans == "{" ? "" : ans;
    }
};

//Optimised 
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0,j=0,count=0,n=s.size(),mini=INT_MAX;
        string minAns="";
        while(j<n){
            if(s[j]=='1')count++;
            while(s[i]=='0' || count>k){
                if(s[i]=='1')count--;
                i++;
            }
            if(count==k){                
                int m=j-i+1;
                string temp=s.substr(i,m);
                if(m<mini){
                    mini=m;
                    minAns=temp;
                }
                else{
                    if(mini==m){//if they are same length take lexicographically smaller one
                        if(minAns>temp){
                            minAns=temp;
                        }
                    }
                }
            }
            j++;
        }
        return minAns;
    }
};