#include <bits/stdc++.h>
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

node* takeInput_Better() {
	int data;
	cin >> data;
	node *head = NULL;
	node *tail = NULL;
	while(data != -1) {
		node *newnode = new node(data);
		if(head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail -> next = newnode;
			tail = tail -> next;
			// OR
			// tail = newnode;
		}

		cin >> data;
	}
	return head;
}
 
 node* deletenode(node *head,int i)
 {
 	int count=0;
 	node *temp=head;
 	node *temp1;
 	if(i==0)
 	{
 		head=head->next;
 		delete temp;
 		return head;
	 }
	 	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp==NULL||temp->next==NULL)
	return head;
	 
	else{
			temp1=temp->next->next;
	       delete temp->next;
	        temp->next=temp1;
	}

	 return head;
 }

node* insertnode(node *head, int i, int data) {
	node *newnode = new node(data);
	int count = 0;
	node *temp = head;

	if(i == 0) {
		newnode -> next = head;
		head = newnode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		node *a = temp -> next;
		temp -> next = newnode;
		newnode -> next = a;
	}
	return head;
}

void print(node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}

 int recursivecount(node *head)
 {
 	if(head==NULL)
     return 0;
     else
     return 1+ recursivecount(head->next);
 }
 
 int searching(node *head,int data)
 {

 	while(head!=NULL)
 	{
 		if(data==head->data)
 		return 1;
 		head=head->next;
	 }
	 return 0;
 	
 }
 node* insertrecursive(node *head,int data,int index)
 {
 	int count;
	 node *temp;
 	if(head==NULL)
 	return head;
 	count= recursivecount(head);
 	if(index>count)
 	return head;
 	if(index==0)
 	{
 		node *newnode=new node(data);
 		newnode->next=head;
 		head=newnode;
 		return head;
	 }
	temp=insertrecursive(head=head->next,data,index=index-1); //incomplete
	temp=head;
	return head;
 }
 
 int printrecursive(node* head)
 {
 	if(head!=NULL)
 	{
 	printrecursive(head->next);
 		cout<<head->data<<" ";
	 }
 }
 
 int getindex(node *head,int data)
 {
    int c=0;
 	while(head!=NULL)
 	{
 		if(data==head->data)
 		break;
 		c++;
 		head=head->next;
	 }
	 return c;
 	
 }
 
void insert_n_node_to_last(node *head,int m)
{
	int skip;
	int lenght=recursivecount(head);
    
    if(lenght!=m&& m<lenght)
    {
    skip=lenght-m;
	node *prev=NULL;
	node *curr=head;
	
	while(skip>0)
	{
		prev=curr;
		curr=curr->next;
		skip--;
		}	
		prev->next=NULL;
		node *temphead=head;
		head=curr;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
			curr->next=temphead;
	}
	print(head);
}

void remove_dublicate(node *head)
{
	if(head==NULL||head->next==NULL)
	print(head);
	node *h1,*h2;
	h1=head;
	h2=head->next;
	while(h2!=NULL)
	{
	if(h1->data!=h2->data)
	{
		h2=h2->next;
		h1=h1->next;
	}
		else
		{
			h2=h2->next;
			delete h1->next;
			h1->next=h2;
		}
		
	}
	print(head);
}
/*void palindrome(node *head)
{
	node *h1,*h2;                    // incomplete
	h1=head;
	int count=recursivecount(head);
	count=count/2;
	int i=0;
	while(i<count)
	{
		h1=h1->next;
		i++;
	}
	h2=h1->next;
	h1->next=NULL;
	 printrecursive(h2);
	 while(h1!=NULL||h2!=NULL)
	 {
	 	if(h1->data==h2->data)
	 	cout<<"Palindrome ";
	 	
	 }
	
}*/
 void printmid(node *head)
 {
 	/*node *temp=head;
 	int count=recursivecount(head);
 	int len=(count-1)/2;
 	int c=1;
 	
 	while(c<=len)
 	{
 		temp=temp->next;
 		c++;
	 }
	 cout<<endl<<temp->data;*/
	 
	 // without calculating lenght
	  node *slow,*fast;
	  slow=head;
	  fast=head->next;
	  while(fast!=NULL&&fast->next!=NULL)
	  {
	  	slow=slow->next;
	  	fast=fast->next->next;
	  }
	  cout<<endl<<slow->data<<endl;
	 
 }
 
 /*void mergelist(node *head,node *head1)    //incomplte
 {
 	node *fh=NULL,*ft=NULL;
 	while(head!=0&&head1!=0)
 	{
 		if(head->data<head1->data)
 		fh=ft=head;
 		ft=ft->next;
 		if(ft->data>head1->data)
 		ft=head1;
 		fh=ft;
	 }
	 if(head==NULL)
	 fh=head;
	 else
	 fh=head1;
	 print(fh);
 }*/
node *  reverse_ll_recursion(node *head)
{
	
	if(head==NULL||head->next==NULL)
	return head;
	node *small_input=reverse_ll_recursion(head->next);
	node *temp=small_input;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	return small_input;
}
node *  reverse_ll_recursion_2(node *head)
{
	
	if(head==NULL||head->next==NULL)
	return head;
	node *small_input=reverse_ll_recursion(head->next);
    node *tail=head->next;
	tail->next=head;	
	head->next=NULL;
	return small_input;
}
int main() {

	node *head = NULL;
	//node *head1 = NULL;
	head=takeInput_Better();
	//head1=takeInput_Better();
	print(head);
	//print(head1);
	int i, data,count,index,n;
	
/*	cin >> i >> data;
	head = insertnode(head, i, data);
	print(head);
	cout<<endl;*/

/*	cin>>i;
      head=deletenode(head,i);*/
    
	/*count= recursivecount(head);
    cout<<"No. of node is" <<count;*/
    
    /*cout<<"Enter data which is in linked list : ";
    cin>>data;
	count=searching(head,data);
	if(count==1)
	cout<<"Node of found "<<data<<endl;
	else 
	cout<<"Not found "<<data<<endl;*/

   /* cin >> data >> i;
	head=insertrecursive(head,data,i);*/

/*	
     printrecursive(head);
     */
     
  /*  cin >> data ;
	index=getindex(head,data);
	cout<<index<<" ";*/
	
/*	cin>>n;
	insert_n_node_to_last(head,n);*/
	 
	 /* cout<<endl;
	  remove_dublicate(head);*/
   
   /*
    printmid(head);*/
    
   /* mergelist(head,head1);
                                // incomplte
   */
  
  /*head= reverse_ll_recursion(head);
   print(head);*/
  
  head= reverse_ll_recursion_2(head); //better approcah
	print(head);
    
    
    
    
}

