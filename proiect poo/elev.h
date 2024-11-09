#pragma once
#include <iostream>
#include <string>
#include <vector>

class Elev {
private:
    int id;
    std::string nume;
    std::string username;
    std::string password;
    std::vector<std::string> cursuri; // Lista cursurilor la care elevul este înscris
    bool autentificat; // Starea de autentificare a elevului

public:
    Elev(int id, std::string nume, std::string username, std::string password)
        : id(id), nume(nume), username(username), password(password), autentificat(false) {}

    bool autentificare(const std::string& username, const std::string& password) {
        if (this->username == username && this->password == password) {
            autentificat = true;
            std::cout << "Autentificare reusita pentru elevul " << nume << "!\n";
            return true;
        }
        else {
            std::cout << "Autentificare esuata. Verificati datele introduse.\n";
            return false;
        }
    }

    void deconectare() {
        autentificat = false;
        std::cout << "Elevul " << nume << " a fost deconectat.\n";
    }

    void inscriereLaCurs(const std::string& numeCurs) {
        if (autentificat) {
            cursuri.push_back(numeCurs);
            std::cout << "Elevul " << nume << " s-a inscris la cursul " << numeCurs << ".\n";
        }
        else {
            std::cout << "Autentificare necesara pentru inscrierea la cursuri.\n";
        }
    }

    void afisareCursuri() {
        if (autentificat) {
            std::cout << "Elevul " << nume << " este inscris la urmatoarele cursuri:\n";
            for (const auto& curs : cursuri) {
                std::cout << "- " << curs << std::endl;
            }
        }
        else {
            std::cout << "Autentificare necesara pentru vizualizarea cursurilor.\n";
        }
    }

    int getId() const { return id; }
    std::string getNume() const { return nume; }
};
