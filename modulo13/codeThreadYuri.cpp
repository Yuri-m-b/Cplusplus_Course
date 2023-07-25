#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>
#include <condition_variable>
using namespace std;

condition_variable cv;
// Protects shared data from being accessed at the
// same time
mutex acctLock;

bool isPing = true;

void printPing()
{
    for(int i = 0; i < 10; ++i)
    {
        unique_lock<mutex> lock(acctLock);
        cv.wait(lock, [] {return isPing;});
        cout << "Ping" << endl;
        
        isPing = false;
        cv.notify_one();
    }
}


void printPong()
{
    for(int i = 0; i < 10; ++i)
    {
        unique_lock<mutex> lock(acctLock);
        cv.wait(lock, [] {return !isPing;});
        cout << "Pong" << endl;
        
        isPing = true;
        cv.notify_one();
    }
}


int main()
{
    for(int i = 0; i < 10; ++i)
    {
        thread pingThread(printPing);
        thread pongThread(printPong);

        pingThread.join();
        pongThread.join();
    }

    return 0;
}
