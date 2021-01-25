#include<iostream>
#include<cstdlib>
#include <string>

#include "Travail.hh"

class Entreprise : public Travail{

protected:
	
public:
	Entreprise(std::string name) : Travail(name) {
		frequentationMax = 130;
		fContamination = 80;
		affluence = 50;
		tempsMax = 10;
	}
	//plus la durée sur le site et l'affluence st élevées, plus cela a impact négatif 
	//plus de risque de contamination
	//si la durée max sur le site est atteinte, ça compte double
	void impact(Personnage &perso) const{
		int nonimmun = 0;
		std::map<std::string, int>::const_iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first != "immunisés"){
				nonimmun = it->second;
			}
		}

		int impactPhy;
		if(perso.getDonneeLieu() == tempsMax){
			impactPhy = 2*(perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		else{
			impactPhy = (perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		perso.setPhysique(-impactPhy);

		//plus la durée est élevée, plus cela a un impact négatif
		//d'un autre cote, bien de voir des gens : impact positif
		int impactMent = (perso.getDonneeLieu())%10 - 4;
		perso.setMental(-impactMent);

		//rapporte de l'argent
		perso.setMonnaie(50);
	}
};