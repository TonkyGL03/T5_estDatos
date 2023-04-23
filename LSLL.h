#ifndef LSLL_H_INCLUDED
#define LSLL_H_INCLUDED

#include <cstdlib>
#include <string>
#include <iostream>

#include "ListException.h"

class List{
private:
    int data[500];
    int last;

    bool isValidPos(const int&);
    void copyAll(const List&);

    void swapData(int&, int&);

    void sortDataMerge(const int&, const int&);
    void sortDataQuick(const int&, const int&);

public:
    List();
    List(const List&);

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const int&);
    void deleteData(const int&);

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const int&);
    int getNextPos(const int&);

    int findDataLinear(const int&);
    int findDataBinary(const int&);

    int retrieve(const int&);

    void sortDataBubble();
    void sortDataShell();
    void sortDataInsert();
    void sortDataSelect();

    void sortDataMerge();
    void sortDataQuick();

    std::string toString();

    void print();

    void deleteAll();

    List& operator = (const List&);
};

#endif // LSLL_H_INCLUDED
