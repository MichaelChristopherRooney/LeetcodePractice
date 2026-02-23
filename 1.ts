function twoSum(nums: number[], target: number): number[] {
    // value -> index
    const seen = new Map<number, number>();
    for(var i = 0; i < nums.length; i++) {
        const num = nums[i];
        const diff = target - num;
        const result = seen.get(diff);
        if(result !== undefined) {
            return [i, result];
        }
        seen.set(num, i);
    }
    return [];
};