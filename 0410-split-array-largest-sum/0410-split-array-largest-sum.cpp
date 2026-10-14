class Solution {
public:
  int canWePaint(vector<int>&arr,int day){
      long long painter=1 , wallsPainted=0;
      
      for(int i=0;i<arr.size();i++){
          if(wallsPainted+arr[i]<=day){
              wallsPainted+=arr[i];
          }
          else{
              painter++;
              wallsPainted=arr[i];
          }
      }
      
      return painter;
  }
    int splitArray(vector<int>& arr, int k) {
          if(k>arr.size()) return -1;
        // code here
        
        long low=*max_element(arr.begin(),arr.end());
        long high = accumulate(arr.begin(),arr.end(),0);
        
        while(low<=high){
            long mid=low+(high-low)/2;
            
            if(canWePaint(arr,mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return low;
        
    }
};