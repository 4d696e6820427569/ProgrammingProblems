class Solution {

    public int search(int[] sums, int target) {
        return searchAux(sums, target, 0, sums.length-1);
    }

    public int searchAux(int[] nums, int target, int i, int j) {
        if (i > j)
            return -1;

        int mid = (i + j)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return searchAux(nums, target, mid+1, j);
        } else {
            return searchAux(nums, target, i, mid-1);
        }
    }
    public int iter_search(int[] nums, int target) {
        // Got TLE.
        int i = 0, j = nums.length - 1;

        while (i <= j) {
            int mid = i + (j-1) / 2;
            if (target < nums[mid]) {
                j = mid-1;
            } else if (target > nums[mid]) {
                i = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}
