//Given a singly linked list of size N. The task is to sum the elements of the linked list.
//solution

int sumOfElements(Node *head)
{
   int sum=0;
   if(head==NULL)
   return 0;
   Node* temp=head;
   while(temp!=NULL)
   {
       sum=sum+temp->data;
       temp=temp->next;
   }
   return sum;
}