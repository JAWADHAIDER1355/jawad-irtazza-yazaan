#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class book {

private:
    char* name;
    //type;
    char* author;
    bool status;

public:
    book()
    {
        name = nullptr;
        author = nullptr;

    }
    void createnewactivation(int*arr, int totalbooks)
    {
        ofstream off("activationrecord.txt");
        
        for (int i = 0; i<totalbooks ; i++)
        {
            off << arr[i];
            off << endl;
        }


   }
    void showstatus(int& c, char* nameofbook, int totalbooks, int& co)
    {
        fstream in("dataofbooks.txt");
        ifstream activation("activationrecord.txt");
        ifstream copy("activationrecord.txt");
   //   char* a=new char;//for author name accessing from file named(dataofbooks.txt)
        char* b= new char[40];
	//tring a;
            
		int*arr=new int[totalbooks];
		for(int i=0; i<totalbooks;i++)
        {
            copy>>arr[i];
        }
        
        for(int i = 0; i < totalbooks ; i++)
        {
            if(i==c)
            {   
                name = nameofbook;
			//    string temp;
         // getline(inn, temp);
       
	 //     cin.ignore();
   
				in.getline(b,40);
				//t l=strlen(a);
				//l]='\0';
				cout<<b<<endl;
                this->author = b;
                activation >> this->status;
                arr[i] = this->status;
                
                    if (this->status == 0 || this->status == 1)
                    {
                        
                        if (co == 1 && this->status==true)
                        {
                            cout << endl << " Book is Available : ) " << endl;
                            cout << "Name of book: " << name << endl;
                            cout << endl << "Author is: " << this->author << endl;

                            arr[i] = 0;
                            createnewactivation(arr, totalbooks);
                            break;
                        }
                        else if (co == 1 && this->status == false)
                        {
                            arr[i] = 0;
                            createnewactivation(arr, totalbooks);
                            cout << endl << "Book is Unavailable : / " << endl;
                            break;
                        }
                         else if (co == 2 && this->status==false)
                        {
                            
                            arr[i] = 1;
                            createnewactivation(arr, totalbooks);
                            
                            break;
                        }
                         else if(co == 2 && this->status == true)
                         {
                            cout << endl<< "Book is already avaialble you cant return it."<<endl;
                            return;
                         }
                        
                        
                    }
                
            }
            else
            {
                in.getline(b,40);
                activation >> status;
            }
        }
    }
};
class user {

private:
    char** name;
    char** password;

    int i;

public:
    book** uniquenumberofbook;
    user()
    {
        name = nullptr;
        password = nullptr;
        uniquenumberofbook = nullptr;
        i = 0;
        name = new char* [100];
        password = new char* [100];
    }
    void checkwhilebookisavailableornot(char* issuebook, int& co)
    {
        uniquenumberofbook = new book* [20];
        
        int i,c=0,f;
        char* a = new char[40];
        ifstream inn("allbooks.txt");
        for (f = 0; !inn.eof(); f++)
        {
            string temp;
            getline(inn, temp);
        }
        ifstream d("allbooks.txt");
        while (!d.eof())
        {
             i = 0;
            
            d.getline(a, 40);
            

            uniquenumberofbook[c] = new book[strlen(a)];
            for (int k = 0; k <= strlen(a); k++)
            {
                if (issuebook[k] == a[k])
                {
                    i++;
                }
                if (i == strlen(a))
                {
                      cout << i<<endl;
                      uniquenumberofbook[c]->showstatus(c,issuebook,f,co);
                      //showstatus();
                }
                
            
            }
            c++;
        }
        



    }
    void showoptions()
    {
        int co = 0;
        char** base = new char* [1];
        base[0] = new char[30];
        cout << endl << "-----------------------------WELCOME TO USER PANEL----------------------------" << endl;
        cout << "Enter 1 to issue a book." << endl;

        cout << "Enter 2 to return a book." << endl;
        cin >> co;
        if (co == 1 || co==2)
        {
            cout << "PLEASE--Enter the Name of the book which You want to issue or return" << endl;
            char* issuebook = new char[40];
            
            cin.ignore();
            cin.getline(issuebook,40);
            cout << endl;
            cout << issuebook << endl;
            checkwhilebookisavailableornot(issuebook,co);
            //obj.uniquenumberofbook;
            //issue a book
        }
        
        else
        {
            cout << endl << "Please enter correct number." << endl;
            return;
        }


    }


    bool signinuser()
    {
        cout << endl << "\t\t\tLogging-IN of User" << endl;
        ifstream obj("alldata.txt");//ifstream used here to check the list of the alldata.txt file and finding the exact matched user name and password

        char* name = new char[30];//allocation of user name entered by the user during logging in at run time
        char* password = new char[30];//allocation of password entered by the user during logging in at the run time
        char* namecpy = new char[30];//allocation of the user name which is present in the record of registered user names and passwords OR (alldata.txt)File
        char* passcpy = new char[30];//allocation of the user password which is present in the record of registered user names and passwords OR (alldata.txt)File


        int temp = 1;//when temp=1,I have used bool ture and when temp=0 I have used bool false

        int N;//size of registered names present in the (alldata.txt) file
        int P;//size of registered passwords present in the (alldata.txt) file


        cout << "Enter name:\t\t\t";
        cin >> name;
        int n = strlen(name);//length of username taken by user at runtime for putting delimeter(\0)..U can also see in next line
        name[n++] = '\0';

        cout << "Enter password:\t\t\t";
        cin >> password;
        int p = strlen(password);//length of paswrd taken by user at runtime for putting delimeter(\0)..U can also see in next line
        password[p++] = '\0';

        cout << "================================================================================" << endl << endl;

        cout << "Entered USER NAME is:\t\t";
        cout << name;
        cout << endl;
        cout << "Entered PASSWORD is:\t\t" << password << endl << endl;


        while (!obj.eof())//means if file is not empty further yet
        {
            temp = 1;//every time bool will become true in start because we have to check all lines of registred names and paswrds

            obj >> namecpy;
            N = strlen(namecpy);
            namecpy[N++] = '\0';
            cout << namecpy << "\t";

            obj >> passcpy;
            P = strlen(passcpy);
            passcpy[P++] = '\0';
            cout << passcpy;
            int i;
            for (i = 0; i < N; i++)
            {
                if (name[i] != namecpy[i])
                {
                    temp = 0;
                }
            }

            int k;
            for (k = 0; k < P; k++)
            {
                if (password[k] != passcpy[k])
                {
                    temp = 0;
                }
            }

            cout << endl;
            if (temp == 1)
            {
                return true;
            }

        }
        return false;
    }

    void enterdatainfile(char** nameof, char** passof, fstream& data)
    {

        data << *nameof;
        data << " ";
        data << *passof;
        data << endl;

    }
    void registeryourself(fstream& data)
    {
        //====================NAME--ENTERING======================================
        cout << "\t\t\t Registering of User" << endl;
        cout << "============================================================================" << endl;
        cout << "Enter Login User name:\t\t";
        char* a;
        a = new char[30];
        cin >> a;
        int l = strlen(a);

        name[i] = new char[l];

        for (int k = 0; k < l; k++)
        {
            name[i][k] = a[k];
        }
        name[i][l] = '\0';
        cout << endl << name[i] << endl;


        //===================PASSWORD--ENTERING======================================

        cout << "Enter Login PASSWORD:\t\t";
        char* passwordofuser;

        passwordofuser = new char[30];
        cin >> passwordofuser;

        int lengthofenteredpassword;

        lengthofenteredpassword = strlen(passwordofuser);

        password[i] = new char[lengthofenteredpassword];

        int k;

        for (k = 0; k < lengthofenteredpassword; k++)
        {
            password[i][k] = passwordofuser[k];
        }
        password[i][k] = '\0';

        cout << endl << password[i] << endl;
        //i++;
        enterdatainfile(name, password, data);


    }
};
class librarian {

private:
    char** name;
    char** password;
    user** userlist;
    book** books;
    int j;

public:
    librarian()
    {
        userlist = nullptr;
        books = nullptr;
        name = nullptr;
        password = nullptr;
        j = 0;
        name = new char* [1];
        password = new char* [1];

    }
	void showoptionstolibrarian()
	{
		int a;
		cout<<"Press 1 to add book."<<endl;
		cout<<"Press 2 to remove a book."<<endl;
		cout<<"Press 3 to edit a book."<<endl;
		cin>>a;
		if(a==1)
		{
			char* newbook=new char[40];
			cin.ignore();//just to ignore errors
		cin.getline(newbook,40);
		fstream obj("allbooks.txt",ios::app);
		obj<<newbook<<endl;
		//process in working
		//linking with book class and functions will be made in book class which were accessed by two d array present in the private area of librarian and in the function of book class,we will easily access to private area of book class
		}else
		if(a==2)
		{
			//process in working
			//remove book
		}else
		if(a==3)
		{

			//edit book
			//book will open indeed as the text of books will be pasted to the files from the internet and these books will be separated by the delimeters like -1
			//process in working
		}
		else
		{
			cout<<"You entered wrong button:)"<<endl;
		}
	



	}
    void signinlibrarian()
    {
        //==============NAME--ENTERING===========================================
        cout << endl << "\t\t\tSign---in of the LIBRARIAN" << endl;
        cout << "============================================================================" << endl;
        cout << "Enter login user name:\t\t";
        char* nameoflibrarian;
        nameoflibrarian = new char[30];
        cin >> nameoflibrarian;

        int lengthofenteredname = strlen(nameoflibrarian);

        name[j] = new char[lengthofenteredname];
        int x;

        for (x = 0; x < lengthofenteredname; x++)
        {
            name[j][x] = nameoflibrarian[x];
        }
        name[j][x] = '\0';

        cout << endl << name[j] << endl;


        //================PASS-WORD ENTERING====================================
        char* passwordoflibrarian;
        cout << "Enter login PASS--WORD:\t\t";
        passwordoflibrarian = new char[30];
        cin >> passwordoflibrarian;
        int lengthofenteredpassword;
        lengthofenteredpassword = strlen(passwordoflibrarian);
        password[j] = new char[lengthofenteredpassword];
        int k;
        for (k = 0; k < lengthofenteredpassword; k++)
        {
            password[j][k] = passwordoflibrarian[k];
        }
        password[j][k] = '\0';
        cout << endl << password[j] << endl;




    }
};

int typeofperson()
{
    cout << "Enter '1' If you are a User. " << endl << "Enter '2' If you are Librarian. " << endl;
    cout << "Now Who Are You?\n";
    int enterednum;
    cin >> enterednum;
    return enterednum;

}

void main()
{

    fstream data("alldata.txt", ios::app);
    //fstream is to input and output file simultaneously and  ios::app is for
    //entering values without losing previous values
    user obj;
    librarian holder;

    int choice = typeofperson();
    if (choice == 1)
    {
        int c;
        cout << "If you want to register,then Press 1. " << endl << "If you already have an account,then Press 2." << endl;
        cin >> c;
        if (c == 1)
        {
            obj.registeryourself(data);
        }
        else if (c == 2)
        {
            if (obj.signinuser() == false)
            {
                cout << endl << "Your entered credentials are incorrect!!.";
            }
            else
            {

                obj.showoptions();


                //code likhna ha
                //panel show krna ha jo puchega k issue krni ha ya jo b krna ha
                cout << "SUCCESSFULL";
            }
        }
    }
    else if (choice == 2)
    {
        cout << endl << "\t\t\t LIBRARIAN PANEL" << endl;
        holder.signinlibrarian();
		holder.showoptionstolibrarian();
    }
    else
    {
        cout << endl << "Panel don't exist because you have entered wrong number :) " << endl;
        return;
    }
    system("pause");
}