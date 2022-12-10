//
// Created by pedro on 15/11/22.
//

//Edited by Juan Freire on 10/12/2022
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Herois.h"
#include "LeitorDeDados.h"
using namespace std;

vector<pair<string,vector<int>>> sendStatus(string entity)
{
    vector<int>variaveisInteiras;
    vector<pair<string,vector<int>>> allStatus;
    
    string race;
    string name;
    string atk;
    string def;
    string lif;
    
    int atkI;
    int defI;
    int lifI;
    pair<string, vector<int>> auxPair;
    
    fstream arquivo;

    if(entity == "Dwarf"){arquivo.open("Dwarf.txt", ios::in);}
    else if(entity == "Inimigo"){arquivo.open("Inimigo.txt", ios::in);}
    else if(entity == "Boss"){arquivo.open("Boss.txt", ios::in);}

    if(arquivo.is_open()){
        while(arquivo.good()){
            getline(arquivo,race);
            getline(arquivo,name);
            getline(arquivo,atk);
            getline(arquivo,def);
            getline(arquivo,lif);
            atkI = stoi(atk);
            defI = stoi(def);
            lifI = stoi(lif);
            variaveisInteiras.push_back(atkI);
            variaveisInteiras.push_back(defI);
            variaveisInteiras.push_back(lifI);
            auxPair = make_pair(name, variaveisInteiras);
            allStatus.push_back(auxPair);
        }
        arquivo.close();
    }
    return allStatus;
}