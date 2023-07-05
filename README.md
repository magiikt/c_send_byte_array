# Concatenate c variables into a byte array to be sent, then decode the byte array received as hexadecimal into javascript variables

## main.c

### FRENCH

Cette partie contient des fonctions permettant de convertir des variables en c en tableau d'octet, puis de concatener ces tableau d'octet en un tableau d'octet final qui sera envoyé par la fonction send.

#### MESSAGE_SIZE
```
#define MESSAGE_SIZE 30
```
Par défaut, la taille du message est de 30 octets, mais vous pouvez configurer la variable définie "TABLEAU_SIZE" si nécessaire.

#### convertTypeToArrayThenConcatenateToMessage
```
void convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var,
                                                int int_var, long long_var,
                                                float float_var,
                                                double double_var,
                                                long double longdouble_var)
```
Pour ajouter n'importe quel type de données au tableau de message qui sera envoyé, utilisez convertTypeToArrayThenConcatenateToMessage avec le nom de la variable correspondant au bon type, puis mettez 0 pour les autres types.

Par exemple, pour ajouter une valeur flottante :
```convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, float_var, 0, 0); ```

#### concatenateArrayToMessage
```
void concatenateArrayToMessage(uint8_t buffer_array[], size_t size,
                               uint8_t message_array[])
```
Pour ajouter un tableau d'octets au tableau de messages qui sera envoyé, utilisez concatenateArrayToMessage et spécifiez la longueur du tableau d'octet.

Par exemple, pour ajouter un tableau d'octets de 4 octets :
```concatenateArrayToMessage(buffer_array, 4, tableau_array); ```

Ce code ne contient pas la partie permettant l'envoie du tableau d'octet.

### ENGLISH

This section contains functions for converting c variables into byte arrays, then concatenating these byte arrays into a final byte array to be sent by the send function.

#### MESSAGE_SIZE
```
#define MESSAGE_SIZE 30
```
By default, the size for the message is 30 bytes, but you can configure the defined "TABLEAU_SIZE" variable if needed.

#### convertTypeToArrayThenConcatenateToMessage
```
void convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var,
                                                int int_var, long long_var,
                                                float float_var,
                                                double double_var,
                                                long double longdouble_var)
```
To add any data type to the message array that will be sent, use convertTypeToArrayThenConcatenateToMessage with the variable name corresponding to the correct type, then put 0 for other types.

For example, to add a float value:
```convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, float_var, 0, 0);```

#### concatenateArrayToMessage
```
void concatenateArrayToMessage(uint8_t buffer_array[], size_t size,
                               uint8_t message_array[])
```
To add a byte array to the message array that will be sent, use concatenateArrayToMessage and specify the length of the array.

For example, to add a byte array of 4 bytes :
```concatenateArrayToMessage(buffer_array, 4, tableau_array);```

This code does not contain the part allowing the byte array to be sent.

## script.js

### FRENCH

Cette partie contient des fonctions permettant de décoder le message, qui est un tableau d'octet, en variables javascript.

```
//Hexadecimal to char
const hexToChar = hex => String.fromCharCode(hex);
```

```
//Hexadecimal to decimal (short/int/long)
const hexToDecimal = hex => parseInt(hex, 16);
```

```
//Hexadecimal to an array of bytes
function hexToBytes(hex) {
    let bytes = [];
    for (c = 0; c < hex.length; c += 2) bytes.push(parseInt(hex.substr(c, 2), 16));
    return bytes;
}
```

```
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
```

### ENGLISH

This part contains functions used to decode the message, which is an array of bytes, into javascript variables.

```
//Hexadecimal to char
const hexToChar = hex => String.fromCharCode(hex);
```

```
//Hexadecimal to decimal (short/int/long)
const hexToDecimal = hex => parseInt(hex, 16);
```

```
//Hexadecimal to an array of bytes
function hexToBytes(hex) {
    let bytes = [];
    for (c = 0; c < hex.length; c += 2) bytes.push(parseInt(hex.substr(c, 2), 16));
    return bytes;
}
```

```
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
```
