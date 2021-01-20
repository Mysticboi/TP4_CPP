/*************************************************************************
                           FluxLog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <FluxLog> (fichier FluxLog.h) ----------------
#if ! defined ( FluxLog_H )
#define FluxLog_H


//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FluxLog>
//
//
//------------------------------------------------------------------------

//Création structure LigneLog

struct LigneLog{
    string IP;
    string UserLogname;
    string AuthenticatedUser;
    string Date;
    string Heure;
    string Status;
    string QuantiteDonnees;
    string Referant;
    string Navigateur;

    // Opérateur = pas besoin de surcharger car classe simple 
};




class FluxLog:public ifstream
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    /*FluxLog & operator = ( const FluxLog & unFluxLog );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


//-------------------------------------------- Constructeurs - destructeur
    FluxLog ( const FluxLog & unFluxLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FluxLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    FluxLog(string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FluxLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    LigneLog ProchainLog() const;



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <FluxLog>

#endif // FluxLog_H

