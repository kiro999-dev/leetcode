
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode *NEXT;
            ListNode *curr;
            ListNode *prv;
            curr = head;
            prv = nullptr;
            NEXT = head;
            while (NEXT!= nullptr)
            {
                NEXT = curr->next;
                curr->next = prv;
                prv = curr;
                curr = NEXT;
            }
            return prv;
        }
    };