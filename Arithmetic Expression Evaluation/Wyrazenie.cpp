#include <sstream>
#include <iomanip>
#include "Wyrazenie.hpp"

Liczba::Liczba(double val) {
    value = val;
}

double Liczba::oblicz() const {
    return value;
}

string Liczba::zapis() const {
    if (value == int(value)) {
        return to_string(int(value));
    }
    ostringstream oss;
    oss << fixed << setprecision(3) << value;
    return oss.str();
}

vector<pair<string,  double>> Zmienna::zmienne;

Zmienna::Zmienna(string nazw, double val) {
    nazwa = nazw;
    zmienne.emplace_back(nazwa, val);
}

void Zmienna::dodajzmienna(string nazwa, double val) {
    zmienne.emplace_back(nazwa,val);
}

void Zmienna::usunzmienna(string nazwa) {
    for (int i = 0; i < zmienne.size(); i++) {
        if (zmienne[i].first == nazwa) {
            zmienne.erase(zmienne.begin() + i);
            return;
        }
    }
    throw std::invalid_argument("taka zmienna nie istnieje");
}

void Zmienna::zmienzmienna(string nazwa, double val) {
    for (int i = 0; i < zmienne.size(); i++) {
        if (zmienne[i].first == nazwa) {
            zmienne[i].second = val;
            return;
        }
    }
    throw std::invalid_argument("taka zmienna nie istnieje");
}

double Zmienna::oblicz() const {
    for (int i = 0; i < zmienne.size(); i++) {
        if (zmienne[i].first == nazwa) {
            return zmienne[i].second;
        }
    }
    throw std::invalid_argument("taka zmienna nie istnieje");
}

string Zmienna::zapis() const {
    return nazwa;
}