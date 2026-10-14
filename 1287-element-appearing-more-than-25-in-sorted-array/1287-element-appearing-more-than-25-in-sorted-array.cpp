class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        int n=arr.size();

        unordered_map<int,int> mpp;
        for(auto &it:arr){
            mpp[it]++;
        }

        int cnt = n/4;

        for(auto &it:mpp){
            if(it.second > cnt){
                return it.first;
            }
        }

        return 0;
        
    }
};