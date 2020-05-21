#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//统计字符数
void CharCount()
{
	FILE *fp;
	int cc=0;
	char ch;
	if((fp = fopen("input.txt","r")) == NULL)
	{
		printf("文件打开失败"); 
	}
	ch = fgetc(fp);
	while(ch != EOF)
	{
		cc++;
		ch = fgetc(fp);
	 } 
	 printf("字符数：%d\n",cc);
	 fclose(fp);
 } 
 
 //统计单词数
 void WordCount()
 {
 	FILE *fp;
	int wc=0,f=0;
	char ch;
	if((fp = fopen("input.txt","r")) == NULL)
	{
		printf("文件打开失败"); 
	}
	ch = fgetc(fp);
	while(ch != EOF)
	{
		if(ch==' ')
		{
			f=0;
			ch = fgetc(fp);
		}
		else
		{
			if(f==0)
			{
				wc++;
				f=1;
			}
			ch = fgetc(fp);
		}
	}
	printf("单词数：%d\n",wc);
	fclose(fp);
  } 
  
int main(int argc, char *argv[]) {
	//统计字符数 
	if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "input.txt") == 0))
	{
		CharCount();
	}
	//统计单词数 
	if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "input.txt") == 0))
	{
		WordCount(); 
	} 
	return 0;
}
