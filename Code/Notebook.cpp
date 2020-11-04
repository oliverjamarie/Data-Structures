#include "Notebook.h"
#include <string>
#include <iostream>
using namespace std;

Notebook::Notebook(void){
    name = "Undefined";
}

Notebook::Notebook (string notebook_name_in){
    name = notebook_name_in;
}

bool Notebook::insertTopic(string topic_name){
    int id = topics.size();
    Topic topic (id, topic_name);

    topics.push_back(topic);

    return true;
}
