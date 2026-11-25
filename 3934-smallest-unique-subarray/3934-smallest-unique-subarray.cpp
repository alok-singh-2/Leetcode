
class Solution {
public:
    const long long MOD1 = 1000000007;
    const long long MOD2 = 1000000009;

    const long long BASE1 = 911382323;
    const long long BASE2 = 972663749;

    bool check(int len, vector<int>& nums) {
        int n = nums.size();

        long long hash1 = 0;
        long long hash2 = 0;

        long long power1 = 1;
        long long power2 = 1;

        for (int i = 0; i < len; i++) {
            power1 = (power1 * BASE1) % MOD1;
            power2 = (power2 * BASE2) % MOD2;
        }

        unordered_map<unsigned long long, int> mp;

        for (int i = 0; i < len; i++) {
            hash1 = (hash1 * BASE1 + nums[i]) % MOD1;
            hash2 = (hash2 * BASE2 + nums[i]) % MOD2;
        }

        unsigned long long key =
            (hash1 << 32) | hash2;

        mp[key]++;

        for (int i = len; i < n; i++) {

            hash1 = (hash1 * BASE1
                    - (nums[i - len] * power1) % MOD1
                    + nums[i] + MOD1) % MOD1;

            hash2 = (hash2 * BASE2
                    - (nums[i - len] * power2) % MOD2
                    + nums[i] + MOD2) % MOD2;

            key = (hash1 << 32) | hash2;

            mp[key]++;
        }

        for (auto it : mp) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int ans = nums.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
