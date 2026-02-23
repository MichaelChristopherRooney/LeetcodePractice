function longestPalindrome(s: string): string {
    var best = s.substring(0, 1);
    for(var i = 0; i < s.length; i++) {
        const oddMatch = expandFromCenter(s, i, i);
        if(oddMatch.length > best.length) {
            best = oddMatch;
        }
        const evenMatch = expandFromCenter(s, i, i + 1);
        if(evenMatch.length > best.length) {
            best = evenMatch;
        }
    }
    return best;
};

function expandFromCenter(s: string, start: number, end: number) {
    while(start >= 0 && end < s.length && s.charCodeAt(start) === s.charCodeAt(end)) {
        start--;
        end++;
    }
    return s.substring(start + 1, end);

}