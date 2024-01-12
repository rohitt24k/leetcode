/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        if(head->next == NULL)  return head;

   ListNode *slowPointer = head;
   ListNode *fastPointer = head;

   int listLength = 1; // Calculate list length
  while (fastPointer->next != NULL) {
    listLength++;
    fastPointer = fastPointer->next;
  }

  k = k % listLength; // Ensure k is within list bounds
  fastPointer = head;
  
  for (int i = 0; i < k; i++) {
    fastPointer = fastPointer->next; // Move fastPointer for k positions
  }

   while(fastPointer->next != NULL){
     slowPointer = slowPointer -> next;
     fastPointer = fastPointer -> next;
   }
   fastPointer->next = head;
   head = slowPointer->next;
   slowPointer->next = NULL;
   return head;
    }
};