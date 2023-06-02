#include "Biblioteka.h"
#include "Vector.h"
class Zmogus {
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() {}
    Zmogus(const string& v, const string& p) : vardas(v), pavarde(p) {}

    // Getteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }

    // Setteriai
    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }

    // Virtualusis metodas
    virtual void printInfo() const = 0; // Pure virtualus metodas - abstrakti bazinė klasė
    virtual ~Zmogus() {} // Virtualus destruktorius
};

class Studentas : public Zmogus {
private:
    Vector<int> paz;
    int egz;

public:
    Studentas() : egz(0) {}
    Studentas(const string& v, const string& p, const Vector<int>& pazymiai, int egzaminas)
        : Zmogus(v, p), paz(pazymiai), egz(egzaminas) {}

    // Getteriai
    Vector<int> getPaz() const { return paz; }
    int getEgz() const { return egz; }

    // Setteriai
    void setPaz(const Vector<int>& p) { paz = p; }
    void setEgz(int e) { egz = e; }

    // Perrašomas metodas
    void printInfo() const override {
        cout << "Vardas: " << vardas << endl;
        cout << "Pavarde: " << pavarde << endl;
        cout << "Pazymiai: ";
       for (int pazymys : paz) {
            cout << pazymys << " ";
        }
        cout << endl;
        cout << "Egzaminas: " << egz << endl;
    }
};
