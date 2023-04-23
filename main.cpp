#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "LSLL.h"

using namespace std;

int main(){
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(1, 999);
    auto dice = bind(distribution, generator);

    List myLista;
    int value;

    cout << "llenando lista..." << endl;

    for(int i(0); i<50; i++){
        value = dice();

        cout << "insertando:" << value << endl;

        myLista.insertData(myLista.getLastPos(), value);
    }

    cout << endl << endl;

    cout << "contenido de la lista (original):" << endl;
    cout << myLista.toString();

    cout << endl << endl;

    cout << "contenido de la lista (ordenado):" << endl;
    myLista.sortDataBubble();
    cout << myLista.toString();
    cout << endl << endl;


}
