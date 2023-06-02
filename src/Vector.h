#include "Biblioteka.h"
template <typename T>
class Vector {
private:
    T* data;          //rodykle i dinamini masyva
    size_t size;      // storintas elementu skaicius
    size_t capacity;  // dinaminio masyvo dydis

public: 
    //konstruktorius
    Vector() : data(new T[0]), size(0), capacity(0) {}

    //destruktorius
    ~Vector() {
        delete[] data;
    }
    //vektoriaus kopijavimo konstruktorius
    Vector(const Vector& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity)  {
    for (size_t i = 0; i < size; ++i)
        data[i] = other.data[i];
    }
    //vektoriaus prilyginimo operatorius
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
            }
        return *this;
    }

    void push_back(const T& value) {
        if (size >= capacity) {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;

            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }
    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    T& back() {
        if (size > 0) {
            return data[size - 1];
        }
        throw std::out_of_range("Vektorius tuscias");
    }
    
     void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Neteisingas indeksas");
        }

        if (size >= capacity) {
            if (capacity == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            T* newData = new T[capacity];
            for (size_t i = 0; i < index; ++i) {
                newData[i] = data[i];
            }
            newData[index] = value;
            for (size_t i = index; i < size; ++i) {
                newData[i + 1] = data[i];
            }

            delete[] data;
            data = newData;
            ++size;
        } else {
            for (size_t i = size; i > index; --i) {
                data[i] = data[i - 1];
            }
            data[index] = value;
            ++size;
        }
    }
    template<typename Iterator>
    void customInsert(const Iterator& start, const Iterator& end) {
        size_t count = std::distance(start, end);
        size_t oldSize = size;
        resize(oldSize + count);

        Iterator it = start;
        for (size_t i = oldSize; i < size; ++i) {
            data[i] = *it;
            ++it;
        }
    }

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Invalid index");
        }

        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
    size_t getSize() const {
        return size;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    size_t getCapacity() const {
        return capacity;
    }

     T* begin () {
        return data;
    }

    T* end() {
        return data + size;
    }
    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }
    void resize(size_t newSize) {
        if (newSize > capacity) {
            capacity = newSize;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        size = newSize;
    }

    void clear() {
        size = 0;
    }    
};
