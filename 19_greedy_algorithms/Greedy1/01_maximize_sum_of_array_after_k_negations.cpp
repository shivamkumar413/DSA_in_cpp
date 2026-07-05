// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int> > pq(nums.begin(),nums.end());

        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];

        while(k > 0){
            int tp = pq.top();
            if(tp == 0) break;
            pq.pop();
            sum -= tp;
            pq.push(-1*tp);
            sum += (-1*tp);
            k--;
        }

        return sum;
    }
};