#ifndef PACKAGE_H
#define PACKAGE_H

#include <vector>
#include <cstring>
#include <string>
#include <stdexcept>

const unsigned int ER = 1;
const unsigned int ST = 2;
const unsigned int TS = 4;
const unsigned int TX = 8;

enum Type{

    //Pacchetto per la gestione interna, quando il gestore dei pacchetti riceve questo messaggio allora eseguire una routine per inviare i dati al client appena connesso
    ONLINE,

    //Pacchetto Per l'inoltro e il controllo dei messaggi
    MSG,

    //Pacchetto utilizzato per interrogare il server
    ACK,

    //Pacchetto utilizzato per segnalare un errore
    ERROR,

    //Pacchetto utilizzato per la fase iniziale di login
    ACCESS,

};

enum Opcode{

    STATUS,
    TEXT,
    TIMESTAMP,
    ERROR_TYPE,
    ACK_TYPE,
    ID,
    ACCESS_TYPE
};

enum Error_type{
    USER_NOT_FOUND,
    USER_ALREADY_ONLINE,
    USER_ALREADY_EXITS
};

enum Access_type{
    LOGIN,
    LOGIN_SUCCESSFUL,
    LOGIN_FAILED,

    SIGNUP,
    SIGNUP_SUCCESSFUL,
    SIGNUP_FAILED,
};

//Classe pacchetto che avere diversi valori
class Package{
    public:
    
    static const unsigned int TIMESTAMP_LENGHT = 40;
    static const unsigned int MSG_LENGHT =  500;
    static const unsigned int METADATA_LENGTH = 1000;
  

    enum Type type;
    unsigned int source;
    unsigned int destination;
    unsigned char flags; 
    unsigned char number_of_metadata = 0;
    unsigned int length_metadata = 0;
    unsigned char metadata[METADATA_LENGTH];

    class Metadata{
        public:
        enum Opcode* opcode;
        unsigned int* length;
        void* value;

        Metadata(Package *pk, unsigned int index);

        unsigned int getLength() { return *length;}
    };


    //Setter
    void setMetadata(Opcode opcode, unsigned int length, void* data);
    void setMetadata(Opcode opcode, std::string data);
    void setMetadata(Opcode opcode, char* data);
    void setMetadata(Opcode opcode, int data);

    void setTimestamp(char* timestamp);
    void setTimestamp(std::string timestamp);

    //Getter
    std::vector<Metadata> getMetadata(); //Per raccogliere tutti i metadata
    void* getMetadata(Opcode opcode);
    void* getMetadata(Opcode opcode,int& length);

    //Funzione per controllare il flag
    bool checkFlag(unsigned int checkflag);

};


#endif