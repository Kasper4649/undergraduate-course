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
        cout<<"�������"<<i + 1<<"��Ԫ�أ�";
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
        throw"����λ�ô���";
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
        throw"ɾ����λ�ô���";
    }
    else{
        node *q = p->next;
        char x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

int getlocal(node *&head,T x){ //��ֵ����
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

T getelement(node *&head,int i){ //��λ����
    node *p = head->next;
    int j = 1;
    while(p != NULL && j < i){
        p = p->next;j++;
    }
    if(p == NULL){
        throw"���ҵ�λ�ô���";
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
    cout<<"��һ��"<<endl;
    node *l1;
    cout<<"����һ����"<<endl;
    initlist(l1);
    input(l1,5);
    cout<<"��������"<<endl;
    output(l1);
    cout << "�������е�5��Ԫ���ǣ�" << getelement(l1,5) << endl;
    cout << "��������Ԫ��5��λ���ǣ�" << getlocal(l1,'5') << endl;
    cout<<"�ڱ��2��λ���ϲ���Ԫ��f"<<endl;
    insertlist(l1,2,'f');
    cout<<"��������"<<endl;
    output(l1);
    cout<<"ɾ����2��λ���ϵ�Ԫ��"<<endl;
    deletelist(l1,2);
    cout<<"��������"<<endl;
    output(l1);
    cout<<"----------------"<<endl;
    cout<<"�ڶ��⣺"<<endl;
    node *A,*B;
    split(l1,A,B);
    return 0;
}
