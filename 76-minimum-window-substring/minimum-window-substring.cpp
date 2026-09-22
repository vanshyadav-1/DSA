class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";

        vector<int> need(128, 0);

        // Frequency of characters required from t
        for (char c : t) {
            need[c]++;
        }

        int required = t.size();
        int left = 0;

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // This character was still required
            if (need[c] > 0) {
                required--;
            }

            // Add c to the current window
            need[c]--;

            // Window contains all characters of t
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Remove leftmost character
                char leftChar = s[left];

                need[leftChar]++;

                // We removed a required character
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
