#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

bool isAnagram(char* s, char* t) {
  int i, j;
  size_t sSize = strlen(s);
  size_t tSize = strlen(t);
  bool charFound = false;

  if (sSize != tSize) 
    return false;

  for (i = 0; i < sSize; i++) {
    // printf("t: %s\n", t);
    for (j = i; j < sSize; j++) {
      if (*(t + j) == *(s + i)) {
        // printf("found matching char %c at pos %d to init char %c at pos %d\n", *(t + j), j, *(s + i), i);
        if (j > i) {
          swap(&t[i], &t[j]);
        }
        charFound = true;
        break;
      }
    }

    if (!charFound)
      return false;
    charFound = false;
  }

  return true;
}

int main() {
  char str1[] = "anagram";
  char str2[] = "nagaram";
  bool result1 = isAnagram(str1, str2);
  printf("result1 is: %s\n", result1 ? "true" : "false");

  char str3[] = "rat";
  char str4[] = "car";
  bool result2 = isAnagram(str3, str4);
  printf("result2 is: %s\n", result2 ? "true" : "false");
}
