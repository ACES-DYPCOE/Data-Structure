//Given a doubly linked list of size n, you have to delete the head of the linked list and return the new head.
//Note: Please set the previous of new head to null, and set the next of old head to null, and then delete the old head.

Node *deleteHead(Node * head)
{
   if(head==NULL) return NULL;
   Node* temp=head;
   
   head=temp->next;
   head->prev=NULL;
   
   delete temp;
   return head;
}