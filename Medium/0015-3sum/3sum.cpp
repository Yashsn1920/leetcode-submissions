class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> ans; 
        for(int k = 0; k < nums.size(); k++){ 
            if(k > 0 && nums[k] == nums[k - 1]) {
                continue; 
            }
            int i = k + 1;
            int j = nums.size() - 1; 
            while(i < j){ 
                if(nums[i] + nums[j] == -nums[k]){ 

                    ans.push_back({nums[k],nums[i],nums[j]}); 
                    i++; 
                    j--; 

                    while (i < j && nums[i] == nums[i - 1])
                        i++;

                    while (i < j && nums[j] == nums[j + 1])
                        j--;
                }
                else if(nums[i] + nums[j] < -nums[k]){
                    i++;
                }
                else{ 
                    j--;                 }
            }
        }
        return ans; 
        
    }
};