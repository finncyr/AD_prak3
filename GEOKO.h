class GEOKO {
    private:
        int BrGr;
        int LaGr;
        int BrMin;
        int LaMin;
        double BrSec;
        double LaSec;
        double abstand;

    public:
        GEOKO() : BrGr(0), BrMin(0), BrSec(0), LaGr(0), LaMin(0), LaSec(0){};
        GEOKO(int nBrGr, int nLaGr, int nBrMin, int nLaMin, double nBrSec, double nLaSec) : 
            BrGr(nBrGr), LaGr(nLaGr), BrMin(nBrMin), LaMin(nLaMin), BrSec(nBrSec), LaSec(nLaSec){};
        ~GEOKO();

        bool operator >(GEOKO &);
        bool operator ==(GEOKO &);

        void setAbstand(GEOKO *);
        double getDistance(GEOKO *);
        double getAbstand();

        int getBrGr();
        int getLaGr();
        int getBrMin();
        int getLaMin();
        double getBrSec();
        double getLaSec();

        void setBrGr(int);
        void setLaGr(int);
        void setBrMin(int);
        void setLaMin(int);
        void setBrSec(double);
        void setLaSec(double);
};