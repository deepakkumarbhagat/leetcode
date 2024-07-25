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

/* Approach 2.
    Using hash table without altering the original array.

int hash(int key) { return abs(key); }

typedef struct hashTable {
 int key;
 int value;
} hT;

hT* hash_create(int capacity) {
 hT* hTbl = malloc(sizeof(hT) * capacity);
 memset(hTbl, -1, sizeof(hT) * capacity);
 return hTbl;
}

void hash_put(hT* hT, int capacity, int key, int value) {
 int hash_key = hash(key);
 int hash_index = hash_key % capacity;

 while (hT[hash_index].key != -1) {
     if (hT[hash_index].key == key) { // it's an update
         return;
     } else {
         // the kye is different , try to place it in the next index
         hash_index += 1; // liner probing
     }
     if (hash_index >= capacity) {
         hash_index = 0;
     }
 }
 hT[hash_index].key = key;
 hT[hash_index].value = value;
}

int hash_get(hT* hT, int capacity, int key) {
 int hash_key = hash(key);
 int hash_index = (hash_key % capacity);

 while (hT[hash_index].key != -1) {
     if (hT[hash_index].key == key) {
         return hT[hash_index].value;
     } else {
         // the kye is different , try to place it in the next index
         hash_index += 1; // liner probing
     }
     if (hash_index >= capacity) {
         hash_index = 0;
     }
 }
 return -1;
}
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /*
      target = x + y;
      => y = target - x;
      search for y, for every x in the array.
    */

    int* sumPair = (int*)malloc(sizeof(int) * 2);
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

    /* Approach 2.
    Using hashTable without alreating the original array
     target = x + y;
     => y = target - x;
     search for y, for every x in the array.

    hT* hTbl = hash_create(numsSize);
    int diff = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        diff = target - nums[i];
        if (index = hash_get(hTbl, numsSize, diff) != -1) {
            *(sumPair + 0) = index;
            *(sumPair + 1) = i;
            return sumPair;
        } else {
            hash_put(hTbl, numsSize, nums[i], i);
        }
    }
    */
    return NULL;
}
