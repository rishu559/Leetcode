class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int miny = nums[0];
        int maxy = nums[0];

        int res = nums[0];
        bool flag = true;
        for(int i:nums){
            if(flag){
                flag = false;
                continue;
            }
            if(i<0){
                swap(miny,maxy);
            }
            maxy = max(maxy*i,i);
            miny = min(miny*i,i);
            res = max({res,maxy,miny});
        }
        return res;
    }
};