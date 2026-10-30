#include <iostream>
#include <string>

using namespace std;
class Personne {
protected:
    string nom;
    string prenom;

public:
    Personne(string n, string p) {
        nom = n;
        prenom = p;
    }
    void afficher() {
        cout << "Nom : " << nom << ", Prenom : " << prenom;
    }
};
class Chercheur {
protected:
    string domaineRecherche;

public:
    Chercheur(string domaine) {
        domaineRecherche = domaine;
    }
    void afficher() {
        cout << ", Domaine de recherche : " << domaineRecherche;
    }
};
class EnseignantChercheur : public Personne, public Chercheur {
private:
    string departement; 

public:
    EnseignantChercheur(string n, string p, string domaine, string dept) 
        : Personne(n, p), Chercheur(domaine) {
        departement = dept;
    }
    void afficher() {
        Personne::afficher();
        Chercheur::afficher();
        cout << ", Departement : " << departement << endl;
    }
};

int main() {
    cout << "Test de l'Heritage Multiple" << endl << endl;
    EnseignantChercheur ec("El Amrani", "Youssef", "Intelligence Artificielle & Big Data", "Departement Informatique");

    cout << "Informations completes de l'enseignant-chercheur :" << endl;
    ec.afficher();

    return 0;
}