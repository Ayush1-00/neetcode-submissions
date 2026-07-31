class Solution {
public:
    bool isPalindrome(string s) {
        int x=0;
        int y=0;
        while(y<s.length()){
            if(s[y]<='Z'&&s[y]>='A'){
                char ch='a'+(s[y++]-'A');
                s[x++]=ch;
            }
            else if((s[y]>='a'&&s[y]<='z')||(s[y]>='0'&&s[y]<='9'))s[x++]=s[y++];
            else y++;
        }
        int i=0;
        int j=x-1;
        while(i<j&&i!=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
};
