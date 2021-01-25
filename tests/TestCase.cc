#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "test_matcher.hh"

#include "Ville.hh"

#include <fstream>

TEST_CASE("1: Creation de Personnage"){
  ZeroPoil zp1("Universite");
  TroisBras tb1("Cinema");
  Normal n1("Bar");
  NonVaccine nv1("Bus");

  REQUIRE(zp1.getLieu() == "Universite");
  REQUIRE(tb1.getLieu() == "Cinema");
  REQUIRE(n1.getLieu() == "Bar");
  REQUIRE(nv1.getLieu() == "Bus");

  REQUIRE_THAT(zp1.getPhy(), IsBetween(0,100));
  REQUIRE_THAT(tb1.getMent(), IsBetween(0, 100));
  REQUIRE_THAT(n1.getPhy(), IsBetween(0,100));
  REQUIRE_THAT(nv1.getMent(), IsBetween(0,100));
}

TEST_CASE("2: Creation de Lieu"){
  ZeroPoil zp1("Universite");
  TroisBras tb1("Cinema");
  Normal n1("Bar");
  NonVaccine nv1("Bus");

  Bar lafac("Bar");
  Cinema ugc("Cinema");
  Bus b86("Bus");
  Universite polytech("Universite"); 

  REQUIRE(zp1.getLieu() == polytech.getNom());
  REQUIRE(tb1.getLieu() == ugc.getNom());
  REQUIRE(n1.getLieu() == lafac.getNom());
  REQUIRE(nv1.getLieu() == b86.getNom());
}

TEST_CASE("3: Creation d'une Ville"){
  Ville city;

  ZeroPoil zpm1("Supermarche");
  NonVaccine nv1("Cinema");

  REQUIRE(city.getListePerso().size() == 29);
  REQUIRE(city.getListeLieu().size() == 10);
  city.ajoutPersoVille(zpm1);
  REQUIRE(city.getListePerso().size() == 30);
  city.ajoutPersoVille(nv1);
  REQUIRE(city.getListePerso().size() == 30); 
}

TEST_CASE("4: Map liée à un Lieu"){
  Ville city;
  
  int nbMetro = 0;
  std::map<std::string, std::vector<Personnage*>> personnageParLieu = city.getPersoParLieu();
  std::map<std::string, std::vector<Personnage*>>::iterator it;
  for(it = personnageParLieu.begin(); it != personnageParLieu.end(); ++it){
    if(it->first == "Metro"){
      nbMetro = it->second.size();
    }
  }

  REQUIRE(nbMetro == 4);

}

TEST_CASE("6: Fonction toString()"){
  NonVaccine amelie(0, 0);
  std::string presentation1 = "Le Personnage n'est pas vacciné. Il n'est pas immunisé. Son physique : 34 Son mental : 65 Son argent : 500";
  std::string presentation2 = amelie.toString() ;

  TroisBras tb1("Universite");
  std::string presentation3 = "Le Personnage est vacciné. Il n'est pas immunisé. Son physique : 34 Son mental : 65 Son argent : 500";
  std::string presentation4 = tb1.toString() ;
}

TEST_CASE("7: Operateur Plus Faible Que"){
  NonVaccine amelie(0, 1);
  NonVaccine fadi(1,1);

  REQUIRE((amelie<fadi) == true);
}

TEST_CASE("8: Test lavage main & gelHydoalcoolique"){
  ZeroPoil zp1("Universite");

  int avant = zp1.getPhy();
  zp1.gelHydroAlcoolique();
  int apresGHA = zp1.getPhy();
  zp1.lavageMains();
  int apresLM = zp1.getPhy();

  REQUIRE((avant<apresGHA) == true);
  REQUIRE((apresGHA<apresLM) == true);
}

TEST_CASE("9: Impact sur un personnage"){
  Ville city;

  NonVaccine amelie("Universite");
  city.ajoutPersoVille(amelie);
  int phyAvt = amelie.getPhy();
  int mentAvt = amelie.getMent();
  int moneyAvt = amelie.getMonnaie();

  city.impactDuLieu(amelie);
  int phyAp = amelie.getPhy();
  int mentAp = amelie.getMent();
  int moneyAp = amelie.getMonnaie();

  REQUIRE(phyAvt > phyAp);
  REQUIRE(mentAvt < mentAp);
  REQUIRE(moneyAvt > moneyAp);

}