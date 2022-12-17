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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1=list1,*curr2=list1;
        a--;
        while(a-- && curr1->next!=NULL)
        {
            curr1=curr1->next;
        }
        while(b-- && curr2!=NULL)
        {
            curr2=curr2->next;
        }
        ListNode* lst=list2;
        while(lst->next!=NULL)
        {
            lst=lst->next;
        }
        curr1->next=list2;
        lst->next=curr2->next;
        
        return list1;
    }
};