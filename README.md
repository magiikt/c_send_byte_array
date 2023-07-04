## c_send_byte_array

# FRENCH
Par défaut, la taille du message est de 30 octets, mais vous pouvez configurer la variable définie "TABLEAU_SIZE" si nécessaire.

Pour ajouter n'importe quel type de données au tableau de message qui sera envoyé, utilisez convertTypeToArrayThenConcatenateToMessage avec le nom de la variable correspondant au bon type, puis mettez 0 pour les autres types.
convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var, int int_var, long long_var, float float_var, double double_var, long double longdouble_var)
Par exemple, pour ajouter une valeur flottante :
convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, float_var, 0, 0) ;

Pour ajouter un tableau d'octets au tableau de messages qui sera envoyé, utilisez concatenateArrayToMessage et spécifiez la longueur du tableau d'octet.
concatenateArrayToMessage(uint8_t buffer_array[], size_t size, uint8_t tableau_array[])
Par exemple, pour ajouter un tableau d'octets de 4 octets :
concatenateArrayToMessage(buffer_array, 4, tableau_array) ;

Ce code ne contient pas la partie permettant l'envoie du tableau d'octet.

# ENGLISH
By default, the size for the message is 30 bytes, but you can configure the defined "TABLEAU_SIZE" variable if needed.

To add any data type to the message array that will be sent, use convertTypeToArrayThenConcatenateToMessage with the variable name corresponding to the correct type, then put 0 for other types.
convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var, int int_var, long long_var, float float_var, double double_var, long double longdouble_var)
For example, to add a float value:
convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, float_var, 0, 0);

To add a byte array to the message array that will be sent, use concatenateArrayToMessage and specify the length of the array.
concatenateArrayToMessage(uint8_t buffer_array[], size_t size, uint8_t tableau_array[])
For example, to add a byte array of 4 bytes :
concatenateArrayToMessage(buffer_array, 4, tableau_array);

This code does not contain the part allowing the byte array to be sent.
