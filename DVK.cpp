#include "DVK.h"


DVK::DVK(int Anzahl) : Max(Anzahl), Anz(0), DVKE(){
    Index = new DVKE*[Anzahl];
}

DVK::~DVK(){
    delete Index;
}



bool DVK::anhaenge(GEOKO *){

}

void heapSort();
void heapDown(long , long );
void erzeugeHeap(long Anzahl);
void vertausche(long First, long Second);

void insertionSort();