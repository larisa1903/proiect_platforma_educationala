#include <iostream>
#include <string>
#include <vector>
#include "elev.h"
#include "curs.h"
#include "profesor.h"

class Admin {
private:
    std::string username;
    std::string password;

public:
    // Constructor cu user și parolă
    Admin(std::string username, std::string password)
        : username(username), password(password) {}

    // Metodă pentru autentificare (simplificată)
    bool autentificare(const std::string& user, const std::string& pass) const {
        return (username == user && password == pass);
    }

    // Adaugă un elev într-o listă de elevi
    void adaugaElev(std::vector<Elev>& elevi, int id, const std::string& nume) {
        elevi.emplace_back(id, nume);
        std::cout << "Elevul " << nume << " a fost adăugat.\n";
    }

    // Șterge un elev după id
    void stergeElev(std::vector<Elev>& elevi, int id) {
        auto it = std::remove_if(elevi.begin(), elevi.end(), [id](const Elev& elev) { return elev.getId() == id; });
        if (it != elevi.end()) {
            std::cout << "Elevul cu ID-ul " << id << " a fost șters.\n";
            elevi.erase(it, elevi.end());
        }
        else {
            std::cout << "Elevul cu ID-ul " << id << " nu a fost găsit.\n";
        }
    }

    // Adaugă un curs într-o listă de cursuri
    void adaugaCurs(std::vector<Curs>& cursuri, const std::string& numeCurs, const std::string& profesor, int capacitateMaxima) {
        cursuri.emplace_back(numeCurs, profesor, capacitateMaxima);
        std::cout << "Cursul " << numeCurs << " a fost adăugat.\n";
    }

    // Șterge un curs după nume
    void stergeCurs(std::vector<Curs>& cursuri, const std::string& numeCurs) {
        auto it = std::remove_if(cursuri.begin(), cursuri.end(), [numeCurs](const Curs& curs) { return curs.getNumeCurs() == numeCurs; });
        if (it != cursuri.end()) {
            std::cout << "Cursul " << numeCurs << " a fost șters.\n";
            cursuri.erase(it, cursuri.end());
        }
        else {
            std::cout << "Cursul " << numeCurs << " nu a fost găsit.\n";
        }
    }

    // Adaugă un profesor într-o listă de profesori
    void adaugaProfesor(std::vector<Profesor>& profesori, const std::string& nume, const std::string& username, const std::string& password) {
        profesori.emplace_back(nume, username, password);
        std::cout << "Profesorul " << nume << " a fost adăugat.\n";
    }

    // Șterge un profesor după username
    void stergeProfesor(std::vector<Profesor>& profesori, const std::string& username) {
        auto it = std::remove_if(profesori.begin(), profesori.end(), [username](const Profesor& profesor) { return profesor.getUsername() == username; });
        if (it != profesori.end()) {
            std::cout << "Profesorul cu username-ul " << username << " a fost șters.\n";
            profesori.erase(it, profesori.end());
        }
        else {
            std::cout << "Profesorul cu username-ul " << username << " nu a fost găsit.\n";
        }
    }

    // Getter pentru username
    std::string getUsername() const { return username; }
};
#pragma once
