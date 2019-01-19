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
	cout<<"创建一个顺序表，请输入元素个数：";
	cin>>l->length;
	for(int i = 0;i < l->length;i++){
		cout<<"请输入第"<<i + 1<<"个数：";cin>>l->data[i];
	}
}

void input(Node *&head){
    head = new Node;
    Node *r = head;
    int n;
    cout<<"创建一个链式表，请输入元素个数：";
	cin>>n;
    for(int i = 0;i < n;i++){
        Node *s = new Node;
        cout<<"请输入第"<<i + 1<<"个元素：";
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
    cerr<<"未找到！"<<endl;
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
    cerr<<"未找到！"<<endl;
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
    cerr<<"未找到！"<<endl;
    return 0;
}


int main(){
    Seqlist *l1;
    Node *l2;
    int n;
    input(l2);
    cout<<"请输入你要顺序链表查找的数：";
    cin>>n;
    cout<<"你要查找的数是第"<<NodeSearch(l2,n)<<"个数"<<endl;
    input(l1);
    cout<<"请输入你要顺序数组查找的数：";
    cin>>n;
    cout<<"你要查找的数是第"<<ArrSearch(l1,n)<<"个数"<<endl;
    cout<<"请输入你要二分查找的数：";
    cin>>n;
    cout<<"你要查找的数是第"<<BinarySearch(l1,n)<<"个数"<<endl;
    return 0;
}
