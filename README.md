# Vector_uzd
**Čia bus naudojamas custom, paties sukurtas vektorius programos vykdymui**

Objektinio programvimo paskutinei versijai buvo padarytas atskiras ***Vector.h*** failas, kuriame yra paties sukurta vektoriaus klasė, skirta programos vykdymui.
Buvo sukurtos visos funkcijos, kurios yra reikalingos ***funkcijos.cpp*** failui.

1. Sukurtas "=" operatorius, kopijavimo priskyrimo operatorius, kuris leidžia priskirti vieną Vector objektą kitam. Veikimo principas: 
Funkcija patikrina, ar objektas, į kurį vyksta priskyrimas, nėra tas pats kaip kitas objektas, siekiant išvengti nereikalingo savęs priskyrimo.
Jei objektai yra skirtingi, funkcija pirmiausia atlaisvina esamą atmintį ištrindama duomenys *delete[]* data.
Kitoj eilutėj kopijuojami dydis ir talpa iš kito objekto į esamą objektą.
Naudodamasi new *T[capacity]*, sukuriamas naujas dinaminis masyvas tipo T su atnaujinta talpa.
Elementai iš kitų objekto duomenų masyvo kopijuojami į esamo objekto duomenų masyvą naudojant ciklą.
Galiausiai grąžinama nuoroda į esamą objektą (*this).  
2. Sukurta *push_back* funkcija, kuri pirmiausia tikrina ar vektoriaus dydis yra lygus jo talpai, jei taip, tai jis turi būti padidintas.  
Seni masyvo *data* elementai yra nukopijuojami į naują dinaminį masyvą naudojant for ciklą.  
Senas masyvas yra atlaisvinamas, jame yra ištrinami elementai naudojant *delete[] data*.  
Tada masyvo *data* elementai yra priskiriami naujam masyvui *newData*.  
Naujas elementas (value) priskiriamas į masyvo (data) galą, o vektoriaus dydis (size) padidinamas vienetu.

