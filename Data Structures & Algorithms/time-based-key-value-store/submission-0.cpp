class TimeMap {
    unordered_map<string,vector<pair<int,string>>>m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end())return "";
        vector<pair<int,string>>temp=m[key];
        int ind=-1;
        int s=0;
        int e=temp.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(temp[mid].first==timestamp){
                ind=mid;
                break;
            }
            else if(temp[mid].first<timestamp){
                ind=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        return ind==-1?"":temp[ind].second;
    }
};
