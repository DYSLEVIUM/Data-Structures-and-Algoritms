class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> forces(n);

        int curr_force = 0;
        // l to r
        for(int i = 0; i < n; ++i) {
            if(dominoes[i] == 'R') {
                curr_force = n;
            } else if(dominoes[i] == 'L') {
                curr_force = 0;
            } else {
                curr_force = max(curr_force - 1, 0);
            } // we got a standing domino, we decay the force

            forces[i] += curr_force;
        }

        curr_force = 0;
        // r to l
        for(int i = n - 1; i >= 0; --i) {
            if(dominoes[i] == 'L') {
                curr_force = n;
            } else if(dominoes[i] == 'R') {
                curr_force = 0;
            } else {
                curr_force = max(curr_force - 1, 0);
            } // we got a standing domino, we decay the force

            forces[i] -= curr_force;
        }

        string ans;
        for(const int & force : forces) {
            ans += force ? (force < 0 ? 'L' : 'R') : '.';
        }

        return ans;
    }
};
