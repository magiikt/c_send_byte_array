//Javascript part to decode hexadecimal message sent with the c code.

//Hexadecimal to char
const hexToChar = hex => String.fromCharCode(hex);

//Hexadecimal to decimal (short/int/long)
const hexToDecimal = hex => parseInt(hex, 16);

//Hexadecimal to an array of bytes
function hexToBytes(hex) {
    let bytes = [];
    for (c = 0; c < hex.length; c += 2) bytes.push(parseInt(hex.substr(c, 2), 16));
    return bytes;
}

//Hexadecimal to float (float, double, long double)
const hexToFloat32 = (int) => {
    if (int > 0 || int < 0) {
        var sign = (int >>> 31) ? -1 : 1;
        var exp = (int >>> 23 & 0xff) - 127;
        var mantissa = ((int & 0x7fffff) + 0x800000).toString(2);
        var float32 = 0
        for (i = 0; i < mantissa.length; i += 1) { float32 += parseInt(mantissa[i]) ? Math.pow(2, exp) : 0; exp-- }
        return float32 * sign;
    } else return 0
}

let bytes = hexToBytes("419a1f8d0000000000000000000000000000000000000000000000000000")
decoded = (bytes[0] << 24 | bytes[1] << 16 | bytes[2] << 8 | bytes[3]);
console.log(hexToFloat32(decoded))
