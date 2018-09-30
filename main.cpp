#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <thread>


using namespace std;
bool stop = false;
void loop() {



    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    char trying [80];
    int x=0;


    while(!stop)
    {
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
            strftime (trying,80,"%c",timeinfo );
            puts (buffer);
            puts(trying);
            x++;
            _sleep(500);
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
    // Set the atomic boolean to true. The loop thread will exit from
    // loop and terminate.
    stop = true;


    return 0;
}


