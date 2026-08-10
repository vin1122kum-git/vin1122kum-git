class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n==0) return;

        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }

            return;
        }

        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j++];
        }

        sort(nums1.begin(),nums1.end());
    }
};