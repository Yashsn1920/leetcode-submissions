class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int top = 0; 
        int cnt = 0;
        int s = n; 
        while(s > 0 && top < students.size()){ 
            int i = 0; 
            s = sandwiches.size(); 
            if(students[i] == sandwiches[i]){ 
                sandwiches.erase(sandwiches.begin());
                students.erase(students.begin());
                cnt++;
                top = 0; 
            }
            else{
                int a = students.front(); 
                students.erase(students.begin()); 
                students.push_back(a); 
                top++;

            }
            i++;
        }
        return n - cnt;
    }
};