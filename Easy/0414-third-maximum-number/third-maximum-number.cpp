class Solution {
public:
    long long thirdMax(vector<int>& nums) {
        long long max = LLONG_MIN; 
        int n = nums.size(); 
        for(int i = 0; i < n; i++){ 
            if(nums[i] > max){ 
                max = nums[i]; 
            }
        }
        long long max2 = LLONG_MIN; 
        for(int i = 0; i < n; i++){ 
            if(nums[i] < max && nums[i] > max2){ 
                max2 = nums[i]; 
            }
        }
        long long max3 = LLONG_MIN; 
        for(int i = 0; i < n; i++){ 
            if(nums[i] < max2 && nums[i] > max3){ 
                max3 = nums[i]; 
            }
        }
         return max3 == LLONG_MIN ? max : max3;
    }
};