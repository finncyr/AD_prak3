#include "DVK.h"


DVK::DVK(int Anzahl) : Max(Anzahl), Anz(0), DVKE(){
    Index = new DVKE*[Anzahl];
}

DVK::~DVK(){
    delete Index;
}

int DVK::getAnz(){
    return this->Anz;
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

    return true;
}

// ----------------- HEAP SORT -----------------

void DVK::heapSort(){
    erzeugeHeap(Anz);

    for(int i = Anz; i > 1; i--){
        vertausche(0, i - 1);
        heapDown(i - 1, 1);
    }
}



void DVK::heapDown(long groesse, long index){
    while(index <= groesse/2){
        int LN = index*2;
        if(LN < groesse) if (*((GEOKO *)Index[LN]->getData()) > *((GEOKO *)Index[LN-1]->getData())) LN++;
        if(*((GEOKO *)Index[LN-1]->getData()) > *((GEOKO *)Index[index - 1]->getData())){
            vertausche(index-1,LN-1);
            index = LN;
        }
        else index = groesse;
    }
}


void DVK::erzeugeHeap(long Anzahl){
    for (long i = Anzahl / 2; i >= 1; i--) {
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

    if(Index[First]->getV() != nullptr){
        Index[First - 1]->setN(Index[First]);
    }
    if(Index[First]->getN() != nullptr){
        Index[First + 1]->setV(Index[First]);
    }
    if(Index[Second]->getV() != nullptr){
        Index[Second - 1]->setN(Index[Second]);
    }
    if(Index[Second]->getN() != nullptr){
        Index[Second + 1]->setV(Index[Second]);
    }
}

// ----------------- INSERTION SORT -----------------

//TODO Test if works ansosnten index auf Array überprüfen
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


// Zusätzliche Methoden

void DVK::CalcAllDistances() {
    for (int i = 0; i < getAnz(); i++) {
        ((GEOKO *)Index[i]->getData())->setAbstand((GEOKO *)this->getData());
    }
}

void DVK::CalcMiddle(double brSecDurchschnitt, double laSecDurchschnitt) {
    brSecDurchschnitt = brSecDurchschnitt / this->getAnz();
    laSecDurchschnitt = laSecDurchschnitt / this->getAnz();
    int brMinDurchschnitt = (int) (brSecDurchschnitt / 60);
    int laMinDurchschnitt = (int) (laSecDurchschnitt / 60);
    int brGrDurchschnitt = (int) (brSecDurchschnitt / 3600);
    int laGrDurchschnitt = (int) (laSecDurchschnitt / 3600);

    this->setData(
        new GEOKO(
            brGrDurchschnitt,  laGrDurchschnitt,
            brMinDurchschnitt, laMinDurchschnitt,
            brSecDurchschnitt, laSecDurchschnitt
        )
    );
}

void DVK::PrintMiddle(std::ostream& out){
    out << *((GEOKO *)this->getData()) << std::endl;
}

void DVK::PrintIndex(int i, std::ostream& out){
    out << *((GEOKO *)Index[i]->getData()) << std::endl;
}
