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

    if(this->getData() != nullptr){
        ((GEOKO *)Index[Anz]->getData())->setAbstand((GEOKO *)this->getData());
    }

    Anz++;
}

// ----------------- HEAP SORT -----------------

void DVK::heapSort(){
    erzeugeHeap(Anz);

    for(int i = Anz; i > 1; i--){
        vertausche(0, i - 1);
        heapDown(i - 1, 1);
    }
}


//TODO Checken ob funktioniert sonst Arrayindex immer "index" - 1
void DVK::heapDown(long groesse, long index){
    for (long i = 2 * index; i < groesse; i = 2 * i) {
        if (((i + 1) < groesse) && (*((GEOKO *)Index[i + 1]->getData()) > *((GEOKO *)Index[i]->getData())))
            i++;
        if (*((GEOKO *) Index[i / 2]->getData()) >= *((GEOKO *)Index[i]->getData()))
            break;

        vertausche(i / 2, i);
    }
}

void DVK::erzeugeHeap(long Anzahl){
    for (long i = Anzahl / 2; i >= 0; i--) {
        heapDown(Anzahl, i);
    }
}


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

// ----------------- INSERTION SORT -----------------

void DVK::insertionSort(){
    int j = 0;
    for(int i = 1; i < Anz; i++){
        j = i;
        while (j > 0 && *((GEOKO *)Index[j-1]->getData()) > *((GEOKO *)Index[j]->getData())){
            vertausche(j, j-1);
            j -= 1;
        }
    }
}