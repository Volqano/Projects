#include "Wyrazenie.hpp"

class OperatorUnarny : public Operator {
protected:
    Wyrazenie* Operand;
public:
    OperatorUnarny(Wyrazenie* op);
};




class Bezwzgl : public OperatorUnarny {
public:
    Bezwzgl(Wyrazenie *op);
    double oblicz() const override;
    string zapis() const override;
};

class Sin : public OperatorUnarny {
public:
    Sin(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

class Cos : public OperatorUnarny {
public:
    Cos(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

class Exp : public OperatorUnarny {
public:
    Exp(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

class Ln : public OperatorUnarny {
public:
    Ln(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

class Przeciw : public OperatorUnarny {
public:
    Przeciw(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

class Odwrot : public OperatorUnarny {
public:
    Odwrot(Wyrazenie* op);
    double oblicz() const override;
    string zapis() const override;
};

