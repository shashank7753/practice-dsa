
#include <vector>

class Solution {
public:
    int maximumStrongPairXor(std::vector<int>& nums) {
        int ans = 0;

        for (auto x : nums) {
            for (auto y : nums) {
                if (abs(x - y) <= std::min(x, y)) {
                    ans = std::max(ans, x ^ y);
                }
            }
        }

        return ans;
    }
};
