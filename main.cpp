#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>



using namespace std;


int main()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    int no_menu=1;
    double eWallet=0.00;
    double price;
    string item;
    bool entered = false;
    bool from_menu2 = false;
    string buff_acc;
    int buff_pass;
    string buff_passS;
    double n_balance;
    bool main_pass = true;


        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
        cout << buffer << endl ;

while (1==1)
    {
        //Show Menu'
    do
        {system("CLS");
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo );
        cout << buffer << endl ;

        if (entered==false)
                {
                    cout << "Welcome to Intelligent Vending Machine!"<< endl ;
                    cin.clear(); cin.ignore();
                    cin.get();
                    cout << "Please enter your account name.\n";
                    cin.clear(); cin.ignore();
                    cin >> buff_acc;
                    no_menu=7;
                }
        else
        {
        cout<<fixed<<showpoint<<setprecision(2);;
        cout << "Welcome back! "<<buff_acc<<"\n"<<"Now,you are now using Intelligent Vending Machine."<< endl ;
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

       if (no_menu==1) //Program for depositing
         {
                double keyin;
                cout <<"Deposit for buying things: RM ";
                cin >> keyin;
                if (keyin+eWallet>100) //Limit for the eWallet
                {

                    cout << "Warning!!!";
                    cout << "You have deposit too much or your wallets full.\n";
                    cin.clear();cin.ignore();
                    cin.get();

                }
                    else {eWallet=eWallet+keyin;}  //add the deposited money to the eWallet.
         }



        if (no_menu==2)
            {

                if ( eWallet<0) {cout << "Please deposit more in order to buy more great staff. (Press 1)";cin.clear();cin.ignore();cin.get(); } //check for the eWallet so that the user have some money in the eWallet before buying.
                else if (eWallet==0){cout<<"Please deposit first in order to proceed! (Press 1) \n";cin.clear();cin.ignore();cin.get();}
                else
                    {
                        cout << " Here are the HOT item that are in sale right now. \n";    //showing best seller.
                        cout << "-Apple Macbook Pro\n";
                        cout << "-Seagate 250G SSD\n";
                        cout << "-MSI Gaming Laptop\n";
                        cout <<"-Cosiaer Gaming Mouse\n";
                        cout <<"-Dell XPS 15\n";
                        cout << "\nYou can buy almost anything except things that are impossible to buy like time and life. \n";
                        cout << "Please don't buy things that are prohibited under the law.\nFollow the rule of law.\n";
                        cin.clear();cin.ignore();                               //for clearing the cin        //ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, item);   //get item name from user
                        srand(time(0)) ;        //randomize the prize
                        price= 1000+(rand()%5530);
                        price=price/100;
                        from_menu2=true;
                        cout << "\n\n\n"<<"Please check the item list below carefully.\n\n";
                        no_menu=3;
                        system("CLS");
                        }
            }


        if (no_menu==3)
            {
                if (price<=0)
                     {cout<<"You have come to the wrong place."<<"Come back after you have purchase something interesting."<<"Please an key to teleport you back to the main menu"; cin.clear();cin.ignore(); cin.get();}
               else{
                cout << "The items that you have brought.\n";
                cout << "Name of item: "<<  item <<endl;
                cout << "Price in RM: RM" <<  price<<endl;

            //Check whether come from menu 2.

                    if (from_menu2==true)
                        {cout << endl << "Is this the right thing that you want to buy?"<<"\n\n\n";from_menu2=false;}
                    else
                        {srand(time(0)) ;cout <<endl<<"Have you change your mind?"<<endl<<"Be fast the item maybe sold out soon."<< endl<<"It is around "<< rand()%10+1<<" left!!!"<<"\n\n\n";}

                    cout <<"If buy it, please press any key except \' 0 \' "<<endl<<"If want to cancel, please press \' 0 \' "<<endl << "If want to go back to the main menu, please press \' - \' and \' 1 \' "<<endl<<"and press enter.\n";

                    n_balance = eWallet - price; // calculate balance
                    if (n_balance<0){cout<<"Please kindly fulfilled the required amount of money in the eWallet by putting more money into the eWallet.\n";}
                    cin >> no_menu;
                    if (no_menu!=0 ||no_menu!= -1) //if user want to buy but does not have enough money
                    {

                        if(n_balance>=0)   {no_menu=4;system("CLS");}
                        else {
                                cout << "\n I am sorry my friend. \nPlease kindly top up your eWallet. \nThis is because my company does not give small loan to customers yet. \nNext time, remember to deposit enough amount of money in eWallet to avoid this situation to happen again.\n";
                                cout<< "You are on your way back to main menu to deposit more money. \nPress \' 1 \' and press \' enter \' after reach main menu.\n";cin.clear(); cin.ignore(); cin.get();}
                    }
                    else if(no_menu==0) {string item; double price;double n_balance;} //reset the value
                    }
                    }

        if(no_menu == 4)
            {

                            n_balance = eWallet - price; // calculate
                            n_balance= (round(n_balance * 20))/20;
                            if (n_balance >0)
                            {
                                int c_balance = n_balance *100;
                                int note_50=0;
                                int note_20=0;
                                int note_10=0;
                                int note_5=0;
                                int note_1=0;
                                int cent_50=0;
                                int cent_20=0;
                                int cent_10=0;
                                int cent_5=0;
                                //calculate for all the least Ringgit Malaysian denomination

                                if (c_balance>=5000)
								{
								note_50 = c_balance/5000;
                                c_balance = c_balance%5000;
								}
                                if (c_balance>=2000)
                                {
								note_20 = c_balance/2000;
                                c_balance = c_balance%2000;
								}
                                if (c_balance>=1000)
                                {
								note_10 = c_balance/1000;
                                c_balance = c_balance%1000;
								}
                                if (c_balance>=500)
                                {
								note_5 = c_balance/500;
                                c_balance = c_balance%500;
                           		}
                                if (c_balance>=100)
                                {
								note_1 = c_balance/100;
                                c_balance = c_balance%100;
                                }
								if (c_balance>=50)
                                {
								cent_50 = c_balance/50;
                                c_balance = c_balance%50;
                                }
								if (c_balance>=20)
                                {
								cent_20=c_balance/20;
                                c_balance = c_balance%20;
                                }
								if (c_balance>=10)
                                {
								cent_10=c_balance/10;
                                c_balance = c_balance%10;
                                }
                                if (c_balance>0)
								{
								cent_5 = c_balance/5;
								}

                                    cout << "Your balance after paying = "<<n_balance<<endl;
                                    cout << "Your change: "<< endl;
                                    cout << "No. of RM50 note = " << note_50<< endl;
                                    cout << "No. of RM20 note = " << note_20<< endl;
                                    cout << "No. of RM10 note = " << note_10<< endl;
                                    cout << "No. of RM5 note = " << note_5<< endl;
                                    cout << "No. of RM1 note = " << note_1<< endl;
                                    cout << "No. of 50 sen = "<< cent_50<<endl;
                                    cout << "No. of 20 sen = "<< cent_20<<endl;
                                    cout << "No. of 10 sen = "<< cent_10<<endl;
                                    cout << "No. of 5 sen = "<< cent_5<<endl;



                            }
                            else if (n_balance ==0)
                            {
                                cout << "Your balance after paying = "<<n_balance<<endl;
                                cout << "So you no need your change already. I don't need to calculate the whole thing. Thank God."<< endl;
                            }
                            else
                                {
                                    cout << "Oh not! You does not have the enough money to buy thing. Please proceed to menu 1 to deposit more money."<<endl;
                                    cout << "You may retry to buy the same thing due to the prices are random. Ha ha!";
                                }
                             if (n_balance >=0)
                             {
                                 cout << endl << "Press \' 1 \' and \' enter \' to proceed the buying process."<<endl;
                                 cout << "Press \' 2 \' and \' enter \' to see the price of item and the balance in other currency.";
                                 cout << "Press enter only will bring you back to main menu."
                             }
                            cin.clear();cin.ignore();
                            cin  >>  no_menu;
                            if (no_menu = 1){no_menu=7;}
                            else if (no_menu=2){no_menu=5;}
                        }


        if(no_menu ==6)
            {
            cout << "Thank you for using the Intelligent Vending Machine.\n";
            cout << "See you in the next transaction.\n";
            cout << "Have a nice day!\n";
            entered=false;}

         if(no_menu==7)
            {

                cout << "Please enter your pin number.\n";
                cin.clear(); cin.ignore();
                cin >> buff_passS;
                buff_pass=stoi(buff_passS);
                system("cls");
                entered=true;
            int sec_code=0;                       //declare and reset the thing.
            int buff=0;
            int buff2=0;
            for (int x=0;x<=3;x++)
            {                                                                       //secret sauce ha ha ha :)
                buff2=pow(10,x+1);
                buff = (buff_pass%buff2) / (pow(10,x)); //Equation finding the place value
                if((buff % 2)>=0.5){buff=(buff+7)%10;}  //Find Odd numbe
                else {buff=(buff+11)%10;}//Find even number                   r
                sec_code=sec_code+buff*pow(10,3-x);
               }


            cout << "Below is your secret code for your account. \nPlease make sure it is the right secure code to avoid scamming and fishing. \n";
            cout <<"Your secret code is "<< sec_code;

            cin.clear();cin.ignore();
            cin.get();}



    }while (no_menu <=0 || no_menu >= 10 );
}//while(1==1) end. The big loop that may no be escaped.
}//main end




