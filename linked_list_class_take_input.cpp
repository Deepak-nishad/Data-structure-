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

/*node* takeinput() //o(n2) time
{
	int data;
	cin>>data;
	node *head=NULL;
	while(data!=-1)
	{
	       node *newnode=new node(data);
		   if(head==NULL)
		   {
		   	head=newnode;
		   }	
	       else
		   {
			   	node *temp=head;
			   	while(temp->next!=NULL)
		   	{
			   		temp=temp->next;
		      }
		      temp->next=newnode;
			   }
			   cin>>data;
	}
	return head;
}*/
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
int main()
{
//	node *head=takeinput();
    node *head=takeinput_better();
	print(head);
}
