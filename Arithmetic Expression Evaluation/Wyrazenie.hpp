//
// Created by Mateusz Matyskiel on 06/05/2024.
//
#include <string>
#include <cmath>
using namespace std;

#ifndef ZADANIE8_WYRAZENIE_HPP
#define ZADANIE8_WYRAZENIE_HPP

class Wyrazenie {
public:
    virtual double oblicz() const = 0;
    virtual string zapis() const = 0;
    virtual ~Wyrazenie() {}
};

class Operand : public Wyrazenie {};

class Operator : public Wyrazenie {};

class Liczba : public Operand {    
private:
    double value;
public:
    Liczba(double val);
    double oblicz() const override;
    string zapis() const override;
};

class Zmienna : public Operand {
private:
    string nazwa;
    static vector<pair<string,  double>> zmienne;
public:
    Zmienna(string nazwa, double val);
    void dodajzmienna(string nazwa, double val);
    void usunzmienna(string nazwa);
    void zmienzmienna(string nazwa, double val);
    double oblicz() const override;
    string zapis() const override;
};

#endif //ZADANIE8_WYRAZENIE_HPP
