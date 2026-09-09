class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i >= n)
                break;
            int j = i;
            while (j < n && s[j] != ' ')
                j++;
            words.push_back(s.substr(i, j - i));
            i = j;
        }
        string ans;
        for (int k = words.size() - 1; k >= 0; k--) {
            ans += words[k];
            if (k > 0)
                ans += " ";
        }
        return ans;
    }
};