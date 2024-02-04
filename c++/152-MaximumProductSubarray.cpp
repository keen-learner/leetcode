/*

Find the contiguous subarray within an array (containing at least 
one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        else if (n == 1) return nums[0];
        
        int run_max_plus, run_max_minus;
        run_max_plus = run_max_minus = nums[0];
        //if(nums[0] >= 0) {run_max_plus = nums[0]; run_max_minus = 1;}
        //else {run_max_minus = nums[0]; run_max_plus = 1;}
        int prev_max = nums[0];
        
        for(int i = 1; i <  n; ++i){
            
            int temp = run_max_plus;
            run_max_plus = max(nums[i], max(run_max_plus*nums[i], run_max_minus*nums[i]));
            run_max_minus = min(nums[i], min(temp*nums[i], run_max_minus*nums[i]));
            prev_max = max(prev_max, run_max_plus);
            
        }
        return prev_max;
    }
};
