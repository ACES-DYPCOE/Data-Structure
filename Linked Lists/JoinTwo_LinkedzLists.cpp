//Given two linked lists of size n1 and n2 respectively, 
//you have to join the head of second list to the tail of first so that we can traverse both the lists using head of 1st list.

//solution
Node * joinTheLists(Node * head1, Node * head2)
{
    if(head1==NULL)
    head1=head2;
    
    Node* temp=head1;

    while(temp->next!=NULL)
    temp=temp->next;
    
    temp->next=head2;
    
    return head1;
}