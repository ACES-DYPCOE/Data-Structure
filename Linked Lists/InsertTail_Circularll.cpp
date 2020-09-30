//Given a circular linked list of size N, you need to insert an element data after the tail.
//The tail of the linked list is connected to head.

//solution
Node *insertInTail(Node * head, int data)
{
    Node* newn=new Node(data);
    if(head==NULL)
    {
        head=newn;
        newn->next=head;
    }
    else
    {
        Node* temp=head;
     
        while(temp->next!=head)
        {
             temp=temp->next;
        }
        temp->next=newn;
        newn->next=head;
    }
    return head;
}