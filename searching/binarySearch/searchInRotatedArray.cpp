int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l ) / 2;
        if (nums[mid] == target)
            return mid;
        // left sorted part
        if (nums[l] <= nums[mid]) {
            if (target > nums[mid] or target < nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        } else { // right sorted part
            if (target < nums[mid] or target > nums[r])
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}