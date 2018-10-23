#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>
#include <Windows.h>


using namespace std;


int main()
{
    //initialization for time funtion
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    //initialization of variable
    int no_menu=1;
    double eWallet=0.00;
    double price=0;
    string item;
    bool entered = false;
    bool from_menu2 = false;
    string buff_acc;
    int buff_pass;
    int pass;
    string buff_passS;
    double n_balance=0;
    double renminbi = 1.66;
    double  yen=27.535;
    clock_t timer; //initialization for timer
    istream &ignore( streamsize num=1, int delim=EOF ); //Extract and discard characters so that the cin function can get the right input.

//while loop for whole program
while (1)
    {

        system("CLS");//clear the screen for anything that is display in the forehand.
        //Getting the time from the system
        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,80,"Now it's %I:%M%p. %x",timeinfo ); //set the format for time stamp
        cout << buffer << endl ; //display the time stamp

        if (entered==false)
                {
                    //welcome screen before login
                    cout << "Welcome to Intelligent Vending Machine!"<< endl ;
                    cout << "Please press \' enter \' to continue." <<endl;
                    cin.get();
                    cin.clear();
                    //getting the username
                    cout << "Please enter your account name.\n";
                    getline(cin, buff_acc);

                    no_menu=7; //go to password program.
                }
        else
        {//Show Menu after the user keyin the user name and password/secret code
        cout<<fixed<<showpoint<<setprecision(2); //fix the decimal point to 2 decimal place.
        cout << "Welcome back! "<<buff_acc<<"\n"<<"Now,you are now using Intelligent Vending Machine."<< endl ;
        cout << "Current amount in eWallet: RM" << eWallet   << endl;
        cout << "1. Depositing into eWallet\n" ;
        cout << "2. Purchase an item\n" ;
        cout << "3. Display the item purchased and amount due\n" ;
        cout << "4. Checkout / Display the balance or change in the most efficient that is least Ringgit Malaysian denomination.\n" ;
        cout << "5. Display currency exchange rate and price of item the balance in the currency\n" ;
        cout << "6. Exit\n" ;
        cout << "Please press the number for the menu and press \' enter \' to continue.\n";
        cin  >>  no_menu; //key in no of menu
        system("cls");}


        if (no_menu <=0) //if user key in the number that is negative and other than number. Warn the user.
        {
            cout << "You have crash the system. Restarting the system....................\n";
            cout << "countdown:\n";
            for (int i=10; i>0; --i) {
                cout << i << std::endl;
            this_thread::sleep_for (std::chrono::seconds(1));
            }
            cin.clear();cin.ignore();
            entered=false;
        }

       if (no_menu==1) //Program for depositing
         {
                double keyin;
                cout <<"Deposit for buying things (The limit for the deposit is RM100): RM ";
                cin >> keyin;
                if (keyin+eWallet>100) //Limit for the eWallet
                {
                    cout << "Warning!!!";
                    cout << "You have deposit too much or your wallets full.\n";
                    cout << "Please press \' enter \' to continue.\n";
                    cin.clear();cin.ignore(); //reset cin function
                    cin.get();
                }
                    else if (keyin<0)
                    {cout << "why you are typing negetive number?"}
                    else {eWallet=eWallet+keyin;}  //add the deposited money to the eWallet if not exceed the limit.
         }



        if (no_menu==2)
            {

                if ( eWallet<0) {cout << "Please deposit more in order to buy more great staff. (Press 1)";cout << "Please press \' enter \' to continue.\n";cout << "Please press \' enter \' to continue.\n";cin.clear();cin.ignore();cin.get(); } //check for the eWallet so that the user have some money in the eWallet before buying.
                else if (eWallet==0){cout<<"Please deposit first in order to proceed! (Press 1) \n";cout << "Please press \' enter \' to continue.\n";cin.clear();cin.ignore();cin.get();} //avoid the user from entering menu 2 before depositing
                else
                    {
                        //showing best seller item list
                        cout << " Here are the HOT item that are in sale right now. \n";
                        cout << "-Apple Macbook Pro\n";
                        cout << "-Seagate 250G SSD\n";
                        cout << "-MSI Gaming Laptop\n";
                        cout <<"-Cosiaer Gaming Mouse\n";
                        cout <<"-Dell XPS 15\n";
                        cout << "\nYou can buy almost anything except things that are impossible to buy like time and life. \n";
                        cout << "Please don't buy things that are prohibited under the law.\nFollow the rule of law.\n";
                        cout << "You can buy only one thing at a time. \n";
                        cin.clear();cin.ignore();                //for clearing the cin
                        getline(cin, item);   //get item name from user
                        srand(time(0)) ;        //randomize the prize
                        price= 5+(rand()%5526); // limit the price from RM0.05 to RM55.30
                        price=price/100; //convert from sen to RM
                        from_menu2=true;    // define from_menu2 to true so that afterwards can know which menu come from.
                        cout << "\n\n\n"<<"Please check the item list below carefully.\n\n";
                        no_menu=3; //Going to menu 3
                        }
            }


        if (no_menu==3)
            {
                if (price<=0) //avoid user from entering menu 3 before depositing
                     {cout<<"You have come to the wrong place."<<"Come back after you have purchase something interesting."<<"Please an key to teleport you back to the main menu"; cout << "Please press \' enter \' to continue.\n";cin.clear();cin.ignore();cin.get();}
               else{
                cout << "The items that you have brought.\n";
                cout << "Name of item: "<<  item <<endl; //display item name
                cout << "Price in RM: RM" <<  price<<endl; //display price

            //Check whether come from menu 2.
                    if (from_menu2==true)
                        {cout << endl << "Is this the right thing that you want to buy?"<<"\n\n\n";from_menu2=false;}
                    else
                        {srand(time(0)) ;cout <<endl<<"Have you change your mind?"<<endl<<"Be fast the item maybe sold out soon."<< endl<<"It is around "<< rand()%10+1<<" left!!!"<<"\n\n\n";}
                    //To let user choose whether to buy it or cancel it or back to the main menu.
                    cout <<"If buy it, please press any key except \' 0 \' "<<endl<<"If want to cancel, please press \' 0 \' "<<endl << "If want to go back to the main menu, please press \' - \' and \' 1 \' "<<endl<<"and press enter.\n";

                    n_balance = eWallet - price; // calculate balance
                    if (n_balance<0){cout<<"Please kindly fulfilled the required amount of money in the eWallet by putting more money into the eWallet.\n";} //check whether the user have enough money to pay for it. If it is true, then it will warn user to deposit more.
                    cin >> no_menu;
                    if (no_menu!=0 && no_menu!= -1) //if user want to buy
                    {

                        if(n_balance>=0)   {no_menu=4;system("CLS");} //If user choose to buy, the program will lend user to menu 4.
                        else { // if the user want to buy but does not have enough money.
                                cout << "\n I am sorry my friend. \nPlease kindly top up your eWallet. \nThis is because my company does not give small loan to customers yet. \nNext time, remember to deposit enough amount of money in eWallet to avoid this situation to happen again.\n";
                                cout<< "You are on your way back to main menu to deposit more money. \nPress \' 1 \' and press \' enter \' after reach main menu.\n";cin.clear();cin.ignore();cin.get();}
                    }
                    else if(no_menu==0) {string item; double price;double n_balance;no_menu=1;} //reset the value since user choose to cancel the purchase and lead the user to go back to main menu.
                    else if (no_menu==-1){no_menu=1;} // user choose to go back to main menu.

                    }
                    }

        if(no_menu == 4)
            {
                            n_balance = (round(n_balance * 20))/20; //round off the balance/change to nearest 0.05.
                            if (n_balance > 0 && price >0 )  //check whether the user has buy an item and have enough money to buy it.
                            {
                                //condition for user who need the change.
                                //initializing all the variable that will be use in calculating the least Ringgit Malaysian denomination
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
								//End calculation and displaying the outcome
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
                            else if (n_balance ==0 && price > 0) //For the condition of no need for the change.
                            {
                                cout << "Your balance after paying = "<<n_balance<<endl;
                                cout << "So you no need your change already. I don't need to calculate the whole thing. Thank God."<< endl;
                            }
                            else if (eWallet !=0)
                                { //for condition of the user not having enough money.
                                    cout << "Oh not! You does not have the enough money to buy thing. Please proceed to menu 1 to deposit more money."<<endl;
                                    cout << "You may retry to buy the same thing due to the prices are random. Ha ha! \n";
                                    cout << "Please press \' enter \' to continue.\n";
                                    cin.clear();cin.ignore();
                                    cin.get();
                                }
                             if (n_balance >=0 && price > 0)
                             { //display for the user who have brought an item.
                                 cout << endl << "Press \' 1 \' and \' enter \' to proceed the buying process."<<endl;
                                 cout << "Press \' 2 \' and \' enter \' to see the price of item and the balance in other currency."<<endl;
                                 cout << "Press other than that two keys and \'enter\' only will bring you back to main menu."<<endl;
                                 cin.clear();cin.ignore();
                            cin  >>  no_menu;
                            if (no_menu == 1){no_menu=7;system("cls");} //lead user to password program
                            else if (no_menu==2){no_menu=5;system("cls");} //lead user to menu 5
                             }

                        }

        if(no_menu == 5)
            { //menu for converting into foreign currency
                if (eWallet>0) //check for the user have deposit the money or not
                {
                    if (price > 0)//check for the user  have buy an item or not
                    {
                        SetConsoleOutputCP(CP_UTF8); //Set the console to UTF-8 to support for displaying the symbol for the currency. Windows console default using ASCII therefore it cannot diaplay ¥.                        cout << "Which currency do you looking for?"<<endl;
                        //menu for choosing the currency they want
                        cout << "Press 1 for Japanese Yen\n";
                        cout << "Press 2 for Chinese Yuan Renminbi.\n";
                        cin.clear();cin.ignore(); //clear for cin function
                        cin >> no_menu;

                        if (no_menu==1){
                                //display the price in RM and Japanese Yen
                            cout << "The exhange rate for Japanese Yen today is RM 1 = ¥" <<yen<< endl;
                            cout << "The price of "<< item <<  " in Malaysian Ringgit is RM "<< price << " while in Japanese Yen is ¥"<<price * yen<< ". \n";
                            cout <<"The balance in Malaysian Ringgit is RM" << n_balance << " while in Japanese Yen is ¥" << n_balance*yen<<".  \n";
                        }
                        else if (no_menu==2)
                        {
                            //display the price in RM and Chinese Yuan
                            cout <<"The exhange rate for Chinese Yuan Reminbi today is RM 1 = ¥" <<yen<< endl;
                            cout << "The price of "<< item <<  " in Malaysian Ringgit is RM "<< price << " while in Chinese Yuan Reminbi is ¥"<<price * renminbi<< ". \n";
                            cout << "The balance in Malaysian Ringgit is RM" << n_balance << " while in Chinese Yuan Reminbi is ¥" << n_balance*renminbi<<".  \n";
                        }
                        else {cout << "You are not yet buying thing. Go and buy some stuff.";} // if the user not buying thing.
                        cout << "Please press \' enter \' to continue.\n";
                        cin.clear();cin.ignore();
                        cin.get();
                }
                else {cout << "You are not yet depositing money into me. Go and deposit some money. ";} //if the user not depositing money.
            }
            }



         if(no_menu == 7)  //For secret code/ password program.
            {
                do
            {

            cout << "Please enter your pin number ";
            if (price > 0) // to show the reason for the user to key in their pass for the second time.
            {cout <<"to ensure that you are really wanted to buy and ensure that it is the right person make the purchase.\n";cin.clear();cin.ignore();}
            else
            {cout << ".\n";}
            cin.clear();
            getline(cin, buff_passS);
            buff_pass = stoi(buff_passS);
            if  (entered == false) {entered=true;pass=buff_pass;/*save the pass*/timer = clock();/*get the time now when the user enter for the first time*/}
            system("cls");
           if (buff_pass==pass)
            {int sec_code=0;                       //declare and reset the variable to be used in generating secret code.
            int buff=0;
            int buff2=0;
            for (int x=0;x<=3;x++)
            {                                                                       //secret sauce ha ha ha :)
                buff2=pow(10,x+1);
                buff = (buff_pass%buff2) / (pow(10,x)); //Equation finding the place value
                if((buff % 2)>=0.5){buff=(buff+7)%10;}  //Find Odd numbe
                else {buff=(buff+11)%10;}//Find even number                   r
                sec_code=sec_code+buff*pow(10,3-x); //put into one int variable
               }


            cout << "Below is your secret code for your account. \nPlease make sure it is the right secure code to avoid scamming and fishing. \n";
            cout <<"Your secret code is "<< sec_code<<endl; //show the secret code.
            if (price>0)
            { // thanks user for using it to buy thing and show the change.
            eWallet=n_balance;
            price=0;n_balance=0; //resetting the variable before the user buy other things or exit.
            cout << "Thanks you for buying things using me.\n";
            cout<< "Here are you change.";

            }
            cout << "Please press \' enter \' to continue.\n";
            cin.clear();
            cin.get();
            }
            else {cout << "Wrong pin number. \nPlease type in the right pin number.\n" ;} //if wrong pass is keyed in

            }while (pass != buff_pass);  //loop the password program until the user key in the right pass
            }


        if(no_menu == 6) //exit
            { //thanks the user for using it and show the transaction time
            cout << "Thank you for using the Intelligent Vending Machine.\n";
            timer = clock() - timer; //use the time from the program when the user first enter into the main menu.
            float diff_time= (float)timer/CLOCKS_PER_SEC; //calculate for the transaction time.
            cout <<"Your transaction time is "<< diff_time << " second.\n"; //show the time used by the user.
            cout << "See you in next time.\n";
            cout << "Have a nice day!\n";
            cout << "countdown:\n"; //wait for 5 second
            for (int i=5; i>0; --i) {
                cout << i << std::endl;
            this_thread::sleep_for (std::chrono::seconds(1));
            }
            //resetting variables
            entered=false;
            price=0;n_balance=0;
            eWallet=0;
            cin.clear();cin.ignore();
             }

}//while(1==1) end. The big loop that may no be escaped.
}//main end
