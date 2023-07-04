#include <stdint.h>
#include <stdio.h>

#define TABLEAU_SIZE 30

uint8_t tableau[TABLEAU_SIZE];
//float fl = 15.39;
//float fl2 = 13.37;
//float fl3 = 19.64;
int position = 0;

void printContenuTableau(uint8_t array[]) {
  for (int i = 0; i < TABLEAU_SIZE ; i++) {
    printf("%d ", array[i]);
  }
}

void concatenateArrayToMessage(uint8_t buffer_array[], size_t size, uint8_t tableau_array[]) {
  if ((position+size) < TABLEAU_SIZE) {
  uint8_t size_array[1] = {size};
  memcpy(tableau_array+position, size_array, size);
  memcpy(tableau_array+position+1, buffer_array, size);
  position = position+size+1;
  } else {
    return;
  }
}

void convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var, int int_var, long long_var,
                 float float_var, double double_var, long double longdouble_var) {
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    printf("Aucun paramètre renseigné.");
    return;
  }
  //char
  if (!(char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 1;
    uint8_t buffer[1];
    memcpy(buffer, (unsigned char *)(&char_var),size);
    //char length = (sizeof(buffer) / sizeof(buffer[0]));
    //printf("%d \n", length);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //short
  if ((char_var == 0) && !(short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 2;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&short_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //int
  if ((char_var == 0) && (short_var == 0) && !(int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 2;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&int_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //long
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      !(long_var == 0) && (float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 4;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&long_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //float
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && !(float_var == 0) && (double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 4;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&float_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //double
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && !(double_var == 0) &&
      (longdouble_var == 0)) {
    size_t size = 8;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&double_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  //longdouble
  if ((char_var == 0) && (short_var == 0) && (int_var == 0) &&
      (long_var == 0) && (float_var == 0) && (double_var == 0) &&
      !(longdouble_var == 0)) {
    size_t size = 10;
    uint8_t buffer[size];
    memcpy(buffer, (unsigned char *)(&longdouble_var),size);
    concatenateArrayToMessage(buffer, size, tableau);
    return;
  }
  printf("Plusieurs paramètres renseignés.");
  return;
}

int main(void) {
  //convertTypeToArrayThenConcatenateToMessage(char char_var, short short_var, int int_var, long long_var, float float_var, double double_var, long double longdouble_var)
  
  convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, fl, 0, 0);
  printContenuTableau(tableau);
  printf("\n");

  convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, fl2, 0, 0);
  printContenuTableau(tableau);
  printf("\n");

  convertTypeToArrayThenConcatenateToMessage(0, 0, 0, 0, fl3, 0, 0);
  printContenuTableau(tableau);
  printf("\n");
  return 0;
}