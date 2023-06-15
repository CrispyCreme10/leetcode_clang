#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t);

int main() {
  bool result1 = isAnagram("anagram", "nagaram");
  printf("result1 is: %s\n", result1 ? "true" : "false");

  bool result2 = isAnagram("rat", "car");
  printf("result2 is: %s\n", result2 ? "true" : "false");
}

bool isAnagram(char* s, char* t) {
  int i, j;
  size_t sSize = strlen(s);
  size_t tSize = strlen(t);
  bool charFound = false;

  if (sSize != tSize) 
    return false;

  for (i = 0; i < sSize; i++) {
    for (j = i; j < sSize; j++) {
      if (*(t + j) == *(s + i)) {
        printf("found matching char %c at pos %d to init char %c at pos %d\n", *(t + j), j, *(s + i), i);
        if (j > i) {
          char temp = t[i];
          printf("test: %c %c", temp, t[j]);
          t[i] = &t[j];
          printf("test: %c %c", temp, t[j]);
          t[j] = temp;
          printf("test: %c %c", temp, t[j]);
        }
        charFound = true;
        break;
      }
    }

    printf("t: %s\n", t);
    if (!charFound)
      return false;
    charFound = false;
  }
}