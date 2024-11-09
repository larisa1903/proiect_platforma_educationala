#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Elev.h"
#include "Curs.h"
#include "Profesor.h"
#include "Admin.h"

class PlatformaEducatie {
private:
    std::vector<Elev> elevi;
    std::vector<Curs> cursuri;
    std::vector<Profesor> profesori;
    Admin admin;

public:
    PlatformaEducatie(const Admin& admin) : admin(admin) {}

    void afiseazaCursuri() const {
        std::cout << "Cursurile disponibile sunt:\n";
        for (const auto& curs : cursuri) {
            std::cout << "- " << curs.getNumeCurs() << std::endl;
        }
    }

    void inscriereElevLaCurs(int idElev, const std::string& numeCurs) {
        auto itElev = std::find_if(elevi.begin(), elevi.end(), [idElev](const Elev& elev) { return elev.getId() == idElev; });
        auto itCurs = std::find_if(cursuri.begin(), cursuri.end(), [&numeCurs](const Curs& curs) { return curs.getNumeCurs() == numeCurs; });

        if (itElev != elevi.end() && itCurs != cursuri.end()) {
            itCurs->adaugaElev(&(*itElev));
        }
