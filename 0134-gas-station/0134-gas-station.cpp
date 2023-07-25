class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum =0;
        for(int i=0;i<gas.size();i++){
            sum += gas[i]-cost[i];
        }
        if(sum<0) return -1;

        int ans = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            ans = ans + gas[i] - cost[i];
            if(ans<0){
                ans =0;
                start = (i+1)%gas.size();
            }
        }
        return start;
    }
};