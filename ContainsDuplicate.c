/* Approach 1 */
/* Sort and compare the consecutive elements */
int comparator(void *a, void *b) { return (*(int *)a - *(int *)b); }

bool containsDuplicate(int *nums, int numsSize) {

  qsort(nums, numsSize, sizeof(int), comparator);

  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == nums[i - 1]) {
      return true;
    }
  }
  return false;
}

/* Approach 2 */
/* Using hashtable to store and compare elements */
#if 0
typedef struct hashTable {
  int key;
  bool value;
} hTbl;

int hash(int key) { return abs(key); }

bool hashGet(hTbl *hT, int numsSize, int key) {
  int hashKey = hash(key);
  int hashIndex = (hashKey % numsSize);

  while (hT[hashIndex].value != false) {
    if (hT[hashIndex].key == key) {
      return true;
    } else {
      hashIndex++;
    }
    if (hashIndex >= numsSize) {
      hashIndex = 0;
    }
  }
  return false;
}

void hashPut(hTbl *hT, int numsSize, int key) {
  int hashKey = hash(key);
  int hashIndex = (hashKey % numsSize);

  while (hT[hashIndex].value != false) {
    if (hT[hashIndex].key == key) {
      return;
    } else {
      hashIndex++;
    }
    if (hashIndex >= numsSize) {
      hashIndex = 0;
    }
  }

  hT[hashIndex].key = key;
  hT[hashIndex].value = true;
}

bool containsDuplicate(int *nums, int numsSize) hTbl hT[numsSize];

for (int i = 0; i < numsSize; i++) {
  hT[i].value = false;
}

for (int i = 0; i < numsSize; i++) {
  if (hashGet(hT, numsSize, nums[i])) {
    return true;
  } else {
    hashPut(hT, numsSize, nums[i]);
  }
}

return false;
}
#endif
