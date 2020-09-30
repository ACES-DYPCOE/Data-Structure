//Given a circular linked list of size N, you need to insert an element data before the head and make it the new head. The tail of the linked list is connected to head.

//solution
Node *insertInHead(Node * head, int data)
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
        do{
            temp=temp->next;
        }while(temp->next!=head);
        newn->next=head;
        head=newn;
        temp->next=head;
    }
    return head;
}