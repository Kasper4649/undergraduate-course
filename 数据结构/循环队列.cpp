#include<iostream>
using namespace std;
const int maxqueue = 100;
typedef char T;
typedef struct sequeue{
	T data[maxqueue];
	int front,rear;
};

void initqueue(sequeue *&q){
	q = new sequeue;
	q->front = 0;
	q->rear = 0;
}

void enqueue(sequeue *&q,T x){
	if((q->rear + 1) % maxqueue == q->front){
		cerr<<"overflow";
		return;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % maxqueue;
}

T delqueue(sequeue *&q){
	if(q->front == q->rear){
		cerr<<"underflow";
		return 0;
	}
	T x = q->data[q->front];
	q->front = (q->front + 1) % maxqueue;
    return x;
}

void displaysequeue(sequeue *&q){
	if(q->front == q->rear){
		cerr<<"underflow";
		return ;
	}
	for(int i = q->front;i != q->rear;i = (i + 1) % maxqueue){
		cout<<q->data[i]<<" ";
	}
	cout<<endl;
}

T getop(sequeue *&q){
    if(q->front == q->rear){
		cerr<<"underflow";
		return 0;
	}
	return q->data[q->front];
}

int main(){
    cout<<"创建一个线性队列："<<endl;
	sequeue *q1;
	initqueue(q1);
	enqueue(q1,'a');
	enqueue(q1,'b');
	enqueue(q1,'c');
	enqueue(q1,'d');
	cout<<"输出这个队列："<<endl;
	displaysequeue(q1);
	cout<<"输出队首元素："<<getop(q1)<<endl;
	cout<<"删除队首元素。"<<endl;
	delqueue(q1);
	cout<<"输出这个队列："<<endl;
	displaysequeue(q1);
	return 0;
}
