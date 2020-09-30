//Given a circular linked list of size n, you have to delete the head of the linked list and return the new head.
//In the circular linked list the tail of the list is connected to the head using the next pointer.
//Note: Please also set the next of the original head to null.

//solution
Node * deleteHead(Node *head)
{
   if(head==NULL)
   return NULL;
   
   Node* temp=head;
   Node* temp1=head;
   while(temp->next!=head)  temp=temp->next;
   temp->next=temp1->next;
   head=temp1->next;
   temp1->next=NULL;
   return head;
}