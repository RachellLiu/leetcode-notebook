/****************************************************************

  24. Swap Nodes in Pairs
  
*****************************************************************/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            tmp1->next = tmp2;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};

/*******************************************************************************

  19. Remove Nth Node From End of List
  
  用快慢指针，快指针先跑n+1下，然后和慢指针一起，最终快到达最后，慢指针就是倒数第n个的前一个
  
********************************************************************************/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
    }
};

/*****************************************************************************************

  02.07. Intersection of Two Linked Lists LCCI
  
  先分别求长度，然后算长度差gap，把长的那条先跑gap下，使得末端是对齐的，然后再一起往后找相同的节点，
  遇到相同的直接返回
  
******************************************************************************************/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* curA = headA;
      ListNode* curB = headB;
      int lenA = 0, lenB = 0;
      while (curA != NULL) {
          lenA++;
          curA = curA->next;
      }  
      while (curB != NULL) {
          lenB++;
          curB = curB->next;
      }
      curA = headA;
      curB = headB;
      if (lenA < lenB) {
          swap(lenA, lenB);
          swap(curA, curB);
      }
      int gap = lenA - lenB;
      while (gap--) {
          curA = curA->next;
      }
      while(curA != NULL) {
          if (curA == curB) {
              return curA;
          }
          curA = curA->next;
          curB = curB->next;
      }
      return NULL;
    }
};

/*****************************************************************************************

  142. Linked List Cycle II
  
  
  
******************************************************************************************/

