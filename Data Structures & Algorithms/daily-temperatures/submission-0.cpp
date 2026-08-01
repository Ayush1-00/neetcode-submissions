class Solution {
    vector<int> nextGreaterElement(vector<int>arr){
        int len=arr.size();
        vector<int>ans(len,-1);
        stack<int>st;
        for(int i=len-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>right;
        right=nextGreaterElement(temperatures);
        int len=temperatures.size();
        vector<int>ans(len,0);
        for(int i=0;i<len;i++){
            if(right[i]!=-1)ans[i]=right[i]-i;
        }
        return ans;
    }
};
