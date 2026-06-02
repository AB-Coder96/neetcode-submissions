#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
       constexpr size_t CAPACITY = 2048;
        constexpr size_t MASK = CAPACITY - 1;
        alignas(64) int keys[CAPACITY];
        alignas(64) int values[CAPACITY];
        alignas(64) bool occupied[CAPACITY] = {false};
        const int* data_ptr = nums.data();
        const size_t len = nums.size();

        for (size_t i = 0; i < len; ++i) {
            int current_num = data_ptr[i];
            int complement = target - current_num;
            size_t hash_idx = (static_cast<size_t>(complement) * 2654435761U) & MASK;
            while (occupied[hash_idx]) {
                if (keys[hash_idx] == complement) [[unlikely]] {
                    return {values[hash_idx], static_cast<int>(i)};
                }
                hash_idx = (hash_idx + 1) & MASK;
            }
            size_t insert_idx = (static_cast<size_t>(current_num) * 2654435761U) & MASK;
            while (occupied[insert_idx]) {
                insert_idx = (insert_idx + 1) & MASK;
            }
            keys[insert_idx] = current_num;
            values[insert_idx] = static_cast<int>(i);
            occupied[insert_idx] = true;
        }

        return {};
    }
};