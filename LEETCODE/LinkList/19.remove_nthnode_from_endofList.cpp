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
        ListNode *p1=head;
        ListNode *p2=head;
        //check edge case later on 
        if(n==1 and (head==NULL or head->next==NULL)) return NULL;

         while(n>1){
                p2=p2->next;
                n--;
            }
            //manlo p2 last me phuch gya
            if(p2->next==NULL) {
                //first element hatana nhia 
                p1=p1->next;
                head=p1;
                return head;
               
            }
            else if(p2->next->next==NULL){//p2 at last sec
                //2nd element htana hai 
                p1->next=p1->next->next;
                return head;
            }
        else{
        while (p2->next->next!=NULL){
            // while(n>0){
            //     p2=p2->next;
            // }
                p1=p1->next;
                p2=p2->next;

        }//jisko hatana hai p1 us se ek pehel hai 
        }
        p1->next=p1->next->next;
        return head;
    }
};
//1. array
//2.stack
//************3.) do pointer lo , start head pe , and dono ke beech ke diff ko n kro, means ek ko n baar aage le jao , fir dono ko badhana start kr do , and jab aage waala, edn pe hoga then piche wala nth pe hoga //
// ************    **********    ***********
// beetr is , ki end tk nhi end-1 tk chlo , so now u know , ki piche wala jo pointer hai uske aage wala htana hai 
