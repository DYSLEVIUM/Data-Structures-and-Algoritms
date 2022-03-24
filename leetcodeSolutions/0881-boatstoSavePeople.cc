class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        
        sort(people.begin(), people.end());
        int ptr_1 = 0, ans = 0, ptr_2 = n - 1;
        while(ptr_1 <= ptr_2) {
            if(people[ptr_1] + people[ptr_2] <= limit) ++ptr_1, --ptr_2;
            else --ptr_2;
            
            ++ans;
        }
        
        return ans;
    }
};
