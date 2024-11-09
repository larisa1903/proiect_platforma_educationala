#include <iostream>
#include <string>
#include <vector>
#include "curs.h"
#include "elev.h"

class Profesor {
private:
    std::string nume;
    std::string username; // Userul profesorului
    std::string password; // Parola profesorului
    std::vector<Curs*> cursuriPredate; // Cursurile predate de profesor

public:
    // Constructor cu user și parolă
    Profesor(std::string nume, std::string username, std::string password)
        : nume(nume), username(username), password(password) {}

    // Adaugă un curs predat
    void adaugaCurs(Curs* curs) {
        cursuriPredate.push_back(curs);
    }

    // Afișează cursurile predate
    void afisareCursuriPredate() const {
        std::cout << "Profesorul " << nume << " predă următoarele cursuri:\n";
        for (const auto& curs : cursuriPredate) {
            std::cout << "- " << curs->getNumeCurs() << std::endl;
        }
    }

    // Adaugă un elev la un curs specificat
    bool adaugaElevLaCurs(Curs* curs, Elev* elev) {
        for (auto& cursPredat : cursuriPredate) {
            if (cursPredat == curs) {
                return cursPredat->adaugaElev(elev);
            }
        }
        std::cout << "Profesorul " << nume << " nu predă cursul " << curs->getNumeCurs() << ".\n";
        return false;
    }

    // Elimină un elev de la un curs specificat
    bool eliminaElevDeLaCurs(Curs* curs, Elev* elev) {
        for (auto& cursPredat : cursuriPredate) {
            if (cursPredat == curs) {
                return cursPredat->eliminaElev(elev);
            }
        }
        std::cout << "Profesorul " << nume << " nu predă cursul " << curs->getNumeCurs() << ".\n";
        return false;
    }

    // Getters pentru nume și username
    std::string getNume() const { return nume; }
    std::string getUsername() const { return username; }
};
#pragma once
