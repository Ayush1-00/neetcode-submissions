class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        while(j<s.length()&&i<s.length()){
            while(j<s.length()&&m.find(s[j])==m.end()){
                m[s[j]]=j;
                j++;
            }
            if(j==s.length()){
                int dis=j-i;
                len=max(len,dis);
                return len;
            }
            else {
                int dis=j-i;
                len=max(len,dis);
                int targetIndex = m[s[j]];
                while(i<=targetIndex){
                    m.erase(s[i++]);
                }

            }
        }
        return len;
    }
};
