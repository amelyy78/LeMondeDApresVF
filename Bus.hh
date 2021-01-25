#include<iostream>
#include<cstdlib>
#include <string>

#include "Transport.hh"

class Bus : public Transport {
private:

public:
	Bus(std::string name) : Transport(name) {
		frequentationMax = 90;
		fContamination = 80;
		affluence = 30;
		distanceMax = 30;		//on peut parcourir 30km avec le bus
	}

	//plus la distance parcourue est élevée, plus c'est risqué
	//plus la distance parcourue est élevée, plus cela un impact sur le mental (énervement)
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

		int impactMent = (perso.getDonneeLieu())%10 + 3;
		perso.setMental(-impactMent);

		perso.setMonnaie(-2);
	}
};