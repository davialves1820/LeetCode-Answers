class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        char carry = '0';
        string result = "";

        while (i >= 0 || j >= 0) {
            char bitA = i >= 0 ? a[i] : '0';
            char bitB = j >= 0 ? b[j] : '0';

            int sum = (bitA - '0') + (bitB - '0') + (carry - '0');
            result += (sum % 2) + '0';  
            carry = (sum / 2) + '0';    

            i--;
            j--;
        }

        if (carry == '1') {
            result += '1';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
