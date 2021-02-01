#include "DVKE.h"


DVKE *DVKE::getV() {
    return this->V;
}

DVKE *DVKE::getN() {
    return this->N;
}

DVKE *DVKE::getData() {
    return this->Data;
}

void DVKE::setV(DVKE *nV) {
    this->V = nV;
}

void DVKE::setN(DVKE *nN) {
    this->N = nN;
}

void DVKE::setData(void *nData) {
    this->Data = nData;
}
