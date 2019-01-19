#include<iostream>
using namespace std;
const int maxsize = 100;
struct Seqlist{
	int data[maxsize];
	int length;
};

struct Node{
    int data;
    Node *next;
};

void input(Seqlist *&l){
    l = new Seqlist;
	cout<<"����һ��˳���������Ԫ�ظ�����";
	cin>>l->length;
	for(int i = 0;i < l->length;i++){
		cout<<"�������"<<i + 1<<"������";cin>>l->data[i];
	}
}

void input(Node *&head){
    head = new Node;
    Node *r = head;
    int n;
    cout<<"����һ����ʽ��������Ԫ�ظ�����";
	cin>>n;
    for(int i = 0;i < n;i++){
        Node *s = new Node;
        cout<<"�������"<<i + 1<<"��Ԫ�أ�";
        cin>>s->data;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

int ArrSearch(Seqlist *&l,int x){
	int flag = 1;
	for(int i = 0;i< l->length;i++){
		if(l->data[i] == x){
			flag = 0;
			return i + 1;
		}
	}
    cerr<<"δ�ҵ���"<<endl;
    return 0;
}

int NodeSearch(Node *&head,int x){
    Node *p = head->next;
    int j = 1;
    while(p != NULL){
        if(p->data == x){
            return j;
        }
        p = p->next;
        j++;
    }
    cerr<<"δ�ҵ���"<<endl;
    return 0;
}

int BinarySearch(Seqlist *&l,int x){
    int high = l->length - 1;
    int low = 0;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(x < l->data[mid])
            high = mid - 1;
        else if(x > l->data[mid])
            low = mid + 1;
        else
            return mid + 1;
    }
    cerr<<"δ�ҵ���"<<endl;
    return 0;
}


int main(){
    Seqlist *l1;
    Node *l2;
    int n;
    input(l2);
    cout<<"��������Ҫ˳��������ҵ�����";
    cin>>n;
    cout<<"��Ҫ���ҵ����ǵ�"<<NodeSearch(l2,n)<<"����"<<endl;
    input(l1);
    cout<<"��������Ҫ˳��������ҵ�����";
    cin>>n;
    cout<<"��Ҫ���ҵ����ǵ�"<<ArrSearch(l1,n)<<"����"<<endl;
    cout<<"��������Ҫ���ֲ��ҵ�����";
    cin>>n;
    cout<<"��Ҫ���ҵ����ǵ�"<<BinarySearch(l1,n)<<"����"<<endl;
    return 0;
}
