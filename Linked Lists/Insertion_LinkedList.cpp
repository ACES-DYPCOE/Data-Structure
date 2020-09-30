//Insertion at front and end of Linked List
//solution

//function inserts the data in front of the list
Node *insertAtBegining(Node *head, int newData) {
   Node *newn=new Node(newData);
   if(head==NULL)
        head=newn;
      else
   {
       newn->next=head;
       head=newn;
   }
   return head;
}

// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
  Node *newn=new Node(newData);
  if(head==NULL)
     head=newn;
   else
   {
       Node* temp=head;
       while(temp->next!=NULL)
           temp=temp->next;

       temp->next=newn;
   }
   return head;
}