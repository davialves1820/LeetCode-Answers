class Solution {
public:
    int smallestNumber(int n) {
        int i = 1, d = 1;
        while (i < n) {
            i = i + pow(2, d++);
        }
        return i;
    }
};
