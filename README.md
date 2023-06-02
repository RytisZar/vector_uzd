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
3. Sukurta *pop_back* funkcija, kuri pradeda nuo patikros, ar masyvo dydis *size* yra didesnis nei nulis. Tikrinama yra bent vienas elementas, kurį galima pašalinti, jei sąlyga tenkinama, tada yra pašalinamas paskutinis elementas ir sumažinamas masyvo dydis.
4. Sukurta papildoma *insert* funkcija.  
Patikrinama, ar talpa yra lygi nuliui. Jei taip, tai reiškia, kad masyvas buvo tuščias ir priskiriama talpa 1. Kitu atveju, talpa padauginama iš 2.  
Sukuriamas naujas masyvas *newData* su didesne talpa *capacity*.
Perkopijuojami esami elementai iš seno masyvo *data* į naują masyvą *newData*. Kopijuojami visi elementai iki nurodyto indekso *index*.  
Į naują masyvą (newData) įterpiamas naujas elementas (value) nurodytoje pozicijoje (index).  
Likę elementai nuo nurodyto indekso (index) perkeliami į naują masyvą (newData) pradedant nuo kitos pozicijos (index + 1).  
Senas masyvas *data* yra ištrinamas naudojant *delete[]*.  
Rodyklė "data" yra nukreipiama į naują masyvą (newData).  
Masyvo dydis *size* padidinamas vienetu.
5. Sukurta papildoma *erase* funkcija.



