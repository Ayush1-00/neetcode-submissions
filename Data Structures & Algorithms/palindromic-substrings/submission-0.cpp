class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int x=i;
            int y=i;
            while(x>=0&&y<n&&s[x]==s[y]){
                count++;
                x--;
                y++;
            }
            x=i;
            y=i+1;
            while(x>=0&&y<n&&s[x]==s[y]){
                count++;
                x--;
                y++;
            }
        }
        return count;
    }
};
