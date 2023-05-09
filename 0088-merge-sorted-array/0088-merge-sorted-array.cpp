class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0,b=0;
        vector<int> res;
        while(a!=m && b!=n){
            if(nums1[a]<nums2[b]){
                res.push_back(nums1[a]);
                a++;
            }
            else{
                res.push_back(nums2[b]);
                b++;
            }
        }
        while(a!=m){
            res.push_back(nums1[a]);
            a++;
        }
        while(b!=n){
            res.push_back(nums2[b]);
            b++;
        }
        nums1 = res;
    }
};