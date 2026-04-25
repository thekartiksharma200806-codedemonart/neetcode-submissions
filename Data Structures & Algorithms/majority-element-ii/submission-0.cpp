class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times= nums.size()/3;
        vector<int>result;

        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.second >times) result.push_back(i.first);
        }
        return result;

    }
};