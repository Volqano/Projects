#include "Unarne.hpp"

OperatorUnarny::OperatorUnarny(Wyrazenie* op) {
    Operand = op;
}

Bezwzgl::Bezwzgl(Wyrazenie *op) : OperatorUnarny(op) {}

double Bezwzgl::oblicz() const {
    return abs(Operand->oblicz());
}

string Bezwzgl::zapis() const {
    return "|" + Operand->zapis() + "|";
}

Sin::Sin(Wyrazenie *op) : OperatorUnarny(op) {}

double Sin::oblicz() const {
    return sin(Operand->oblicz());
}

string Sin::zapis() const {
    return "Sin(" + Operand->zapis() + ")";
}

Cos::Cos(Wyrazenie *op) : OperatorUnarny(op) {}

double Cos::oblicz() const {
    return cos(Operand->oblicz());
}

string Cos::zapis() const {
    return "Cos(" + Operand->zapis() + ")";
}

Exp::Exp(Wyrazenie *op) : OperatorUnarny(op) {}

double Exp::oblicz() const {
    return exp(Operand->oblicz());
}

string Exp::zapis() const {
    return "Exp(" + Operand->zapis() + ")";
}

Ln::Ln(Wyrazenie *op) : OperatorUnarny(op) {}

double Ln::oblicz() const {
    return log(Operand->oblicz());
}

string Ln::zapis() const {
    return "Ln(" + Operand->zapis() + ")";
}

Przeciw::Przeciw(Wyrazenie *op) : OperatorUnarny(op) {}

double Przeciw::oblicz() const {
    return (-1) * Operand->oblicz();
}

string Przeciw::zapis() const {
    return "Przeciw(" + Operand->zapis() + ")";
}

Odwrot::Odwrot(Wyrazenie *op) : OperatorUnarny(op) {}

double Odwrot::oblicz() const {
    return 1 / Operand->oblicz();
}

string Odwrot::zapis() const {
    return "Odwrot(" + Operand->zapis() + ")";
}