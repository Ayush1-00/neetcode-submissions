class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int x=i;
            int y=i;
            while(x>=0&&y<n&&s[x]==s[y]){
                if(maxi<=y-x+1){
                    maxi=y-x+1;
                    ans=s.substr(x,maxi);
                }
                x--;
                y++;
            }
            
            x=i;
            y=i+1;
            while(x>=0&&y<n&&s[x]==s[y]){
                if(maxi<=y-x+1){
                    maxi=y-x+1;
                    ans=s.substr(x,maxi);
                }
                x--;
                y++;
            }
        }
        return ans;
    }
};
