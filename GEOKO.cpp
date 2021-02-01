#include "GEOKO.h"

// Vergleich nach Breitengrad -> Längengrad
bool GEOKO::operator >(GEOKO &nObj){
    if(this->getBrGr() > nObj.getBrGr()){return true;}
    else if(this->getLaGr() > nObj.getLaGr()){return true;}
    else if(this->getBrMin() > nObj.getBrMin()){return true;}
    else if(this->getLaMin() > nObj.getLaMin()){return true;}
    else if(this->getBrSec() > nObj.getBrMin()){return true;}
    else if(this->getLaSec() > nObj.getLaSec()){return true;}
    else return false;
}

bool GEOKO::operator ==(GEOKO &nObj){
    if(
        this->BrGr == nObj.getBrGr() &&
        this->BrMin == nObj.getBrMin() &&
        this->BrSec == nObj.getBrSec() &&
        this->LaGr == nObj.getLaGr() &&
        this->LaMin == nObj.getLaMin() &&
        this->LaSec == nObj.getLaSec()
    ){
        return true;
    }
    else return false;
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