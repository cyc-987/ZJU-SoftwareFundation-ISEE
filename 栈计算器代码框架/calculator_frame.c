#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP    100
#define NUMBER   '0'    // signal that a number was found
#define EMPTY    0

int getop(char []);
double calc(double num1, double num2, char c)
{
	if(c == '+') return num1+num2;
	else if(c == '-') return num2-num1;
	else if(c == '*') return num1*num2;
	else return num2/num1;
}

int main()
{
	int c;
	char s[MAXOP];

	//initialize two stacks
	double NS[MAXOP];
	int topNS = 0;
	char OS[MAXOP];
	OS[0] = ';';
	int topOS = 1;
	int isEnd = 0;
	int notGet = 0;

	while (isEnd == 0) 
	{
		if(!notGet){
			c = getop(s);
		}
		if(c == EOF){
			notGet = 1;
		}
		switch (c) 
		{
			case NUMBER:
			{
				//////////////////////////////////////////////////////////////////////////
				char** ptr = NULL;
				double number = strtod(s,ptr);
				NS[topNS] = number;
				topNS++;
				//////////////////////////////////////////////////////////////////////////
				printf("%lf\n", atof(s));
				break;
			}
			case '+':        // + 和 - 优先级最低，把除了 '(' 以外的全部操作符弹出后入栈
			case '-':
			{
				//////////////////////////////////////////////////////////////////////////
				if(OS[topOS-1] != '(' && OS[topOS-1] != ';'){
					//pop one op
					char op = OS[topOS-1];
					topOS--;
					//pop two number
					double num1, num2;
					num1 = NS[topNS-1];topNS--;
					num2 = NS[topNS-1];topNS--;
					//push the number back
					double num = calc(num1,num2,op);
					NS[topNS] = num;
					topNS++;
				}
					//push the op in
					OS[topOS] = c;
					topOS++;
				
				//////////////////////////////////////////////////////////////////////////
				printf("%c\n", c);
				break;
			}
			case '*':              // 乘除优先级最高，把相同优先级的乘和除弹出后入栈
			case '/':
			{
				//////////////////////////////////////////////////////////////////////////
				if(OS[topOS-1] == '*' || OS[topOS-1] == '/'){
					//pop one op
					char op = OS[topOS-1];
					topOS--;
					//pop two number
					double num1, num2;
					num1 = NS[topNS-1];topNS--;
					num2 = NS[topNS-1];topNS--;
					//calculate
					double num = calc(num1,num2,op);
					//push the result
					NS[topNS] = num;
					topNS++;
				}
					OS[topOS] = c;
					topOS++;
				
				//////////////////////////////////////////////////////////////////////////
				printf("%c\n", c);
				break;
			}
			case '(':        // '(' 不作运算，直接放入optor栈。
			{
				//////////////////////////////////////////////////////////////////////////
				OS[topOS] = '(';
				topOS++;
				//////////////////////////////////////////////////////////////////////////
				printf("%c\n", c);
				break;
			}
			case ')':        // 把 '(' 之前的全部操作符弹出，计算后把 '(' 也弹出
			{
				//////////////////////////////////////////////////////////////////////////
				//pop one op
				char op = OS[topOS-1];
				topOS--;
				//if op=(, goes on
				if(op != '('){
					//pop two number
					double num1, num2;
					num1 = NS[topNS-1];topNS--;
					num2 = NS[topNS-1];topNS--;
					//calculate the result
					double num = calc(num1,num2,op);
					//push back
					NS[topNS] = num;
					topNS++;
					if(OS[topOS-1] != '('){
						notGet = 1;
						c = ')';
					}else{
						topOS--;
						notGet = 0;
					}
				}
				
				//////////////////////////////////////////////////////////////////////////
				printf("%c\n", c);
				break;
			}
			case '\n':        // 把余下的操作符全部弹出，计算后输出结果
			{
				//////////////////////////////////////////////////////////////////////////
				//pop one op
				char op = OS[topOS-1];
				topOS--;
				//calculate
				if(op != ';'){
					//pop two number
					double num1, num2;
					num1 = NS[topNS-1];topNS--;
					num2 = NS[topNS-1];topNS--;
					//calc
					double num = calc(num1, num2, op);
					//push back
					NS[topNS] = num;
					topNS++;
					notGet = 1;
					if(OS[topOS-1] != ';'){
						c = '\n';
					}
				}
				//////////////////////////////////////////////////////////////////////////
				printf("%c\n", c);
				if(OS[topOS-1] == ';'){
					isEnd = 1;
					printf("%.2f",NS[topNS-1]);
				}
				break;
			}
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getchar()) == ' ' || c == '\t')
    ;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; 
	
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getchar())) ;
	
	if (c == '.') 
		while (isdigit(s[++i] = c = getchar()))  ;
	
	s[i] = '\0';
	if (c != EOF)  ungetc(c, stdin);
	return NUMBER;
}