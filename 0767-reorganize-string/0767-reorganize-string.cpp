class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &[ch, cnt] : mp) {
            pq.push({cnt, ch});
        }

        string ans;

        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            ans += ch;
            cnt--;

            // Put the previous character back now that
            // we've used a different character.
            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = {cnt, ch};
        }

        if (ans.size() != s.size()) {
            return "";
        }

        return ans;
    }
};