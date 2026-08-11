class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // int left = 0;
        // int right = arr.size() - 1;

        // while (right - left + 1 > k) {
        //     if (abs(arr[left] - x) > abs(arr[right] - x))
        //         left++;
        //     else
        //         right--;
        // }

        // return vector<int>(arr.begin() + left, arr.begin() + right + 1);


            priority_queue<pair<int, int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            pq.push({abs(arr[i] - x), arr[i]});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};