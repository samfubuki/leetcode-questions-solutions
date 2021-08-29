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
    ListNode* partition(ListNode* head, int x) {
      ListNode* small = new ListNode(0);
      ListNode* higher = new ListNode(0);
      ListNode* smallhead = small;
      ListNode* higherhead = higher;
      while(head!=NULL)
      {
          if(head->val<x)
          {
              smallhead->next=head;
              smallhead=smallhead->next;
          }
         else
         {
             higherhead->next = head;
             higherhead = higherhead->next;
         }
        head=head->next;
      }
      higherhead->next = NULL;
      smallhead->next = higher->next;
      return small->next;
    }
};
