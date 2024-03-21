#include <stdio.h>
#include <stdlib.h>

int main() {
  // Open the file for writing
  FILE *fp;
   fp = fopen("random.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Generate a random number
  int random_number = rand();

  // Write the random number to the file
  fprintf(fp, "%d\n", random_number);

  // Close the file
  fclose(fp);

  return 0;
}
