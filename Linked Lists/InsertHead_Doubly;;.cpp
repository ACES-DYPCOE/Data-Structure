//Given a doubly linked list of size n, you need to insert an element data before the head and make it the new head.

//solution
Node *insertInHead(Node * head, int data)
{
    Node* newn = new Node(data);
    
    if(head==NULL)
    head=newn;
    else
    {
        Node* temp=head;
        newn->next=head;
        head->prev=newn;
        head=newn;
    }
    return head;
}