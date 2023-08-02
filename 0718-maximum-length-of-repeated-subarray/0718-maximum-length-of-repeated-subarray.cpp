class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n2+1,vector<int>(n1+1,0));
        int res = 0;
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=n1;j++){
                if(nums2[i-1]==nums1[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max({res,dp[i][j],dp[i-1][j],dp[i][j-1]});
                }
                res = max({res,dp[i][j-1],dp[i-1][j]});
            }

        }
        return res;

    }
};