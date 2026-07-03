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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;//for carry
        int sum=0;
        if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        //itne me dono agr null hua to bhi inhi se ho jayega handle
        ListNode *curr=NULL;
        ListNode *head=NULL;


        while(l1!=NULL and l2!=NULL ){

         sum=l1->val+l2->val+carry;
         carry=0;

         
         if(sum<=9){ 
             ListNode *nn= new ListNode(sum);
         if(head==NULL) head=nn;
         if(curr!=NULL) {curr->next=nn;
         curr=nn;}
         else{
            curr=head;
          }
          l1=l1->next;
          l2=l2->next;

         }

         else{//sum>9
         ListNode *nn=new ListNode(sum%10);
         carry=1;
         if(head==NULL) head=nn;
         if(curr!=NULL){
            curr->next=nn; curr=nn;
         }
         else{
            curr=head;
         }
           l1=l1->next;
          l2=l2->next;
         }
        //  Node *nn= new Node(sum);
        //  if(head==NULL) head=nn;
        //  if(curr!=NULL) {curr->next=nn;
        //  curr=nn;}
        //  else{
        //     curr=head;
        //  }
        }

    if(l1!=NULL){
       while(l1!=NULL)
         { sum=l1->val +carry;
          carry=0;
          if(sum<=9){
            ListNode *nn= new ListNode(sum);
         if(head==NULL) head=nn;
         if(curr!=NULL) {curr->next=nn;
         curr=nn;}
         else{
            curr=head;
          }
          l1=l1->next;
          

          }
          else{
            ListNode *nn=new ListNode(sum%10);
         carry=1;
         if(head==NULL) head=nn;
         if(curr!=NULL){
            curr->next=nn; curr=nn;
         }
         else{
            curr=head;
         }
           l1=l1->next;
         
         }
          }
    }
        
    else if(l2!=NULL){

while(l2!=NULL)
         { sum=l2->val +carry;
          carry=0;
          if(sum<=9){
            ListNode *nn= new ListNode(sum);
         if(head==NULL) head=nn;
         if(curr!=NULL) {curr->next=nn;
         curr=nn;}
         else{
            curr=head;
          }
          l2=l2->next;
          

          }
          else{
            ListNode *nn=new ListNode(sum%10);
         carry=1;
         if(head==NULL) head=nn;
         if(curr!=NULL){
            curr->next=nn; curr=nn;
         }
         else{
            curr=head;
         }
           l2=l2->next;
         
         }
          }


    }
    
        if(carry==0)return head;
        else{
            ListNode *nn=new ListNode(1);
            curr->next=nn;
            return head;
        }
    

        
    return head;
    }
};
