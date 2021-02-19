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
void print(node *head)
{
   while(head!=NULL)
   {
   	cout<<head->data<<" ";
   	head=head->next;
   }
}
int main()
{
/*	node n1(10);
	node *head=&n1;
	node n2(20);
	node n3(30);
	node n4(40);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	print(head);*/
	
	// Dynamically 
	  node *n1=new node(10);
	  node *head=n1;
	  node *n2=new node(10);
	  node *n3=new node(20);
	  node *n4=new node(10);
	  n1->next=n2;
	  n2->next=n3;
	  n3->next=n4;
	print(head);
}
