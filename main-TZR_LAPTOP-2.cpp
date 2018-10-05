#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>



using namespace std;


int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    int no_menu=0;
    double eWallet=0.00;
    double price;
    string item;
    bool entered = false;
    bool from_menu2 = false;
    int buff_acc;
    int buff_pass;
    string buff_passS;
    int n_balance;


        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
        cout << buffer << endl ;

while (1==1)
    {
        //Show Menu
    do
        {system("CLS");
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
        cout << buffer << endl ;
        if (entered==false)
                {
                    cout << "Welcome to Intelligent Vending Machine!"<< endl ;
                    cin.get();
                    cout << "Please enter your account number.\n";
                    cin >> buff_acc;
                    cout << "Please enter your pin number.\n";
                    cin.clear();cin.ignore();
                    string buff_passS;
                    getline(cin,buff_passS) ;
                    buff_pass=stoi(buff_passS);
                    system("cls");
                    no_menu=7;


                }
        else
        {
        cout<<fixed<<showpoint<<setprecision(2);;
        cout << "Welcome back!\n"<<"Now,you are now using Intelligent Vending Machine."<< endl ;
        cout << "Current amount in eWallet: RM" << eWallet   << endl;
        cout << "1. Depositing into eWallet\n" ;
        cout << "2. Purchase an item\n" ;
        cout << "3. Display the item purchased and amount due\n" ;
        cout << "4. Display the balance or change in the most efficient that is least Ringgit Malaysian denomination.\n" ;
        cout << "5. Display currency exchange rate and price of item the balance in the currency\n" ;
        cout << "6. Exit\n" ;
        cin  >>  no_menu; //key no of menu
        system("cls");

        if (no_menu <=0)
        {
            cout << "You have crash the system. Restarting the system....................\n";
            cin.clear();cin.ignore();
            cin.get();
            entered=false;
        }
        }
        if(no_menu==7)
        {
            int sec_code;
            int x ;
            int buff;
            int buff2;
            entered=true;
            for (x=0;x<=3;x++)
            {//secret sauce ha ha ha :)
                buff2=pow(10,x+1);
                buff = (buff_pass%buff2) / (pow(10,x)); //Equation finding the place value
                if((buff % 2)>=0.5){buff=(buff+7)%10;}  //Find Odd numbe
                else {buff=(buff+11)%10;}//Find even number                   r
                sec_code=sec_code+buff*pow(10,3-x);
               }
            entered==true;
            cout << "Below is your secret code for your account. \nPlease make sure it is the right secure code to avoid scamming and fishing. \n";
            cout <<"Your secret code is "<< sec_code;
            cin.clear();cin.ignore();
            cin.get();
        }



        if (no_menu==1) //Program for depositing
         {
                double keyin;
                cout <<"Deposit for eWallet: RM ";
                cin >> keyin;
                if (keyin+eWallet>10000) //Limit for the eWallet
                {

                    cout << "Warning!!!";
                    cout << "You have deposit too much or your wallets full.\n";
                    cin.clear();cin.ignore();
                    cin.get();

                }
                    else {eWallet=eWallet+keyin;}
         }
        if(no_menu ==6)
        {
            cout << "Thank you for using the Intelligent Vending Machine.\n";
            cout << "See you in the next transaction.\n";
            cout << "Have a nice day!\n";
            entered=false;


        }
        if (no_menu==2 && eWallet>0 )
            {
                cout << " Here are the HOT item that are in sale right now. \n";
                cout << "-Apple Macbook Pro\n";
                cout << "-Seagate 250G SSD\n";
                cout << "-MSI Gaming Laptop\n";
                cout <<"-Cosiaer Gaming Mouse\n";
                cout <<"-Dell XPS 15\n";
                cout << "\nYou can buy almost anything except things that are impossible to buy like time and life. \n";
                cout << "Please don't buy things that are prohibited under the law.\nFollow the rule of law.\n";
                cin.clear();cin.ignore();    //for clearing the cin        //ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, item);
                srand(time(0)) ;
                price= 1000+(rand()%5530);
                price=price/100;
                n_balance = eWallet - price;
                from_menu2=true;
                cout << "\n\n\n"<<"Please check the item list below carefully.\n\n";

                no_menu=3;
            }
        if (no_menu==2 && eWallet<0 )
            {cout << "Please deposit more in order to buy more great staff. (Press 1)";cin.ignore(numeric_limits<streamsize>::max(), '\n');cin.get(); }

        if (no_menu==2 && eWallet==0 )
            {cout<<"Please deposit first in order to proceed! (Press 1) \n";cin.ignore(numeric_limits<streamsize>::max(), '\n');cin.get();}

        if (no_menu==3)
            {
                if (price<=0)
                     {cout<<"You have come to the wrong place."<<"Come back after you have purchase something interesting."<<"Please an key to teleport you back to the main menu"; cin.clear();cin.ignore(); cin.get();}
               else{
                cout << "The items that you have brought.\n";


                cout << "Name of item: "<<  item <<endl;
                cout << "Price in RM: RM" <<  price<<endl;
                cout << "Your Balance: RM"<<n_balance<<endl;


                                    //Check whether come from menu 2.
                    if (from_menu2==true)
                        {cout << endl << "Is this the right thing that you want to buy?"<<"\n\n\n";from_menu2=false;}
                    else
                        {srand(time(0)) ;cout <<endl<<"Have you change your mind?"<<endl<<"Be fast the item maybe sold out soon."<< endl<<"It is around "<< rand()%100+1<<" left!!!"<<"\n\n\n";}

                    cout <<"If buy it, please press any key except \' 0 \' "<<endl<<"If want to cancel, please press \' 0 \' "<<endl << "If want to go back to the main menu, please press \' - \' and \' 1 \' "<<endl<<"and press enter.\n";
                    if (n_balance<0){cout<<"Please kindly fulfilled the required amount of money in the eWallet by putting more money into the eWallet.\n";}
                    cin >> no_menu;
                    if (no_menu!=0 ||no_menu!= -1)
                    {
                        if(n_balance>=0)
                        {no_menu=4;}
                        else {cout << "\n I am sorry my friend. \nPlease kindly top up your eWallet. \nThis is because my company does not give small loan to customers yet. \nNext time, remember to deposit enough amount of money in eWallet to avoid this situation to happen again.\n";
                        cout<< "You are on your way back to main menu to deposit more money. \nPress \' 1 \' and press \' enter \' after reach main menu.\n";cin.clear(); cin.ignore(); cin.get();}
                    }
                    else if(no_menu==0){string item; double price;double n_balance;}
                    }
                }

    }while (no_menu <=0 || no_menu >= 10 );
}//while(1==1) end. The big loop that may no be escaped.
}//main end




