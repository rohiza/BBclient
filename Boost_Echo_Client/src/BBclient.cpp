
#include <cstdlib>
#include <iostream>
#include "../include/BBclient.h"
#include "../include/connectionHandler.h"
#include "../include/Task.h"
#include <boost/thread.hpp>
using namespace std;

int main (int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " host port" << endl << endl;
        return -1;
    }
    string host = argv[1];
    short port = atoi(argv[2]);
    ConnectionHandler connectionHandler(host, port);
    atomic<bool> terminate(false);
    Task task(&connectionHandler, &terminate);
    //boost::thread task1(&Task::run, &task);
    boost::thread thread(boost::bind(&Task::run, &task));
    if (!connectionHandler.connect()) {
        cerr << "Cannot connect to " << host << ":" << port << endl;
        return 1;
    }

    while (!terminate.load()) {
        const short bufsize = 1024;
        char buf[bufsize];
        if (!cin.eof()) {
            cin.getline(buf, bufsize);
            string line(buf);
            int len = line.length();
            if (!connectionHandler.sendLine(line)) {
                cout << "Disconnected. Exiting...\n" << endl;
                break;
            }
            // connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
            cout << "Sent " << len + 1 << " bytes to server" << endl;
        }
    }
    return 0;
}

