/*************************************************************************
                           FluxLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <FluxLog> (fichier FluxLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <sstream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "FluxLog.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type FluxLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*FluxLog & FluxLog::operator = ( const FluxLog & unFluxLog )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
FluxLog::FluxLog ( const FluxLog & unFluxLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FluxLog>" << endl;
#endif
} //----- Fin de FluxLog (constructeur de copie)


FluxLog::FluxLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FluxLog>" << endl;
#endif
} //----- Fin de FluxLog

FluxLog::FluxLog(string nomFic)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FluxLog>" << endl;
#endif
	file.open(nomFic);

} //----- Fin de FluxLog



FluxLog::~FluxLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FluxLog>" << endl;
#endif
file.close();
} //----- Fin de ~FluxLog

LigneLog FluxLog::ProchainLog(){
	LigneLog myLigneLog;
	string line;
	getline(file,line);

	vector <string> tokens;

    stringstream check1(line);

    string intermediate;

    while(getline(check1, intermediate, '"')){
        tokens.push_back(intermediate);
	}
	if(tokens.size()<3){
		return myLigneLog;
	}
	myLigneLog.Navigateur = tokens[tokens.size()-1];
	myLigneLog.Referant = tokens[tokens.size()-3];

	tokens.clear();
	intermediate.clear();
    stringstream check2(line);
    while(getline(check2, intermediate, ' ')){
        tokens.push_back(intermediate);
	}
	
	if(tokens.size()<10){
		return myLigneLog;
	}
	myLigneLog.IP = tokens[0];
	myLigneLog.UserLogname = tokens[1];
	myLigneLog.AuthenticatedUser = tokens[2];
	myLigneLog.Date = tokens[3].substr(1,tokens[3].size()-10);
	myLigneLog.Heure = tokens[3].substr(tokens[3].size()-8,5);
	myLigneLog.Cible = tokens[6];
	myLigneLog.Status = tokens[8];
	myLigneLog.QuantiteDonnees = tokens[9];
	if(myLigneLog.Referant.size()>=32 && myLigneLog.Referant.substr(0,32)=="http://intranet-if.insa-lyon.fr/")
		myLigneLog.Referant = myLigneLog.Referant.substr(32,myLigneLog.Referant.size()-32);
	if(myLigneLog.Cible.size()>1)
		myLigneLog.Cible = myLigneLog.Cible.substr(1,myLigneLog.Cible.size()-1);
	return myLigneLog;
}

bool FluxLog::eof()
{
	return file.eof();
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
