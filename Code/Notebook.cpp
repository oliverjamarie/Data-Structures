#include "Notebook.h"
#include <string>
#include <iostream>
using namespace std;

Notebook::Notebook(void){
    name = "Undefined";
    id = 0;
}

Notebook::Notebook (string notebook_name_in){
    name = notebook_name_in;
    id = 0;
}

bool Notebook::insertTopic(string topic_name){
    int id = topics.size();
    Topic topic (id, topic_name);

    topics.push_back(topic);

    return true;
}

//they are the same if they have the same name and id
int Notebook::compare(Notebook other){
    int cmp = name.compare(other.name);//built in string function

    if (cmp == 0){
        if (id == other.id){
            return 0; 
        }
        if (id < other.id){
            return -1;
        }
        return 1;
        
    }

    return cmp;
}