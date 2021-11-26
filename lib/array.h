#include <iostream>
#include <stdexcept>

/**
 * Class par Alexandre Billereau dans le cadre du cour INF3105
 * a l'UQAM
 *
 * Class approuver par le professeur.
 *
 * date : 2021
 */

const int ARRAY_DEFAULT_CAPACITY = 100;
const int INITIAL_SIZE = 0;

template <typename T>
class Array{
private:

    //variable;
    T* ptr;
    int _size = INITIAL_SIZE;
    int _capacity = ARRAY_DEFAULT_CAPACITY;

    //function;
    void resize();

public:

    //function;
    Array(T arr[], int size = 16);
    Array(const Array &other);
    Array();
    ~Array();
    void push(T elem);
    T& get(int);
    void set(int, T);
    int indexof(T);
    bool contains(T);
    void insert(int, T);

    //function for const
    int length() const;
    T& get(int) const;
    int capacity() const;

    //define operator
    T& operator[](int);
    const T& operator[](int) const;
    const std::ostream& operator << (std::ostream& os);
    bool operator == (const Array&) const;
    bool operator!=(const Array&) const;
    Array<T>& operator = (const Array<T> &other);

    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Array<F> &array);
};


template<typename T>
void Array<T>::resize(){
    _capacity *= 2;
    //create temp array to stock new data
    T *temp = new T[_capacity];
    for(int i(0); i < _size; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

//Array function
template <typename T>
Array<T>::Array(T arr[], int size){

    ptr = new T[size];

    for(int i(0); i < size; i++){
        ptr[i] = arr[i];
    }

    _size = _capacity = size;
}

template <typename T>
Array<T>::Array(){
    ptr = new T[ARRAY_DEFAULT_CAPACITY];
    _size = INITIAL_SIZE;
}

template<typename T>
Array<T>::Array(const Array &other) {
    _capacity = other.capacity();
    _size = other.length();
    ptr = new T[_capacity];
    for(int i(0); i < _size ; i++)
        ptr[i] = other.ptr[i];
}

template <typename T>
Array<T>::~Array<T>() {
    delete []ptr;
    ptr = nullptr;
}

template<typename T>
int Array<T>::length() const {
    return _size;
}

template<typename T>
int Array<T>::capacity() const {
    return _capacity;
}

template<typename T>
void Array<T>::push(T elem){
    if(_size == _capacity){
        this->resize();
    }
    ptr[_size++] = elem;
}

template<typename T>
T& Array<T>::get(int index) const{
    if(index < 0 || index >= _size)
        throw std::out_of_range("Array out of range");
    return ptr[index];
}

template<typename T>
T &Array<T>::get(int index) {
    if(index < 0 || index >= _size)
        throw std::out_of_range("Array out of range");
    return ptr[index];
}

template<typename T>
void Array<T>::set(int index, T value){
    ptr[index] = value;
}

template<typename T>
int Array<T>::indexof(T value){
    for(int i(0); i < _size; i++){
        if(ptr[i] == value){
            return i;
        }
    }
    return -1;
}

template<typename T>
bool Array<T>::contains(T value){
    for(int i(0); i < _size; i++){
        if(ptr[i] == value){
            return true;
        }
    }
    return false;
}


/***********|ANSWER|************
 * @warning this functions is not tested.
 */
template<typename T>
void Array<T>::insert(int index, T _value){
    T valueTemp;
    T value = _value;

    if( _size == _capacity){
        this->resize();
    }

    for(int i(0); i < _size + 1; i++){
        if( i >= index ){
            valueTemp = ptr[i];
            ptr[i] = value;
            value = valueTemp;
        }
    }

    _size++;
}

//Operator

template<typename T>
T& Array<T>::operator[](int number){
    return this->get(number);
}

template<typename T>
const T& Array<T>::operator[](int number) const {
    return this->get(number);
}

template<typename T>
const std::ostream &Array<T>::operator<<(std::ostream& os) {
    for(int i(0); i < _size; i++){
        os << this[i] << std::endl;
    }

    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array){
    for(int i(0); i < array.length(); i++){
        os << array[i] << std::endl;
    }

    return os << std::endl;
}

template<typename T>
bool Array<T>::operator==(const Array& other) const {
    if(_size != other.length()){
        return false;
    }
    for(int i(0); i < _size; i++)
        if(ptr[i] != other[i])
            return false;
    return true;
}

template<typename T>
bool operator==(const Array<T>& array1, const Array<T>& array2){
    if(array1.length() != array2.length())
        return false;
    for(int i(0); i< array1.length(); i++)
        if(array1[i] != array2[i])
            return false;
    return true;
}



template<typename T>
Array<T> &Array<T>::operator=(const Array& other) {
    if(other != this){
        if(_size != other.length()){
            delete []ptr;
            _size = other.length() * 2;
            ptr = new T[_size];
        }
        for(int i(0); i < _size; i++ ){
            ptr[i] = other[i];
        }
    }
    return *this;
}

template<typename T>
bool Array<T>::operator!=(const Array & other) const {
    return !(this == other);
}

template<typename T>
bool operator != (const Array<T>& array, const Array<T> &other){
    return !(array == other);
}





