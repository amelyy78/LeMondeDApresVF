#include<iostream>
#include<cstdlib>
#include <string>

#include "Loisir.hh"

class Bar : public Loisir{
private:
	
public:
	//la donnée du lieu pour le bar est le nombre de bières qui va être bues
	Bar(std::string name) : Loisir(name) {
		frequentationMax = 6; 				//de la table
		fContamination = 80;
		affluence = 2;
		nbMax = 4; 							//nombre de bières max
	}

	//plus le nb de bière est élevé, plus cela a impact négatif 
	//plus de risque de contamination
	//si le nb max de biere est atteint, ça compte double
	void impact(Personnage &perso) const{
		int nonimmun = 0;
		std::map<std::string, int>::const_iterator it;
		for(it = mapPerso.begin(); it != mapPerso.end(); ++it){
			if(it->first != "immunisés"){
				nonimmun = it->second;
			}
		}

		int impactPhy;
		if(perso.getDonneeLieu() == nbMax){
			impactPhy = 2*(perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		else{
			impactPhy = (perso.getDonneeLieu())%10 + affluence%10 + nonimmun*fContamination%10;
		}
		//est risqué pour le joueur
		perso.setPhysique(-impactPhy);

		//plus le nb de biere est élevé, plus cela a un impact positif
		int impactMent = (perso.getDonneeLieu())%10 * 5;
		perso.setMental(impactMent);

		//fait perdre de l'argent, 3 pieces par biere
		perso.setMonnaie(-3*perso.getDonneeLieu());
	}

};