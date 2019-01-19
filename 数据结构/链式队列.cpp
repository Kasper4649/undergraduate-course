#include<iostream>
using namespace std;
typedef char T;
typedef struct qnode{
	T data;
	qnode *next;
};

void initqueue(qnode *&front,qnode *&rear){
	front = new qnode;
	front->next = NULL;
	rear = front;
}

void enqueue(qnode *&front,qnode *&rear,T x){
	qnode *s;
	s = new qnode;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
}

T delqueue(qnode *&front,qnode *&rear){
	if(front == rear){
		cerr<<"underflow";
		return 0;
	}
	qnode *s;
	s = front->next;
	T x = s->data;
	front->next = s->next;
	delete s;
	return x;
}

T getop(qnode *&front,qnode *&rear){
	if(front == rear){
		cerr<<"underflow";
		return 0;
	}
	return front->next->data;
}

void displayqueue(qnode *&front,qnode *&rear){
	qnode *s;
	s = front->next;
	while(s != NULL){
		cout<<s->data<<" ";
		s =s->next;
	}
	cout<<endl;
}

int main(){
    cout<<"����һ�����Զ��У�"<<endl;
	qnode *f1,*r1;
	initqueue(f1,r1);
	enqueue(f1,r1,'a');
	enqueue(f1,r1,'b');
	enqueue(f1,r1,'c');
	enqueue(f1,r1,'d');
	cout<<"���������У�"<<endl;
	displayqueue(f1,r1);
	cout<<"�������Ԫ�أ�"<<getop(f1,r1)<<endl;
	cout<<"ɾ������Ԫ��"<<endl;
	delqueue(f1,r1);
	cout<<"���������У�"<<endl;
	displayqueue(f1,r1);
	cout<<"�������Ԫ�أ�"<<getop(f1,r1)<<endl;
	return 0;
}
