#include "user.hpp"
#include "Hashas/hash.hpp"
#include "transaction.hpp"

void VartotojuGeneravimas(vector<User> &vartotojai)
{
    int n = 1000; //kiek vartotoju bus
    vartotojai.reserve(n);

    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(100,1000000);

    for(int i = 0; i<n; i++)
    {
        User u;

        u.setVardas("Vardas"+to_string(i));
        u.setVal(distribution(generator));
        u.setPk(DuomenuHashinimas(u.getVardas()+to_string(u.getVal()))); //laikinas private key generavimo sprendimas

        vartotojai.push_back(u);
    }
}

void TransakcijuGeneravimas(vector<User> vartotojai, vector<Transaction> &transactionPool)
{
    int n = 10000;
    transactionPool.reserve(n);

    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, 1000-1);

    int u1; //user 1 (siuntejas)
    int u2; //user 2 (gavejas)

    while(transactionPool.size()!=transactionPool.capacity())
    {
        Transaction t;

        u1 = distribution(generator);
        u2 = distribution(generator);

        if(u1 != u2)
        {
            uniform_real_distribution<float> distributionF(1, (vartotojai[u1].getVal()/5)); //kol kas vartotojai atsakingi ir neisleidzia daugiau nei penktadalio valiutos :)

            t.setVal(distributionF(generator));
            t.setSiuntejoPk(vartotojai[u1].getPk());
            t.setGavejoPk(vartotojai[u2].getPk());

            t.setId(DuomenuHashinimas(to_string(t.getVal()) + t.getSiuntejoPk() + t.getGavejoPk()));

            transactionPool.push_back(t);
        }
    }   
}

void TransakcijuParinkimas(vector<Transaction> transactionPool, vector<Transaction> &transactionList, int n)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, 10000-1);

    for(int i = 0; i<n; i++) // n nurodo kiek transakciju bus paimta
    {
        int sk = distribution(generator);

        transactionList.push_back(transactionPool[sk]);
    }
}