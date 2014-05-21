// CaesarCode.cpp: определяет точку входа для консольного приложения.
//

#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#pragma warning(disable :4996)


int len=0;
int key;
int i;

using namespace std;

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("Invalid count of arguments!");
		return 1;
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);


	printf("Please enter KEY:");
	scanf("%d",&key);
	key=(key+256)%256;
	FILE* in=fopen(argv[1],"r");

	long size=0;
	fseek(in,0,SEEK_END);
	size=ftell(in);
	fseek(in,0,SEEK_SET);

	fclose(in);

	string *str;

	str=new string [size];



	while(!ifst.eof())
	{
    getline(ifst,str[i]);
	len+=str[i].length();
	i++;
	}
	
	int slen;

	for (int i = 0; i < len; i++)
	{
		slen=str[i].length();
		for(int j=0; j < slen; j++)
		{
		str[i][j]+=key;
		}
	}
	i=0;
	while(i!=len)
	{
	  ofst << str[i]<<endl;
	  i++;
	}


	/*system("copy /A out.txt C:\\Users\\uaspectr\\Documents\\\"Visual Studio 2012\"\\Projects\\CaesarDecode\\ConsoleApplication1\\out.txt /A");*/
	return 0;
}

