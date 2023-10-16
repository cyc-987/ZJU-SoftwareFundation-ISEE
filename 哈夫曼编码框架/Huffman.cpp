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

}

void HuffmanTree(int n, bnode node[],int w[])
{
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
	//HuffmanTree(26, node, weight);

	//哈夫曼编码
	for (i=0; i<26; i++)
	{
		printf("Now processing %c -----", i+65);
		
		printf("\n");
	}

	free(node);
	fclose(fp);
}