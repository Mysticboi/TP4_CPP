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

FluxLog::FluxLog ( string nomFichier)
// Algorithme :
//
{
    open(nomFichier);
#ifdef MAP
    cout << "Appel au constructeur de <FluxLog>" << endl;
#endif
} //----- Fin de FluxLog



FluxLog::~FluxLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FluxLog>" << endl;
#endif
} //----- Fin de ~FluxLog

LigneLog FluxLog:: ProchainLog() const{
    
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

