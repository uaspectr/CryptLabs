// VigenereCode.cpp: определяет точку входа для консольного приложения.
//
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#pragma warning(disable :4996)

using namespace std;
bool compare(string *buf,char *rect,int i,int j);

int length=0,len=0;

int x=0,y=0;

bool flag=false;
char **key;
char **tmp;
int cnt;
int k;
int len_of_key=0;
int len_of_k=0;
char rect[52]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char tabula_recta[52][52];
char **res_string;
string *buf;




bool compare(string *buf,char *rect,int i,int j)
{
int l=0;

bool flg=false;
while(l<strlen(rect))
{
if(buf[i][j]==rect[l])
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


// генерация tabularecta
if(argc!=3)
{
printf("Error: invalid count of arguments\n");
return 1;
}
ifstream ifst (argv[1]);
ofstream ofst (argv[2]);

FILE* in=fopen(argv[1],"r");

long size=0;
fseek(in,0,SEEK_END);
size=ftell(in);
fseek(in,0,SEEK_SET);

fclose(in);


buf=new string [size];

char **res_string= new char * [size];
char **key = new char * [size];
char **tmp = new char * [size];
for (int i = 0; i < size; i++)
{
res_string[i]= new char[size];
key[i]=new char[size];
tmp[i]=new char[size];
}

int shift=0;

for (int i = 0; i < 52; i++)
for (int j = 0; j < 52; j++)
{
shift = j + i;
if (shift >= 52) shift = shift % 52;
tabula_recta[i][j] = rect[shift];
}

for (int i = 0; i < 52; i++)
{
for (int j = 0; j < 52; j++)
{
printf("%c",tabula_recta[i][j]);
}
printf("\n");
}




int i;
// чтение из файла входного сообщения
while(!ifst.eof())
{
getline(ifst,buf[k]);
len+=buf[k].length();
k++;
}
cnt=k;



// ввод и формирования ключа
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



// вывод ключа на экран
printf("\nKey: ");
for (int i = 0; i < len; i++)
{
printf("%c",key[i]);
}
printf("\n");




// шифр входного сообщения и запись его в выходной файл
int l=0;
int j=0;
int m=0;
for(int i = 0; i < cnt ; i++)
{
if (i!=0)
ofst << endl;
l=0;
j=0;
flag=false;
while(l < 52&&flag==false)
{
if(key[i]==rect[l])
{
x=l;
flag=true;
}
l++;
}
int slen;





slen=buf[m].length();
m++;
while(j!=slen)
{
l=0;
flag=false;

if(!compare(buf,rect,i,j))
{
res_string[i][j]=buf[i][j];
ofst << res_string[i][j];
j++;
}
else
{
while (l < 52 && flag==false)
{



if(buf[i][j]==rect[l])
{
y=l;
flag=true;
}
l++;



}
res_string[i][j]=tabula_recta[x][y];
ofst << res_string[i][j];
j++;
}
}




}



return 0;
}
