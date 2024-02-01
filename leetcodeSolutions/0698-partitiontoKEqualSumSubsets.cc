#pragma GCC optimize("O3", "unroll-loops")

class Solution {
public:
    bool canPartitionKSubsets(const vector<int> & nums, const int & k) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static int INF = 0x3f3f3f;

        const int n = nums.size();
        if (n < k) {
            return false;
        }

        int sum = 0, maxx = -INF;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            maxx = max(maxx, nums[i]);
        }

        if (sum % k) {
            return false;
        }

        const int block_sum = sum / k;
        if (maxx > block_sum) {
            return false;
        }
        
        vector<int> cache(1 << n, -1);
        auto can_make_blocks = [&](const auto & can_make_blocks, const int & idx, const int & blocks_left, const int & mask, const int & curr_sum) -> bool {
            if (!blocks_left) {
                return true;
            }

            if (cache[mask] != -1) {
                return cache[mask];
            }

            if (idx == n || curr_sum > block_sum) {
                return false;
            }

            if (curr_sum == block_sum) {
                return cache[mask] = can_make_blocks(can_make_blocks, 0, blocks_left - 1, mask, 0);
            }

            for (int i = idx; i < n; ++i) {
                const int is_used = mask & (1 << i);
                if (is_used) {
                    continue;
                }

                const int use_num_mask = mask | (1 << i);
                cache[mask] = can_make_blocks(can_make_blocks, i + 1, blocks_left, use_num_mask, curr_sum + nums[i]);
                if (cache[mask]) {
                    return true;
                }
            }

            return cache[mask] = false;
        };

        return can_make_blocks(can_make_blocks, 0, k - 1, 0, 0); // last set is implied
    }
};
