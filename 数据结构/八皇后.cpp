#include<iostream>
#include<cmath>
using namespace std;

//λ�ó�ͻ�㷨
bool judge(int a[], int n){//a[]λ�����飬n�ʺ����
    int i = 0, j = 0;
    for (i = 2; i <= n; i++)
        for (j = 1; j <= i-1; j++)//�жϵ�i�������Ƿ��ͻ���ڷ��Ƿ����������ֻ��Ҫ��ǰ��i-1��У�Ծ�ok
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == i-j))//1����һ�У�2���ڶԽ����� �Ѿ���֤��ÿһ�ж�ֻ��һ���ʺ�
                return false;   //��ͻ
    return true;//����ͻ
}

//�˻ʺ�ö���㷨
void measure1(){
    int a[9] = {0}; //���ڼ�¼�ʺ�λ�ã�(��0��0�����ǲ���)���磺a[3] = 4;��ʾ��3�е�4��λ���лʺ�
    int i = 0,count = 0;  //���ڼ���
    for (a[1] = 1; a[1] <= 8; a[1]++)
        for (a[2] = 1; a[2] <= 8; a[2]++)
            for (a[3] = 1; a[3] <= 8; a[3]++)
                for (a[4] = 1; a[4] <= 8; a[4]++)
                    for (a[5] = 1; a[5] <= 8; a[5]++)
                        for (a[6] = 1; a[6] <= 8; a[6]++)
                            for (a[7] = 1; a[7] <= 8; a[7]++)
                                for (a[8] = 1; a[8] <= 8; a[8]++){
                                    if (!judge(a,8))//�����ͻ�������ö��
                                        continue;
                                    else{
                                        cout<<"��"<<++count<<"�������\n";//��ӡ���
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

//�˻ʺ󣺻����㷨���ݹ飩
void measure2(int k){ //����k���ݹ�ڷŵ�k���ʺ�
    if(count == 92)
        count = 0;
    int i = 0;
    if (k > 8){      //k>n����k>8��ʾ���һ���ʺ�ڷ����
        cout<<"��"<<++count<<"�������\n";//��ӡ���
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
    else{   //8���ʺ�δȫ���ڷ����
        for (i = 1; i <= 8; i++){//�ڷŵ�k���ʺ�ʱ��ת��һ�У�
               //���δ��ж��˿�ʼ������һֱ���е׶ˣ�ֱ���ҵ�����λ��,���δ�ҵ����Զ������ϲ�ݹ�(����)
            a[k] = i;
            if (judge(a,k))//����ͻ
                measure2(k+1);//�ݹ�ڷ���һ���ʺ�
        }
    }
}

//�˻ʺ󣺻��ݷ����ǵݹ飩
void measure3(){
    int count = 0;    //��¼��ǰ�������
    int a[9] = {0};   //��Żʺ�λ�ã��磺a[3] = 4;��ʾ��3�е�4����һ���ʺ�a[0]���ã�
    int i = 0,k = 1;  //��ʼ��kΪ��һ��
    while (k > 0){     //k==0ʱ����ʾ�ڷŵ�1���ʺ�ͳ������еײ������Ѿ��������������
        a[k] += 1;    //a[k]λ�ã��ڷ�һ���ʺ�
        while ((a[k] <= 8) && (!judge(a,k)))//���a[k]�����ʺ�ڷ�λ�ã�û�е�����ײ����Ұڷų�ͻ��
            a[k] += 1;//���ʺ�������һλ
        if (a[k] <= 8){//�ʺ�ڷ�λ��û�е�������ײ�
            if (k == 8){//k==n��ʾ��8�лʺ�ȫ���ڷ����
                cout<<"��"<<++count<<"�������\n";//��ӡ���
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
            else{      //�ʺ�δ�ڷ����
                k += 1;    //�����ڷ���һ��
            }
        }
        else{//���ݣ���a[k]>8����else,��ʾ�ڵ�k����û���ҵ����ʵİڷ�λ��
            a[k] = 0;//���г�ʼ��a[k] = 0;��ʾ��k�У��ӵ�һ�п�ʼ�ڷŻʺ�
            k -= 1;//���ݵ�k-1����k��ʾ�ڼ����ʺ�a[k]��ʾ��k���ʺ�ڷŵ�λ��
        }
    }
}

void menu(){   	//�������
	cout<<"��----------------------------��"<<endl;
	cout<<"��                            ��"<<endl;
	cout<<"��      �˻ʺ�����            ��"<<endl;
	cout<<"��   1.����һ��  ����ö�ٷ�   ��"<<endl;
	cout<<"��   2.��������  ���ݵݹ鷨   ��"<<endl;
	cout<<"��   3.�����������ݷǵݹ鷨   ��"<<endl;
	cout<<"��   0.�˳�                   ��"<<endl;
	cout<<"��                            ��"<<endl;
   	cout<<"��----------------------------��"<<endl;
}

int main(){
    menu();
	while(true){
        cout<<endl;
	    cout<<"���0-3��ѡ��һ������";
	    int number;
	    cin>>number;
	    switch(number){
	        case 1:  measure1();break;
	        case 2:  measure2(1);break;
	        case 3:  measure3();break;
            case 0:  return 0;
            default:
                cout<<"��Ǹ��û�и�ѡ�����������ѡ��:)"<<endl;
		}
	}
	return 0;
}
