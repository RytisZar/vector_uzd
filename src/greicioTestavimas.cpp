#include "funkciju_bib.h"

int main(){
    string temp;
    for(int i = 1000; i <= 10000000; i = i * 10){
        string failas = "studentas" + std::to_string(i) + ".txt";
        string failas_kietiakai = "kietiakai" + std::to_string(i) + ".txt";
        string failas_nuskriaustukai = "nuskriaustukai" + std::to_string(i) + ".txt";
        Vector<Studentas>studentai;
        Vector<Studentas>nuskriaustukai;
        Vector<Studentas>kietiakai;

        auto t1start = chrono::high_resolution_clock::now(); // Visos programos greicio startas

        ifstream file("studentas" + std::to_string(i) + ".txt");
        auto t2start = chrono::high_resolution_clock::now();
        if (file.good()) {
            cout<<i<<" irasu failas jau egzistuoja"<<endl;
        }
         // Generuojamas failas
        else {
            sukurimas_random_failo(failas, i);
        }
        auto t2end = chrono::high_resolution_clock::now();
        
        auto t3start = chrono::high_resolution_clock::now(); //Skaitymas is failo
        skaitymas_is_failo(studentai, failas);
        auto t3end = chrono::high_resolution_clock::now(); 
       
        auto t4start = chrono::high_resolution_clock::now(); // Dalijimas i dvi grupes
        dalintiStudentus(studentai, kietiakai, nuskriaustukai);
        auto t4end = chrono::high_resolution_clock::now(); 

        auto t5start = chrono::high_resolution_clock::now(); // Rusiavimas didejimo tvarka
        rusiavimasDid(kietiakai);
        rusiavimasDid(nuskriaustukai);
        auto t5end = chrono::high_resolution_clock::now(); 
        
        auto t6start = chrono::high_resolution_clock::now();
        isvedimasFailu(kietiakai, failas_kietiakai);
        auto t6end = chrono::high_resolution_clock::now(); 

        auto t7start = chrono::high_resolution_clock::now();
        isvedimasFailu(nuskriaustukai, failas_nuskriaustukai);
        auto t7end = chrono::high_resolution_clock::now();

        auto t1end = chrono::high_resolution_clock::now(); 

        auto t1_dur = chrono::duration_cast<chrono::milliseconds>( t1end - t1start ).count();
        auto t2_dur = chrono::duration_cast<chrono::milliseconds>( t2end - t2start ).count();
        auto t3_dur = chrono::duration_cast<chrono::milliseconds>( t3end - t3start ).count();
        auto t4_dur = chrono::duration_cast<chrono::milliseconds>( t4end - t4start ).count();
        auto t5_dur = chrono::duration_cast<chrono::milliseconds>( t5end - t5start ).count();
        auto t6_dur = chrono::duration_cast<chrono::milliseconds>( t6end - t6start ).count();
        auto t7_dur = chrono::duration_cast<chrono::milliseconds>( t7end - t7start ).count();

        cout << "Failo "<<i<<" irasu"<<" generavimo greitis: " << t2_dur << "ms" << endl;
        cout << i<<" irasu nuskaitymo greitis: " << t3_dur << "ms" << endl;
        cout << i<< " irasu atskyrimo i nuskriaustukus ir kietiakus greitis: " << t4_dur << "ms" << endl;
        cout <<i<< " irasu rusiavimo greitis: " << t5_dur << "ms" << endl;
        cout << "Kietiaku irasymas i " << failas_kietiakai<<" greitis: "<< t6_dur << "ms" << endl;
        cout << "Nuskriaustuku irasymas i " << failas_nuskriaustukai<<" greitis: "<< t6_dur << "ms" << endl;
        cout << "Visos programos su " << i <<" irasu greitis: "<< t1_dur << "ms" << endl;

        cout << "Testi laiko testavima? Spauskite bet kuria raide." << endl;
        cin >> temp;
    }


}