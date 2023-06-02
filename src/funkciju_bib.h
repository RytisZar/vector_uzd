#include "Biblioteka.h"
#include "Studentas.h"
void pildymas(Studentas &studentai);
double pazymiu_vidurkis(const Vector<int>& paz);
double pazymiu_mediana(const Vector<int>&pazymiai);
double galBalas (double skaicius_1, int skaicius_2);
void skaitymas_is_failo(Vector <Studentas>& studentai, const std::string & file_name);
void isvedimas(const Vector<Studentas>& studentai);
Vector<Studentas> ivedimas();
bool palygintiStudentus(const Studentas& student1, const Studentas& student2);
void rusiavimasStudentu(Vector<Studentas>& studentai);
void sukurimas_random_failo(const std::string&failo_pav, int studentu_skaicius);
bool studentuPalyginimas(const Studentas& s1, const Studentas& s2);
void spausdintiStudentus(const Vector<Studentas>& studentai, ofstream& outfile);
void dalintiStudentus(Vector<Studentas>& studentai, Vector<Studentas>& kietiakai, Vector<Studentas>& vargsiukai);
bool yraVargsiukas(const Studentas& temp);
void isvedimasFailu(Vector<Studentas> studentai, const std::string & file_name);
void rusiavimasDid(Vector<Studentas>& studentai);

