
//solution
int length(Node* head)
{
int ct=0;
if(head==NULL) return ct;

Node* temp=head;
do{
ct++;
temp=temp->next;
}while(temp!=head);

return ct;
}