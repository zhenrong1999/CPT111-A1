#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <thread>
#include <string>


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
            cout << "Welcome to Intelligent Vending Machine!"<< flush << endl ;
            cout << buffer << flush << endl ;
            _sleep(100);
            system("CLS");



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
    bool stop2=false;

    //Show Menu
    int no_menu=0;
    double eWallet=0.00;
    _sleep(150);
    system("CLS");

    while (1==1)
    {
        system("CLS");
        cout << "Current amount in eWallet: RM" << eWallet   << endl;
        cout << "1. Depositing into eWallet\n" ;
        cout << "2. Purchase an item\n" ;
        cout << "3. Display the item purchased and amount due\n" ;
        cout << "4. Display the balance or change in the most efficient that is least Ringgit Malaysian denomination.\n" ;
        cout << "5. Display currency exchange rate and price of item the balance in the currency\n" ;
        cout << "6. Checkout\n" ;
        cout << "7. Exit\n" ;
        cin  >>  no_menu; //key no of menu

        if (no_menu <=0)
        {
            cout << "You have crash the system. Please restart the system....................";
            system("start Intelligent Vending Machine.exe");
            return 0;
        }
        if(no_menu ==7)
        {
            cout << "Thank you for using the Intelligient Vending Machine.\n";
            cout << "See you in the next transaction.\n";
            _sleep (2000);
            stop=false;
            thread t(loop);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            stop=true;

            return 1;

        }
        if (no_menu==2 & eWallet>0 )
            {
                cout << " Here are the HOT item that are in sale right now. \n";
                cout << "Apple Macbook Pro\n";
                cout << "-Seagate 250G SSD\n";
                cout << "-MSI Gaming Laptop\n";
                cout <<"-Cosiaer Gaming Mouse\n";
                cout <<"-Dell XPS 15\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string item_name;
                getline(cin, item_name);
            }

        if (no_menu==2 & eWallet==0 )
            {cout<<"Please deposit first in order to proceed! (Press 1) \n";cin.ignore(numeric_limits<streamsize>::max(), '\n');cin.get();}

        if (no_menu==1) //Program for depositing
         {
                double keyin;
                cout <<"Deposit for eWallet: RM ";
                cin >> keyin;
                if (keyin+eWallet>10000) //Limit for the eWallet
                {

                    cout << "Warning!!!";
                    cout << "You have deposit too much or your wallets full.\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();

                }
                    else {eWallet=eWallet+keyin;}
          }
         }
}



