//Given a doubly linked list of size n, you need to insert an element data after the tail.
//solution

Node *insertInTail(Node * head, int data)
{
   Node* newn=new Node(data);
   
   if(head==NULL)
   head=newn;
   else
   {
       Node* temp=head;
       while(temp->next!=NULL)
       temp=temp->next;
       
       temp->next=newn;
       newn->prev=temp;
   }
   return head;
}