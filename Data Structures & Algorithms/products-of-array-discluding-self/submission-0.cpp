class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
                vector<int> output(nums.size());
                vector<int> prodbegin(nums.size(),1);
                vector<int> prodend(nums.size(),1);
                int prodbegintemp=1;
                int prodendtemp=1;
                for (int i=0, j=nums.size()-1; i<nums.size(); i++, j--){
                    if (i==0){
                    prodbegintemp*=1;
                    prodbegin[i]=1; }
                    else{
                    prodbegintemp*=nums[i-1];
                    prodbegin[i]=prodbegintemp;}
                    if (j==nums.size()-1){
                    prodendtemp*=1;
                    prodend[j]=1;  
                    }
                    else {
                    prodendtemp*=nums[j+1];
                    prodend[j]=prodendtemp;
                    }                    
                }
                for (int i=0; i<nums.size(); i++){
                    output[i]=prodbegin[i]*prodend[i];
                }
                return output;
    }
};
