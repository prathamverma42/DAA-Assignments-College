#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *prev, *next;
};
class list{
	Node* head=NULL;
	public:
	void create(int x){
		Node* temp = new Node;
		temp->data=x;
		temp->prev=temp->next=NULL;
		if(head == NULL){
			head=temp;
		}
		else{
			Node* last=head;
			while(last->next!=NULL){
				last=last->next;
			}
			last->next=temp;
			temp->prev=last;
		}
	}
	void insert(int x, int pos){
		Node* temp = new Node;
		temp->data=x;
		temp->prev=temp->next=NULL;
		
		if(pos==1){
			temp->next=head;
			head=temp;
			return;
		}
		
		Node *p=head, *q=NULL;
		int i=1;
		while(i!=pos && p!=NULL){
			q=p;
			p=p->next;
			i++;
		}
		if(q->next==NULL && p==NULL && i==pos){
			q->next=temp;
			temp->prev=q;
			return;
		}
		temp->next=p;
		temp->prev=q;
		p->prev=temp;
		q->next=temp;
	}
	void reverse(){
		Node *p=head->next,*q=head,*r=head->prev;
		while(q!=NULL){
			q->next=r;
			q->prev=p;
			r=q;
			q=p;
			if(p=p->next)
			p=p->next;
		}
		head=r;
	}
	void print(){
		Node* temp= head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};
int main(){
	list z;
	z.create(2);
	z.create(3);
	z.print();
	cout<<endl;
	z.insert(4,1);
	z.insert(5,3);
	z.insert(6,5);
	z.print();
	z.reverse();
	z.print();
}
