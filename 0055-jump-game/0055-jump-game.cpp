class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        if(n==1) return true;
        for(int i=0;i<=maxi && i<n-1;i++){
            nums[i] = max(maxi,nums[i]+i);
            maxi = max(maxi,nums[i]);
            if(maxi>=n-1) return true;
        }
        return false;
    }
};