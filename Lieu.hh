#pragma once
#include<iostream>
#include<cstdlib>
#include <string>
#include <map>

#include "Personnage.hh"
//un lieu est composé de personnages

class Lieu{
protected:
	int frequentationMax; 					//frequentation Max du lieu, dit si oui ou non le perso peut y alle
	int fContamination; 					//facteur de contamination
	int affluence; 							//si ya bcp de monde ou pas dans le courant 
	std::string nom;						//Nom du lieu
	std::map<std::string, int> mapPerso; 	//Nombre de personnes immunisées et non immunisées dans le lieu

	public:
	//constructeur
	Lieu(std::string name){
		nom = name;
		affluence = 0; 						
		mapPerso["immunisés"] = 0;
		mapPerso["nonimmunisés"] = 0;
	}
	virtual ~Lieu(){};

	//accesseurs - getters
	int getFreqMax() const{
		return frequentationMax;
	}

	int getFContamination() const{
		return fContamination;
	}

	int getAffluence() const{
		return affluence;
	}

	std::string getNom() {
		return nom;
	}
	int getNbImmun(){
		std::map<std::string, int>::iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first == "immunisés")
				return it->second;
		}
		return 0;
	}
	int getNbNonImmun(){
		std::map<std::string, int>::iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first == "nonimmunisés"){
				return it->second;
			}
		}
		return 0;
	}
	//permet d'obtenir la map du lieu
	std::map<std::string, int> getMapPerso(){
		return mapPerso;
	}
	void setAffluence(int newAffluence){
		affluence = newAffluence;
	}
	void setMapPerso(int immun, int nonimmun){
		std::map<std::string, int> it;
		mapPerso["immunisés"] += immun;
		mapPerso["nonimmunisés"] += nonimmun;
	}
	void setNbNonImmun(int nb){
		std::map<std::string, int>::iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first == "nonimmunisés"){
				it->second = nb;
			}
		}
	}
	//impact que le lieu a sur le personnage
	//dépend de chaque lieu
	virtual void impact(Personnage &perso) const=0;
};