#include <stdio.h>
#include "math.h"

void swap(int *a,int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}


//��ѡ������
void SelectSort(int r[],int n)
{
	int i,j,k;
	int t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		//find
		for(j=i+1;j<n;j++)
		{
			if(r[j]<r[k])
			{
				k=j;
			}
		}
		//swap
		if(k!=i)
		{
			t=r[i];
			r[i]=r[k];
			r[k]=t;
		}
	}
}

//������
void Sift(int r[], int n, int k)  //����r[]�еĽ��k,ʹ���Ϊ��
{
	int fakenum = k+1;
	int fakechild = fakenum;
	int temp = r[k];

	for(;fakenum*2<n;fakenum = fakechild){
		fakechild = 2*fakenum;
		if(fakechild+1 <= n && r[fakechild-1] > r[fakechild]) fakechild++;
		if(r[fakechild-1] < r[fakenum-1]){
			r[fakenum-1] = r[fakechild-1];
		}else break;
	}
	r[fakenum-1] = temp;
}

void BSift(int r[],int n)
{
	//find half
	int i = (n+1)/2;
	//down
	for(;i>=0;i--){
		Sift(r,n,i);
	}
}

void HeapSort(int r[], int n)
{
	int result[n];
	BSift(r,n);
	//read
	for(int i = 0; i<n;i++){
		result[i] = r[0];
		r[0] = r[n-i-1];
		Sift(r,n-i,0);
	}
	//write
	for(int i = 0; i<n;i++){
		r[i] = result[i];
	}
}


//��������
void InsertSort(int r[], int n)
{
	for(int i = 1;i<n;i++){
		int t = r[i];
		int j = i-1;
		while(t<r[j]){
			r[j+1] = r[j];
			j--;
		}
		r[j+1] = t;
	}
}


//ϣ������
void ShellSort(int r[], int n)
{
	int i,j,k,h;
	int t;
	int m, index;
	int H[50];

	m=(int)(log(n)/log(2));
	for(index=0;index<m;index++)
	{
		H[index]=(int)(pow(2,index));
	}

	//ϣ��������������д����H��, H[0] = 1
	for(k=m-1;k>=0;k--)
	{
		h=H[k];
		for(i=h;i<n;i++)
		{
			t=r[i];
			j=i-h;
			while(j>=0 && t<r[j])
			{
				r[j+h]=r[j];
				j=j-h;
			}
			r[j+h]=t;
		}
	}

}


//ð������
void Bsort(int r[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=n-2;j>=i;j--){
			if(r[j]>r[j+1]) swap(&r[j],&r[j+1]); 
		}
	}
}

//��������
void Qksort(int r[],  int  low,  int high)
{
	int i,j;
	int temp;
	i=low;
	j=high;
	temp=r[i];
	while(i<j)
	{
		while(i<j && r[j]>=temp)
		{
			j--;
		}
		if(i<j)
		{
			r[i]=r[j];
			i++;
		}
		while(i<j && r[i]<=temp)
		{
			i++;
		}
		if(i<j)
		{
			r[j]=r[i];
			j--;
		}
	}
	r[i]=temp;
	if(low<i-1)
	{
		Qksort(r,low,i-1);
	}
	if(i+1<high)
	{
		Qksort(r,i+1,high);
	}
}


int main()
{
	int num[100];
	int n,i,sel;

	printf("�������ݳ���:");
	scanf("%d",&n);
	printf("��������%d������:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}

	printf("��ѡ������ʽ:\n");
	printf(" ---- ѡ������:1\n");
	printf(" ---- ������  :2\n");
	printf(" ---- ��������:3\n");
	printf(" ---- ϣ������:4\n");
	printf(" ---- ð������:5\n");
	printf(" ---- ��������:6\n");
	scanf("%d",&sel);

	switch(sel)
    {
		case 1:SelectSort(num,n);break;
		case 2:HeapSort(num,n);break;
		case 3:InsertSort(num,n);break;
		case 4:ShellSort(num,n);break;
		case 5:Bsort(num,n);break;
		case 6:Qksort(num, 0,n-1);break;
	}

	
	printf("������Ϊ:");
	for(i=0;i<n;++i)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
	return 0;
}

