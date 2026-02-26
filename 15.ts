function threeSum(nums: number[]): number[][] {
    const result: number[][] = [];
    nums.sort((a, b) => a - b);
    let i = 0;
    while (i < nums.length - 2) {
        let iVal = nums[i];
        let j = i + 1;
        let k = nums.length - 1;
        let jVal = nums[j]
        let kVal = nums[k]
        while(j < k) {
            const sum = iVal + jVal + kVal
            if(sum > 0) {
                // Need a smaller number, so shrink k.
                k--;
                kVal = nums[k]
            } else if(sum < 0) {
                // Need a bigger number, so grow j.
                j++
                jVal = nums[j]
            } else {
                result.push([iVal, nums[j], nums[k]]);
                j++
                k--
                kVal = nums[k]
                // Skip over duplicates index by j.
                while(j < k && nums[j] == nums[j - 1]) {
                    j++
                }
                jVal = nums[j]
            }
        }
        i++
        while (i < nums.length && nums[i] === nums[i - 1]) {
            i++;
        }
    }
    return result;
}

// [-4, -1, -1, 0, 1, 2]