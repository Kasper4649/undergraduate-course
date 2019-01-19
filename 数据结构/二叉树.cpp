#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef char elemtype;
struct bitree{
	elemtype data;
	bitree *lchild,*rchild;
};  //定义二叉树的类型
void createbtree(bitree *&bt,char *str){
	 stack<bitree*> s;
	 bitree *p;
	 bt = NULL;
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
			  p = new bitree;
			  p->data = ch;
			  p->lchild = p->rchild = NULL;
			 if(bt == NULL)
               bt = p;
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
void printree(bitree *b){
	if(b != NULL){
		cout<<b->data;
		if((b->lchild != NULL) || (b->rchild != NULL)){
			cout<<"(";
			printree(b->lchild);
			if (b->rchild != NULL)
                cout<<",";
            printree(b->rchild);
			cout<<")";
		}
	}
}

void PreOrder(bitree *b){
    if(b){
        cout<<b->data<<" ";
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void iteratorPreOrder(bitree *b){
    stack<bitree*> s;
    if(b){
        s.push(b);
        while(!s.empty()){
            b = s.top();
            s.pop();
            cout<<b->data<<" ";
            if(b->lchild)
                s.push(b->lchild);
            if(b->rchild)
                s.push(b->rchild);
        }
    }
}

void iteratorPostOrder(bitree *b){
    stack<bitree*> s;
    bitree *lastVist = NULL;
    while(b || !s.empty()){
        while(b){
            s.push(b);
            b = b->lchild;
        }
        b = s.top();
        if(b->rchild && b->rchild != lastVist){
            b = b->rchild;
        }
        else{
            cout<<b->data<<" ";
            lastVist = b;
            b = NULL;
            s.pop();
        }
    }
}

void iteratorInOrder(bitree *b){
    stack<bitree*> s;
    while(b || !s.empty()){
        while(b){
            s.push(b);
            b = b->lchild;
        }
        if(!s.empty()){
            b = s.top();
            cout<<b->data<<" ";
            s.pop();
            b = b->rchild;
        }
    }
}

void InOrder(bitree *b){
    if(b){
        InOrder(b->lchild);
        cout<<b->data<<" ";
        InOrder(b->rchild);
    }
}

void PostOrder(bitree *b){
    if(b){
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout<<b->data<<" ";
    }
}

void LevelOrder(bitree *b){
    queue<bitree*> q;
    q.push(b);
    while(!q.empty()){
        bitree *p = q.front();
        cout<<p->data<<" ";
        q.pop();
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }
}

int main(){
    bitree *bt;
    createbtree(bt,"a(b(,c(d)))#");
    cout<<"嵌套表示法："<<endl;
    printree(bt);
    cout<<"\n前序遍历递归算法："<<endl;
    PreOrder(bt);
    cout<<"\n中序遍历递归算法："<<endl;
    InOrder(bt);
    cout<<"\n后序遍历递归算法："<<endl;
    PostOrder(bt);
    cout<<"\n层次遍历算法："<<endl;
    LevelOrder(bt);
    cout<<"\n前序遍历非递归算法："<<endl;
    iteratorPreOrder(bt);
    cout<<"\n中序遍历非递归算法："<<endl;
    iteratorInOrder(bt);
    cout<<"\n后序遍历非递归算法："<<endl;
    iteratorPostOrder(bt);
    return 0;
}

