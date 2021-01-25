#include<iostream>
#include<cstdlib>
#include <string>

#include "Lieu.hh"

class Maison : public Lieu {
private:
	int tempsMax;
public:
	Maison(std::string name) : Lieu(name){
		tempsMax = 12;
		frequentationMax = 5;
		fContamination = 1;
	}
	//ne pas bouger impact négativement
	//plus la maison est remplie, plus le personnage ne peut pas bouger
	//si la maison est saturée, cela a un impact double
	void impact(Personnage &perso) const{
		int impactPhy = affluence;
		if(affluence == frequentationMax){
			impactPhy = 2*impactPhy;
		}
		perso.setPhysique(-impactPhy);

		int impactMent = affluence%10*fContamination;
		perso.setMental(impactMent);

		perso.setMonnaie(5);
	}
};