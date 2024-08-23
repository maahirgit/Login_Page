#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t        _________________________________________________\n";
    cout<<"\t\t       ||            Welcome To The Login Page           |\n";
    cout<<"\t\t       ||___________________  MENU  _____________________|\n";
    cout<<"\t\t       ||                                                |       \n";
    cout<<"\t\t       ||  Press 1 to LOGIN                              |"<<endl;
    cout<<"\t\t       ||  Press 2 to REGISTER                           |"<<endl;
    cout<<"\t\t       ||  Press 3 Forgot Password?                      |"<<endl;
    cout<<"\t\t       ||  Press 4 to Exit                               |"<<endl;
    cout<<"\t\t       ||________________________________________________|"<<endl;
    cout<<"\n\t\t           Please enter your choice : ";


    cin>>c;
    cout<<endl;

    switch(c){
        case 1: login();
                break;

        case 2: registration();
                break;

        case 3: forgot();
                break;

        case 4: cout<<"\t\t\t Thank You!! \n\n";
                break;

        default: system("cls");
                 cout<<"\t\t\t Please select from the options given above \n"<<endl;
                 main();

    }
}

void login()
{
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t Please enter the username and password : "<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");      //for read
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        cout<<userId<<"\n Logged in successfully \n Thanks for logging in! \n";
        main(); 
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}

void registration(){
    string ruserId,rpassword;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the password : ";
    cin>>rpassword;
    ofstream f1("records.txt", ios::app);  //ios means input output stream and app opens the file and append output in it at end
    f1<<ruserId<<' '<<rpassword<<endl;      //for write
    system("cls");
    cout<<"\n\t\t\t Registration is successfull \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>option;
    switch(option){
        case 1 : {
                int count=0;
                 string suserId,sId,spass;
                 cout<<"\n\t\t\t Enter the username you remembered : ";
                 cin>>suserId;
                 ifstream f2("records.txt");
                 while(f2>>sId>>spass){
                    if(sId==suserId){
                        count=1;
                    }
                    f2.close();
                    if(count==1){
                        cout<<"\n\n Your account is found!"<<endl;
                        cout<<"\n Your password is : "<<spass<<endl;
                    }
                    else{
                        cout<<"\n\t Please enter valid account name \n";
                    }
                    break;
                    }
                }
                case 2 : {
                    main();
                        }

                default : cout<<"\t\t\t Wrong choice please try again "<<endl;
                          forgot();      
    }
}