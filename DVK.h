#include "DVKE.h"
#include "GEOKO.h"
#include <iostream>

class DVK : private DVKE{
    private:
        int Max;
        int Anz;
        DVKE** Index;

    public:
        DVK(int Anzahl);
        ~DVK();

        int getAnz();

        bool anhaenge(GEOKO *);
        void heapSort();
        void heapDown(long , long );
        void erzeugeHeap(long Anzahl);
        void vertausche(long First, long Second);

        void insertionSort();

        void CalcAllDistances();
        void CalcMiddle(double brSecDurchschnitt, double laSecDurchschnitt);
        void PrintMiddle(std::ostream&);
        void PrintIndex(int, std::ostream&);
};
