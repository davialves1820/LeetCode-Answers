class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 || needle.size() == 0) {
            return -1;
        }

        for (int i = 0; i < haystack.size(); i++) {
            int k = 0, j = i;
            while (k < needle.size() && haystack[j] == needle[k]) {
                k++;
                j++;
            }
            if (k == needle.size()) {
               return i;
            } 
        }
        return -1;
    }
};
