function convert(s: string, numRows: number): string {
    if(numRows === 1) {
        return s;
    }
    const data: string[] = new Array(numRows).fill("");
    let dir = 1;
    let rowCount = 0;
    for(let i = 0; i < s.length; i++) {
        data[rowCount] += s[i];
        if(rowCount == numRows - 1) {
            dir = -1;
        }
        if(rowCount == 0) {
            dir = 1;
        }
        rowCount += dir;
    }
    let result = "";
    for(let i = 0; i < numRows; i++) {
        result += data[i];
    }
    return result;
}