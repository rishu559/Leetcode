class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int element = nums[0];
        int i=1;
        while(i<nums.size()){
            if(count==0){
                element = nums[i];
                count=1;
            }
            else if(element==nums[i]) count++;
            else{
                count--;
            }
            i++;
        }
        return element;
    }
};