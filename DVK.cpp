#include "DVK.h"


DVK::DVK(int Anzahl) : Max(Anzahl), Anz(0), DVKE(){
    Index = new DVKE*[Anzahl];
}

DVK::~DVK(){
    delete Index;
}



bool DVK::anhaenge(GEOKO *neu){
    DVKE *Element = new DVKE(nullptr,nullptr,(void*)neu);
    Index[Anz] = Element;

    if(Anz != 0){
        Index[Anz - 1]->setN(Element);
        Element->setV(Index[Anz - 1]);
    }

    Anz++;
}

void heapSort();
void heapDown(long , long );
void erzeugeHeap(long Anzahl);
void vertausche(long First, long Second);

void insertionSort();