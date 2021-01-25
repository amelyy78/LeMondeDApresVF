#include "Ville.hh"

#include <vector>
#include <map>

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

int main(){
	std::cout << "Création de la ville" << std::endl;
	Ville village;

	std::vector<Personnage*> listepopu = village.getListePerso();
	std::vector<Lieu*> listelieu = village.getListeLieu();

	//ajout du personnage ZeroPoil
	std::cout << "\nCréation d'un ZeroPoil" << std::endl;
	ZeroPoil zpm1("Supermarche");
	std::cout << zpm1 << std::endl;

	std::cout << "\nAjout d'un ZeroPoil à la ville" << std::endl;
	std::cout << "Taille avant ajout : ";
	std::cout << listepopu.size() << std::endl;
	village.ajoutPersoVille(zpm1);
	std::cout << "Taille après ajout : ";
	listepopu = village.getListePerso();
	std::cout << listepopu.size() << std::endl;

	NonVaccine nv2("Cinema");
	std::cout << "\nEssai d'ajout à la ville " << std::endl;
	std::cout << "Taille avant ajout : ";
	std::cout << listepopu.size() << std::endl;
	village.ajoutPersoVille(nv2);
	std::cout << "Taille après essai d'ajout : ";
	std::cout << listepopu.size() << std::endl;

	//test de l'impact
	std::cout << "Physique de zpm1 avant : " << zpm1.getPhy() << std::endl;
	village.impactDuLieu(zpm1);
	std::cout << "Physique de zpm1 après : " << zpm1.getPhy() << std::endl;

	//creation du joueur
	std::cout << "\nCréation du joueur" << std::endl;
	NonVaccine joueur(1, 1);
	std::cout << joueur.getNom() << std::endl;
	std::cout << joueur.getDifficulte() << std::endl;
	std::cout << joueur.getMonnaie() << std::endl;

	//test de la surcharge
	//on compare le ZeroPoil et le joueur
	std::cout << "Comparaison" << std::endl;
	std::cout << "Physique du joueur : " << joueur.getPhy() << std::endl;
	std::cout << "Physique du ZeroPoil : " << zpm1.getPhy() << std::endl;
	std::cout << zpm1.estPlusFaibleQue(joueur) << std::endl;

};