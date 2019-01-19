#include<iostream>
using namespace std;
const int maxstack = 100;
typedef char T;
typedef struct snode{
	T data;
	snode *next;
};
void initstack(snode *&top){
	top = NULL;
}

void push(snode *&top,T x){
	snode *s = new snode;
	s->data = x;
	s->next = top;
	top = s;
}

T pop(snode *&top){
	if(top == NULL){
		cerr<<"underflow";
		return 0;
	}
	T x = top->data;
	snode *p = top;
	top = top->next;
	delete p;
	return x;
}

T getop(snode *&top){
    if(top == NULL){
		cerr<<"underflow";
		return 0;
	}
	return top->data;
}

/*T search(snode *&top,int i){
	snode *p = top;
	int j = 0;
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	}
	return p->data;
}*/

void displaystack(snode *&top){
	snode *p = top;
	while(p != NULL){
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	cout<<"创建一个链式栈。"<<endl;
	snode *s1;
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
