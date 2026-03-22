class Solution {

  public:
    long long countTriplets(int n, long long target, long long nums[]) {
        sort(nums, nums+n);
        int count = 0;
        for(int i = 0; i < n; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum >= target){
                    k--;
                }
                else{
                    count += (k-j); //all k less than current k will be in the triplet
                    j++;
                }
            }
        }
        return count;
    }
};
