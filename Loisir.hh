#pragma once
#include<cstdlib>
#include <string>

#include "Lieu.hh"

class Loisir : public Lieu{
private:
	static std::default_random_engine _generator;
  	static std::uniform_int_distribution<int> _distribution;

protected:
	//la donnée du lieu concerne le nombre de bieres consommées, films regardés ou de machines de sport utilisées
	int nbMax;
	
public:
	Loisir(std::string name) : Lieu(name) {
		nbMax = 5;
	}

	int getNbMax() const{
		return nbMax;
	}
};