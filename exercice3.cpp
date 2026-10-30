#include <iostream>
#include <string>

using namespace std;
class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string mar, string mod) {
        marque = mar;
        modele = mod;
    }

    virtual ~Vehicule() {}

    void afficherVehicule() {
        cout << "Marque : " << marque << " | Modele : " << modele;
    }
};
class Thermique : virtual public Vehicule {
protected:
    double consommationCarburant; 

public:
    Thermique(string mar, string mod, double conso) : Vehicule(mar, mod) {
        consommationCarburant = conso;
    }

    void afficherThermique() {
        cout << " | Consommation : " << consommationCarburant << " L/100km";
    }
};
class Electrique : virtual public Vehicule {
protected:
    int autonomieBatterie;

public:
    Electrique(string mar, string mod, int autonomie) : Vehicule(mar, mod) {
        autonomieBatterie = autonomie;
    }

    void afficherElectrique() {
        cout << " | Autonomie batterie : " << autonomieBatterie << " km";
    }
};
class Hybride : public Thermique, public Electrique {
public:
    Hybride(string mar, string mod, double conso, int autonomie) 
        : Vehicule(mar, mod), Thermique(mar, mod, conso), Electrique(mar, mod, autonomie) {}
    void afficherCaracteristiques() {
        cout << "Fiche technique du Vehicule Hybride" << endl;
        afficherVehicule(); 
        afficherThermique();
        afficherElectrique();
    }
};

int main() {
    cout << "Test de l'Heritage Virtuel" << endl << endl;
    Hybride myCar("Toyota", "Prius", 4.5, 60);
    myCar.afficherCaracteristiques();

    return 0;
}