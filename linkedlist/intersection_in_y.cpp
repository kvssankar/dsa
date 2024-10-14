/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int difference(ListNode *headA, ListNode *headB){
        int a=0,b=0;
        while(headA!=NULL || headB!=NULL){
            if(headA){
                a++;
                headA=headA->next;
            }
            if(headB){
                b++;
                headB=headB->next;
            }
        }
        return a-b;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff =  difference(headA,headB);
        if(diff>0){
            while(diff-- >0) headA=headA->next;
        }
        else{
            while(diff++ <0) headB=headB->next;
        }
        while(headA && headB && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

// int intersectPoint(Node* head1, Node* head2)
// {
//     Node *ptr1=head1;
//     Node *ptr2=head2;
//     if(head1==NULL || head2==NULL)
//     return -1;
//     int count1=1,count2=1;
//     while(ptr1->next!=NULL){
//         count1++;
//         ptr1=ptr1->next;
//     }
//     while(ptr2->next!=NULL){
//         count2++;
//         ptr2=ptr2->next;
//     }
//     ptr1=head1;
//     ptr2=head2;
//     int d=abs(count1-count2);
//     if(count1>count2){
//         for(int i=0;i<d;i++){
//             if(ptr1==NULL)
//             return -1;
//             ptr1=ptr1->next;
//         }
//         while(ptr1!=NULL && ptr2!=NULL){
//             if(ptr1==ptr2){
//                 return ptr1->data;
//             }
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//         return -1;
//     }else{
//         for(int i=0;i<d;i++){
//             if(ptr2==NULL)
//             return -1;
//             ptr2=ptr2->next;
//         }
//         while(ptr1!=NULL && ptr2!=NULL){
//             if(ptr1==ptr2){
//                 return ptr1->data;
//             }
//             ptr1=ptr1->next;
//             ptr2=ptr2->next;
//         }
//         return -1;
//     }
// }