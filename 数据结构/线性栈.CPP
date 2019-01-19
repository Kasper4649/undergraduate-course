#include<iostream>
using namespace std;
const int maxstack = 100;
typedef char T;
typedef struct stack{
	T data[maxstack];
	int top;
}seqstack;

void initstack(seqstack *&s){
	s = new seqstack;
	s->top = -1;
}

void push(seqstack *&s,T x){
	if(s->top == maxstack){
		cerr<<"overflow";
	}
	s->data[++s->top] = x;
}

T pop(seqstack *&s){
	if(s->top == -1){
		cerr<<"underflow";
		return 0;
	}
	return s->data[s->top--];
}

T getop(seqstack *&s){
	if(s->top == -1){
		cerr<<"underflow";
		return 0;
	}
	return s->data[s->top];
}

void displaystack(seqstack *&s){
	for(int i = s->top;i >= 0;i--){
		cout<<s->data[i]<<" ";
	}
	cout<<endl;
}

int main(){
    cout<<"创建一个线性栈。"<<endl;
	stack *s1;
	initstack(s1);
	push(s1,'a');
	push(s1,'b');
	push(s1,'c');
	push(s1,'d');
	cout<<"输入这个栈："<<endl;
	displaystack(s1);
    cout<<"输出栈顶元素："<<getop(s1)<<endl;
	cout<<"删除栈顶元素。"<<endl;
	pop(s1);
	cout<<"输入这个栈："<<endl;
    displaystack(s1);
	return 0;
}
