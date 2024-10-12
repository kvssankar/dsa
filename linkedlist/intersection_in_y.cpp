int intersectPoint(Node* head1, Node* head2)
{
    Node *ptr1=head1;
    Node *ptr2=head2;
    if(head1==NULL || head2==NULL)
    return -1;
    int count1=1,count2=1;
    while(ptr1->next!=NULL){
        count1++;
        ptr1=ptr1->next;
    }
    while(ptr2->next!=NULL){
        count2++;
        ptr2=ptr2->next;
    }
    ptr1=head1;
    ptr2=head2;
    int d=abs(count1-count2);
    if(count1>count2){
        for(int i=0;i<d;i++){
            if(ptr1==NULL)
            return -1;
            ptr1=ptr1->next;
        }
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2){
                return ptr1->data;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return -1;
    }else{
        for(int i=0;i<d;i++){
            if(ptr2==NULL)
            return -1;
            ptr2=ptr2->next;
        }
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1==ptr2){
                return ptr1->data;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return -1;
    }
}