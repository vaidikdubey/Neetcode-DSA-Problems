class TimeMap {
    unordered_map<string, vector<pair<int, string>>> keyMap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyMap[key].emplace_back(timestamp, value); //O(1)
    }
    
    string get(string key, int timestamp) {
        auto &values = keyMap[key];
        int lo = 0, hi = values.size() - 1;
        string res = "";

        //Binary search for most recent timestamp -> O(log n)
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            //Possible latest timestamp
            if(values[mid].first <= timestamp) {
                res = values[mid].second;
                //Check right if later timestamps are available
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return res; //O(log n)
    }
};
