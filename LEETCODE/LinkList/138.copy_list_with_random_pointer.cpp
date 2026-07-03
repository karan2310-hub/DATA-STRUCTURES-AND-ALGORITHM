/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
     Node *curr=head;
     if(head == NULL) return NULL;
     while(curr!=NULL){
        Node *nn=new Node(curr->val);
        nn->next=curr->next;
        curr->next=nn;
        curr=nn->next;
     }//a->a'->b->b'->c->c'->d->d' format done

     //aab random fix kro 
     Node *c=head->next;
     curr=head;
     while(curr!=NULL){
        if(curr->random==NULL) c->random=NULL;
        else{
       c->random=curr->random->next;
        }
        if(c->next==NULL) break;
        curr=c->next;
        c=curr->next;
     }

     head=head->next;
     curr=head;
     if(curr->next==NULL)return head;
     else{
     while(curr->next!=NULL){//revisit dikkt
        curr->next=curr->next->next;
        curr=curr->next->next;
     }
     }
  return head;

    }
};
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//       Node *curr=head;
//       Node *h2=NULL;
//       unordered_map<Node*, Node*>mp;
//       while(curr!=NULL){
//         mp[curr]=new Node(curr->val);
//         curr=curr->next;

//       }
//       curr=head;
//       while(curr!=NULL){
//         mp[curr]->next=mp[curr->next];
//         mp[curr]->random=mp[curr->random];
//         curr=curr->next;
//       }
//       h2=mp[head];
//       return h2;
//     }
// };

//2 methods:-
//1) map use to link old and new node
//2) -> optimised:- a->a'->b->b'->c->c'->d->d'
