#include <vector>
#include <unordered_map>
#include <iostream>

// Force compiler and I/O speedups upfront
#pragma GCC optimize("O3,unroll-loops")
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution { 
public: 
    std::vector<int> twoSum(const std::vector<int>& nums, int target) { 
        std::unordered_map<int, int> dict_nums; 
        dict_nums.reserve(1024); // Hand-picked based on the 1000 max size constraint

        const int len = nums.size();
        for (int i = 0; i < len; ++i) { 
            int complement = target - nums[i];
            auto j = dict_nums.find(complement); 
            
            if (j != dict_nums.end()) [[unlikely]] { 
                return {j->second, i}; 
            } 
            
            dict_nums[nums[i]] = i; 
        }
        return {}; 
    } 
};
