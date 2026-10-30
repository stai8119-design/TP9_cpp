#include <iostream>
#include <string>

using namespace std;
class Technicien {
protected:
    double salaireTechnicien;

public:
    Technicien(double salTech) {
        salaireTechnicien = salTech;
    }

    void afficherSalaire() {
        cout << "Salaire Technicien : " << salaireTechnicien << " EUR" << endl;
    }
};

class Comptable {
protected:
    double salaireComptable;

public:
    Comptable(double salComp) {
        salaireComptable = salComp;
    }

    void afficherSalaire() {
        cout << "Salaire Comptable : " << salaireComptable << " EUR" << endl;
    }
};
class EmployePolyvalent : public Technicien, public Comptable {
private:
    string nomEmploye;

public:
    EmployePolyvalent(string nom, double salTech, double salComp) 
        : Technicien(salTech), Comptable(salComp) {
        nomEmploye = nom;
    }

    void afficherTousSalaires() {
        cout << "Fiche de paie de l'employe polyvalent : " << nomEmploye << endl;
        
        cout << "Partie technique -> ";
        Technicien::afficherSalaire();

        cout << "Partie comptable -> ";
        Comptable::afficherSalaire();  
    }
};

int main() {
    cout << "Test de l'Heritage Multiple et Resolution d'Ambiguité" << endl;
    EmployePolyvalent ep("Yassir", 3500.0, 4000.0);
    ep.afficherTousSalaires();
    return 0;
}