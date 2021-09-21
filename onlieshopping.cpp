#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
string character;
//multilist




//STRUCTURE DEFINITION---------------------------------------------------------------------------------------------------------------------------
struct node
{
    string email,password,username;
    struct node *next;
}*head,*tail,*curr;
//Structure definition for men women and kids-------------------------------------------------------------------------
struct mwk
{
    string prodname;
    int no,price,rating,discount;
    struct mwk *next;
}*men_head,*men_tail,*men_curr,*women_head,*women_tail,*women_curr,*kids_head,*kids_tail,*kids_curr,*start1_men,*start1_women,*start1_kids,*curr1,*start2_men,*start2_women,*start2_kids,*curr2;;

//Functions defined---------------------------------------------------------------------------------------------------------
void add_men(int,string,int,int);
void add_women(int,string,int,int);
void add_kids(int,string,int,int);
void final(int,int);

void add_node(string,string,string);
int user_login(string,string);
int user_sign(string,string);
void display();
int get_discount(string, string);
void pastorders();
//CLASS DEFINITION--------------------------------------------------------------------------------------------------------------------------------

class Products
{

public:

//Constructor Calling-------------------------------------------------------------------------------------------------------------------
    Products()
    {
    }
//-----------------------------------------------------------------------------------------------------------------------------------------------


//*************************************************************************************************************************************************

void SignLogin()
{
    int counter = 1;
    int num;
    cout<<endl<<endl<<endl<<"                    1.Signup(For new Customer)    2.Login(For Existing Customer)           "<<endl;
    cin>>num;

    system("cls");
    if(num == 1)
    {
        //system("color A1");
        signup();
    }
    else if (num == 2)
    {
        //system("Color 1B");
        Login();
    }
    else
    {
        cout<<"Invalid";
        return SignLogin();
    }
}


void shopping_user(string character)
{
    //system("color 2A");
    int num;
    system("cls");

    if(character=="Guest")
    {
        cout<<"                                                                                                                                                                                         Welcome "<<character<<" !   (Press 0 to login or Signup)"<<endl;
    }
    else
    {
        cout<<"                                                                                                                                                                                    Past Orders(press 5)  "   <<"Welcome "<<character<<" !"<<endl;
    }
    cout<<endl<<endl<<endl<<"                                          WELCOME!!                     "<<endl;
    category:
    cout<<"                                       Please Choose Your Category                "<<endl;
    cout<<endl<<"                           1.Male           2.Female             3.Child    "<<endl;
    cin>>num;
    int i;
    cout<<"                                         //::  Select Your Products ::\\              "<<endl;
    //Male Section
    int above;
    char cart;

    int choice;
    if(num == 1)
    {
        again:
        i=1;
        men_curr=men_head;
        while(men_curr!=NULL)
        {
            cout<<i<<". "<<men_curr->prodname<<" "<<men_curr->price<<endl;
            i++;
            men_curr=men_curr->next;
        }
        cin>>choice;
        if(choice>=1 && choice<=9)
        {
            final(num,choice);
            cout<<"Press s for cart";
            cin>>cart;
            if(cart=='s')
            {
                display();
            }
            cout<<"Press 0 to exit and any other number to continue :";
            cin>>above;
            if(above!=0)
                goto again;
            else
            {
                system("cls");
                goto category;
            }
        }
        else
        {
            cout<<"Wrong choice";
            goto again;
        }
    }

    //Female Section
    else if(num == 2)
    {
        again2:
        i=1;
        women_curr=women_head;
        while(women_curr!=NULL)
        {
            cout<<i<<". "<<women_curr->prodname<<" "<<women_curr->price<<endl;
            i++;
            women_curr=women_curr->next;
        }
        cin>>choice;
        if(choice>=1 && choice<=9)
        {
            final(num,choice);
            cout<<"Press s for cart";
            cin>>cart;
            if(cart=='s')
            {
                display();
            }
            cout<<"Press 0 to exit and any other number to continue :";
            cin>>above;
            if(above!=0)
                goto again2;
            else
            {
                system("cls");
                goto category;
            }
        }
        else
        {
            cout<<"Wrong choice";
            goto again2;
        }
    }

    //Child Section
    else if(num == 3)
    {
        again3:
        i=1;
        kids_curr=kids_head;
        while(kids_curr!=NULL)
        {
            cout<<i<<". "<<kids_curr->prodname<<" "<<kids_curr->price<<endl;
            i++;
            kids_curr=kids_curr->next;
        }
        cin>>choice;
        if(choice>=1 && choice<=9)
        {
            final(num,choice);
            cout<<"Press s for cart";
            cin>>cart;
            if(cart=='s')
            {
                display();
            }
            cout<<"Press 0 to exit and any other number to continue :";
            cin>>above;
            if(above!=0)
                goto again3;
            else
            {
                system("cls");
                goto category;
            }
        }
        else
        {
            cout<<"Wrong choice";
            goto again3;
        }
    }
    //Login page
    else if(num == 0)
    {
        system("cls");
        int num;
        //system("color 31");
        SignLogin();
    }

    else if (num==5)
    {
        pastorders();
    }
}

string signup()
{
    system("cls");
    string username, email;
    string password;
    int temp;
    signup_again:
    cout<<"Enter Name: ";
    cin>>username;

    //Email Validation
    int x=1;
    while(x == 1)
    {
        int count=0,i,num;
        cout<<endl<<"Enter Email: ";
        cin>>email;
        password_again:
        cout<<endl<<"Enter Password: ";
        cin>>password;
        for(i=0; i<=email.size(); i++)
        {
            if(email[i] == '@')
            count++;
        }
        if(count != 1)
        {
            cout<<"invalid email"<<endl<<"enter again";
            goto signup_again;
        }
        else
        {
            x = 2;
            //password validation
        for(i=0;i<password.size();i++)
        {
            if(password[i]==' ')
                goto password_again;
        }

        //checking in database(replica for signup if not then signing up)
            curr=head;
            temp=user_sign(email,password);
                    if(temp==1)
                {
                    cout<<"Username created"<<endl;
            character= username;
                        curr=head;
                        while(curr->next!=NULL)
                            curr=curr->next;
                        shopping_user(username);
                      }

                else if(temp==0)
                {
                    cout<<"Username already exist"<<endl;
                    goto signup_again;

}
        }
    }
}

string Login()
{
    string email,password;
    int temp,choose;
    system("cls");
    Login_again:
    cout<<"Enter email and password"<<endl;
    cin>>email>>password;
    curr=head;

    temp=user_login(email,password);
    if(temp==1)
    {
        cout<<"Logged in";
        character=curr->username;
        shopping_user(curr->username);
    }
    else if(temp==0)
    {
        cout<<"UserID or Password is incorrect";
        goto Login_again;
    }
    else if(temp==-1)
    {
        cout<<"email doesn't exist"<<endl;
        cout<<"Press 1 for signup and 2 for exit 0 to try again"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 0: goto Login_again;
            case 1: cout<<endl;
                    signup();
                    break;
            case 2:
                    break;
        }
    }
}
}t;



//MAIN FUNCTION HERE ---------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    start1_men=start1_kids=start1_women=NULL;
    start2_men=start2_kids=start2_women=NULL;
    head=tail=NULL;
    men_head=men_tail=men_curr=NULL;
    women_head=women_tail=women_curr=NULL;
    kids_head=kids_tail=kids_curr=NULL;

    string email,password,username;
    string women_prodname,men_prodname,kids_prodname;
    int men_no,men_price,men_rating;
    int women_no,women_price,women_rating;
    int kids_no,kids_price,kids_rating;

    ifstream fout;
    fout.open("login.txt");
    if(fout==NULL)
    {

    }
    else
    {
        while (!fout.eof())
        {
            add_node(email,password,username);
            fout>>username;
            fout>>email;
            fout>>password;
        }
    }
    //retrieving men data
    ifstream foutmen;
    foutmen.open("men.txt");
    if(foutmen==NULL)
    {
    }
    else
    {
        while (!foutmen.eof())
        {
            foutmen>>men_no;
            foutmen>>men_prodname;
            foutmen>>men_price;
            foutmen>>men_rating;
            add_men(men_no,men_prodname,men_price,men_rating);
        }
    }
    //retrieving women data
    ifstream foutwomen;
    foutwomen.open("women.txt");
    if(foutwomen==NULL)
    {
    }
    else{
        while (!foutwomen.eof())
        {
            foutwomen>>women_no;
            foutwomen>>women_prodname;
            foutwomen>>women_price;
            foutwomen>>women_rating;
            add_women(women_no,women_prodname,women_price,women_rating);
        }
    }
    //retrieving kids data
    ifstream foutkids;
    foutkids.open("kids.txt");
    if(foutkids==NULL)
    {
    }
    else
    {
        while (!foutkids.eof())
        {
            foutkids>>kids_no;
            foutkids>>kids_prodname;
            foutkids>>kids_price;
            foutkids>>kids_rating;
            add_kids(kids_no,kids_prodname,kids_price,kids_rating);
        }
    }

    //system("color 5D");
    int choice;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                          Welcome To Online Shopping Mall       "<<endl;
    cout<<"                                                   1. Start Shopping          "<<endl;
    cout<<"                                                   2. Login as Customer                 "<<endl;
    cout<<"                                       (Press buttons to perform these actions)    "<<endl;
    cin>>choice;

    //Shopping Screen-----------------------------------------------------------------------------------------------------------------------------
    if (choice == 1)
    {
        //system("color 2A");
        character="Guest";
        t.shopping_user("Guest");
    }
    //-------------------------------------------------------------------------------------------------------------------------------------------

    //Customer Login-----------------------------------------------------------------------------------------------------------------------------
    else if(choice == 2)
    {
        system("cls");
        //system("Color 0A");
        t.SignLogin();
    }

    else
    {
        cout<<"Invalid";
        return main();
    }
//----------------------------------------------------------------------------------------------------------------------------------------------
//Closing file after saving all username and passwords are saved

return 0;
}

void final(int num,int choice)
{
    if(num==1)
    {

        struct mwk *temp;
        temp= new struct mwk;

        men_curr=men_head;
        for(int i=1;i<choice;i++)
        {
            men_curr=men_curr->next;
        }

        int discount = get_discount(curr->username, men_curr->prodname);
        int price = men_curr->price - ((discount*men_curr->price)/100);
        temp->no=men_curr->no;
        temp->prodname=men_curr->prodname;
        temp->price=price;
        temp->rating=men_curr->rating;
        temp->discount=discount;
        temp->next=NULL;

        if(start2_men==NULL)
        {
            start2_men=temp;
            curr1=start2_men;
        }
        else{
                curr1=start2_men;
                while(curr1->next!=NULL)
                    curr1=curr1->next;
                curr1->next=temp;
        }
    }
    else if(num==2)
    {
        struct mwk *temp;
        temp= new struct mwk;
        women_curr=women_head;

        for(int i=1;i<choice;i++)
        {
            women_curr=women_curr->next;
        }

        int discount = get_discount(curr->username, women_curr->prodname);
        int price = women_curr->price - ((discount*women_curr->price)/100);
        temp->no=women_curr->no;
        temp->prodname=women_curr->prodname;
        temp->price=price;
        temp->rating=women_curr->rating;
        temp->discount=discount;
        temp->next=NULL;

        if(start2_women==NULL)
        {
            start2_women=temp;
            curr1=start2_women;
        }
        else{
                curr1=start2_women;
                while(curr1->next!=NULL)
                    curr1=curr1->next;
                curr1->next=temp;
        }
    }
    else if(num==3)
    {

        struct mwk *temp;
        temp= new struct mwk;

        kids_curr=kids_head;
        for(int i=1;i<choice;i++)
        {
            kids_curr=kids_curr->next;
        }

        int discount = get_discount(curr->username, kids_curr->prodname);
        int price = kids_curr->price - ((discount*kids_curr->price)/100);
        temp->no=kids_curr->no;
        temp->prodname=kids_curr->prodname;
        temp->price=price;
        temp->rating=kids_curr->rating;
        temp->discount=discount;
        temp->next=NULL;

        if(start2_kids==NULL)
        {
            start2_kids=temp;
            curr1=start2_kids;
        }
        else{
                curr1=start2_kids;
                while(curr1->next!=NULL)
                    curr1=curr1->next;
                curr1->next=temp;
        }
    }
}

//add men database into link list
void add_men(int no,string prodname,int price,int rating)
{
    struct mwk *temp;
    temp=new struct mwk;
    temp->no=no;
    temp->prodname=prodname;
    temp->price=price;
    temp->rating=rating;
    temp->next=NULL;

    if(men_head==NULL)
    {
        men_head=temp;
        men_tail=temp;
    }
    else{
        men_tail->next=temp;
        men_tail=men_tail->next;
    }
}
void add_women(int no,string prodname,int price,int rating)
{
    struct mwk *temp;
    temp=new struct mwk;
    temp->no=no;
    temp->prodname=prodname;
    temp->price=price;
    temp->rating=rating;
    temp->next=NULL;

    if(women_head==NULL)
    {
        women_head=temp;
        women_tail=temp;
    }
    else{
        while(women_tail->next!=NULL)
            {
                women_tail=women_tail->next;
            }
        women_tail->next=temp;
        women_tail=women_tail->next;
    }
}
void add_kids(int no,string prodname,int price,int rating)
{
    struct mwk *temp;
    temp=new struct mwk;
    temp->no=no;
    temp->prodname=prodname;
    temp->price=price;
    temp->rating=rating;

    if(kids_head==NULL)
    {
        kids_head=temp;
        kids_tail=temp;

    }
    else{
        while(kids_tail->next!=NULL)
            {kids_tail=kids_tail->next;}
        kids_tail->next=temp;
        kids_tail=kids_tail->next;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
//Retrieving data from saved file and adding new users
void add_node(string email,string password,string username)
    {
        struct node *tmp = new struct node;
        tmp->username=username;
        tmp->email = email;
        tmp->password = password;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;

        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
}

//user login
int user_login(string email,string password)
{   int temp;
    curr=head;
    if(curr!=NULL){
       while(curr!=NULL)
                    {
                        if(curr->email==email && curr->password==password)
                         {
                             temp= 1;
                             goto login_down;
                            //login ho jayega
                         }
                        else if(curr->email==email && curr->password!=password){
                            temp= 0;
                            goto login_down;
                            }
                        else{
                        temp= -1;

                        }
                        curr=curr->next;
                    }}
                    else{cout<<"Empty";}

        if(curr==NULL)
            temp=-1;
     login_down:
    return temp;

}

//Signup verification
int user_sign(string email,string password)
{   int temp;
    curr=head;
       while(curr!=NULL)
                    {
                        if(curr->email==email)    //If another username already exist
                         {
                             temp= 0;
                             goto login_done;
                            //login ho jayega
                         }
                        else{temp=1;}
                        curr=curr->next;
                    }
        if(curr==NULL)
            temp=1;
        login_done:
    return temp;

}

int get_discount(string username, string productname) {
    int i, discount, sum = 0;
    for (i = 0; username[i] != '\0'; i++)
        sum = sum + username[i];
    for (i = 0; productname[i] != '\0'; i++)
        sum = sum + productname[i];
    discount = sum % 9;
    return discount;
}

void display(){
    curr1=start2_men;
if(curr1!=NULL)
{
     while(curr1!=NULL)
    {
        cout<<"-- Product name : "<<curr1->prodname<<"  Price : "<<curr1->price<<"  Discount : "<<curr1->discount<<"%"<<endl;
        curr1=curr1->next;
    }
    cout<<"\n";
}
curr1=start2_women;
if(curr1!=NULL)
{
    while(curr1!=NULL)
    {
        cout<<"-- Product name : "<<curr1->prodname<<"  Price : "<<curr1->price<<"  Discount : "<<curr1->discount<<"%"<<endl;
        curr1=curr1->next;
    }
    cout<<"\n";
}
 curr1=start2_kids;
if(curr1!=NULL)
{
    while(curr1!=NULL)
    {
        cout<<"-- Product name : "<<curr1->prodname<<"  Price : "<<curr1->price<<"  Discount : "<<curr1->discount<<"%"<<endl;
        curr1=curr1->next;
    }
    cout<<"\n";
}

int buy;

cout<<"Press 1 to buy: ";
cin>>buy;
string prodname;
if(buy==1)
{       int in;
    if(character=="Guest")
    {
        cout<<"Login to buy"<<endl;
        cout<<"Press 1 for login and other number to exit: ";
        cin>>in;
        if(in==1)
        {
            t.SignLogin();
        }
        else{

            exit(0);
        }
    }
    else{       character=curr->username+".txt";
                curr1=start2_men;
                ifstream foutc;
                foutc.open(character.c_str());
                foutc.close();
                cout<<"---------------------------------------"<<endl;
                ofstream finc(character.c_str());

                if(start2_men!=NULL){
                    while(curr1!=NULL)
                        {
                    prodname=curr1->prodname;
                    finc<<prodname<<" ";
                    curr1=curr1->next;
                        }
                }

                curr1=start2_women;
                if(start2_women!=NULL){
                while(curr1!=NULL)
                    {

                prodname=curr1->prodname;
                finc<<prodname<<" ";
                curr1=curr1->next;
                    }
                }

                curr1=start2_kids;
                if(start2_kids!=NULL){
                while(curr1!=NULL)
                    {

                prodname=curr1->prodname;
                finc<<prodname<<" ";
                curr1=curr1->next;
                    }

                }
                finc.close();

        cout<<"Order placed"<<endl;
        cout<<"Thank you for shopping"<<endl;
    }
}
}
void pastorders(){
    int i,j;
    string a[100];
string prodname;

character=curr->username+".txt";

ifstream foutp;
i=0;
    foutp.open(character.c_str());
    if(foutp==NULL){}
    else{
    while (!foutp.eof()) {
        foutp>>a[i];
        i++;
        }
}
foutp.close();
for(j=0;j<i;j++)
    cout<<a[j]<<endl;
int menu;
cout<<"Press 0 to return to main menu and other number to exit"<<endl;
cin>>menu;
if(menu==0)
     t.shopping_user(curr->username);
else{exit(0);}
}
