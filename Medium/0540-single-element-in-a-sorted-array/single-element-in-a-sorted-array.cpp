class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        int i = 0; 
        int j = n - 1; 
        int m = 0; 
        while(i < j){ 
            m = i + (j - i) / 2;
            if(m % 2 != 0){ 
                m--; 
            }
            if(nums[m] == nums[m + 1]){
                i = m + 2; 
            }
            else{
                j = m; 
            }
        }
        return nums[i]; 
        
    }
};