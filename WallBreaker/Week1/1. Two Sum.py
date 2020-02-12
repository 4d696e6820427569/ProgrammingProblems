class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hTable = dict()
        for i in range(len(nums)):
            hTable[nums[i]] = i
            nums[i] = target - nums[i]

        for i in range(len(nums)):
            if nums[i] in hTable and i != hTable[nums[i]]:
                return [hTable[nums[i]], i]
