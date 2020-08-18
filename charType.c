/*
* Name: Anthony Wong
* CruzID: 1652596
* Class: 12M
* Date: 7 Feb 2019
* Desc: Reads file and prints the number of each type of character in the file in a new output file.
* File Name: charType.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_STRING_LENGTH 256

/* copies characters from string s into appropriate output arrays a (alphabetic), d (digits), p (punctuation), or w (whitespace).*/
void extract_chars(char* s, char* a, char* d, char* p, char* w) {
  int i = 0, j = 0, k = 0, l = 0, m = 0;
  while(s[i] != '\0' && i < MAX_STRING_LENGTH) {
      if (isalpha((int) s[i])) a[j++] = s[i];  // if character is alphabetic
      if (isdigit((int) s[i])) d[k++] = s[i];  // if character is numeric
      if (ispunct((int) s[i])) p[l++] = s[i];  // if character is punctuation
      if (isspace((int) s[i])) w[m++] = s[i];  // if character is whitespace
      i++;
  }
  a[j] = '\0';
  d[k] = '\0';
  p[l] = '\0';
  w[m] = '\0';
}

void print(FILE* out, char* s, char* type) {
  int i = 0;
  while (s[i] != '\0') {  // calculates length of string
    i++;
  }

  if (i == 1) {
    fprintf(out, "%d %s character: %s\n", i, type, s);
  }
  else {
    fprintf(out, "%d %s characters: %s\n", i, type, s);
  }
}

int main(int argc, char* argv[]) {
  FILE* in;  // input file
  FILE* out; // output file
  char* line;  // string holding input line
  int lineNum = 1; // keeps track of what line number program is on
  char* alpha; // string holding all alphabetic chars
  char* numeric; // string holding all numeric characters
  char* punct; // string holding all punctuation characters
  char* ws; // string holding all whitespace characters

  // check command line for correct number of arguments
  if (argc != 3) {
    printf("Usage: %s input-file output-file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // open input file for reading
  if ((in = fopen(argv[1], "r")) == NULL) {
    printf("Unable to read from file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // open output file for writing
  if ((out = fopen(argv[2], "w")) == NULL){
    printf("Unable to write to file %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  // allocate strings on the heap
  line = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  alpha = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  numeric = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  punct = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  ws = calloc(MAX_STRING_LENGTH+1, sizeof(char));
  assert(line != NULL && alpha != NULL  && numeric != NULL && punct != NULL && ws != NULL);

  // read each line in input file
  while (fgets(line, MAX_STRING_LENGTH, in) != NULL) {
    extract_chars(line, alpha, numeric, punct, ws);
    fprintf(out, "line %d contains:\n", lineNum);
    print(out, alpha, "alphabetic");
    print(out, numeric, "numeric");
    print(out, punct, "punctuation");
    print(out, ws, "whitespace");
    fprintf(out, "\n");
    lineNum++;
  }

  // free heap memory
  free(line);
  free(alpha);
  free(numeric);
  free(punct);
  free(ws);

  // close input and output files
  fclose(in);
  fclose(out);

  return EXIT_SUCCESS;
}
