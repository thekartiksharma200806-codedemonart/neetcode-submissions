class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // count frequency
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        vector<int> result;

        for (int i = 0; i < k; i++) {

            int maxFreq = 0;
            int element;

            for (auto &p : freq) {
                if (p.second > maxFreq) {
                    maxFreq = p.second;
                    element = p.first;
                }
            }

            result.push_back(element);
            freq[element] = 0;  // mark as used
        }

        return result;
    }
};