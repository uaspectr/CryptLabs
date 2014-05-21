// VigenereDeCode.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#pragma warning(disable :4996)

using namespace std;

char rect[52]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char tabula_recta[52][52];
string *code;
char **result_string;
int len=0;
int slen=0;
char key[10000];
int len_of_key=0;
int x=0;
int y=0;
int k=0;
int m=0;
int len_of_k=0;
char tmp[10000];



bool compare(string *code,char *rect,int i,int j)
{
	int l=0;

	bool flg=false;
	while(l<strlen(rect))
	{
		if(code[i][j]==rect[l])
		{
			flg=true;
			break;
		}
		l++;
	}

	return flg;
}

int main(int argc, char* argv[])
{

	if(argc!=3)
	{
		printf("Error: Invalid count of arguments");
		return 1;
	}

	// генерация tabularecta
	int shift=0;

	for (int i = 0; i < 52; i++)
		for (int j = 0; j < 52; j++)
		{
			shift = j + i;
			if (shift >= 52) shift = shift % 52;
			tabula_recta[i][j] = rect[shift];
		}
	

		// чтение их файла входного сообщения
		ifstream ifst(argv[1]);
		ofstream ofst(argv[2]);

		FILE* in=fopen(argv[1],"r");

	   long size=0;
	   fseek(in,0,SEEK_END);
	   size=ftell(in);
	   fseek(in,0,SEEK_SET);
	   fclose(in);
	   code=new string [size];

	   char **result_string= new char * [size];
	for (int i = 0; i < size; i++)
	{
		result_string[i]= new char[size];
	}


		while(!ifst.eof())
		{
			getline(ifst,code[k]);
			len+=code[k].length();
			k++;
		}
		
		

		// ввод и формирование ключа
		printf("\nEnter key\n key: ");
		gets(key);
		len_of_key=strlen(key);
		for (int i = 0; i < len_of_key; i++)
		{
			tmp[i]=key[i];
		}

		while(len_of_k<len)
		{
			for (int i = 0; i < len_of_key; i++)
			{
				key[i+len_of_k]=tmp[i];
			}
			len_of_k=strlen(key);
		}
		

		// вывод ключа
		printf("\nKey: ");
		for (int i = 0; i < len; i++)
		{
			printf("%c",key[i]);
		}
		printf("\n");



		// дешифровка входного сообщения
		int l = 0;
		int j= 0;
		bool flag = false;
		for (int i = 0; i < len; i++)
		{
			if(i!=0)
			ofst <<endl;
			l = 0;
			j = 0;
			flag = false;

			while ((l < 52) && (flag == false))
			{
				if (key[i] == rect[l])
				{

					x = l;
					flag = true;
				}
				l++;
			}

			slen=code[m].length();
			m++;

			while(j!=slen)
			{
			l=0;
			flag=false;
			if(!compare(code,rect,i,j))
			{
				result_string[i][j]=code[i][j];
				ofst << result_string[i][j];
				j++;
			}
			else
			{

			while ((l<52) && (flag == false))
			{
				if (code[i][j] == tabula_recta[x][l])
				{
					y = l;
					flag = true;
				}
				l++;
			}
			result_string[i][j]=rect[y];
			ofst << result_string[i][j];
			j++;
			}
			}
			
			

		}

		return 0;
}

