class Solution {
public:
    bool isValid(string s) {
        int v[3] = {0};
        stack<char> p;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{' ) {
                p.push(c); 
            } else if (!p.empty()) {
                if ((c == ')' && p.top() != '(') || 
                        (c == ']' && p.top() != '[') || 
                        (c == '}' && p.top() != '{')) {
                    return false;
                } else {
                    p.pop();
                } 
            } else {
                p.push(c);
            }
        }
        return p.empty();
    }
};
