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
typedef unordered_map<string,unsigned int> MapSecondaire1;
typedef multimap<unsigned int, string> MapSecondaire2;

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

    void AjouterTop10(string Cible, string Referent);
    // Mode d'emploi :
    // Ajouter une ligne dans la MapTop10
    // Contrat :
    //


    void GenererGraphe(string nomFichier);
    // Mode d'emploi :
    // Genere le fichier graphe nomFichier.dot
    // Contrat :
    //

    void Top10();
    // Mode d'emploi :
    // Génère les attributs Top10 et affiche le résultat
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    MapPrincipal MapGraphe;
    MapSecondaire1 MapTop10_1;
    MapSecondaire2 MapTop10_2;
    


};

//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // Stats_H

