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
using namespace std;
 
int GetRandom(int max){
    srand(time(NULL));
    return rand() % max;
}
 
/* ----- SIMPLE THREAD EXAMPLE -----
void ExecuteThread(int id){
    // Get current time
    auto nowTime = chrono::system_clock::now(); 
    
    // Convert to a time we can output
    time_t sleepTime = 
            chrono::system_clock::to_time_t(nowTime);
    
    // Convert to current time zone
    tm myLocalTime = *localtime(&sleepTime);
    
    // Print full time information
    cout << "Thread " << id << 
            " Sleep Time : " <<
            ctime(&sleepTime) << endl;
    
    // Get separate pieces
    cout << "Month : " <<
            myLocalTime.tm_mon << endl;
    cout << "Day : " <<
            myLocalTime.tm_mday << endl;
    cout << "Year : " <<
            myLocalTime.tm_year + 1900 << endl;
    cout << "Hours : " <<
            myLocalTime.tm_hour << endl;
    cout << "Minutes : " <<
            myLocalTime.tm_min << endl;
    cout << "Seconds : " <<
            myLocalTime.tm_sec << "\n\n";
    
    // Put the thread to sleep for up to 3 seconds
    this_thread::sleep_for (chrono::seconds(GetRandom(3)));
    nowTime = chrono::system_clock::now();
    sleepTime = 
            chrono::system_clock::to_time_t(nowTime);
    cout << "Thread " << id << 
            " Awake Time : " <<
            ctime(&sleepTime) << endl;
    
}
// ----- END SIMPLE THREAD EXAMPLE ----- */
 
string GetTime(){
    auto nowTime = chrono::system_clock::now();
    time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
    return ctime(&sleepTime);
}
 
double acctBalance = 100;
 
// Protects shared data from being accessed at the
// same time
mutex acctLock;
 
void GetMoney(int id, double withdrawal)
{
    
    // The exception safe way to protect access
    // to code within its scope. The lock is released 
    // after execution leaves this scope
    lock_guard<mutex> lock(acctLock);
    
    // Blocks access between lock and unlock
    // until execution completes
    // This isn't good to use however if an error 
    // occurs between lock and unlock
    // acctLock.lock();
    
    this_thread::sleep_for(chrono::seconds(3));
    
    cout << id << 
            " tries to withdrawal $" <<
            withdrawal << " on " <<
            GetTime() << endl;
            
    if((acctBalance - withdrawal) >= 0){
        acctBalance -= withdrawal;
        cout << "New Account Balance is $" <<
                acctBalance << endl;
    } else {
        cout << "Not Enough Money in Account\n";
        cout << "Current Balance is $" <<
                acctBalance << endl;
    }
    // acctLock.unlock();
}
 
int main()
{
    /* ----- SIMPLE THREAD EXAMPLE -----
    // Create a thread and pass a parameter
    // to the function
    thread th1 (ExecuteThread, 1);
    
    // Join the thread to the main thread
    // meaning main waits for this thread to
    // stop executing before continuing execution
    // of code in main
    th1.join();
    
    thread th2 (ExecuteThread, 2);
    th2.join();
    ----- END SIMPLE THREAD EXAMPLE ----- */
    
    // We will create a pool of threads that
    // will access a bank account in no particular
    // order
    thread threads[10];
    
    for(int i = 0; i < 10; ++i){
        threads[i] = thread(GetMoney, i, 15);
    }
    
    for(int i = 0; i < 10; ++i){
        threads[i].join();
    }
    return 0;
}
