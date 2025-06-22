/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        cout << diff ;
        int ans = -1 ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                for(int k = j+1; k < n ;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    int  d = abs(sum-target);
                    cout << d << " ";
                    if(d<diff){
                        diff= d; 
                        ans = sum ;
                    }
                }
                    
            }
        }

        return ans ; 
    }
};
// @lc code=end

