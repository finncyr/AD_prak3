class DVKE {
    protected:
        DVKE *V;
        DVKE *N;
        void *Data;

    public:
        DVKE() : V(nullptr), N(nullptr), Data(nullptr){};
        DVKE(DVKE *nV, DVKE *nN, void *nData) :
            V(nV), N(nN), Data(nData){};
        ~DVKE();

        DVKE *getV();
        DVKE *getN();
        void *getData();

        void setV(DVKE *);
        void setN(DVKE *);
        void setData(void *);
};
