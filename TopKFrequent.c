/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hashTable {
    int key;
    int value;
} hTable;

int hash(int key) { return abs(key); }

void hashPut(hTable* hT, int numsSize, int key) {
    int hashKey = hash(key);
    int hashIndex = hashKey % numsSize;

    while (hT[hashIndex].value != 0) {
        if (hT[hashIndex].key == key) {
            // increment the frequency of the element.
            hT[hashIndex].value += 1;
            return;
        } else {
            hashIndex++;
        }
        if (hashIndex == numsSize) {
            hashIndex = 0;
        }
    }
  
    hT[hashIndex].key = key;
    hT[hashIndex].value = 1;
}

int comparator(void* a, void* b) {
    return (((hTable*)b)->value - ((hTable*)a)->value);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    /* Hash table to store the (nums, frequency) pair,
    sort the hash table based on the frequency in decreasing order
    print first k elements after sorting
    */
  
    hTable hT[numsSize] = {};

    int *returnNums = (int*)malloc(sizeof(int) * k);
    *returnSize = k;

    for (int i; i < numsSize; i++) {
        hashPut(hT, numsSize, nums[i]);
    }

    qsort(hT, numsSize, sizeof(hTable), comparator);

    for (int i; i < k; i++) {
        returnNums[i] = hT[i].key;
    }

    return returnNums;
}
