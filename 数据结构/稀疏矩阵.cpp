#include<iostream>
using namespace std;
const int maxsize = 100;
typedef int T;
struct Trituple{
	int row,col;
	T value;
};

struct SparseMatrix{
	Trituple data[maxsize];
	int Rows,Cols,Terms;
};

void CreateMatrix(SparseMatrix *s1){
	int i,j;
	T v;
	cout<<"请输入系数矩阵的行数、列数、非零元素的个数：";
	cin>>s1->Rows>>s1->Cols>>s1->Terms;
	for(int k = 0;k < s1->Terms;k++){
		cout<<"请输入第"<<k + 1<<"个元素的行、列、值：";
		cin>>i>>j>>v;
		s1->data[k].row = (i - 1);
	    s1->data[k].col = (j - 1);
	    s1->data[k].value = v;
	}
	/*int i1,j1;T v1;
	for(int m = 0;m < s1->Terms - 1;m++){
        for(int n = 0;m < s1->Terms - 1 - m;n++){
            if(s1->data[m].row > s1->data[m + 1].row || (s1->data[m].row == s1->data[m + 1].row &&
                                                            s1->data[m].col > s1->data[m + 1].col)){
                i1 = s1->data[m].row;
                j1 = s1->data[m].col;
                v1 = s1->data[m].value;
                s1->data[m].row = s1->data[m + 1].row;
                s1->data[m].col = s1->data[m + 1].col;
                s1->data[m].value = s1->data[m + 1].value;
                s1->data[m + 1].row = i1;
                s1->data[m + 1].col = j1;
                s1->data[m + 1].value = v1;
            }
        }
	}*/
}

void DisplayMatrix(SparseMatrix *s1){
	int k = 0;
	for(int i = 0;i < s1->Rows;i++){
		for(int j = 0;j < s1->Cols;j++){
			if(s1->data[k].row == i && s1->data[k].col == j){
				cout<<" "<<s1->data[k].value;
				k++;
			}
			else
				cout<<" 0";
		}
		cout<<endl;
	}
}

void Transpose(SparseMatrix *s1,SparseMatrix *s2){
	s2->Rows = s1->Cols;
	s2->Cols = s1->Rows;
	s2->Terms = s1->Terms;
	if(s1->Terms > 0){
		int k,i,j = 0;
		for(k = 0;k < s1->Cols;k++)
			for(i = 0;i < s1->Terms;i++){
				if(s1->data[i].col == k){
					s2->data[j].row = k;
					s2->data[j].col = s1->data[i].row;
					s2->data[j].value = s1->data[i].value;
					j++;
				}
			}
	}
}

void FastTranspose(SparseMatrix *s1,SparseMatrix *s2){
    int *rowSize = new int[s1->Cols];
    int *rowStart = new int[s1->Cols];
    s2->Rows = s1->Cols;
	s2->Cols = s1->Rows;
	s2->Terms = s1->Terms;
    if(s1->Terms > 0){
        int i,j;
        for(i = 0;i < s1->Cols;i++)
            rowSize[i] = 0;
        for(i = 0;i < s1->Terms;i++)
            rowSize[s1->data[i].col]++;
        rowStart[0] = 0;
        for(i = 1;i < s1->Cols;i++)
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        for(i = 0;i < s1->Terms;i++){
            j = rowStart[s1->data[i].col];
            s2->data[j].row = s1->data[i].col;
            s2->data[j].col = s1->data[i].row;
            s2->data[j].value = s1->data[i].value;
            rowStart[s1->data[i].col]++;
        }
    }
    delete []rowSize;
    delete []rowStart;
}

int main(){
	SparseMatrix s1,s2,s3;
	cout<<"创建一个稀疏矩阵："<<endl;
    CreateMatrix(&s1);
	s3 = s2 = s1;
	cout<<"输出这个矩阵："<<endl;
    DisplayMatrix(&s1);
	Transpose(&s1,&s2);
	cout<<"普通转置后的矩阵："<<endl;
    DisplayMatrix(&s2);
    FastTranspose(&s1,&s3);
    cout<<"快速转置后的矩阵："<<endl;
    DisplayMatrix(&s3);
	return 0;
}
