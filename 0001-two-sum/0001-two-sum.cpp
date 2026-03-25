class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++){
            int residue = target - nums[i];
            if(hash.find(residue) != hash.end()){
                return {hash[residue], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};