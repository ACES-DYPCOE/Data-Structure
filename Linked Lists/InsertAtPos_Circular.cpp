//You are given a circular linked list of size N. You need to insert an element data just after the given position pos.
//The position of first element is 1. If the given position is greater than N, then don't insert anything as it is not possible.
//As the given linked list is circular, it means that the tail is connected to the head of the lis

//solution
void insertAtPosition(Node *head, int pos, int data)
{
    Node *temp=new Node(data);
    Node *cur=head;
    int i;
if(pos==1)
{
if(head==NULL)
return ;
if(head->next==head)
{
temp->next=head;
head->next=temp;
return ;
}
temp->next=head->next;
head->next=temp;
}
else{
for(i=0;i<pos-1;i++) {
cur=cur->next;
if(cur==head){
return ;
}

}
temp->next=cur->next;
cur->next=temp;
} 
}