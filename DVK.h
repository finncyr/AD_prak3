#include "DVKE.h"
#include "GEOKO.h"

class DVK : private DVKE{
    private:
        int Max;
        int Anz;
        DVKE** Index;

    public:
        DVK(int Anzahl) : Max(Anzahl), Anz(0){};
        ~DVK();

        bool anhaenge(GEOKO *);
        void heapSort();
        void heapDown(long , long );
        void erzeugeHeap(long Anzahl);
        void vertausche(long First, long Second);

        void insertionSort();
    
};