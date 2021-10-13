#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Block
{
    private:
        string pHash; //praeito bloko hashas
        string bHash; //pacio blocko hashas
        string mHash; //merkle tree hashas
        int timestamp;
        int nonce = 0;
        string difficulty;
        string version = "v0.1";
    public:
        Block() {}
        Block(string pHash, string mHash) 
        { 
            this->pHash = pHash; 
            this->mHash = mHash;
            
            timestamp = time(0);
        }
        Block(string pHash, string mHash, int nonce, string difficulty) 
        { 
            this->pHash = pHash; 
            this->mHash = mHash;
            
            timestamp = time(0);

            this->nonce = nonce;
            this->difficulty = difficulty;
        }

        ~Block () {}

        string getPrevHash() const { return pHash; }
        string getHash() const { return bHash; }
        string getMerkleHash() const { return mHash; }
        int getNonce() const { return nonce; }
        int getTimestamp() const { return timestamp; }
        string getVersion() const { return version; }
        string getDifficulty() const { return difficulty; }

        void setHash(string bHash) { this->bHash = bHash; }
        void setNonce(int nonce) { this->nonce = nonce; }
        void setDifficulty(string difficulty) { this->difficulty = difficulty; }
};

void BlockMining(Block &b);

#endif