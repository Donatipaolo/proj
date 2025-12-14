#include "package.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                      SETTER
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Package::Metadata::Metadata(Package *pk, unsigned int index){
    this->opcode = (enum Opcode*) &pk->metadata[index];
    index += sizeof(enum Opcode*);
    this->length = (unsigned int*) &pk->metadata[index];
    index +=  sizeof(unsigned int*);
    this->value = (void*) &pk->metadata[index];
}

void Package::setMetadata(Opcode opcode, unsigned int length, void* data){

    if(length_metadata + sizeof(Opcode) + sizeof(unsigned int) + length > this->METADATA_LENGTH){
        throw std::runtime_error("Medata Error: not enough space");
        return;
    }

    std::memcpy((void*) &metadata[length_metadata],(void*) &opcode,sizeof(Opcode));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode)],(void*) &length,sizeof(unsigned int));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode) + sizeof(unsigned int)],(void*) &data,length);
    length_metadata += sizeof(Opcode) + sizeof(unsigned int) + length;

    number_of_metadata++;

}

void Package::setMetadata(Opcode opcode, std::string data){
    unsigned int l = data.length();

    if(length_metadata + sizeof(Opcode) + sizeof(unsigned int) + l > this->METADATA_LENGTH){
        throw std::runtime_error("Medata Error: not enough space");
        return;
    }

    std::memcpy((void*) &metadata[length_metadata],(void*) &opcode,sizeof(Opcode));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode)],(void*) &l,sizeof(unsigned int));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode) + sizeof(unsigned int)],(void*) data.c_str(),l);
    length_metadata += sizeof(Opcode) + sizeof(unsigned int) + l;

    number_of_metadata++;
}

void Package::setMetadata(Opcode opcode, char* data){
    unsigned int l = strlen(data);

    if(length_metadata + sizeof(Opcode) + sizeof(unsigned int) + l > this->METADATA_LENGTH){
        throw std::runtime_error("Medata Error: not enough space");
        return;
    }

    std::memcpy((void*) &metadata[length_metadata],(void*) &opcode,sizeof(Opcode));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode)],(void*) &l,sizeof(unsigned int));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode) + sizeof(unsigned int)],(void*) data,l);
    length_metadata += sizeof(Opcode) + sizeof(unsigned int) + l;

    number_of_metadata++;
}

void Package::setMetadata(Opcode opcode, int data){
    if(length_metadata + sizeof(Opcode) + sizeof(unsigned int) + sizeof(int) > this->METADATA_LENGTH){
        throw std::runtime_error("Medata Error: not enough space");
        return;
    }

    int l = sizeof(int);

    std::memcpy((void*) &metadata[length_metadata],(void*) &opcode,sizeof(Opcode));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode)],(void*) &l,sizeof(unsigned int));
    std::memcpy((void*) &metadata[length_metadata + sizeof(Opcode) + sizeof(unsigned int)],(void*) &data,l);
    length_metadata += sizeof(Opcode) + sizeof(unsigned int) + l;

    number_of_metadata++;
}
    

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                      GETTER
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<Package::Metadata> Package::getMetadata(){
    std::vector<Package::Metadata> v;
    unsigned int index;
    for(int i = 0; i < this->number_of_metadata; i++){
        v.push_back(Package::Metadata(this,index));
        index+= v.back().getLength();
    }

    return v;
}

//Funzione che controlla se è presente un tipo di metadato se è presente resituisce un puntatore al valore altrimenti manda un eccezzione
void* Package::getMetadata(Opcode opcode){
    
    unsigned int current_index = 0;
    int l;

    for(int i = 0; i < number_of_metadata; i++){
        if((Opcode)metadata[current_index] == opcode){
            current_index+=sizeof(Opcode) + sizeof(unsigned int);
            return (void*)&metadata[current_index];
        }

        current_index += sizeof(Opcode);
        l = (unsigned int) metadata[current_index];
        current_index += l;
    }

    throw std::runtime_error("Metdata Error: Opcode not found in metadata");
    return nullptr;
}

void* Package::getMetadata(Opcode opcode, int& length){
    
    unsigned int current_index = 0;
    int l;

    for(int i = 0; i < number_of_metadata; i++){
        if((Opcode)metadata[current_index] == opcode){
            current_index+=sizeof(Opcode) + sizeof(unsigned int);
            return (void*)&metadata[current_index];
        }

        current_index += sizeof(Opcode);
        l = (unsigned int) metadata[current_index];
        current_index += l;
    }

    throw std::runtime_error("Metdata Error: Opcode not found in metadata");
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    CHECK FLAG
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Package::checkFlag(unsigned int checkflag){
    if(flags & checkflag == checkflag)
        return true;
    return false;
}