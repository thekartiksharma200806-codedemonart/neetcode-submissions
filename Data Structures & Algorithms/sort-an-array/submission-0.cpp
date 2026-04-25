class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    void mergesort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};