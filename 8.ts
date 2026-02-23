function myAtoi(s: string): number {
    let index = 0;
    // Skip leading whitespace.
    const spaceChar = " ".charCodeAt(0);
    while(s.charCodeAt(index) == spaceChar) {
        index++;
    }
    let sign = 1;
    if(s[index] === "+") {
        index++;
    } else if(s[index] === "-") {
        index++;
        sign = -1;
    }
    const asciiBase = "0".charCodeAt(0);
    const asciiEnd = "9".charCodeAt(0);
    let value = 0;
    while(index < s.length) {
        const c = s.charCodeAt(index);
        if(c < asciiBase || c > asciiEnd) {
            break;
        }
        value *= 10;
        const digit = c - asciiBase;
        value += digit;
        index++;
    }
    if(sign === 1) {
        if(value > 2147483647) {
            return 2147483647;
        }
        return value;
    } else {
        if(value > 2147483648) {
            return -2147483648;
        }
        return -value;
    }
};