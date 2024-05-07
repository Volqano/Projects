#include <iostream>
#include "Wyrazenie.hpp"
#include "Binarne.hpp"
#include "Unarne.hpp"
#include "Stale.hpp"

int main() {
    Zmienna *x = new Zmienna("x", 0);
    Wyrazenie *w1 = new Dzielenie(new Mnozenie(new Odejmowanie(x, new Liczba(1)), x), new Liczba(2));
    cout << w1->zapis() << endl;
    for (double i = 1; i < 10; i++) {
        x->zmienzmienna("x", i);
        cout << "x = " << i << ", wartosc = " << w1->oblicz() << endl;
    }

    cout << endl;
    Wyrazenie *w2 = new Dzielenie(new Dodawanie(new Liczba(3), new Liczba(5)), new Dodawanie(new Liczba(2), new Mnozenie(x, new Liczba(7))));
    cout << w2->zapis() << endl;
    for (double i = 1; i < 10; i++) {
        x->zmienzmienna("x", i);
        cout << "x = " << i << ", wartosc = " << w2->oblicz() << endl;
    }

    cout << endl;
    Zmienna *y = new Zmienna("y", 0);
    Wyrazenie *w3 = new Odejmowanie(new Dodawanie(new Liczba(2), new Mnozenie(x, new Liczba(7))), new Dodawanie(new Mnozenie(y, new Liczba(3)), new Liczba(5)));
    cout << w3->zapis() << endl;
    for (double i = 0; i < 10; i ++) {
        x->zmienzmienna("x", i);
        for (double j = 0; j < 10; j ++) {
            y->zmienzmienna("y", j);
            cout << "x = " << i << ", y = " << j << ", wartosc = " << w3->oblicz() << endl;
        }
    }

    cout << endl;
    Wyrazenie *w4 = new Dzielenie(new Cos(new Mnozenie(new Dodawanie(x, new Liczba(1)), new Pi())), new Potega(new e(), new Potega(x, new Liczba(2))));
    cout << w4->zapis() << endl;
    for (double i = 0; i < 10; i++) {
        x->zmienzmienna("x", i);
        cout << "x = " << i << ", wartosc = " << w4->oblicz() << endl;
    }
}
