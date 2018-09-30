#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>


using namespace std;

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    char trying [80];
    int x=0;



    while(x<=9)
    {
            time (&rawtime);
            timeinfo = localtime (&rawtime);
            strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
            strftime (trying,80,"%c",timeinfo );
            puts (buffer);
            puts(trying);
            x++;
            system
            _sleep(1000);
    }
    return 0;
}


