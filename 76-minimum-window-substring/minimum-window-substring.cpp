class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        vector<int> need(128, 0);
        for (char c : t) {
            need[c]++;
        }
        int required = t.size();
        int left = 0;
        int minLength = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (need[c] > 0) {
                required--;
            }
            need[c]--;
            while (required == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                char leftChar = s[left];
                need[leftChar]++;
                if (need[leftChar] > 0) {
                    required++;
                }
                left++;
            }
        }
        if (minLength == INT_MAX)
            return "";
        return s.substr(start, minLength);
    }
};
