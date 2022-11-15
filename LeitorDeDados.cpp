//
// Created by pedro on 15/11/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string,vector<int>>> sendStatus()
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
    arquivo.open("personagensInfo.txt", ios::in);
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
            auxPair = make_pair(name,variaveisInteiras);
            allStatus.push_back(auxPair);
        }
        arquivo.close();
    }
    return allStatus;
}