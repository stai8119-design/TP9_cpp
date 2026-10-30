#include <iostream>
#include <string>

using namespace std;
class Utilisateur {
protected:
    int id;
    string login;

public:
    Utilisateur(int identifiant, string log) {
        id = identifiant;
        login = log;
    }

    virtual ~Utilisateur() {}
    void afficherUtilisateur() {
        cout << "ID : " << id << " | Login : " << login;
    }
};
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int identifiant, string log, string droits) : Utilisateur(identifiant, log) {
        droitsAcces = droits;
    }

    void gererSysteme() {
        cout << "[ADMIN] L'administrateur " << login << " gere le systeme avec les droits : " << droitsAcces << endl;
    }
};
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int identifiant, string log, int niveau) : Utilisateur(identifiant, log) {
        niveauModeration = niveau;
    }

    void modererContenu() {
        cout << "[MODO] Le moderateur " << login << " modere le contenu (Niveau : " << niveauModeration << ")" << endl;
    }
};
class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int identifiant, string log, string droits, int niveau) 
        : Utilisateur(identifiant, log), Administrateur(identifiant, log, droits), Moderateur(identifiant, log, niveau) {}
    void afficherProfil() {
        cout << "PROFIL DU SUPER UTILISATEUR" << endl;
        afficherUtilisateur();
        cout << " | Droits : " << droitsAcces << " | Niveau Modo : " << niveauModeration << endl;
    }
};
int main() {
    int choix;
    int idSuper = 0;
    int niveauModo = 0;
    string loginSuper = "";
    string droitsAdmin = "";
    SuperUtilisateur* superUser = nullptr;
    bool created = false;

    do {
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Afficher le profil complet" << endl;
        cout << "3. Tester la methode gererSysteme() [Admin]" << endl;
        cout << "4. Tester la methode modererContenu() [Moderateur]" << endl;
        cout << "5. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "\nCreation du SuperUtilisateur" << endl;
                cout << "Entrer l'ID : ";
                cin >> idSuper;
                cout << "Entrer le login : ";
                cin >> loginSuper;
                cout << "Entrer les droits d'acces: ";
                cin >> droitsAdmin;
                cout << "Entrer le niveau de moderation : ";
                cin >> niveauModo;
                if (superUser != nullptr) {
                    delete superUser;
                }
                superUser = new SuperUtilisateur(idSuper, loginSuper, droitsAdmin, niveauModo);
                created = true;
                cout << "[SUCCES] SuperUtilisateur cree avec succes !" << endl;
                break;
            }
            case 2:
                if (created && superUser != nullptr) {
                    superUser->afficherProfil();
                } else {
                    cout << "[ERREUR] Veuillez d'abord creer un SuperUtilisateur (Option 1)." << endl;
                }
                break;
            case 3:
                if (created && superUser != nullptr) {
                    cout << "\nTest Admin" << endl;
                    superUser->gererSysteme();
                } else {
                    cout << "[ERREUR] Aucun SuperUtilisateur disponible." << endl;
                }
                break;
            case 4:
                if (created && superUser != nullptr) {
                    cout << "\nTest Moderateur" << endl;
                    superUser->modererContenu();
                } else {
                    cout << "[ERREUR] Aucun SuperUtilisateur disponible." << endl;
                }
                break;
            case 5:
                cout << "\nFermeture du programme. Au revoir !" << endl;
                break;
            default:
                cout << "[ERREUR] Choix invalide. Veuillez reessayer." << endl;
        }

    } while (choix != 5);
    if (superUser != nullptr) {
        delete superUser;
    }

    return 0;
}