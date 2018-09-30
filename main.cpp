#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

#include <string>
using namespace std;
using std::chrono::system_clock;
int main()
{
    char aas;


            time_t tt = system_clock::to_time_t (system_clock::now());
            struct tm * ptm = localtime(&tt);
            cout << "Now (local time): " << put_time(ptm,"%c") << '\n';

            cout << aas;






    return 0;
}


