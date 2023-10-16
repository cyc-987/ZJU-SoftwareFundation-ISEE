#include <stdio.h>
#include <stdlib.h>

typedef struct huffman_node 
{
	int data;
	int lchild;
	int rchild;
	int parent;
}bnode;  //定义二叉链表结点结构

void SelectIJ(int k, bnode node[], int *i, int *j)
{
	*i = *j = 0;
	int min1 = 32767, min2 = 32767;
	for(int m = 0;m<k;m++){
		if(node[m].parent == 0){
			if(node[m].data < min1){
				min2 = min1;
				*j = *i;
				min1 = node[m].data;
				*i = m;
			}
			else if(node[m].data < min2){
				min2 = node[m].data;
				*j = m;
			}
		}
	}
}

void HuffmanTree(int n, bnode node[],int w[])
{
	int i,j;
	for(int i = 0;i<n;i++){
		node[i].data = w[i];
		node[i].lchild = node[i].rchild = 0;
	}
	for(int i = 0;i<2*n-1;i++) node[i].parent = 0;
	for(int k = n;k<2*n-1;k++){
		SelectIJ(k,node,&i,&j);
		node[k].data = node[i].data + node[j].data;
		node[k].lchild = i;
		node[k].rchild = j;
		node[i].parent = node[j].parent = k;
	}
}

void printHuffmanTree(int i, bnode node[])
{
	int code[26];
	int n = 0, j = 0;
	do
	{
		if(node[node[i].parent].lchild == i){
			code[n++] = 0;
		}
		else{
			code[n++] = 1;
		}
		i = node[i].parent;
	}while(i != 50);
	for(int j = n-1;j>=0;j--){
		printf("%d",code[j]);
	}
}

void main()
{
	FILE *fp;
	int weight[26];

	int i,j;
	int ch;
	int n;

	bnode *node;
	unsigned long code;

	for(i=0; i<26; i++)
	{
		weight[i] = 0;
	}

	if( (fp = fopen("StrayBirds.txt","r")) == NULL )
		return;

	do {
		ch = fgetc(fp);

		if (!( ((ch>=97)&&(ch<=122)) ||
			   ((ch>=65)&&(ch<=90 ))	 )
		   )
		{
			continue;
		}
		if( (ch>=97)&&(ch<=122) )
		{
			ch -= 32;
		}
        putchar(ch);
		weight[ch-65]++;
	} while(feof(fp)==0);

	printf("\n");

	n = 0;
	for(i=0; i<26; i++)
	{
		if(weight[i] > 0) 
		{
			n++;
			printf("%c  %d \n", i+65, weight[i]);
		}
	}

	node = (bnode *)malloc((2*26-1) * sizeof(bnode));

	//建立哈夫曼树
	HuffmanTree(26, node, weight);

	//哈夫曼编码
	for (i=0; i<26; i++)
	{
		printf("Now processing %c -----", i+65);
		printHuffmanTree(i, node);
		printf("\n");
	}

	free(node);
	fclose(fp);
}