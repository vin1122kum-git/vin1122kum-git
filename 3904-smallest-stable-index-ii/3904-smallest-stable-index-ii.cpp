class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n=nums.size();

        int ans=INT_MAX;
        
         vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        // 5 5 5 5 
       // 0 0 1 4

        prefixMax[0]=nums[0];
        suffixMin[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
           prefixMax[i] = max(prefixMax[i-1],nums[i]);
        }

         for(int i=n-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],nums[i]);
        }



        for(int i=0;i<n;i++){
            if(prefixMax[i]-suffixMin[i]<=k){
                ans=min(ans,i);
            }
            
        }


        return ans==INT_MAX ? -1 : ans;
    }
};