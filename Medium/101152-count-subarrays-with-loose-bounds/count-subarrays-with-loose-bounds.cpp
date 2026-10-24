class Solution {
    int sum1(int n){
        int ans = 0; 
        for(int i = 1; i <= n; i++){
            ans += i; 
        }
        return ans; 
    }
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(); 
        int min_ind = 0; 
        int run = 0; 
        int ans = 0; 
        if(minK == maxK){
            for(int i = 0; i < n ; i++){
                if(nums[i] == minK){
                    run++; 
                }
            }
            ans = sum1(run); 
            return ans; 
            
        }
        else{ 
        for(int i = 0; i < n; i++){
            if(nums[i] == minK){
                min_ind = i; 
            }
        }
        for(int i = min_ind; i < n; i++){
            if(nums[i] <= maxK){
                run++; 
            }
             
            if(nums[i] > maxK){
                i++; 
                run = 0; 
            }
            ans += sum1(run);
           
        }
        }
        return ans;
    }
};