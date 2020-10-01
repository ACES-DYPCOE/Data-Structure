int level=1;
// int size;
if(root==nullptr)
{
cout<<"\n";
return ;
}
queue<node *=""> q;
q.push(root);
while(1){
int size=q.size();
if(size==0)
break;
while(size>0){
Node *temp=q.front();
if(level%2!=0)
cout<<temp->data<<" ";
q.pop();
if(temp->left)
q.push(temp->left);
if(temp->right)
q.push(temp->right);
size--;
}
level++;
