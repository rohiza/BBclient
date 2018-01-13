
#ifndef BOOST_ECHO_CLIENT_TASK_H
#define BOOST_ECHO_CLIENT_TASK_H

#include <iostream>
#include "connectionHandler.h"
#include <boost/thread.hpp>
using namespace std;

class Task{
private:
    ConnectionHandler* handler;
    atomic<bool>* terminate;

public:
    Task(ConnectionHandler* handler, atomic<bool>* terminate);
    long run();
};


#endif //BOOST_ECHO_CLIENT_TASK_H
