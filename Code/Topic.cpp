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