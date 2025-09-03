class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        
        for (auto i = 1; i < strs.size(); i++) {
            auto j = 0;
            while (answer[j] == strs[i][j] && j < answer.size()) {
                j++;
            }
            answer = answer.substr(0,j);
            if (answer.empty()) {
                return "";
            }
        }
        return answer;
    }
};
