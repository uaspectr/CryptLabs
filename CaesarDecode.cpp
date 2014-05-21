#include "stdafx.h"
#include <conio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

#pragma warning(disable :4996)
using namespace std;
int len=0;
int key;
int i=0;

int main(int argc, char* argv[])
{
	
	if(argc!=3)
	{
		printf("Invalid count of arguments!");
		_getch();
		return 1;
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	
	
	printf("Please enter KEY for decode:");
	scanf("%d",&key);

	key=(key+256)%256;

	FILE* in=fopen(argv[1],"r");

	long size=0;
	fseek(in,0,SEEK_END);
	size=ftell(in);
	fseek(in,0,SEEK_SET);

	fclose(in);

	string *buf;

	buf=new string [size];

	while(!ifst.eof())
	{
    getline(ifst,buf[i]);
	len+=buf[i].length();
	i++;
	}
	
	int slen;

	for (int i = 0; i < len; i++)
	{
		slen=buf[i].length();
		for(int j=0; j < slen; j++)
		{
		buf[i][j]-=key;
		}
	}
	i=0;
	while(i!=len)
	{
	  ofst << buf[i]<<endl;
	  i++;
	}


	printf("\nFinish...press any key\n");
	getch();
	return 0;
}
