#include <iostream>
using namespace std;
#include "FluxLog.h"
#include "toolmain.h"


int main(int argc, char const *argv[])
{
	if(argc==2 && argv[1][0]!='-')
	{
		onlyLogFile(argv[argc-1]);
	}
	else if(argc==4 && strcmp(argv[1],"-g")==0)
	{
		logFile_g(argv[argc-1],argv[2]);
	}
	else if(argc==5 && strcmp(argv[1],"-g")==0 && strcmp(argv[3],"-e")==0)
	{
		logFile_g_e(argv[argc-1],argv[2]);
	}
	else if(argc==5 && strcmp(argv[1],"-e")==0 && strcmp(argv[2],"-g")==0)
	{
		logFile_g_e(argv[argc-1],argv[3]);
	}
	else if(argc==6 && strcmp(argv[1],"-g")==0 && strcmp(argv[3],"-t")==0)
	{
		logFile_g_t(argv[argc-1],argv[2],argv[4]);
	}
	else if(argc==6 && strcmp(argv[1],"-t")==0 && strcmp(argv[3],"-g")==0)
	{
		logFile_g_t(argv[argc-1],argv[4],argv[2]);
	}
	else if(argc==7 && strcmp(argv[1],"-t")==0 && strcmp(argv[3],"-g")==0 && strcmp(argv[5],"-e")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[4],argv[2]);
	}
	else if(argc==7 && strcmp(argv[1],"-g")==0 && strcmp(argv[3],"-t")==0 && strcmp(argv[5],"-e")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[2],argv[4]);
	}
	else if(argc==7 && strcmp(argv[1],"-e")==0 && strcmp(argv[2],"-g")==0 && strcmp(argv[4],"-t")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[3],argv[5]);
	}
	else if(argc==7 && strcmp(argv[1],"-e")==0 && strcmp(argv[2],"-t")==0 && strcmp(argv[4],"-g")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[5],argv[3]);
	}
	else if(argc==7 && strcmp(argv[1],"-t")==0 && strcmp(argv[3],"-e")==0 && strcmp(argv[4],"-g")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[5],argv[2]);
	}
	else if(argc==7 && strcmp(argv[1],"-g")==0 && strcmp(argv[3],"-e")==0 && strcmp(argv[4],"-t")==0)
	{
		logFile_g_t_e(argv[argc-1],argv[2],argv[5]);
	}
	else
	{
		cout<<"analog : commande incorrecte - Tapez \"man ./analog.man\" pour afficher le manuel\n";
	}
    return 0;
}
