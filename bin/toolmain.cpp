#include "toolmain.h"
#include "Stats.h"
#include "FluxLog.h"

//gère le cas où aucune option n'est saisie
void onlyLogFile(const char * logFileNamec)
{
	//passage de char * à string
	string logFileName = logFileNamec;

	//tests de la validité des arguments
	checkLogFile(logFileName);
	
	//instanciation du fluxLog et de la ligneLog et d'un objet stats
	LigneLog myLigneLog;
	FluxLog myFlux(logFileName);
	Stats G;

	//Boucle de traitement du fichier
//	while(!myFlux.eof())
//	{
//		myLigneLog = myFlux.ProchainLog();
////      Ligne Vide
//      if(myLigneLog.Cible=="" && myLigneLog.Referant=="" && myLigneLog.Navigateur=="")
//      	continue;
//		if(myLigneLog.Cible=="-")
//			continue;
//		else
//			G.AjouterTop10(myLigneLog.Cible);
//	}
//	G.Top10();



}

//gère le cas où seule l'option -g est renseignée
void logFile_g(const char * logFileNamec, const char * fileNameDotc)
{
	//passage de char * à string
	string logFileName = logFileNamec;
	string fileNameDot = fileNameDotc;

	//formatage et tests de la validité des arguments
	checkLogFile(logFileName);
	string dotFileName = formatDotFileName(fileNameDot);
	
	//instanciation du fluxLog et de la ligneLog et d'un objet stats
	LigneLog myLigneLog;
	FluxLog myFlux(logFileName);
	Stats G;

	//boucle de traitement du fichier
	while(!myFlux.eof())
	{
		myLigneLog = myFlux.ProchainLog();
//      Ligne Vide
      if(myLigneLog.Cible=="" && myLigneLog.Referant=="" && myLigneLog.Navigateur=="")
      	continue;
		if(myLigneLog.Cible=="-" || myLigneLog.Referant=="-")
			continue;
		else
			G.AjouterGraphe(myLigneLog.Cible,myLigneLog.Referant);
	}
	G.GenererGraphe(dotFileName);

}

//gère le cas où les options -g et -t sont renseignées
void logFile_g_t(const char * logFileNamec,const char * fileNameDotc,const char * Heurec)
{
	//passage de char * à string
	string logFileName = logFileNamec;
	string fileNameDot = fileNameDotc;
	string Heure = Heurec;

	//formatage et tests de la validité des arguments
	checkLogFile(logFileName);
	checkDateTime(Heure);
	string dotFileName = formatDotFileName(fileNameDot);
	
	//instanciation du fluxLog et de la ligneLog et d'un objet stats
	LigneLog myLigneLog;
	FluxLog myFlux(logFileName);
	Stats G;
	
	//boucle de traitement du fichier
	while(!myFlux.eof())
	{
		myLigneLog = myFlux.ProchainLog();
//      Ligne Vide
        if(myLigneLog.Cible=="" && myLigneLog.Referant=="" && myLigneLog.Navigateur=="")
      		continue;
		if(myLigneLog.Cible=="-" || myLigneLog.Referant=="-")
			continue;
		int HeureLigneLog = stoi(myLigneLog.Heure.substr(0,2))*100+stoi(myLigneLog.Heure.substr(3,2));
		int HeureSpecifie = stoi(Heure.substr(0,2))*100+stoi(Heure.substr(3,2));
		int HeureSpecifiePlus1 = HeureSpecifie+100;
		if(HeureLigneLog<HeureSpecifie || HeureLigneLog>HeureSpecifiePlus1)
			continue;
		else
			G.AjouterGraphe(myLigneLog.Cible,myLigneLog.Referant);
	}
	G.GenererGraphe(dotFileName);


}

//gère le cas où  les options -g et -e sont renseignées
void logFile_g_e(const char * logFileNamec, const char * fileNameDotc)
{
	//passage de char * à string
	string logFileName = logFileNamec;
	string fileNameDot = fileNameDotc;

	//formatage et tests de la validité des arguments
	checkLogFile(logFileName);
	string dotFileName = formatDotFileName(fileNameDot);
	
	//instanciation du fluxLog et de la ligneLog et d'un objet stats
	LigneLog myLigneLog;
	FluxLog myFlux(logFileName);
	Stats G;


	//boucle de traitement du fichier
	while(!myFlux.eof())
	{
		myLigneLog = myFlux.ProchainLog();
//      Ligne Vide
        if(myLigneLog.Cible=="" && myLigneLog.Referant=="" && myLigneLog.Navigateur=="")
      		continue;
		if(myLigneLog.Cible=="-" || myLigneLog.Referant=="-")
			continue;
		//On passe si le fichier est un js un css un jpeg un gif ou un png
		else if(myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".css" || myLigneLog.Cible.substr(myLigneLog.Cible.size()-3,3)==".js" || myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".jpg"||myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".gif"|| myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".png")
			continue;
		else
			G.AjouterGraphe(myLigneLog.Cible,myLigneLog.Referant);
	}
		G.GenererGraphe(dotFileName);


}

//gère le cas où les options -g et -t et -e sont renseignées
void logFile_g_t_e(const char * logFileNamec,const char * fileNameDotc,const char * Heurec)
{
	//passage de char * à string
	string logFileName = logFileNamec;
	string fileNameDot = fileNameDotc;
	string Heure = Heurec;

	//formatage et tests de la validité des arguments
	checkLogFile(logFileName);
	checkDateTime(Heure);
	string dotFileName = formatDotFileName(fileNameDot);
	
	//instanciation du fluxLog et de la ligneLog et d'un objet stats
	LigneLog myLigneLog;
	FluxLog myFlux(logFileName);
	Stats G;

	//boucle de traitement du fichier
	while(!myFlux.eof())
	{
		myLigneLog = myFlux.ProchainLog();
//      Ligne Vide
        if(myLigneLog.Cible=="" && myLigneLog.Referant=="" && myLigneLog.Navigateur=="")
      		continue;
		if(myLigneLog.Cible=="-" || myLigneLog.Referant=="-")
			continue;
		int HeureLigneLog = stoi(myLigneLog.Heure.substr(0,2))*100+stoi(myLigneLog.Heure.substr(3,2));
		int HeureSpecifie = stoi(Heure.substr(0,2))*100+stoi(Heure.substr(3,2));
		int HeureSpecifiePlus1 = HeureSpecifie+100;
		if(HeureLigneLog<HeureSpecifie || HeureLigneLog>HeureSpecifiePlus1)
			continue;
		//On passe si le fichier est un js un css un jpeg un gif ou un png
		else if(myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".css" || myLigneLog.Cible.substr(myLigneLog.Cible.size()-3,3)==".js" || myLigneLog.Cible.substr(myLigneLog.Cible.size()-5,5)==".jpeg"||myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".gif"|| myLigneLog.Cible.substr(myLigneLog.Cible.size()-4,4)==".png")
			continue;
		else
			G.AjouterGraphe(myLigneLog.Cible,myLigneLog.Referant);
	}
		G.GenererGraphe(dotFileName);

}
