//Given a circular linked list of size n, you have to delete the tail (last element) in the linked list.
//In a circular linked list, the tail is connect to the head using the next pointer.

//solution
Node * deleteTail(Node * head)
{
    if(head==NULL)  return NULL;
    
    Node* temp=head;
    while(temp->next->next!=head) temp=temp->next;
    temp->next=head;
    return head;
}