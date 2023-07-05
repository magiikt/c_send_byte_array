#include <stdint.h>
#include <stdio.h>

// global variables
#define MESSAGE_SIZE 30
uint8_t message[MESSAGE_SIZE];
int position = 0;

//-------------------------------------------------//
//---------------printArrayElements----------------//
//-------------------------------------------------//
// printArrayElements prints every elements of an array in a row. This function
// is used as debugging.
void printArrayElements(uint8_t array[]) {
  for (int i = 0; i < MESSAGE_SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

//-------------------------------------------------//
//------------concatenateArrayToMessage------------//
//-------------------------------------------------//
/*
// WITH SIZES BEFORE VALUE BYTES
void concatenateArrayToMessage(uint8_t buffer_array[], size_t size,
                               uint8_t message_array[]) {
  if ((position + size) < MESSAGE_SIZE) {
    uint8_t size_array[1] = {size};
    memcpy(message_array + position, size_array, size);
    memcpy(message_array + position + 1, buffer_array, size);
    position = position + size + 1;
  } else {
    return;
  }
}
*/

// WITHOUT SIZES BEFORE VALUE BYTES
void concatenateArrayToMessage(uint8_t buffer_array[], size_t size,
                               uint8_t message_array[]) {
  if ((position + size) < MESSAGE_SIZE) {
    memcpy(message_array + position, buffer_array, size);
    position = position + size;
  } else {
    return;
  }
}

//-------------------------------------------------//
//---convertTypeToArrayThenConcatenateToMessage----//
//-------------------------------------------------//
void convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var,
                                                int int_var, long long_var,
                                                float float_var,
                                                double double_var,
                                                long double longdouble_var) {
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    printf("No parameters set.");
    return;
  }
  // char
  if (!(char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 1;
    uint8_t buffer[1];
    memcpy(buffer, (unsigned char *)(&char_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // short
  if ((char_var == 0) && !(short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 2;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&short_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // int
  if ((char_var == 0) && (short_var == 0) && !(int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 2;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&int_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // long
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      !(long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 4;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&long_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // float
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && !(float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 4;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&float_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // double
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && !(double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 8;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&double_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  // longdouble
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      !(longdouble_var == 0)) {
    size_t size = 10;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&longdouble_var), size);
    concatenateArrayToMessage(buffer, size, message);
    return;
  }
  printf("Multiple parameters set. Please set only one parameters with "
         "variable, and the others with '0'.");
  return;
}

//-------------------------------------------------//
//----------------------main-----------------------//
//-------------------------------------------------//
int main(void) {
  // convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var,
  // int int_var, long long_var, float float_var, double double_var, long double
  // longdouble_var)

  // concatenateArrayToMessage(uint8_t buffer_array[], size_t size, uint8_t
  // message_array[])

  // In this example, a float variable is converted in an array of bytes.
  float fl = 24.747431;

  convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, fl, 0, 0);
  printArrayElements(message);

  // This next lines are decoding the array bytes in a float variable.
  uint8_t bytes[4] = {message[0], message[1], message[2], message[3]};
  float decoded_float;
  memcpy(&decoded_float, bytes, 4);
  printf("%f", decoded_float);

  return 0;
}
