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
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        if(head->next==NULL) return head->val;
        ListNode* temp=head;
        string num="";
        while(temp!=NULL){
            int dig=temp->val;
            num+=to_string(dig);
            temp=temp->next;
        }
        int ans=0;
        for(int i=0; i<num.size(); i++){
            ans+=(pow(2, i)*(num[num.size()-i-1]-'0'));
        }
        return ans;
    }
};