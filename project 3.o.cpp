//project of school manangement system

#include <iostream>
#include <fstream>
#include <string>
//#include <iomanip>
//#include <limits>
#include <conio.h>   //code9

using namespace std;
//functions prototypes//
void intmain();
void adminReg();
void prof_Reg();
void adminLogin();
void prof_Login();
void adminLoginMenu();
int search();
void students();
void color();
void bscs();
void allRecord();
void prof_LoginMenu();


class storeRoom {          //login signup
	string name;
	string pass;
	public:
	friend void prof_Login();
	friend void prof_Reg();
	friend void adminReg(); 
	friend void adminLogin();
	
	void setName( string n)
	{
		name=n;
		
	}
	void setPass(string p){
		pass=p;
	}
	string getName()
	{
		return name;
	}
	string getPass()
	{
		return pass;
	}
	
};

class personalInfo
{
	string name;
	string fatherName;
	public:
	friend void allRecord();
	friend void bscs();
	friend int search();
	friend void students();
		void setName(string n){
		name=n;
	}
	void setFatherName(string f){
		fatherName=f;
	}
	string getName(){
		return name;
	}
	string getFatherName(){
		return fatherName;
	}
	
};


class enroll:public personalInfo
{
	int regId;
	string courseName;
	public:
	friend void allRecord();
	friend void bscs();
	friend void students();
	friend int search();
	personalInfo info_std;
	void setReg(int r){
		regId=r;
	}
	void setCourse(string c){
		courseName=c;
	}
	string getCourseName(){
		return courseName;
	}
	int getRegId(){
		return regId;
	}

};

int main()
{
    color ();
    int choice;
	cout<<"\n     *::  ************ SCHOOL MANAGEMENT SYSTEM ************  ::*    "<<endl;
	cout<<"         _____________________________________________________          "<<endl;
	cout<<"        |*|-----------------  MAIN  MENU  ----------------- |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        1. Register for Admin                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        2. Login for Admin                       |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        3. Register for Professor                |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        4. Login for Professor                   |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        5. Exit                                  |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cin>>choice;
	if(choice==1)
	{
	adminReg();
	}
	else if( choice==2)
	{
	 adminLogin();
	}
	else if(choice==3){
	 prof_Reg();
	}else if(choice==4){
	 prof_Login();
	}else if(choice==5){
	cout<<"Exiting...."<<endl;
	cout<<"Successfully exited from the program";
	}
	else{
		cout<<"Invalid choice"<<endl<<"Returning to main menu..."<<endl;
		system("pause");
		system("cls");
		main();
	}
}
void adminReg()
{
	color();
	storeRoom adminSignup;
	bool check = false;
	cin.ignore();
	start1:
	cout<<"Please enter your new user name: ";
	getline(cin,adminSignup.name);
	cout<<"Please enter your password:      ";
    adminSignup.pass = "";
    char ch;
    do {
        ch = getch();

        switch (ch) {
            case 13:  // Enter key
                cout << endl;
                break;
            case 8:   // Backspace
                if (!  adminSignup.pass.empty()) {
                      adminSignup.pass =   adminSignup.pass.substr(0,   adminSignup.pass.length() - 1);  // Workaround for pop_back()
                    cout << "\b \b";  // Backspace and erase character
                }
                break;
            default:
                  adminSignup.pass += ch;
                cout << '*';  // Mask character
        }
    } while (ch != 13);  // Continue until Enter is pressed
    
	ofstream write("admin.txt",ios::app);
	ifstream read("admin.txt");
	if(!read.is_open())
	{
		
		cout<<"file error of signup";
	}
	else
	{
		string readName,readPass;
	
		while(!read.eof())
		{
		
			getline(read,readName);
			getline(read,readPass);
			if(adminSignup.name==readName)
			{
				cout<<"User Already exists!" <<endl;
				start2:
					cout<<"Do u want to signup again(Y/N): ";
					string choice;
					cin>>choice;
					if(choice=="Y"||choice=="y")
					{
						system("cls");
						adminReg();
						break;
					}
					else
					{
						main();
					}
				
				
			}
			else
				check = true;
			
		}
		read.close();
		if (check)
		{
			write<<adminSignup.name<<endl;
			write<<adminSignup.pass<<endl;
			write.close();
			cout<<"Registration successfull!!!"<<endl;
			system("pause");
			system("cls");
			main();
		}		
    }
}
void prof_Reg()
{
	color();
	storeRoom prof_Signup;
	bool check = false;
	cin.ignore();
	start1:
	cout<<"Please enter your new user name: ";
	getline(cin,prof_Signup.name);
	cout<<"Please enter your password:      ";
    prof_Signup.pass = "";
    char ch;
    do {
        ch = getch();

        switch (ch) {
            case 13:  // Enter key
                cout << endl;
                break;
            case 8:   // Backspace
                if (!  prof_Signup.pass.empty()) {
                      prof_Signup.pass =   prof_Signup.pass.substr(0,   prof_Signup.pass.length() - 1);  // Workaround for pop_back()
                    cout << "\b \b";  // Backspace and erase character
                }
                break;
            default:
                  prof_Signup.pass += ch;
                cout << '*';  // Mask character
        }
    } while (ch != 13);  // Continue until Enter is pressed
    
	ofstream write("professorLogin.txt",ios::app);
	ifstream read("professorLogin.txt");
	if(!read.is_open())
	{
		
		cout<<"file error of signup";
	}
	else
	{
		string readName,readPass;
	
		while(!read.eof())
		{
		
			getline(read,readName);
			getline(read,readPass);
			if(prof_Signup.name==readName)
			{
				cout<<"User Already exists!" <<endl;
				start2:
					cout<<"Do u want to signup again(Y/N): ";
					string choice;
					cin>>choice;
					if(choice=="Y"||choice=="y")
					{
						system("cls");
						prof_Reg();
						break;
					}
					else
					{
						main();
					}
				
				
			}
			else
				check = true;
			
		}
		read.close();
		if (check)
		{
			write<<prof_Signup.name<<endl;
			write<<prof_Signup.pass<<endl;
			write.close();
			cout<<"Registration successfull!!!"<<endl;
			system("pause");
			system("cls");
			main();
		}		
    }
}
void adminLogin()
{
	color();
	cin.ignore();
	string readName,readPassword;
	storeRoom adminLogin;
	bool signupCheck;
	ifstream read("admin.txt");
	cout<<"Please Enter your name     :";
	getline(cin,adminLogin.name);
	cout<<"Please enter your password :";
	adminLogin.pass = "";
    char ch;
    do {
        ch = getch();

        switch (ch) {
            case 13:  // Enter key
                cout << endl;
                break;
            case 8:   // Backspace
                if (!  adminLogin.pass.empty()) {
                      adminLogin.pass =   adminLogin.pass.substr(0,   adminLogin.pass.length() - 1);  // Workaround for pop_back()
                    cout << "\b \b";  // Backspace and erase character
                }
                break;
            default:
                  adminLogin.pass += ch;
                cout << '*';  // Mask character
        }
    } while (ch != 13);  // Continue until Enter is pressed
	if(!read.is_open())
	{
		cout<<"file error";
	}
	else
	{	while(!read.eof())
     	{
	     getline(read,readName);
	     getline(read,readPassword);
	     if(adminLogin.name==readName && adminLogin.pass ==readPassword){
	  	    signupCheck=true;
	  	    break;
	      }else{
	  	    signupCheck=false;
	       }
	       
       }
	   if(signupCheck==true)
	   {
	   	cout<<"login successfull"<<endl;
	   	system("pause");
	   	system("cls");
	   	
	   adminLoginMenu();
	   }
	   else
	   {system("cls");
	   cout<<"Check your password and Try again "<<endl;
	   cout<<"Returning to main..."<<endl;
	   system("pause");
	   system("cls");
	   main();
	   }
	}
	read.close();	
}
void prof_Login()
{
	color();
	cin.ignore();
	string readName,readPassword;
	storeRoom prof_Login;
	bool signupCheck;
	ifstream read("professorLogin.txt");
	cout<<"Please Enter your name     :";
	getline(cin,prof_Login.name);
	cout<<"Please enter your password :";
	prof_Login.pass = "";
    char ch;
    do {
        ch = getch();

        switch (ch) {
            case 13:  // Enter key
                cout << endl;
                break;
            case 8:   // Backspace
                if (!  prof_Login.pass.empty()) {
                      prof_Login.pass =   prof_Login.pass.substr(0,   prof_Login.pass.length() - 1);  // Workaround for pop_back()
                    cout << "\b \b";  // Backspace and erase character
                }
                break;
            default:
                  prof_Login.pass += ch;
                cout << '*';  // Mask character
        }
    } while (ch != 13);  // Continue until Enter is pressed
	if(!read.is_open())
	{
		cout<<"file error";
	}
	else
	{	while(!read.eof())
     	{
	     getline(read,readName);
	     getline(read,readPassword);
	     if(prof_Login.name==readName && prof_Login.pass ==readPassword){
	  	    signupCheck=true;
	  	    break;
	      }else{
	  	    signupCheck=false;
	       }
	       
       }
	   if(signupCheck==true)
	   {
	   	cout<<"login successfull"<<endl;
	   	system("pause");
	   	system("cls");
	   	
	   prof_LoginMenu();
	   }
	   else
	   {system("cls");
	   cout<<"Check your password and Try again "<<endl;
	   cout<<"Returning to main..."<<endl;
	   system("pause");
	   system("cls");
	   main();
	   }
	}
	read.close();	
}
void students() //data storing
{
  color();
  enroll student;
  int id;
  string name;
  string fName, dept;

 start:
 cout<<"Enter the student id of student  :";
 cin>>student.regId;
 cout<<"Enter the Name of student        :";
 cin.ignore();
 getline(cin,student.info_std.name);
 cout<<"Enter father's name of student   :";
 getline(cin,student.info_std.fatherName);
 string deptt[3]={"BSCS","BSSE" ,"BSAVM"};
 cout<<"Enter department code :";
 cin>>student.courseName;
 bool check=true;
 for(int i=0;i<3;i++){
	if(student.courseName != deptt[i]){
		check=false;
   	}
  }if(check==false){
  	cin>>student.courseName;
  }
 
 ofstream write("student.txt",ios::app);

 
 write<<student.regId<<endl;
 write<<student.info_std.name<<endl;
 write<<student.info_std.fatherName<<endl;
 write<<student.courseName<<endl;
 cout<<"Do u want to add another record of student (Y/N)   :";
 string ch;
 cin>>ch;
 if(ch=="Y" || ch=="y")
 {
 	goto start;
 }
 else
 {
 	cout<<"Entering main menu...";
 	system("pause");
 	system("cls");
 	main();
 }
}

void adminLoginMenu(){
	color();
cout<<"\n     *::  ************ SCHOOL MANAGEMENT SYSTEM ************  ::*    "<<endl;
	cout<<"         _____________________________________________________          "<<endl;
	cout<<"        |*|------------------ADMIN MENU  ------------------ |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        1. Enter new record of student           |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        2. Fetch all Record of students          |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        3. Fetch BSCS Record                     |*|          "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        4. Fetch BSSE Record                     |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        5. Fetch BSAVM Record                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        6. Delete Record of student              |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        7. Return to Mainmenu                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
    int choice;
    cin>>choice;
	if(choice==1){
		system("cls");
		students();
	}
	else if(choice==2){
		allRecord();
	}
	else if(choice==3){
		search();
	}else if(choice==4){
		bscs();
	}
	
    else{
		system("cls");
		cout<<"invalid choice returning to main menu"<<endl;
		system("pause");
		main();
	}
	
}
void prof_LoginMenu(){
	color ();
    int choice;
	cout<<"\n     *::  ************ SCHOOL MANAGEMENT SYSTEM ************  ::*    "<<endl;
	cout<<"         _____________________________________________________          "<<endl;
	cout<<"        |*|------------- PROFESSOR LOGIN  MENU  ----------- |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        1. Search Record of student              |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        2. Fetch all Record of students          |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        3. Fetch BSCS Record                     |*|          "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        4. Fetch BSSE Record                     |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        5. fetch BSCS Record                     |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        6. Return to Mainmenu                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	string ch;
	cout<<"Enter your choice: ";
	cin>>ch;
	if(ch=="1"){
		
	}else{
		cout<<"Invalid choice"<<endl;
		cout<<"Returning to Mainmenu..."<<endl;
		system("pause");
		system("cls");
	}
}
int search(){
	color();
    enroll search;
	int input;
	ifstream read("student.txt");
	cout<<"Enter the registration id of student u want to search : ";
	cin>>input;

	if(read.is_open()){
		while(!read.eof()){
			read>>search.regId;
			read.ignore();
			getline(read,search.info_std.name);
			getline(read,search.info_std.fatherName);
			getline(read,search.courseName);
			if(search.regId==input){
			cout<<"------------student data----------------"<<endl;
			cout<<"Registration Id: "<<search.regId<<endl;
			cout<<"Name of student: "<<search.info_std.name<<endl;
			cout<<"father Name    : "<<search.info_std.fatherName<<endl;
			cout<<"course         : "<<search.courseName<<endl;			
			cout<<endl;
			system("pause");
			system("cls");
			adminLoginMenu();
		    return input;
			}
			
		}
    
	}
	else
	{
		cout<"file error";	
	}
	cout<<"Incorrect student ID"<<endl;
	cout<<"Returning to main menu...."<<endl;
	system("pause");
	system("cls");
	
	main();
	
}

void color(){
	system("color f1");
}
void bscs() {
    cout << "-------------BSCS----------" << endl;
	enroll student;
    ifstream read("student.txt");
    if (read.is_open()) {
        while (!read.eof()) {
            read >> student.regId;
            read.ignore();
            getline(read, student.info_std.name);
            getline(read, student.info_std.fatherName);
            getline(read, student.courseName);
            if (student.courseName == "BSCS") {
                cout << "------------student data----------------" << endl;
                cout << "Registration Id: " << student.regId << endl;
                cout << "Name of student: " << student.info_std.name << endl;
                cout << "Father Name: " << student.info_std.fatherName << endl;
                cout << "Course: " << student.courseName << endl;
                cout << endl;
            }
        }
    } else {
        cout << "Student Record file error" << endl;
    }

    read.close();
}
void allRecord(){
	
	cout << "---------AIR UNIVERSITY MULTAN CAMPUS---------" << endl;

	
	
	
	enroll student;
    ifstream read("student.txt");
    if (read.is_open()) {
        while (!read.eof()) {
            read >> student.regId;
            read.ignore();
            getline(read, student.info_std.name);
            getline(read, student.info_std.fatherName);
            getline(read, student.courseName);
         	cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
            cout<< "Registration Id: " << student.regId << endl;
            cout<< "Name of student: " << student.info_std.name << endl;
            cout<< "Father Name    : " << student.info_std.fatherName << endl;
            cout<< "Course Name    : " << student.courseName << endl;
            cout<<"______________________________________________________"<<endl;
            cout << endl;
                
            }
        }else{
        cout << "Student Record file error" << endl;
    }
    system("pause");
    system("cls");
    main();

    read.close();
	
}
