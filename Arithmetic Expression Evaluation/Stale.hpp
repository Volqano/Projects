#include "Wyrazenie.hpp"

class Stala : public Operand {
private:
    string nazwa;
    double wartosc;
public:
    Stala(string nazwa, double val);
    double oblicz() const override;
    string zapis() const override;
};

class Pi : public Stala {
public:
    Pi() : Stala("Pi", 3.14) {}
};

class e : public Stala {
public:
    e() : Stala("e", 2.71) {}
};

class Fi : public Stala {
public:
    Fi() : Stala("Fi", 1.61) {}
};