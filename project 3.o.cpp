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
void reg();
void login();
void loginMenu();
int search();
void students();
void color();
void bscs();


class storeRoom {//login signup
	string name;
	string pass;
	public:
	friend void reg();//friend function
	friend void login();
	
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
	cout<<"        |*|----------------  LOGIN  MENU  ----------------- |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        1. Register for Admin                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        2. Login for Admin                       |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        3.Register for Teacher                   |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        4.Login for Teacher                      |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        5.Exit                                   |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cin>>choice;
	if(choice==1)
	{
	reg();
	}
	else if( choice==2)
	{
	 login();
	}
	else if(choice==3){
		
	}else if(choice==4){
		
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
void reg()
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
						reg();
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
void login()
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
	   	
	   loginMenu();
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

void loginMenu(){
	color();
	cout<<"1.New entry "<<endl;
	cout<<"2.Print all data of students"<<endl;
	cout<<"3.Search data of students "<<endl;
	cout<<"4.Print BSCS Enrolled students"<<endl;
	cout<<"5.Print BSSE Enrolled students"<<endl;
	cout<<"6.Print BSAVM Enrolled students"<<endl;
	cout<<"7.Delete data of student" <<endl;
    int choice;
    cin>>choice;
	if(choice==1){
		system("cls");
		students();
	}
	else if(choice==2){
		//DataStudents();
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
			loginMenu();
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
