//Given a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.
//solution

bool isCircular(Node *head)
{
   if(head==NULL || head->next==head) return true;
   Node* temp=head;
   while(temp->next!=NULL && temp->next!=head)
   temp=temp->next;
   
   return (temp->next==head)?true:false;
}