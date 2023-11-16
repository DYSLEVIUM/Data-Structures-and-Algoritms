class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());

        long long ans = 0;

        int i = 0, j = n - 1;
        int prev = skill.front() + skill.back();        
        while(i < j) {
            if(prev != skill[i] + skill[j]) {
                return -1;
            }
            ans += 1LL * skill[i++] * skill[j--];
        }

        return ans;
    }
};
