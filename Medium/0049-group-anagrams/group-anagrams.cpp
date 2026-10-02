class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans; 
        unordered_map<string, vector<string>> anag1;
        for(int i = 0; i < strs.size(); i++){ 
            string s = strs[i]; 
            sort(s.begin(), s.end()) ; 
            anag1[s].push_back(strs[i]); 
        }
        for(auto &p: anag1){
            ans.push_back(p.second); 
        }
        return ans;

        
    }
};