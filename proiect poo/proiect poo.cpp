#include "PlatformaEducatie.h"
#include "profesor.h"
#include "proiect poo.h"
#include "admin.h"

int main() {
    Admin admin("admin", "parola123");

    // Crearea platformei educaționale
    PlatformaEducatie platforma(admin);

    // Crearea unor profesori
    Profesor profesor1("Prof. Popescu");
    Profesor profesor2("Prof. Ionescu");

    // Crearea unor cursuri
    Curs curs1("Matematica", "Prof. Popescu", 30);
    Curs curs2("Informatica", "Prof. Ionescu", 25);

    // Adăugarea cursurilor
    platforma.adaugaCurs(curs1);
    platforma.adaugaCurs(curs2);

    // Crearea elevilor
    Elev elev1(1, "Ion");
    Elev elev2(2, "Maria");

    // Adăugarea elevilor
    platforma.adaugaElev(elev1);
    platforma.adaugaElev(elev2);

    // Înregistrarea elevilor la cursuri
    platforma.inscriereElevLaCurs(1, "Matematica");
    platforma.inscriereElevLaCurs(2, "Informatica");

    // Afișarea cursurilor la care sunt înscriși elevii
    elev1.afisareCursuri();
    elev2.afisareCursuri();

    return 0;
}
