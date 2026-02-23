function lengthOfLongestSubstring(s: string): number {
    if(s.length === 0) {
        return 0;
    }
    const alreadySeen: boolean[] = new Array(128).fill(false);
    var left = 0;
    var right = 0;
    var bestLen = 0;
    while(right < s.length) {
        const cR = s.charCodeAt(right);
        if(!alreadySeen[cR]) {
            alreadySeen[cR] = true;
            right++;
            bestLen = Math.max(bestLen, right - left);
        } else {
            const cL = s.charCodeAt(left);
            alreadySeen[cL] = false;
            left++;
        }
    }
    return bestLen;

}
