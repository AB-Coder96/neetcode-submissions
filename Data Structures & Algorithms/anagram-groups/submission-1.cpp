#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map stores character frequency counts as keys, and list of strings as values
        map<map<char, int>, vector<string>> dict_s;
        vector<vector<string>> flat;
        
        for (int i = 0; i < strs.size(); ++i) {  
            map<char, int> dict_c; // Character frequency counter
            for (int j = 0; j < strs[i].size(); ++j) {
                dict_c[strs[i][j]]++;
            } 
            dict_s[dict_c].push_back(strs[i]);                   
        } 
        
        for (auto& [key, vec] : dict_s) {
            flat.push_back(std::move(vec)); 
        }
        return flat;
    }
};