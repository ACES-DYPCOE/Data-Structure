//Given a linked list of size n, you have to delete the tail (last element) in the linked list.
//solution

Node* deleteTail(Node *head)
{
    //empty linked list
    if(head==NULL)
    return head;

    Node* temp=head;
    while(temp->next->next!=NULL)
    temp=temp->next;
    
    delete temp->next;
    temp->next=NULL;
    
    return head;
}