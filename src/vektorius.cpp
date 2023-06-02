#include "funkciju_bib.h"

int main() {
    int ivestis;
    cout<<"Pasirinkite kaip norite gauti studentu duomenis: "<<endl;
    cout<<"1. Suvedimas ranka \n"<<"2. Failo skaitymas\n"<<"3. Sugeneruoto failo skaitymas ir padalijimas i 2 failus\n";
    cout<<"Jusu pasirinkimas: ";
    while (cin>>ivestis) {
        if (ivestis != 1 && ivestis != 2 && ivestis != 3) {
            cout << "Pasirinkite 1 arba 2: ";
            continue;
        }
        break;
    }
    if (ivestis==1) {
        Vector<Studentas>stud= ivedimas();
        isvedimas(stud);
    }
    if (ivestis==2) {
        Vector<Studentas>stud;
        string failo_pav;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failo_pav;
        skaitymas_is_failo(stud, failo_pav);
        //rusiavimasStudentu(stud);
        isvedimas(stud);
    }
    if (ivestis==3) {
        string failo_pav;
        int studentu_skaicius;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failo_pav;
        cout<<"Iveskite studentu skaiciu: ";
        cin>>studentu_skaicius;
        auto start_visas = chrono::high_resolution_clock::now();
        auto start = chrono::high_resolution_clock::now();
        sukurimas_random_failo(failo_pav, studentu_skaicius);//pasirinkt kiek irasu nori tureti
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end-start).count();
        cout<<"Failo sudarymo laikas uztruko: "<<duration<<" milisekundziu"<<endl;

        Vector<Studentas> studentai, kietiakai, nuskriaustukai;
        auto start_1 = chrono::high_resolution_clock::now();
        skaitymas_is_failo(studentai, failo_pav);
        auto end_1 = chrono::high_resolution_clock::now();
        auto duration_1 = chrono::duration_cast<chrono::milliseconds>(end_1-start_1).count();
        cout<<"Failo skaitymo laikas uztruko: "<<duration_1<<" milisekundziu"<<endl;
        
        dalintiStudentus(studentai, kietiakai, nuskriaustukai);

        rusiavimasDid(kietiakai);
        rusiavimasDid(nuskriaustukai);

        isvedimasFailu(kietiakai, "kietiakai.txt");
        isvedimasFailu(nuskriaustukai, "nuskriaustukai.txt");
        
        auto end_visas = chrono::high_resolution_clock::now();
        auto duration_visas = chrono::duration_cast<chrono::milliseconds>(end_visas-start_visas).count();
        cout<<"Visas testo laikas uztruko: "<<duration_visas<<" milisekundziu"<<endl;
    }
    return 0;
}