#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node *next;
	
	node(int value)
	{
		data=value;
		next=NULL;
	}

};

 int count(node *head)
 {
 	int count=0;
 	while(head!=NULL)
 	{
 	count++	;
 	head=head->next;
	 }
	 cout<<endl<<"Total number of node are : "<<count<<endl;
 }
 int ithnode(node *head)
 {
 	int index,c=0;
 	cout<<"Enter the index of node : ";
 	cin>>index;
 	if(index<0)
 	{
 		exit(0);
	 }
    if(head==NULL)
    cout<<"No node present "<<endl;
    while(c!=index)
    {
    head=head->next;
	c++;	
	}
   cout<<"data at ith node is "<<head->data<<endl; 
 }
void print(node *head)
{
   while(head!=NULL)
   {
   	cout<<head->data<<" ";
   	head=head->next;
   }
}

node* takeinput_better()// o(n) time
{
	int data;
	cin>>data;
	node *head=NULL;
	node *tail=NULL;
	while(data!=-1)
	{
	       node *newnode=new node(data);
		   if(head==NULL)
		   {
		   	head=newnode;
		   	tail=newnode;
		   }	
	       else
		   {
			   	tail->next=newnode;
			   	tail=tail->next;
			   }
			   cin>>data;
	}
	return head;
}

 node* insertithnode(node *head,int i,int data)
{
	node *newnode=new node(data);
	int count=0;
	node *temp=head;
	if(i==0)
	{
		newnode->next=head;
		head=newnode;
		return head;
	}
	
	while(temp!=NULL&& count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		node *a=temp->next;
		temp->next=newnode;
		newnode=a;
	}
	return head;
}
int main()
{
		int countvalue;
//	node *head=takeinput();
    node *head=takeinput_better();
	print(head);
	
	count(head);
	
	ithnode(head);
	
	int i, data;
	cin >> i >> data;
	
head=insertithnode(head ,i,data);
	
	print(head);	

}
