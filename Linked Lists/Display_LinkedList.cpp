//Given a singly linked list of integers. The task is to display the linked list.
//solution code snippet


vector<int> displayList(Node *head)
{
    vector<int>v;
    //empty linked list
    if(head==NULL)
    return v;
    Node* temp=head;
    while(temp!=NULL)
    {
        int val=temp->data;
        v.push_back(val);
        temp=temp->next;
    }
    return v;
}