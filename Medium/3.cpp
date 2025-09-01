class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, right = 0, maxLength = 0;

        while (right < s.size()) {
            if (chars.find(s[right]) == chars.end()) {
                
                chars.insert(s[right]);
                maxLength = std::max(maxLength, right - left + 1);
                right++;
            } else {
                
                chars.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};
