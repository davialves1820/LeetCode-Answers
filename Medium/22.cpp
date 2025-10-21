class Solution {
public:

    void backtrack(vector<string>& answer, string current, int open, int close, int n) {
    
        if (current.size() == 2 * n) {
            answer.push_back(current);
            return;
        }

        if (open < n){ 
            backtrack(answer, current + "(", open + 1, close, n);
        }

        if (close < open){
            backtrack(answer, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtrack(answer, "", 0, 0, n);
        return answer;
    }
};
