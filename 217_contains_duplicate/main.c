#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int*, int);
void printArr(int*, int);

int main() {
  int input1[4] = {1,2,3,1};
  bool result1 = containsDuplicate(input1, 4);
  printf("result1 is: %s\n", result1 ? "true" : "false");

  int input2[4] = {1,2,3,4};
  bool result2 = containsDuplicate(input2, 4);
  printf("result2 is: %s\n", result2 ? "true" : "false");

  int input3[10] = {1,1,1,3,3,4,3,2,4,2};
  bool result3 = containsDuplicate(input3, 10);
  printf("result3 is: %s\n", result3 ? "true" : "false");

  return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
  int i, j;
  bool swapped;

  for (i = 0; i < numsSize - 1; i++) {
    swapped = false;
    printf("preswap arr: ");
    printArr(nums, numsSize);
    for (j = 0; j < numsSize - i - 1; j++) {
      if (*(nums + j) == *(nums + j + 1)) {
        return true;
      }

      if (*(nums + j) > *(nums + j + 1)) {
        // swap
        int temp = *(nums + j);
        *(nums + j) = *(nums + j + 1);
        *(nums + j + 1) = temp;
        swapped = true;

        printf("swapped %d and %d\n", *(nums + j), *(nums + j + 1));
      }
    }

    if (!swapped)
      break;
  }

  return false;
}

void printArr(int* arr, int size) {
  printf("[");
  int i;
  for (i = 0; i < size; i++) {
    printf("%d", *(arr + i));
    if (i < size - 1) {
      printf(",");
    }
  }
  printf("]\n");
}