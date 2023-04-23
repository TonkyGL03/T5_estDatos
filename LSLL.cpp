#include "LSLL.h"

using namespace std;


///private

void List::copyAll(const List& l){
    int i(0);
    while(i<= l.last){
        data[i] = l.data[i];

        i++;
    }

    last = l.last;
}

bool List::isValidPos(const int& p){
    return p >= 0 and p<= last;
}
///public

List::List() : last(-1){ }

List::List(const List& l){
    copyAll(l);
}

bool List::isEmpty(){
    return last == -1;
}

bool List::isFull(){
    return last == 499;
}

void List::insertData(const int& p, const int& e){
    if(isFull()){
        throw listException("desbordamiento de Datos, insertData");
    }

    if(p != -1 and !isValidPos(p)){
        throw  listException("posicion invalida, insertData");
        return;
    }

    int i(last);
    while(i > p){
        data[i + 1] = data[i];

        i--;
    }

    data[p + 1] = e;

    last++;
}

void List::deleteData(const int& p){
    if(!isValidPos(p)){
        throw listException("posicion invalida, deleteData");
        return;
    }

    int i(p);
    while(i < last){

        data[i] = data[i + 1];

        i++;
        }

    last--;
    }

int List::getFirstPos(){
    if(isEmpty()){
        return -1;
    }

    return 0;
}

int List::getLastPos(){
    return last;
}

int List::getPrevPos(const int& p){
    if(p == getFirstPos() or isValidPos(p)){
        return -1;
    }

    return p-1;
}

int List::getNextPos(const int& p){
    if(p==getLastPos() or isValidPos(p)){
        return -1;
    }

    return p+1;
}

int List::retrieve(const int& p){
    if(!isValidPos(p)){
        throw listException("posicion invalida, retrieve");
    }
    return data[p];
}

string List::toString(){
    string result;
    int i(0);

    while(i <= last){
        result += to_string(data[i]) + ",";

        i++;
    }

    result += "\n";

    return result;
}

void List::print(){
    int i(0);
    while(i<=last){
        cout << data[i++] << ",";
    }
    cout << endl;
}

int List::findDataLinear(const int& elem){
    int s;
    for(int i=0;i<=last; i++){
        s=data[i];
    if(elem==s)
        return i;
    }
    return -1;
}

int List::findDataBinary(const int& elem){
    int i(0), j(last), m;

    while(i <= j){
        m=(i + j) / 2;

        if(data[m] == elem){
            return m;
        }

        if(elem < data[m]){
            j = m-1;
        }

        else{
            i = m + 1;
        }
    }

    return -1;
}

void List::swapData(int& a, int& b){
    int aux(a);
    a = b;
    b = aux;
}

void List::sortDataBubble(){
    int i(last), j;
    bool flag;

    do{
        flag = false;
        int j = 0;

        while(j<i){
            if(data[j] > data[j+1]){
                swapData(data[j], data[j+1]);

                flag = true;
                }

            j++;
            }

        i--;
        }
    while(flag);
}

void List::sortDataInsert(){
    int i(1), j;
    int aux;

    while(i <= last){
        aux = data[i];
        j = i;

        while(j > 0 and aux < data[j-1]){
            data[j] = data[j-1];

            j--;
            }

        if(i != j){
            data[j] = aux;
        }

    i++;
    }
}

void List::sortDataSelect(){
    int i(0), j, m;

    while(i < last){
        m = i;
        j = i+1;

        while(j <= last){
            if(data[j] < data[m]){
                m = j;
            }

        j++;
        }
    if(i != m){
        swapData(data[i], data[m]);
    }

    i++;
    }
}

void List::sortDataShell(){
    float factor(1.0/2.0);
    int dif((last + 1) * factor), i, j;

    while(dif > 0){
        i = dif;

        while(i <= last){
            j = i;

            while(j >= dif and data[j-dif] > data[j]){
                swapData(data[j-dif], data[j]);

                j-= dif;
                }
            i++;
            }
        dif*= factor;
        }
}

/*
void List::sortDataMerge(){
    sortDataMerge(0,last);
}

void List::sortDataMerge(const int& leftEdge, const int& rightEdge){   if(leftEdge>=rightEdge){
        return;
    }

    ///divide y venceras
    int m((leftEdge + rightEdge) / 2);

    sortDataMerge(leftEdge, m);
    sortDataMerge(m+1, rightEdge);

    ///copia el auxiliar
    static int aux[ARRAYSIZE];
    for(int n(leftEdge); n<=rightEdge; n++){
        aux[n] = data[n];
    }

    ///intercalacion
    int i(leftEdge), j(m+1), x(leftEdge);

    while(i<=m and j <= rightEdge){
            while(i <= m and aux[i] <= aux[j]){
                data[x++] = aux[j++];
            }

    if(i <= m){
        while(j<=rightEdge and aux[j] <= aux[i]){
            data[x++] = aux[j++];
            }
        }
    }

    while(i<=m){
        data[x++] = aux[i++];
    }

    while(j<=rightEdge){
        data[x++] = aux[j++];
    }
}

void List::sortDataQuick(){
    sortDataQuick(0, last);
}

void List::sortDataQuick(const int& leftEdge, const int& rightEdge){
    if(leftEdge >= rightEdge){
        return;
    }

    ///separacion
    int i(leftEdge), j(rightEdge);

    while(i<j){
        while (i<j and data[i] <= data[rightEdge]){
            i++;
        }

        while(i<j and data[j] >= data[rightEdge]){
            j--;
        }

        if(i != j){
            swapData(data[i], data[j]);
        }
    }

    if(i != rightEdge){
        swapData(data[i], data[rightEdge]);
    }

    ///divide y venceras
    sortDataQuick(leftEdge, i-1);
    sortDataQuick(i+1, rightEdge);
}
*/

void List::deleteAll(){
    last = -1;
}

List& List::operator = (const List& l){
    copyAll(l);

    return *this;
}
