#include "Wyrazenie.hpp"

class OperatorBinarny : public Operator {
protected:
    Wyrazenie* lewyOperand;
    Wyrazenie* prawyOperand;
public:
    OperatorBinarny(Wyrazenie* lewo, Wyrazenie* prawo);
};

class Dodawanie : public OperatorBinarny {
public:
    Dodawanie(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Odejmowanie : public OperatorBinarny {
public:
    Odejmowanie(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Mnozenie : public OperatorBinarny {
public:
    Mnozenie(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Dzielenie : public OperatorBinarny {
public:
    Dzielenie(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Logarytm : public OperatorBinarny {
public:
    Logarytm(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Modulo : public OperatorBinarny {
public:
    Modulo(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};

class Potega : public OperatorBinarny {
public:
    Potega(Wyrazenie* lewo, Wyrazenie* prawo);
    double oblicz() const override;
    string zapis() const override;
};