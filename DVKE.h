class DVKE {
    protected:
        DVKE *V;
        DVKE *N;
        void *Data;

    public:
        DVKE() : V(nullptr), N(nullptr), Data(nullptr){};

        DVKE *getV();
        DVKE *getN();
        DVKE *getData();

        void setV(DVKE *);
        void setN(DVKE *);
        void setData(void *);
};