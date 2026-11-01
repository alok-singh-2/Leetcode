class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int n = nums.size();
        mp.insert({0,1});
        int result = 0;
        int cumulativesum = 0;
        for(int i=0; i<n ; i++){
            cumulativesum += nums[i];

           if(mp.find(cumulativesum-k) != mp.end()){
            result += mp[cumulativesum-k];
           }
           mp[cumulativesum]++;
        }
        return result;
    }
};