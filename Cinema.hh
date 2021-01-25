#include<iostream>
#include<cstdlib>
#include <string>

#include "Loisir.hh"

class Cinema : public Loisir{
private:
	
public:
	//la donnée du lieu pour le cinéma est le nbre de film que le personnage veut voir
	Cinema(std::string name) : Loisir(name) {
		frequentationMax = 60; 					//de la salle de cinéma
		fContamination = 80;
		affluence = 30;
		nbMax = 3;								//nombre de films visualisés
	}
	//plus le nb de film est élevé, plus cela a impact négatif 
	//plus de risque de contamination
	void impact(Personnage &perso) const{
		int nonimmun = 0;
		std::map<std::string, int>::const_iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first != "immunisés"){
				nonimmun = it->second;
			}
		}

		int impactPhy;
		impactPhy = (perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		
		perso.setPhysique(-impactPhy);

		//plus le nb de film est élevé, plus cela a un impact positif
		int impactMent = (perso.getDonneeLieu())%10 * 6;
		perso.setMental(impactMent);

		//fait perdre de l'argent, 5 pieces par film
		perso.setMonnaie(-5*perso.getDonneeLieu());
	}

};