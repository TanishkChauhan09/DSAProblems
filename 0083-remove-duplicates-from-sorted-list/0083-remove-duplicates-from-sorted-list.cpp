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
   
    ListNode *find(ListNode *&head)
    {
        ListNode *curr = head;
        ListNode *temp;

        while(curr && curr->next)
        {
            temp = curr->next;
            if(curr->val == temp->val)
            {
                curr->next = temp->next;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {

     find(head);
     return head;
        
    }
};