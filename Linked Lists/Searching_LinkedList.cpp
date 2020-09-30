//Search given element in Linked list
//solution

bool searchLinkedList(Node *head, int x)
{
   int pos=1;
   Node* temp=head;
   while(temp!=NULL)
   {
       if(temp->data==x)
       return pos;
       else
       {
           pos++;
           temp=temp->next;
       }
   }
    return 0;   
}