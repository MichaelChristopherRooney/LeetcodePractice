function findAnagrams(s: string, p: string): number[] {
    if(p.length > s.length) {
        return [];
    }
    const desiredChars: number[] = new Array(26).fill(0);
    const currentChars: number[] = new Array(26).fill(0);
    const baseCharCode = "a".charCodeAt(0);
    // Build initial fixed window.
    for(let i = 0; i < p.length; i++) {
        desiredChars[p.charCodeAt(i) - baseCharCode]++;
        currentChars[s.charCodeAt(i) - baseCharCode]++;
    }
    let numMatches = 0;
    for(let i = 0; i < 26; i++) {
        if(desiredChars[i] === currentChars[i]) {
            numMatches++;
        }
    }
    const result: number[] = [];
    if(numMatches === 26) {
        result.push(0)
    }
    for(let i = p.length; i < s.length; i++) {
        const toPop = s.charCodeAt(i - p.length) - baseCharCode;
        const toPush = s.charCodeAt(i) - baseCharCode;
        if(desiredChars[toPush] == currentChars[toPush]) {
            numMatches--;
        }
        currentChars[toPush]++;
        if(desiredChars[toPush] == currentChars[toPush]) {
            numMatches++;
        }
        if(desiredChars[toPop] == currentChars[toPop]) {
            numMatches--;
        }
        currentChars[toPop]--;
        if(desiredChars[toPop] == currentChars[toPop]) {
            numMatches++;
        }
        if(numMatches === 26) {
            result.push(i - p.length + 1)
        }
    }
    return result;
}