class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total;

        for(int i = 0; i < chalk.size(); ++i) {
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }

        return -1;
    }
};
