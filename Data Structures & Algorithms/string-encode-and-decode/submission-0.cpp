#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded="";
        for (auto& str :strs){
            encoded +=to_string(str.length());
            encoded+='#';
            encoded+=str;
        }
        return encoded;
    }
    vector<string> decode(string s) {
        int i=0;
        vector<string> decoded;
        while(i<s.length()){
            int  j = i;
            while (s[j] !='#'){
                j++;
            }
            int length=std::stoi(s.substr(i,j-i));
            j++;
            decoded.push_back(s.substr(j,length));
            i=j+length;
        }
        return decoded;
    }
};
