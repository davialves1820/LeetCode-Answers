class Solution {
public:
    string convert(string s, int numRows) {
    
        if (numRows <= 1 || s.size() <= numRows) {
            return s;
        }

        vector<string> rows(numRows);
        int p = 0;
        int goingDown = false;

        for (char c : s) {
            rows[p] += c;
            
            if (p == 0) {
                goingDown = true;
            } else if (p == numRows - 1) {
                goingDown = false;
            }

            if (goingDown) {
                p++;
            } else {
                p--;
            }
        }

        string answer = "";
        for (const string& r : rows) {
            answer += r;
        }
        return answer;
    } 
};
