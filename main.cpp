#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
    puts (buffer);

    return 0;
}


