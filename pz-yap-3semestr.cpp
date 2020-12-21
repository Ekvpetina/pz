#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdexcept>
#include <cmath>

using namespace std;

class Massiv
{
private:
    int *Arr;
    int N;
public:
    Massiv (int Num);
    Massiv (const Massiv &mass);
    void addition (Massiv &twoArr);
    void subtraction (Massiv &twoArr);
    ~Massiv();
    void Fill();
    void Show();
    void Adding(int val);
    int getArr(int i){
        if((i >= 0) & (i <= N)){
        return *Arr;
        }
        else{
            throw out_of_range("GETerrorRange");
        }
    }

    void setter(int i,int res){
       if((i >= 0) && (i <= N))
       Arr[i] = res;
    else{
            throw out_of_range("SETerrorRange");
        };
    if((res >= -100) && (res <= 100))
    Arr[i] = res;
    else{
        throw invalid_argument("SETerrorInv");
        };
    }
};

Massiv::Massiv(int Num)
{
    N = Num;
    Arr = new int[N];
}

Massiv::~Massiv()
{
    delete[]Arr;
    Arr = NULL;
}

void Massiv::Fill()
{
    for (int i = 0; i < N; i++)
        Arr[i] = rand() % N + 1;
}

void Massiv::Show()
{
    for(int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

Massiv::Massiv (const Massiv &mass){
    int i;
    Arr = new int[mass.N];
    for(i = 0; i<= N; i++){
        Arr[i] = mass.Arr[i];
    }
}

void Massiv::addition (Massiv &twoArr){
    int i;
    N = twoArr.N;
    for(i = 0; i <= N; i++){
        Arr[i] += twoArr.Arr[i];
    }
}

void Massiv::subtraction (Massiv &twoArr){
    int i;
    N = twoArr.N;
    for(i = 0; i <= N; i++){
        Arr[i] -= twoArr.Arr[i];
    }
}

void Massiv::Adding(int val){
    int *Arr2 = NULL;
    if((val >= -100) && (val <= 100)){
        Arr2 = (int*)realloc(Arr, (N+1)*sizeof(int));
        if(Arr2 == NULL){
            Arr2 = (int*)malloc((N+1)*sizeof(int));
            if(Arr2 == NULL){
                //cout << "UPS, ERROR" << endl;
                throw bad_alloc();
            }
            else{
                memcpy(Arr2, Arr, N * sizeof(int));
                Arr2 = Arr;
                free(Arr);
            }
        }
        else{
            N++;
            Arr[N-1] = val;
        }

    }
    else{
        throw invalid_argument("ADDerrorInv");
    }
}

template <typename T>
class Shablon

{
private:
    int N;
    T *Arr;
public:
    Shablon (T Num);
    Shablon (const Shablon &massiv);
    void addition (Shablon &twoarr);
    void subtraction (Shablon &twoarr);
    ~Shablon();
    void Fill();
    void Show();
    void Adding(T val);
    void operator =(Shablon& mass2);
    int getArr(int i){
        if((i >= 0) & (i <= N)){
        return *Arr;
        }
        else{
            throw out_of_range("GETerrR2");
        }
    }

    void setter(int i,T res){
       if((i >= 0) && (i <= N))
       Arr[i] = res;
    else{
            throw out_of_range("SETerrR2");
        };
    if((res >= -100) && (res <= 100))
    Arr[i] = res;
    else{
        throw invalid_argument("SETerrI2");
        };
    }
    friend ostream& operator <<(ostream& os, Shablon<T>& mass) {
        for (int i = 0; i < mass.N; i++)
        os << mass.Arr[i] << " ";
        return os;
    }
    friend float GetRange( Shablon<T>& mass1, Shablon<T>& mass2) {
        float Range = 0;
        int length = mass1.N;
        if (mass1.N > mass2.N)
            length = mass2.N;
        for (int i = 0; i < length; i++) {
            Range = Range + pow((mass1.Arr[i] - mass2.Arr[i]), 2);
        }
        if (mass1.N >= mass2.N)
        for (int i = length; i < mass1.N; i++)
            Range = Range + pow(mass1.Arr[i], 2);
        if (mass1.N < mass2.N)
        for (int i = length; i < mass2.N; i++)
            Range = Range + pow(mass2.Arr[i], 2);
        Range = sqrt(Range);
        return Range;
    }
};
template <typename T>
Shablon<T>::Shablon(T Num)
{
    N = Num;
    Arr = new T[Num];
}
template <typename T>
Shablon<T>::~Shablon()
{
    delete[]Arr;
    Arr = NULL;
}
template <typename T>
void Shablon<T>::Fill()
{
    for (int i = 0; i < N; i++)
        Arr[i] = rand() % N + 1;
}
template <typename T>
void Shablon<T>::Show()
{
    for(int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << endl;
}
template <typename T>
Shablon<T>::Shablon (const Shablon &massiv){
    int i;
    Arr = new T[massiv.N];
    for(i = 0; i<= N; i++){
        Arr[i] = massiv.Arr[i];
    }
}
template <typename T>
void Shablon<T>::addition (Shablon &twoarr){
    int i;
    N = twoarr.N;
    for(i = 0; i <= N; i++){
        Arr[i] += twoarr.Arr[i];
    }
}
template <typename T>
void Shablon<T>::subtraction (Shablon &twoarr){
    int i;
    N = twoarr.N;
    for(i = 0; i <= N; i++){
        Arr[i] -= twoarr.Arr[i];
    }
}
template <typename T>
void Shablon<T>::Adding(T val){
    int *Arr2 = NULL;
    if((val >= -100) && (val <= 100)){
        Arr2 = (T*)realloc(Arr, (N+1)*sizeof(T));
        if(Arr2 == NULL){
            Arr2 = (T*)malloc((N+1)*sizeof(T));
            if(Arr2 = NULL){
                //cout << "UPS, ERROR" << endl;
                throw bad_alloc();
            }
            else{
                memcpy(Arr2, Arr, N * sizeof(T));
                Arr2 = Arr;
                free(Arr);
            }
        }
        else{
            N++;
            Arr[N-1] = val;
        }

    }
    else{
        throw invalid_argument("ADDerrI2");
    }
}

template<typename T>
void Shablon<T> :: operator = (Shablon& mass2) {
    if (this == &mass2) {
    return;
    }
    else {
int length = mass2.N;
if (mass2.N > this->N)
length = this->N;
for (int i = 0; i < length; i++) {
this->Arr[i] = mass2.Arr[i];
        }
    }
}

int main()
{
    srand(time(NULL));
    Massiv mass(10);
    //int N = 10;
    mass.Fill();
    mass.Show();
    cout << "\n\n";
    mass.Show();
    cout << "\n\n";
    cin.get();
    try
    {
        mass.Adding(102);
    }
    catch(bad_alloc()){
        cout << "exception happens: Memory's error" << endl;
    }
    catch(invalid_argument T){
         cout << "exception happens: " << T.what() << endl;
    }
    try
    {
        mass.getArr(77);
    }
    catch(out_of_range R){
        cout << "exception happens: " << R.what() << endl;
    }
    try
    {
        mass.setter(5, 120);
    }
    catch(out_of_range u){
        cout << "exception happens: " << u.what() << endl;
    }
    catch(invalid_argument V){
        cout << "exception happens: " << V.what() << endl;
    }
    cout << "\n\n";
    srand(time(NULL));
    Shablon <int> massiv(5);
    massiv.Fill();
    massiv.Show();
    cout << "\n\n";
    massiv.Show();
    cout << "\n\n";
    cin.get();
    srand(time(NULL));
    Shablon<int> mass1(5);
    Shablon<int> mass2(5);
    mass1.Fill();
    mass2.Fill();
    mass1.Show();
    mass2.Show();
    mass1 = mass2;
    mass1.Show();
    mass2.Show();
    cout << GetRange(mass1, mass2);
}

