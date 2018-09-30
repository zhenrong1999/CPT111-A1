#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <thread>


using namespace std;
bool stop = false; //the boolean stop is created before void so that the stop become public.
void loop() {

    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    int x=0;

    while(!stop)
    {
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
            cout << "Welcome to Intelligent Vending Machine!"<< endl ;
            puts (buffer);
            x++;
            _sleep(1000);
            system ("CLS");
    }

}

int main()
{

    thread t(loop); // Separate thread for loop.
    // This actually starts a thread.
    // Wait for input character (this will suspend the main thread, but the loop
    // thread will keep running).
    cin.get();
    // Set the boolean to true. The loop thread will exit from
    // loop and terminate.
    stop = true;


    return 0;
}


