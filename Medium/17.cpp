class Solution {
public:
    const vector<string> digit_to_letters = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(const string &digits, int index, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const string &letters = digit_to_letters[digit];

        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(const string &digits) {
        vector<string> result;
        if (digits.empty()) return result;

        string current;
        backtrack(digits, 0, current, result);
        return result;
    }

};
