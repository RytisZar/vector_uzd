#include "funkciju_bib.h"
#include <vector>

int main(){
// Pradėti v1 užpildymo laiko matavimą
    auto start = chrono::high_resolution_clock::now();
    unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
    Vector<int> v1;
    for (int i = 1; i <= sz; ++i){
    v1.push_back(i);
    }
// Baigti v1 užpildymo laiko matavimą
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Savo vektoriaus laikas uztruko: " << duration << " milisekundziu" << endl;
// Pradėti v2 užpildymo laiko matavimą
    vector<int> v2;
    auto start_2 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= sz; ++i) {
    v2.push_back(i);
    }
    auto end_2 = chrono::high_resolution_clock::now();
    auto duration_2 = chrono::duration_cast<chrono::milliseconds>(end_2 - start_2).count();
    cout << "Paprasto vektoriaus laikas uztruko: " << duration_2 << " milisekundziu" << endl;

    Vector<int>customvector;
    vector<int>originalvector;
    size_t persiskirstymaicustom = 0;
    size_t persiskirtstymaioriginal = 0;

    for (int i = 0; i < 100000000; ++i) {
        // Insert an element into Vector
        customvector.push_back(i);
        if (customvector.getCapacity() == customvector.getSize()) {
            persiskirstymaicustom++;
        }

        // Insert an element into std::vector
        originalvector.push_back(i);
        if (originalvector.capacity() == originalvector.size()) {
            persiskirtstymaioriginal++;
        }
    }
    cout << "Perskirstymai pacio sukurto vektoriaus: " << persiskirstymaicustom << std::endl;
    cout << "Orginalaus vektorio pasiskirstymai: " << persiskirtstymaioriginal << std::endl;
}