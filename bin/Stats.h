/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
#if ! defined ( Stats_H )
#define Stats_H

//--------------------------------------------------- Interfaces utilisées
#include "FluxLog.h"
#include <map>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef unordered_map<string,unordered_map<string,unsigned int>> MapPrincipal;
typedef unordered_map<string,unsigned int> UMapTop10;
typedef multimap<unsigned int, string> MMapTop10;

typedef unordered_map<string,unsigned int> MapSecondaire1;


//------------------------------------------------------------------------
// Rôle de la classe <Stats>
//
//
//------------------------------------------------------------------------

class Stats 
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
    /*Stats & operator = ( const Stats & unStats );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


//-------------------------------------------- Constructeurs - destructeur
    Stats ( const Stats & unStats );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stats ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stats ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterGraphe(string Cible, string Referent);
    // Mode d'emploi :
    // Ajouter une ligne dans la MapGraphe
    // Contrat :
    //

    void GenererGraphe(string nomFichier);
    // Mode d'emploi :
    // Genere le fichier graphe nomFichier.dot
    // Contrat :
    //

    void Recenser(string Cible);
    // Mode d'emploi :
    // Ajouter une ligne dans la MapTop10
    // Contrat :

    void Top10();
    // Mode d'emploi :
    // 
    // Contrat :

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    MapPrincipal MapGraphe;
    UMapTop10 UMap;
    MMapTop10 MMap;
    


};

//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // Stats_H

