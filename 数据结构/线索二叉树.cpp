#include<iostream>
#include<stack>
using namespace std;
typedef char ElemType;
struct ThreadNode{
    ElemType data;
    int ltag,rtag;
    ThreadNode *lchild,*rchild;
};

void CreateThreadNode(ThreadNode *&b,char *str){
	 stack<ThreadNode*> s;
	 ThreadNode *p;
	 b = NULL;
	 int k,j = 0;
	 char ch = str[j];
	 while(ch != '#'){
		 switch(ch){
		     case '(':
              s.push(p);
			  k = 1;
			  break;
             case ')':
              s.pop();
			  break;
             case ',':
              k = 2;
			  break;
		     default:
			  p = new ThreadNode;
			  p->data = ch;
			  p->lchild = p->rchild = NULL;
			 if(b == NULL)
               b = p;
			 else
                switch(k){
		          case 1: s.top()->lchild = p;break;
		          case 2: s.top()->rchild = p;break;
                }
		 }
	 j++;
	 ch = str[j];
	 }
}

void DispThreadNode(ThreadNode *b){
	if(b){
		cout<<b->data;
		if((b->lchild != NULL) || (b->rchild != NULL)){
			cout<<"(";
			DispThreadNode(b->lchild);
			if (b->rchild)
                cout<<",";
            DispThreadNode(b->rchild);
			cout<<")";
		}
	}
}

ThreadNode *pre;                        //ȫ�ֱ���
void Thread(ThreadNode *&p){
    if (p){
        Thread(p->lchild);            //������������
        if (!p->lchild){        //ǰ������
            p->lchild = pre;            //������ǰ�ڵ��ǰ������
            p->ltag = 1;
        }
        else
            p->ltag = 0;
        if (!pre->rchild){        //�������
            pre->rchild = p;            //����ǰ���ڵ�ĺ������
            pre->rtag = 1;
        }
        else
            pre->rtag = 0;
        pre = p;
        Thread(p->rchild);            //������������
    }
}

//������������������
ThreadNode *CreateThread(ThreadNode *b){
    ThreadNode *root;
    root = new ThreadNode;
    root->ltag = 0;root->rtag = 1;
    root->rchild = b;
    if (!b)
        root->lchild = root;
    else{
        root->lchild = b;
        pre = root;                //pre��*p��ǰ���ڵ�,����������
        Thread(b);                //�������������������
        pre->rchild = root;        //�����,����ָ����ڵ������
        pre->rtag = 1;
        root->rchild = pre;        //���ڵ���������
    }
    return root;
}
void InOrder(ThreadNode *tb){
    if (tb->lchild && tb->ltag == 0)
        InOrder(tb->lchild);
    cout<<tb->data<<" ";
    if (tb->rchild && tb->rtag == 0)
        InOrder(tb->rchild);
}

//Ѱ�������µ�һ�����
ThreadNode *First(ThreadNode *current){
    ThreadNode *p = current;
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

//Ѱ�ҽ���������µĺ�̽��
ThreadNode *Next(ThreadNode *current){
    ThreadNode *p = current->rchild;
    if(current->rtag == 0)
        return First(p);
    else
        return p;
}


void iteratorInOrder(ThreadNode *tb){
    ThreadNode *p = tb->lchild;
    while (p != tb){
        while (p->ltag == 0) p = p->lchild;
        cout<<p->data<<" ";
        while (p->rtag == 1 && p->rchild != tb){
            p = p->rchild;
            cout<<p->data<<" ";
        }
        p = p->rchild;
    }
}
/*
void InOrder1(ThreadNode  *root){
  ThreadNode *p;
  if(root==NULL) return;    //�����������Ϊ��,��ղ�������
  while(p->ltag==0)     //������������ĵ�һ����㲢����
       p=p->lchild;
      cout<<p->data;
     while(p->rchild!=NULL)   //�����P���ں��,���η������̽��
   {
     p=Next(p);
     cout<<p->data;
    }
}*/

int main(){
    ThreadNode *b,*tb;
    CreateThreadNode(b,"a(b(,c(d)))#");
    cout<<"������:";DispThreadNode(b);
    tb=CreateThread(b);
    cout<<"\n������������:";
    cout<<"\n�ݹ��㷨:";InOrder(tb->lchild);
    cout<<"\n�ǵݹ��㷨:";iteratorInOrder(tb);
    //InOrder1(tb);
    return 0;
}
