#include "funkciju_bib.h"

int main() {
    int ivestis;
    cout<<"Pasirinkite kaip norite sugeneruoti faila: "<<endl;
    cout<<"1. ranka"<<endl;
    cout<<"2. automatiskai sugeneruojami"<<endl;
    while (cin>>ivestis) {
        if (ivestis != 1 && ivestis != 2 && ivestis != 3) {
            cout << "Pasirinkite 1 arba 2: ";
            continue;
        }
        break;
    }
    if (ivestis==1) {
        string pavadinimas;
        int kiekis;
        cout<<"Iveskite pavadinima: ";
        cin >> pavadinimas;
        cout<<"Iveskite kieki: ";
        cin >> kiekis;

        sukurimas_random_failo(pavadinimas, kiekis);
    }
    if (ivestis==2) {
        for(int i = 1000; i <= 10000000; i = i * 10) {
            sukurimas_random_failo("studentas" + std::to_string(i) + ".txt", i);
        }
    }
}