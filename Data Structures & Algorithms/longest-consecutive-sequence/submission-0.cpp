#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for ( int num : st){
            int current = num;
            int length=1;
            while (st.count(current+1)){
                current++;
                length++;
            }
            longest=max(longest,length);
        }
        return longest;
    }
};
