#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdarg>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <cerrno>

using namespace std;

#define PI 3.14159265

enum dbgouttype {DBGOUT_COUT,DBGOUT_NOTEPAD};
dbgouttype DBGOUT=DBGOUT_COUT;

ostream *output=&cout;
fstream filestream;		//don't initialize unless needed.

void Err(char* str,...)
{
	//decipher variable number arguments
	char string[1024];		//temp string
	va_list ap;					//list of arguments
	va_start(ap,str);			//initialize ap, takes last parameter name as arg
	vsprintf(string,str,ap);//sprintf arguments in ap into variable string via str
	va_end(ap);					//denitialize ap

	*output<<"Error: "<<string<<endl;
}
void Dbg(char* str,...)
{
	//decipher variable number arguments
	char string[1024];		//temp string
	va_list ap;					//list of arguments
	va_start(ap,str);			//initialize ap, takes last parameter name as arg
	vsprintf(string,str,ap);//sprintf arguments in ap into variable string via str
	va_end(ap);					//denitialize ap

	*output<<"Debug: "<<string<<endl;
}
template<class T>
void Err(T str)
{
	*output<<"Error: "<<str<<endl;
}
template<class T>
void Dbg(T str)
{
	*output<<"Debug: "<<str<<endl;
}

void updateOUT(dbgouttype a)
{
	switch(a)
	{
		case DBGOUT_NOTEPAD:
			if(DBGOUT!=a)
			{
				filestream.open("output.txt");	//open notepad file
				output=&filestream;					//use notepad as stream
				DBGOUT=DBGOUT_NOTEPAD;				//set dbgout
			}
			break;
		case DBGOUT_COUT:
			if(DBGOUT==DBGOUT_NOTEPAD)
				filestream.close();						//close notepad file.
			if(DBGOUT!=a)
			{
				output=&cout;							//use file as stream
				DBGOUT=DBGOUT_COUT;					//set dbgout
			}
			break;
		default:
			Err((char*)"Unrecognized output device %i",a);
			break;
	}
}
