/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* sumListStart = NULL;
    struct ListNode* sumListEnd = NULL;
    struct ListNode* tempNode;

    int carry = 0;
    int sum = 0;
    int firstNode = 1;

    while (l1 || l2 || (carry != 0)) {

        tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempNode->next = NULL;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        if (carry) {
            sum += carry;
        }

        if (sum >= 10) {
            tempNode->val = sum % 10;
            carry = 1;
        } else {
            tempNode->val = sum;
            carry = 0;
        }
        if (firstNode) {
            sumListStart = sumListEnd = tempNode;
            firstNode = 0;
        } else {
            sumListEnd->next = tempNode;
            sumListEnd = tempNode;
        }
        sum = 0;
    }
    return sumListStart;
}
