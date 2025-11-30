class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;

        for (int x : nums) { 
            total += x;
        }

        int target = total % p;
        
        if (target == 0) {
            return 0;  // no removal needed
        }
        
        unordered_map<int,int> lastIndex; 
        lastIndex[0] = -1;  // prefix before array starts
        
        long long prefix = 0;
        int ans = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            
            int want = (prefix - target + p) % p;
            
            if (lastIndex.count(want)) {
                ans = min(ans, i - lastIndex[want]);
            }
            
            lastIndex[prefix] = i;
        }
        
        return (ans == nums.size() ? -1 : ans);
    }
    
};
