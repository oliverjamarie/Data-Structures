#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Topic.h"
#include <string>
#include <vector>

using namespace std; 

class Notebook{
public:
    
    //constructors
    Notebook();
    Notebook(string name_in);
    
    vector<Topic> topics;
    string name;
    int id; 
    bool insertTopic(string );
    bool equals(Notebook );
};



#endif