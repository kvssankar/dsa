// will take u to nth node
// count =2
// a B c
for(int i=1;i<count;i++){
    if(ptr==NULL) break;
    ptr=ptr->next;
}

//will take to last node
while(ptr->next!=NULL){
    ptr=ptr->next;
}

//will get out of list
while(ptr!=NULL){
    ptr=ptr->next;
}