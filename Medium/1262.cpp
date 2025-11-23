class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> rest1, rest2;

        for (int x : nums) {
            total += x;
            if (x % 3 == 1) rest1.push_back(x);
            else if (x % 3 == 2) rest2.push_back(x);
        }

        if (total % 3 == 0) return total;

        sort(rest1.begin(), rest1.end());
        sort(rest2.begin(), rest2.end());

        int removeValue = INT_MAX;

        // Caso a soma dê resto 1
        if (total % 3 == 1) {
            if (!rest1.empty())
                removeValue = min(removeValue, rest1[0]);
            if (rest2.size() >= 2)
                removeValue = min(removeValue, rest2[0] + rest2[1]);
        } 
        // Caso a soma dê resto 2
        else { 
            if (!rest2.empty())
                removeValue = min(removeValue, rest2[0]);
            if (rest1.size() >= 2)
                removeValue = min(removeValue, rest1[0] + rest1[1]);
        }

        return (removeValue == INT_MAX) ? 0 : total - removeValue;
    }
};
