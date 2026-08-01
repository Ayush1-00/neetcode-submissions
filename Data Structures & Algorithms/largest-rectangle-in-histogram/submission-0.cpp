class Solution {
    vector<int> nextSmaller(vector<int>arr){
        int len=arr.size();
        vector<int>ans(len,arr.size());
        stack<int>st;
        for(int i=len-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> previousSmaller(vector<int>arr){
        int len=arr.size();
        vector<int>ans(len,-1);
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=previousSmaller(heights);
        vector<int>right=nextSmaller(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int h=heights[i];
            int b=right[i]-left[i]-1;
            int area=h*b;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};
