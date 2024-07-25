/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct numIndexVal {
    int index;
    int val;
} numIndexVal;

int comparator(void* a, void* b) {
    numIndexVal ta = *(numIndexVal*)a;
    numIndexVal tb = *(numIndexVal*)b;

    if (ta.val > tb.val) {
        return 1;
    } else if (ta.val < tb.val) {
        return -1;
    }
    return 0;
}


int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  /*
     target = x + y;
     => y = target - x;
     search for y, for every x in the array.
 */

  int *sumPair = (int *)malloc(sizeof(int) * 2);
  *returnSize = 2;

  // Approach1. using sorting and two pointer technique
  numIndexVal nStore[numsSize];
  for (int i = 0; i < numsSize; i++) {
    nStore[i].val = *(nums + i);
    nStore[i].index = i;
  }

  qsort(nStore, numsSize, sizeof(numIndexVal), comparator);
  // somehow we need to store the original index of the elements to pass this?
  printf("After qsort\n");

  int l = 0;
  int r = numsSize - 1;
  while (l < r) {
    if (nStore[l].val + nStore[r].val == target) {
      *(sumPair + 0) = nStore[l].index;
      *(sumPair + 1) = nStore[r].index;
      return sumPair;
    } else if (nStore[l].val + nStore[r].val < target)
      l++;
    else
      r--;
  }
  return NULL;
}
