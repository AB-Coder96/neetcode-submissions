class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int ,vector<int>> dict_nums;
            dict_nums.reserve(nums.size()); 
            for (int i = 0; i < nums.size(); ++i) {
                auto j=dict_nums.find(target-nums[i]);
                dict_nums[nums[i]].push_back(i);
                if (j != dict_nums.end()) {
                    int jj = j -> second[0];
                    if (i<jj){
                       return {i,jj};        
                    } 
                    if (i==jj){
                       return {i,jj};        
                    }                                                                  
                    if (i>jj){
                       return {jj,i};        
                    } 
                    
                }
            }
        }    
};
