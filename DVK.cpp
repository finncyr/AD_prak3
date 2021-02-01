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

void DVK::heapSort(){
    erzeugeHeap(Anz);

    for(int i = Anz; i > 1; i--){
        vertausche(0, i - 1);
        heapDown(i - 1, 1);
    }
}

void DVK::heapDown(long groesse, long index){
    for (long i = 2 * index; i < groesse; i = 2 * i) {
        if (((i + 1) < groesse) && (*(Index[i + 1]) > *(Index[i])))
            i++;
        if (*((GEOKO *) Index[i / 2]->getData()) >= *((GEOKO *)Index[i]->getData()))
            break;

        vertausche(i / 2, i);
    }
}

void erzeugeHeap(long Anzahl);
void DVK::vertausche(long First, long Second){
    DVKE *tmp = Index[First];
    Index[First] = Index[Second];
    Index[Second] = tmp;

    tmp = Index[Second]->getV();
    Index[Second]->setV(Index[First]->getV());
    Index[First]->setV(tmp);

    tmp = Index[Second]->getN();
    Index[Second]->setN(Index[First]->getN());
    Index[First]->setN(tmp);

    Index[First - 1]->setN(Index[First]);
    Index[First + 1]->setV(Index[First]);

    Index[Second - 1]->setN(Index[Second]);
    Index[Second + 1]->setV(Index[Second]);
}

void insertionSort();