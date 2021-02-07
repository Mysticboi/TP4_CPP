#include "toolmain1.h"
void checkLogFile(string nomficlog)
{
	ifstream file(nomficlog);
	if(file.fail() || nomficlog.substr(nomficlog.size()-4,4)!=".log")
	{
		cout<<"Vous devez renseigner un fichier log existant avec une extension \".log\""<<endl;
		cout<<"Pour plus d'informations veuillez consulter le manuel : \"man ./analog.man\""<<endl;
		file.close();
		exit(0);
	}
}

string formatDotFileName(string dotFileName)
{
	if(dotFileName.size()<=4 || dotFileName.substr(dotFileName.size()-4,4)!=".dot")
		dotFileName.append(".dot");
	return dotFileName;
}

void checkDateTime(string Heure)
{
	if(Heure.size()!=5)
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	else if(Heure[2]!=':')
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	//le premier chiffre de l'heure est au dessus de 2 ou n'est pas un chiffre
	else if(!(Heure[0]==48 || Heure[0]==49 || Heure[0]==50))
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	//le deuxième chiffre de l'heure n'est pas un chiffre
	else if(!(Heure[1]>=48 && Heure[1]<=57))
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	//l'heure est supérieure à 23
	else if(Heure[0]==50 && Heure[1]>=52)
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	//le premier chiffre des minutes est au dessus de 5 ou n'est pas un chiffre 
	else if(!(Heure[3]>=48 && Heure[3]<=53))
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
	//le deuxième chiffre des minutes n'est pas un chiffre
	else if(!(Heure[4]>=48 && Heure[4]<=57))
	{
		cout<<"Heure invalide - Veuillez rentrer une heure de la forme HH:MM"<<endl;
		exit(0);
	}
}
