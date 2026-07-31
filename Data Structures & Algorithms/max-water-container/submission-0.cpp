class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans= INT_MIN;
        int i=0;
        int j=heights.size()-1;
        while(i<j){
            int h1=heights[i];
            int h2=heights[j];
            int h=min(h1,h2);
            int b=j-i;
            ans=max(ans,h*b);
            if(h1>h2)j--;
            else i++;
        }
        return ans;
    }
};
