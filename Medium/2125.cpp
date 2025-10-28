class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = 0;
        int ant = 0;

        for (auto s : bank) {
            int count = 0;

            for (auto c : s) {
                if (c == '1') {
                    count++;
                }
            }

            if (count > 0) {
                n += ant * count;
                ant = count;
            }
        }
        
        return n;
    }
};
