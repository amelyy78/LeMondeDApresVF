#include<iostream>
#include<cstdlib>
#include <string>

#include "Transport.hh"

class Metro : public Transport {
private:

public:
	Metro(std::string name) : Transport(name) {
		frequentationMax = 90;
		fContamination = 80;
		affluence = 50; 
		distanceMax = 40;
	}
	//plus la distance et l'affluence st élevées, plus cela a impact négatif 
	//plus de risque de contamination
	//si la distance max est atteinte, ça compte double
	void impact(Personnage &perso) const{
		int nonimmun = 0;
		std::map<std::string, int>::const_iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first != "immunisés"){
				nonimmun = it->second;
			}
		}

		int impactPhy;
		if(perso.getDonneeLieu() == distanceMax){
			impactPhy = 2*(perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		else{
			impactPhy = (perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		perso.setPhysique(-impactPhy);
		
		//plus la distance est élevée, plus cela a un impact négatif
		//plus de risque d'être énervé
		int impactMent = (perso.getDonneeLieu())%10 + 5;
		perso.setMental(-impactMent);

		perso.setMonnaie(-5);
	}
};