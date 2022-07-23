class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<int> rank_se;
        for(auto &rank: ranks) {
            rank_se.insert(rank);
        }
        
        unordered_set<int> suit_se;
        for(auto &suit: suits) {
            suit_se.insert(suit);
        }
        
        if(suit_se.size() == 1) {
            return "Flush";
        }
        
        if(rank_se.size() <= 4) {
            vector<int> rank_fa(14);
            int cnt = 0;
            for(auto &rank: ranks) {
                ++rank_fa[rank];
                cnt = max(cnt, rank_fa[rank]);
            }
            
            if(cnt >= 3) {
                return "Three of a Kind";
            } else {
                return "Pair";
            }
        }
        
        return "High Card";
    }
};
