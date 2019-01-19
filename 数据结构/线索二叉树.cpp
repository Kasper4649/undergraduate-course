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

ThreadNode *pre;                        //全局变量
void Thread(ThreadNode *&p){
    if (p){
        Thread(p->lchild);            //左子树线索化
        if (!p->lchild){        //前驱线索
            p->lchild = pre;            //建立当前节点的前驱线索
            p->ltag = 1;
        }
        else
            p->ltag = 0;
        if (!pre->rchild){        //后继线索
            pre->rchild = p;            //建立前驱节点的后继线索
            pre->rtag = 1;
        }
        else
            pre->rtag = 0;
        pre = p;
        Thread(p->rchild);            //右子树线索化
    }
}

//产生中序线索二叉树
ThreadNode *CreateThread(ThreadNode *b){
    ThreadNode *root;
    root = new ThreadNode;
    root->ltag = 0;root->rtag = 1;
    root->rchild = b;
    if (!b)
        root->lchild = root;
    else{
        root->lchild = b;
        pre = root;                //pre是*p的前驱节点,供加线索用
        Thread(b);                //中序遍历线索化二叉树
        pre->rchild = root;        //最后处理,加入指向根节点的线索
        pre->rtag = 1;
        root->rchild = pre;        //根节点右线索化
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

//寻找中序下第一个结点
ThreadNode *First(ThreadNode *current){
    ThreadNode *p = current;
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

//寻找结点在中序下的后继结点
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
  if(root==NULL) return;    //如果线索链表为空,则空操作返回
  while(p->ltag==0)     //查找中序遍历的第一个结点并访问
       p=p->lchild;
      cout<<p->data;
     while(p->rchild!=NULL)   //当结点P存在后继,依次访问其后继结点
   {
     p=Next(p);
     cout<<p->data;
    }
}*/

int main(){
    ThreadNode *b,*tb;
    CreateThreadNode(b,"a(b(,c(d)))#");
    cout<<"二叉树:";DispThreadNode(b);
    tb=CreateThread(b);
    cout<<"\n线索中序序列:";
    cout<<"\n递归算法:";InOrder(tb->lchild);
    cout<<"\n非递归算法:";iteratorInOrder(tb);
    //InOrder1(tb);
    return 0;
}
