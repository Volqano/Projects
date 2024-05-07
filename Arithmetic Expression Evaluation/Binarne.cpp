#include "Binarne.hpp"


OperatorBinarny::OperatorBinarny(Wyrazenie* lewo, Wyrazenie* prawo) {
    lewyOperand = lewo;
    prawyOperand = prawo;
}

Dodawanie::Dodawanie(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Dodawanie::oblicz() const {
    return lewyOperand->oblicz() + prawyOperand->oblicz();
}

string Dodawanie::zapis() const {
    return "(" + lewyOperand->zapis() + " + " + prawyOperand->zapis() + ")";
}

Odejmowanie::Odejmowanie(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Odejmowanie::oblicz() const {
    return lewyOperand->oblicz() - prawyOperand->oblicz();
}

string Odejmowanie::zapis() const {
    return "(" + lewyOperand->zapis() + " - " + prawyOperand->zapis() + ")";
}

Mnozenie::Mnozenie(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Mnozenie::oblicz() const {
    return lewyOperand->oblicz() * prawyOperand->oblicz();
}

string Mnozenie::zapis() const {
    return lewyOperand->zapis() + " * " + prawyOperand->zapis();
}

Dzielenie::Dzielenie(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Dzielenie::oblicz() const {
    if (prawyOperand->oblicz() == 0) {
        throw std::runtime_error("dzielenie przez 0");
    }
    return lewyOperand->oblicz() / prawyOperand->oblicz();
}

string Dzielenie::zapis() const {
    return lewyOperand->zapis() + " / " + prawyOperand->zapis();
}

Logarytm::Logarytm(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Logarytm::oblicz() const {
    return log(prawyOperand->oblicz()) / log(lewyOperand->oblicz());
}

string Logarytm::zapis() const {
    return "log" + lewyOperand->zapis() + "(" + prawyOperand->zapis() + ")";
}

Modulo::Modulo(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Modulo::oblicz() const {
    //zaokraglenie bo nie mozna modulo na zmiennoprzecinkowych
    int lewa = round(lewyOperand->oblicz());
    int prawa = round(prawyOperand->oblicz());
    return lewa % prawa;
}

string Modulo::zapis() const {
    return lewyOperand->zapis() + " % " + prawyOperand->zapis();
}

Potega::Potega(Wyrazenie* lewo, Wyrazenie* prawo) 
    : OperatorBinarny(lewo, prawo) {}

double Potega::oblicz() const {
    int lewa = round(lewyOperand->oblicz());
    int prawa = round(prawyOperand->oblicz());
    return pow(lewa, prawa);
}

string Potega::zapis() const {
    return lewyOperand->zapis() + "^" + prawyOperand->zapis();
}