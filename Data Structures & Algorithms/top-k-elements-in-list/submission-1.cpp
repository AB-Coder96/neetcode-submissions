#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> frequency;
       for (int num : nums){
        frequency[num]++;
       }       
       vector<vector<int>> buckets(nums.size()+1);
       for (auto& pair : frequency){
        int num=pair.first;
        int count=pair.second;
        buckets[count].push_back(num);
       }
       vector<int> answer;
        for (int i=nums.size(); i>=0; i--){
          for (int num : buckets[i]){
            answer.push_back(num);
            if (answer.size()==k){
                return answer;
            }
          }  
        }

        return answer;
    }
};
