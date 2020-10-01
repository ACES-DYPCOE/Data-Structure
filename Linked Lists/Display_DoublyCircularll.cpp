void displayList(Node *head)
{
    vector<int>v;
    Node* temp=head;
    while(temp->next!=head)
    {
        v.push_back(temp->data);
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    v.push_back(temp->data);
    cout<<endl;
    for(int i=v.size()-1;i>=0;i--)
    cout<<v[i]<<" ";

}