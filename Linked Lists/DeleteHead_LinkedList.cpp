//Given a linked list of size n, you have to delete the head of the linked list and return the new head.
//Note: Please also set the next of the original head to null.

Node* deleteHead(Node *head)
{
    Node* temp=head->next;
    head->next=NULL;

    delete head;
    
    return temp;
}