#ifndef TOPIC_H
#define TOPIC_H

#include <string>
#include <vector>

using namespace std;

class Topic{
public:
    // Constructors
    Topic();
    Topic(int);
    Topic (int, string);


    //Functions
    int compare(Topic );

    int id;
    string name;

    
};

#endif