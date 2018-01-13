
#include "../include/Task.h"
#include "../include/connectionHandler.h"
#include <boost/thread.hpp>
using namespace std;

   Task::Task(ConnectionHandler* handler,atomic <bool>* shouldTerminate):handler(handler),terminate(shouldTerminate){}

long Task:: run(){
            while(!terminate->load()) {
                std::string answer;
                if (!(handler->getLine(answer))) {
                    std::cout << "Disconnected. Exiting...\n" << std::endl;
                    break;
                }
                int len = answer.length();
                answer.resize(len - 1);
                cout << answer <<endl;
                if (answer == "ACK signout succeded") {
                    std::cout << "Exiting...\n" << std::endl;
                    break;
                }
            }

            return 0;
        }


