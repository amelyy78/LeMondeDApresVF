#pragma once
#include<cstdlib>
#include <string>

#include "Lieu.hh"

class Course : public Lieu{
private:
	static std::default_random_engine _generator;
  	static std::uniform_int_distribution<int> _distribution;
protected:
	//la donnée du lieu concerne le nombre d'articles achetés
	int nbArticlesMax;
	
public:
	//constructeur
	Course(std::string name) : Lieu(name) {
		nbArticlesMax = 15;
	}
	//accesseur
	int getNbArticlesMax() const{
		return nbArticlesMax;
	}

};