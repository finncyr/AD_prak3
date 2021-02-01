#include "DVK.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <chrono>


#define SEMIKOL ";"
#define LINE_CHAR_MAX 2500

void textSeperator(){
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void CalcGeo(double secLong, double * sec, int * min, int * gr) {
    double tmp = secLong / 3600.;
    *gr = (int) tmp;
    tmp = tmp - *gr;
    tmp = tmp * 60;
    *min = (int) tmp;
    tmp = tmp - *min;
    tmp = tmp * 60;
    *sec = tmp;
}

int main(){
    int menuchoice = 0;
    int in = 0;
    std::string import;
    char *importchar = new char[100];
    DVK* Liste;

    std::fstream f;
    double brSecDurchschnitt = 0;
    double laSecDurchschnitt = 0;
    long left2read; // max to read
    char line[LINE_CHAR_MAX];

    std::chrono::steady_clock::time_point start, stop;
    std::chrono::duration<double> elapsed_seconds;


    while(menuchoice != 5){
        std::cout << "##########################################" << std::endl;
        std::cout << "#           Praktikum 3 in AD            #" << std::endl;
        std::cout << "##########################################" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Bitte Menuepunkt waehlen:" << std::endl;
        std::cout << std::endl;
        std::cout << "1.) Verkettete Liste anlegen" << std::endl;
        std::cout << "2.) Liste sortieren mit Heap Sort" << std::endl;
        std::cout << "3.) Liste sortieren mit Insertion Sort" << std::endl;
        std::cout << "4.) Daten der Liste schreiben" << std::endl;
        std::cout << std::endl;
        std::cout << "5.) Ende" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Nummer eingeben: ";
        std::cin >> menuchoice;

        switch(menuchoice){

        case 1:
            std::cout << "Maximale Länge der Liste? ";
            std::cin >> in;
            Liste = new DVK(in);
            left2read = in;

            std::cout << "Namen der Dateien eingeben: ";
            getchar();
            std::getline(std::cin, import); // Dateiname -> import
            strcpy(importchar, import.c_str());

            f.open(importchar, std::ios::in);
            while (left2read > 0 && !f.eof()) {
                f.getline(line, LINE_CHAR_MAX);

                char *token = strtok(line, ",; \t\n");
                if (!token) continue;
                double brSec = atof(token);
                token = strtok(NULL, ";, \t\n");
                if (!token) continue;
                double laSec = atof(token);

                left2read--;
                brSecDurchschnitt += brSec;
                laSecDurchschnitt += laSec;

                int brMin, laMin;
                int brGr, laGr;
                double brSecShort, laSecShort;
                CalcGeo(brSec, &brSecShort, &brMin, &brGr);
                CalcGeo(laSec, &laSecShort, &laMin, &laGr);

                Liste->anhaenge(
                        new GEOKO(
                        brGr, laGr,
                        brMin, laMin,
                        brSecShort, laSecShort)
                        );
            }
            f.close();
            std::cout << in << " Zeilen eingelesen!" << std::endl;

            Liste->CalcMiddle(brSecDurchschnitt, laSecDurchschnitt);
            Liste->CalcAllDistances();

            std::cout << "Mittelpunkt: " << std::endl;
            Liste->PrintMiddle(std::cout);

            textSeperator();
            break;

        case 2:
            start = std::chrono::steady_clock::now();
            Liste->heapSort();
            stop = std::chrono::steady_clock::now();
            elapsed_seconds = (stop-start);
            std::cout << "elapsed time: " << elapsed_seconds.count() << " s." << std::endl;
            textSeperator();
            break;

        case 3:
            start = std::chrono::steady_clock::now();
            Liste->insertionSort();
            stop = std::chrono::steady_clock::now();
            elapsed_seconds = (stop-start);
            std::cout << "elapsed time: " << elapsed_seconds.count() << " s." << std::endl;
            textSeperator();
            break;

        case 4:
            importchar = strtok(importchar, ".");
            strcat(importchar, "_S.csv");
            f.open(importchar, std::ios::out);

            f << "Anz Daten: " << Liste->getAnz() << "; Mittelpunkt: ";
            Liste->PrintMiddle(f);
            f << std::endl;

            f << std::fixed << std::setprecision(2)
            << std::right << std::setw(12) << std::setfill(' ') << "Abst" << SEMIKOL
            << std::right << std::setw(12) << std::setfill(' ') << "BrSec" << SEMIKOL
            << std::right << std::setw(12) << std::setfill(' ') << "LaSec" << SEMIKOL << std::endl;

            for(int i = 0; i < Liste->getAnz(); i++){
                Liste->PrintIndex(i, f);
            }

            f.close();

            std::cout << "Daten wurden in Datei geschrieben!" << std::endl;

            textSeperator();
            break;

        case 5:
            break;
        default:
            menuchoice = 5;
            break;
        }
	}

	delete importchar;
    delete Liste;

	return 0;
}
