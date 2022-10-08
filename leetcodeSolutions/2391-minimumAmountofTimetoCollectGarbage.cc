class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        unordered_map<char, vector<int>> mp{
            {'M', vector<int>(n)}, {'P', vector<int>(n)}, {'G', vector<int>(n)}
        };
        for(int i = n - 1; i >= 0; --i) {
            for(auto &ch: garbage[i]) {
                ++mp[ch][i];
            }
        }

        // made suffix array for each trash
        for(auto &[ch, trash] : mp) {
            for(int i = n - 2; i >= 0; --i) {
                trash[i] += trash[i + 1];
            }
        }

        int time = 0;
        for(auto &[ch, trash] : mp) {
            time += trash[0]; // collecting all the trash
            for(int i = 1; i < n; ++i) {
                // no trash left in the rest of the houses
                if(!trash[i]) {
                    break;
                }
                time += travel[i - 1];
            }
        }

        return time;
    }
};
