#include<iostream>
#include<cstring>
using namespace std;
typedef char T;
struct node{
    T data;
    node *next;
};

void initlist(node *&head){
    head = new node;
    head->next = NULL;
}

void input(node *&head,T n){
    head = new node;
    node *r = head;
    for(int i = 0;i < n;i++){
        node *s = new node;
        cout<<"请输入第"<<i + 1<<"个元素：";
        cin>>s->data;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void output(node *&head){
    node *p;
    p = head->next;
    while(p != NULL){
        cout<<p->data<<"  ";
        p = p->next;
    }
    cout<<endl;
}

void insertlist(node *&head,int i,T x){
    node *s,*p;
    int j;
    p = head->next;j = 1;
    while(p != NULL && j < i - 1){
        p = p->next;j++;
    }
    if(p == NULL){
        throw"插入位置错误。";
    }
    else{
        s = new node;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

T deletelist(node *&head,int i){
    node *p = head->next;
    int j = 1;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL || p->next == NULL){
        throw"删除的位置错误。";
    }
    else{
        node *q = p->next;
        char x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

int getlocal(node *&head,T x){ //按值查找
    node *p = head->next;
    int j = 1;
    while(p != NULL){
        if(p->data == x){
            return j;
        }
        p = p->next;
        j++;
    }
    return 0;
}

T getelement(node *&head,int i){ //按位查找
    node *p = head->next;
    int j = 1;
    while(p != NULL && j < i){
        p = p->next;j++;
    }
    if(p == NULL){
        throw"查找的位置错误。";
    }
    else{
        return p->data;
    }
}

void split(node *&head,node *&A,node *&B){
    node *rA,*rB;
    A = head;
    rA = A;
    B = new node;
    rB = B;
    node *p = head->next;
    while(p != NULL){
        rA->next = p;rA = p;
        p = p->next;
        if(p != NULL){
            rB->next = p;
            rB = p;
            p = p->next;
        }
    }
    rA->next = NULL;
    rB->next = NULL;
    output(A);
    output(B);
}

int main(){
    cout<<"第一题"<<endl;
    node *l1;
    cout<<"创建一个表："<<endl;
    initlist(l1);
    input(l1,5);
    cout<<"输出这个表："<<endl;
    output(l1);
    cout << "单链表中第5个元素是：" << getelement(l1,5) << endl;
    cout << "单链表中元素5的位置是：" << getlocal(l1,'5') << endl;
    cout<<"在表第2个位置上插入元素f"<<endl;
    insertlist(l1,2,'f');
    cout<<"输出这个表："<<endl;
    output(l1);
    cout<<"删除第2个位置上的元素"<<endl;
    deletelist(l1,2);
    cout<<"输出这个表："<<endl;
    output(l1);
    cout<<"----------------"<<endl;
    cout<<"第二题："<<endl;
    node *A,*B;
    split(l1,A,B);
    return 0;
}
