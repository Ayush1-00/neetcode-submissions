class Solution {
    vector<int> findLeft(vector<int>arr){
        int n=arr.size();
        vector<int>left(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty())left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> findRight(vector<int>arr){
        int n=arr.size();
        vector<int>left(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty())left[i]=st.top();
            st.push(i);
        }
        return left;
    }

public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>preMax(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            preMax[i]=maxi;
        }
        maxi=0;
        vector<int>nextMax(n);
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            nextMax[i]=maxi;
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=min(preMax[i],nextMax[i])-arr[i];
        }
        return total;
    }
};
