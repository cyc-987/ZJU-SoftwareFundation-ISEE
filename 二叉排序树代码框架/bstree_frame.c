#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define null 0
#define n 100

typedef int keytype;

typedef struct node
{
	keytype key;//�������������Ĺؼ�����
	struct node *lchild;
	struct node  *rchild;
}bstnode; //�������������ṹ

typedef bstnode *bstree;//�������������Ͷ���



void insertbst(bstree *tptr,keytype key)
{
	//�ڶ���������tptr�У�����ֵΪkey�Ľ��
	if((*tptr) == null){
		//creat a new node
		bstree temp = (bstree)malloc(sizeof(bstnode));
		temp->key = key;
		temp->lchild = temp->rchild = null;
		//connect
		(*tptr) = temp;
	}else if(key < (*tptr)->key){
		insertbst(&((*tptr)->lchild),key);
	}else{
		insertbst(&((*tptr)->rchild),key);
	}

}//end of insertbst

void createbst(bstree *t)
{
	//����һ�ö���������t
	keytype key;
	int i,m;

	//�������100�����ڵ��������ɶ���������
	//m = rand()%100;
	m = 5;
	printf("random source data:");
	for(i=1; i<=m; i++)
	{
			key=rand()%100;
			printf("%d ",key);
			insertbst(t,key);//���ؼ���key���뵽����������t��
	}
	printf("\n");
	
}//end of createbst 

void inorder(bstree t)
{
	//�Զ���������t�����������
	if (t)
	{
		inorder(t->lchild);//�������������
		printf(" %d",t->key);//���ʸ����
		inorder(t->rchild);//�������������
	}//end of if 
}//end of inorder


int main()//������
{
	bstree t=null,q=null;
	
	srand( (unsigned)time( NULL ) );
	
	createbst(&t);//����һ�ö���������t
	printf("\nbst data:");
	
	inorder(t);//�������������t�������������
	printf("\n");
}

