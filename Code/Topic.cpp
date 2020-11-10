#include "Topic.h"
#include <string>

using namespace std; 

Topic::Topic(void){
    id = 0;
    name = "Undefined";
}

Topic::Topic(int id_in){
    id = id_in;
    name = "Undefined";
}

Topic::Topic (int id_in, string name_in){
    id = id_in;
    name = name_in; 
}

int Topic::compare(Topic other){
    int cmp = name.compare(other.name);

    if (cmp == 0){
        if (id == other.id){
            return 0;
        }
        else if (id < other.id){
            return -1;
        }
        else
        {
            return 1;
        }
        
    }

    return cmp;
}