#include<iostream>
using namespace std;
const int maxsize = 10;
typedef struct{
	int data[maxsize];
	int length;
}seqlist;

void initlist(seqlist *&l){
	l = new seqlist;
	l->length = 0;
}

void input(seqlist *&l){
	cout<<"创建一个顺序表，请输入元素个数："<<endl;
	cin>>l->length;
	for(int i = 0;i < l->length;i++){
		cout<<"请输入第"<<i + 1<<"个数：";cin>>l->data[i];
	}
}

void output(seqlist *&l){
	cout<<"输出这个顺序表中的数："<<endl;
	for(int i = 0;i < l->length;i++){
		cout<<l->data[i]<<" ";
	}
	cout<<endl;
}

int search(seqlist *&l,int i){//按位查找
	if(i < 1 || i > l->length){
		cerr<<"位数输入错误！"<<endl;
		return 0;
	}
	else
		return l->data[i-1];
}

int locate(seqlist *&l,int x){//按值查找
	int flag = 1;
	for(int i = 0;i< l->length;i++){
		if(l->data[i] == x){
			flag = 0;
			return i + 1;
		}
	}
	if(flag){
		cerr<<"未找到！"<<endl;
		return 0;
	}
	else
		return 0;
}

void insert(seqlist *&l,int x,int i){
	if(i < 1||i > l->length)
		cerr<<"插入位置错误！"<<endl;
	if(l->length > maxsize)
		cerr<<"overflow!"<<endl;
	for(int j = l->length - 1;j >= i - 1;j--){
		l->data[j+1] = l->data[j];
	}
	l->data[i-1] = x;
	l->length++;
}

void Delete(seqlist *&l,int i,int x){
	if(l->length == 0)
		cerr<<"表空！"<<endl;
	if(i <1 || i > l->length - 1)
		cerr<<"删除位置错误！"<<endl;
	x = l->data[i-1];
	for(int j = i;j < l->length;j++){
		l->data[j-1] = l->data[j];
	}
	l->length--;
}

int main(){
    seqlist *l1;
	initlist(l1);
	input(l1);
	output(l1);
	int a;
	cout<<"请输入你需要查找的数的位置："<<endl;
	cin>>a;
	cout<<"查找的数是："<<search(l1,a)<<endl;
	cout<<"请输入你需要查找的数："<<endl;
	cin>>a;
	cout<<"查找的数的位置是："<<locate(l1,a)<<endl;
	int b;
	cout<<"请输入你需要插入的数以及位置："<<endl;
	cin>>a>>b;
    insert(l1,a,b);
	output(l1);
	cout<<"请输入你需要删除数的位置："<<endl;
	cin>>a;
	Delete(l1,a,b);
	output(l1);
	return 0;
}
