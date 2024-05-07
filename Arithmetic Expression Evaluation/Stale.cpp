#include "Stale.hpp"


Stala::Stala(string nazw, double val) {
    nazwa = nazw;
    wartosc = val;
}

double Stala::oblicz() const {
    return wartosc;
}

string Stala::zapis() const {
    return nazwa;
}
