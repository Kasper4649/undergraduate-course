#include<iostream>
#include<cmath>
using namespace std;

//位置冲突算法
bool judge(int a[], int n){//a[]位置数组，n皇后个数
    int i = 0, j = 0;
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i-1; j++)//判断第i个棋子是否冲突（摆放是否合理），我们只需要和前面i-1列校对就ok
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1：在一行；2：在对角线上 已经保证了每一列都只有一个皇后
                return false;   //冲突
    return true;//不冲突
}

//八皇后：枚举算法
void measure1(){
    int a[9] = {0}; //用于记录皇后位置：(第0行0列我们不用)。如：a[3] = 4;表示第3列第4行位置有皇后
    int i = 0,count = 0;  //用于计数
    for (a[1] = 1; a[1] <= 8; a[1]++)
        for (a[2] = 1; a[2] <= 8; a[2]++)
            for (a[3] = 1; a[3] <= 8; a[3]++)
                for (a[4] = 1; a[4] <= 8; a[4]++)
                    for (a[5] = 1; a[5] <= 8; a[5]++)
                        for (a[6] = 1; a[6] <= 8; a[6]++)
                            for (a[7] = 1; a[7] <= 8; a[7]++)
                                for (a[8] = 1; a[8] <= 8; a[8]++){
                                    if (!judge(a,8))//如果冲突，则继续枚举
                                        continue;
                                    else{
                                        cout<<"第"<<++count<<"种情况：\n";//打印情况
                                        for (i = 1; i <= 8; i++){
                                           for(int j = 1;j <= 8;j++){
                                               if(j == a[i])
                                                  cout<<"1 ";
                                               else
                                                  cout<<"0 ";
                                           }
                                           cout<<endl;
                                        }
                                        cout<<endl;
                                    }
                                }
}

int a[9] = {0};
int count = 0;

//八皇后：回溯算法（递归）
void measure2(int k){ //参数k：递归摆放第k个皇后
    if(count == 92)
        count = 0;
    int i = 0;
    if (k > 8){      //k>n：即k>8表示最后一个皇后摆放完毕
        cout<<"第"<<++count<<"种情况：\n";//打印情况
        for (i = 1; i <= 8; i++){
            for(int j = 1;j <= 8;j++){
               if(j == a[i])
                    cout<<"1 ";
               else
                    cout<<"0 ";
           }
           cout<<endl;
        }
        cout<<endl;
    }
    else{   //8个皇后未全部摆放完毕
        for (i = 1; i <= 8; i++){//摆放第k个皇后时（转下一行）
               //依次从列顶端开始搜索，一直到列底端，直到找到合适位置,如果未找到，自动返回上层递归(回溯)
            a[k] = i;
            if (judge(a,k))//不冲突
                measure2(k+1);//递归摆放下一个皇后
        }
    }
}

//八皇后：回溯法（非递归）
void measure3(){
    int count = 0;    //记录当前情况个数
    int a[9] = {0};   //存放皇后位置，如：a[3] = 4;表示第3列第4行有一个皇后（a[0]不用）
    int i = 0,k = 1;  //初始化k为第一列
    while (k > 0){     //k==0时：表示摆放第1个皇后就超过了列底部（即已经找完所有情况）
        a[k] += 1;    //a[k]位置，摆放一个皇后
        while ((a[k] <= 8) && (!judge(a,k)))//如果a[k]（即皇后摆放位置）没有到列最底部，且摆放冲突。
            a[k] += 1;//将皇后列下移一位
        if (a[k] <= 8){//皇后摆放位置没有到达列最底部
            if (k == 8){//k==n表示，8列皇后全部摆放完毕
                cout<<"第"<<++count<<"种情况：\n";//打印情况
                for (i = 1; i <= 8; i++){
                    for(int j = 1;j <= 8;j++){
                        if(j == a[i])
                           cout<<"1 ";
                        else
                           cout<<"0 ";
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
            else{      //皇后还未摆放完毕
                k += 1;    //继续摆放下一列
            }
        }
        else{//回溯：当a[k]>8进入else,表示在第k列中没有找到合适的摆放位置
            a[k] = 0;//此行初始化a[k] = 0;表示第k列，从第一行开始摆放皇后
            k -= 1;//回溯到k-1步：k表示第几个皇后，a[k]表示第k个皇后摆放的位置
        }
    }
}

void menu(){   	//输出界面
	cout<<"‖----------------------------‖"<<endl;
	cout<<"‖                            ‖"<<endl;
	cout<<"‖      八皇后问题            ‖"<<endl;
	cout<<"‖   1.方法一：  暴力枚举法   ‖"<<endl;
	cout<<"‖   2.方法二：  回溯递归法   ‖"<<endl;
	cout<<"‖   3.方法三：回溯非递归法   ‖"<<endl;
	cout<<"‖   0.退出                   ‖"<<endl;
	cout<<"‖                            ‖"<<endl;
   	cout<<"‖----------------------------‖"<<endl;
}

int main(){
    menu();
	while(true){
        cout<<endl;
	    cout<<"请从0-3中选择一个数：";
	    int number;
	    cin>>number;
	    switch(number){
	        case 1:  measure1();break;
	        case 2:  measure2(1);break;
	        case 3:  measure3();break;
            case 0:  return 0;
            default:
                cout<<"抱歉，没有该选项，请重新作出选择:)"<<endl;
		}
	}
	return 0;
}
