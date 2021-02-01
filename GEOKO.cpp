#include "GEOKO.h"

#define EPSILON 0.01
#define SEMIKOL ";"


void GEOKO::setAbstand(GEOKO *ngeo){
    abstand = getDistance(ngeo);
}

double GEOKO::getDistance(GEOKO *m){
    double x = abs(this->getBrSec() - m->getBrSec());
    double y = abs(this->getLaSec() - m->getLaSec());
    return sqrt(x * x + y * y);
}

double GEOKO::getAbstand(){
    return this->abstand;
}

int GEOKO::getBrGr(){
    return this->BrGr;
}

int GEOKO::getLaGr(){
    return this->LaGr;
}

int GEOKO::getBrMin(){
    return this->BrMin;
}

int GEOKO::getLaMin(){
    return this->LaMin;
}

double GEOKO::getBrSec(){
    return this->BrSec;
}

double GEOKO::getLaSec(){
    return this->LaSec;
}



void GEOKO::setBrGr(int nBrGr){
    this->BrGr = nBrGr;
}

void GEOKO::setLaGr(int nLaGr){
    this->LaGr = nLaGr;
}

void GEOKO::setBrMin(int nBrMin){
    this->BrMin = nBrMin;
}

void GEOKO::setLaMin(int nLaMin){
    this->LaMin = nLaMin;
}

void GEOKO::setBrSec(double nBrSec){
    this->BrSec = nBrSec;
}

void GEOKO::setLaSec(double nLaSec){
    this->LaSec = nLaSec;
}


bool GEOKO::operator>(GEOKO& nObj){
    return this->getAbstand() > nObj.getAbstand();
}

bool GEOKO::operator<(GEOKO& nObj){
    return this->getAbstand() < nObj.getAbstand();
}

bool GEOKO::operator>=(GEOKO& nObj){
    return this->getAbstand() >= nObj.getAbstand();
}

bool GEOKO::operator<=(GEOKO& nObj){
    return this->getAbstand() <= nObj.getAbstand();
}

bool GEOKO::operator==(GEOKO& nObj){
    return fabs(this->getAbstand() - nObj.getAbstand()) <= EPSILON;
}

bool GEOKO::operator!=(GEOKO& nObj){
    return fabs(this->getAbstand() - nObj.getAbstand()) > EPSILON;
}


// Thanks StackOverflow ^^
std::ostream& operator<<(std::ostream& ostream, GEOKO& geo) {
    ostream << std::fixed << std::setprecision(2) 
            << std::right << std::setw(12) << std::setfill(' ') << geo.getAbstand() << SEMIKOL 
            << std::right << std::setw(12) << std::setfill(' ') << geo.getBrSec() << SEMIKOL 
            << std::right << std::setw(12) << std::setfill(' ') << geo.getLaSec() << SEMIKOL;
    return ostream;
}