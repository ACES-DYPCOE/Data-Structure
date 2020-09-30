//Given a linked list of size n, you have to delete the node at position pos of the linked list and return the new head. The position of initial node is 1.
//The tail of the circular linked list is connected to the head using next pointer.

//solution
Node * deleteAtPosition(Node *head,int pos)
{
if(pos==1)
{
if(head->next==head)
return NULL;
Node *temp=head->next;
head->next=head->next->next;
delete(temp);
return head;
}
else
{
Node *temp=head;
Node *cur;
for(int i=0;i<pos-2;i++) temp=temp->next;
cur=temp->next;
temp->next=temp->next->next;
delete(cur);
return head;
}
}