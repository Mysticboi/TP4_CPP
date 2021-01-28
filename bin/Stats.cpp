/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Stats> (fichier Stats.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Stats.h"
#include <vector>
#include <algorithm>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Stats::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*Stats & Stats::operator = ( const Stats & unStats )
// Algorithme :
//
{
} //----- Fin de operator =
*/


//-------------------------------------------- Constructeurs - destructeur
Stats::Stats ( const Stats & unStats )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats>" << endl;
#endif
} //----- Fin de Stats (constructeur de copie)


Stats::Stats ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats>" << endl;
#endif
} //----- Fin de Stats


Stats::~Stats ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats>" << endl;
#endif
} //----- Fin de ~Stats

void Stats::AjouterGraphe(string Cible, string Referent)
// Algorithme :
//
{   
    // On cherche cible
    // Si Cible n'existe pas
    if(MapGraphe.find(Cible)==MapGraphe.end()){
        MapSecondaire1 mappair;
        mappair[Referent]=1;
        MapGraphe[Cible]=mappair;
    }
    //Si Cible existe
    else{
        MapSecondaire1 mappair;
        mappair=MapGraphe[Cible];
        //On cherche le référent
        //Si référent n'existe pas
        if(mappair.find(Referent)==mappair.end()){
            mappair[Referent]=1;
        }
        //Si référent existe
        else{
            mappair[Referent]=mappair[Referent]+1;
        }
        MapGraphe[Cible]=mappair;

    }
    
}

void Stats::GenererGraphe(string nomFichier)
// Algorithme :
//
{
    ofstream file;
    file.open(nomFichier);
    if(!file.good() or nomFichier.find(".dot")==string::npos){
        cerr<<"Nom fichier erroné"<<endl;
        return;
    }
    file<<"digraph {"<<endl;
    MapPrincipal::const_iterator itr1;
    MapSecondaire1::const_iterator itr2;
    vector <string> vNodes; // Tableau des nodes présents

    // Création de tous les nodes
    for(itr1=MapGraphe.begin(); itr1!=MapGraphe.end(); itr1++){
        // Si le node n'est pas déja présent dans le tableau des nodes on l'ajoute
        if(find(vNodes.begin(),vNodes.end(),itr1->first) ==vNodes.end()){
            vNodes.push_back(itr1->first);
        }
        MapSecondaire1 mappair=itr1->second;
        for(itr2=mappair.begin(); itr2!= mappair.end(); itr2++){
            if( find(vNodes.begin(),vNodes.end(),itr2->first) == vNodes.end() ){
                vNodes.push_back(itr2->first);
            }
        }
    }

    //Ecriture des nodes sur le digraph
    int i=0; // index du node
    for(vector<string>::const_iterator itr= vNodes.cbegin(); itr!=vNodes.cend(); itr++){
        file<<"node"<<i<<" [label=\"/"<<*itr<<"\"];"<<endl;
        ++i;
    }
    int j=0;

    //Ecriture des relations entre les nodes sur le digraph
    for(itr1=MapGraphe.begin(); itr1!=MapGraphe.end(); itr1++){
        i= find(vNodes.begin(),vNodes.end(),itr1->first) - vNodes.begin(); // index de la cible
        MapSecondaire1 mappair=itr1->second;
        for(itr2=mappair.begin(); itr2!= mappair.end(); itr2++){
            j=find(vNodes.begin(),vNodes.end(),itr2->first) - vNodes.begin(); // index du référent
            file<<"node"<<j<<" -> node"<<i<<" [label=\""<<itr2->second<<"\"];"<<endl;
        }
    }

    file<<"}";
    file.close();
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

