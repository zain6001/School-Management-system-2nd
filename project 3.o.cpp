//project of school manangement system

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>   //code9
using namespace std;

//functions prototypes

void intmain();
void adminLoginMenu();
int search();
void color();
void bscs();
void bsse();
void bsavm();
void allRecord();
void prof_LoginMenu();
void deleteRecord();
void updateRecord();

class storeRoom {          //login signup
	string name;
	string pass;
	public:
	void prof_Login(){
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
	   if(signupCheck==true){
	   	cout<<"login successfull"<<endl;
	   	system("pause");
	   	system("cls");
	    prof_LoginMenu();
	   }
	   else{system("cls");
	   cout<<"Check your password and Try again "<<endl;
	   cout<<"Returning to main..."<<endl;
	   system("pause");
	   system("cls");
	   }
	}
	read.close();	
}
	void prof_Reg(){
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
	if(!read.is_open()){
		
		cout<<"file error of signup";
	}
	else{
		string readName,readPass;
	
		while(!read.eof())	{
		
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
			}
			else
				check = true;
			
		}
		read.close();
		if (check)	{
			write<<prof_Signup.name<<endl;
			write<<prof_Signup.pass<<endl;
			write.close();
			cout<<"Registration successfull!!!"<<endl;
			system("pause");
			system("cls");
		}		
    }
	}
	
	
	
	void adminReg(){
	color();
	storeRoom adminSignup;
	bool check = false;
	cin.ignore();
	start1:
	cout<<"Please enter your new user name: ";
	getline(cin,adminSignup.name);
	cout<<"Please enter your password: ";
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
		}		
    }
} 

void adminLogin(){
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
	   if(signupCheck==true){
	   	cout<<"login successfull"<<endl;
	   	system("pause");
	   	system("cls");
	   adminLoginMenu();
	   }else{system("cls");
	   cout<<"Check your password and Try again "<<endl;
	   cout<<"Returning to main..."<<endl;
	   system("pause");
	   system("cls");
	   }
	}
	read.close();	
}
	
	
	void setName( string n){
		name=n;
	}
	void setPass(string p){
		pass=p;
	}
	string getName(){
		return name;
	}
	string getPass(){
		return pass;
	}
	
	


	
};
///////////////////
class personalInfo
{   protected:
	string name;
	string fatherName;
	char gender;
	public:
	friend void updateRecord();

	friend void bsavm();
	friend void bsse();

	friend void bscs();
	friend int search();



	
};




class enroll:public personalInfo{
	protected:
	int regId;
	string courseName;
	string time;
	string date;
	public:
	personalInfo info_std;
	friend void updateRecord();

	friend void bsavm();
	friend void bsse();

	friend void bscs();
	friend int search();




};
class studentRecord:public enroll{
	public:
		//ADD RECORD 
  void students(){
   ofstream write("student.txt",ios::app);
  bool check;
  string arr[3] = {"BSCS","BSSE","BSAVM"};
  cout<<"Enter the student id of student  :";
  int id;
  cin>>id;
  ifstream readFile ("student.txt");
  bool check2=true;
  while(!readFile.eof()){
        readFile>>regId;
    	readFile.ignore();
     	getline(readFile, name);
        getline(readFile, fatherName);
        readFile>>gender;
        readFile.ignore();
        getline(readFile, courseName);
        getline(readFile, time);
        getline(readFile,date);
        
			if(id==regId){
				check2=false;				
			}} 
			readFile.close();
			if(check2==false){
				cout<<"ID ALREADY EXISTS"<<endl;
				system("pause");
				system("cls");
				adminLoginMenu();
			}else if(check2==true){
				regId=id;
  cin.ignore();			
  cout<<"Enter the Name of student        :";
  getline(cin,name);
  cout<<"Enter father's name of student   :";
  getline(cin,fatherName);
  cout<<"Gender(M,F)?                     :";
  cin>>gender;
  
  a:
  cout<<"Enter department code (BSCS,BSSE,BSAVM) :";
  cin>>courseName;
  
  
  for (int i=0; i<3; i++)
  {
  	if (arr[i] ==courseName)
  	check = true;
  }
  if (check == false)
  {
  	cout << "Invalid Program name...Enter valid option." <<endl;
  	goto a;
  }

 write<<"\n"<<regId<<endl;
 write<<name<<endl;
 write<<fatherName<<endl;
 write<<gender<<endl;
 write<<courseName<<endl;
 write<<__TIME__<<endl;
 write<<__DATE__;
 cout<<"Record added successfully"<<endl;
	cout<<"Entering main menu...";
 	system("pause");
 	system("cls");
}
}
//	FETCH
void allRecord(){
	
	        cout<<"______________________________________________________"<<endl;
            cout<<"---------------AIR UNIVERSITY MULTAN CAMPUS -----------"<<endl;	
            cout<<"-----------------------BSAVM---------------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
	        
    ifstream read("student.txt");
    if (read.is_open()) {
        while (!read.eof()){
            read>> regId;
            read.ignore();
            getline(read, name);
            getline(read,fatherName);
            read>>gender;
            read.ignore();
            getline(read,courseName);
            getline(read,time);
            getline(read,date);
 
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : "<<gender<<endl;
                cout << "Course Name    : " << courseName << endl;
                cout<<  "Admission Time : "<<time<<endl;
                cout<<  "Admission Date : "<<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
			     
          
            
		}read.close();
        
    } else {
        cout << "Student Record file error" << endl;
    }
    
    system("pause");
    system("cls");
}
	
	
	
		
	
};

class manipulateRecord:public studentRecord{
	public:
	void deleteRecord(){
	int id;
	bool flag;
	string ch;
	cout<<"Enter id of student you want to delete the data :";
	cin>>id;
	ifstream read("student.txt");
	ifstream readFile("student.txt");
	ofstream write("temp.txt");
	if(readFile.is_open()){
		while(!readFile.eof()){
		
		readFile>>regId;
		readFile.ignore();
		getline(readFile,name);
        getline(readFile,fatherName);
        readFile>>gender;
        readFile.ignore();
        getline(readFile,courseName);
        getline(readFile,time);
        getline(readFile,date);
        if(id==regId){
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : "<<gender<<endl;
                cout << "Course Name    : " << courseName << endl;
                cout<<  "Admission Time : "<<time<<endl;
                cout<<  "Admission Date : "<<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
                flag=true;
                break;
		}else{
		flag=false;
		}
	} readFile.close();
	}else{
	cout<<"file not found"<<endl;
	}
	if(flag==true){
	
	cout<<"Do you really want to delete record of (y/n) "<<id <<" :";
	cin>>ch;
	if(ch=="Y" || ch=="y"){
	while(!read.eof()){
		read>>regId;
		read.ignore();
		getline(read,name);
        getline(read,fatherName);
        read>>gender;
        read.ignore();
        getline(read,courseName);
        getline(read,time);
        getline(read,date);
        if(id!=regId){
        	write<<endl<<regId<<endl;
        	write<<name<<endl;
        	write<<fatherName<<endl;
        	write<<gender<<endl;
        	write<<courseName<<endl;
        	write<<time<<endl;
        	write<<date;
		}
	}
	read.close();
	write.close();
	remove("student.txt");
	rename("temp.txt","student.txt");
	cout<<"Record deleted successfull :( "<<endl;
	system("pause");
	system("cls");
	}else{
		cout<<"You choose not to delete:)"<<endl;
		system("pause");
		system("cls");
	}}else{
		
		cout<<"id not found! "<<endl;
		system("pause");
		system("cls");

	}
	}



void updateRecord(){
	bool search,check;
	search =false;
	check =false;
	int id;
	cout << "Enter Id to update: ";
	cin >> id;
	
	ifstream readFile("student.txt");
	if(readFile.is_open()){
	  while(!readFile.eof()){
		readFile>>regId;
		readFile.ignore();
		getline(readFile,name);
        getline(readFile,fatherName);
        readFile>>gender;
        readFile.ignore();
        getline(readFile, courseName);
        getline(readFile,time);
        getline(readFile,date);
        if(id==regId){
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------PREVIOUS STUDENT DETAIL --------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
        	cout<<"ID          :"<<regId<<endl;
        	cout<<"Name        :"<<name<<endl;
        	cout<<"Father Name :"<<fatherName<<endl;
        	cout<<"Gender      :"<<gender<<endl;
        	cout<<"Course      :"<<courseName<<endl;
        	cout<<"Time        :"<<time<<endl;
        	cout<<"Date        :"<<date<<endl;
        	cout<<"                                                      "<<endl;
        	cout<<"______________________________________________________"<<endl;
        	
            search=true;
	    } 
    }readFile.close();
}else{
	cout<<"file error"<<endl;
}

	if(search==false){
    cout<<"Student dont exist"<<endl;
   	system("pause");
   	system("cls");	
	}
	else 
	{ // input
	    string newName,newFName,newGender,newCourse;
        string arr[3] = {"BSCS","BSSE","BSAVM"};
        string gen[]={"M","F"};
        cin.ignore();
        cout<<"_______________________________________________________"<<endl;
        cout<<"--------------------ENTER NEW DETAIL -----------------"<<endl;	
	    cout<<"______________________________________________________"<<endl;
        
	   	cout<<"Enter Name                          :";
		getline(cin, newName);
	    cout<<"Enter father Name                   :";
        getline(cin, newFName);
        b:
        cout<<"Enter Gender          (M/F)         :";
        cin>>newGender;
        for (int i=0; i<3; i++){
  	    if (gen[i] == newGender)
        check = true;
        }if (check == false){
  	    cout << "Enter valid option." <<endl;
  	    goto b;
         }
      
        a:
        cin.ignore();
        cout<<"Enter Course Name (BSCS,BSSE,BSAVM) :";
        getline(cin, newCourse);
        for (int i=0; i<3; i++){
  	    if (arr[i] == newCourse)
        check = true;
        }if (check == false){
  	    cout << "Enter valid option..." <<endl;
  	    goto a;
        }
         
         ifstream read ("student.txt");
   		 ofstream write("temp.txt");
   		 
   		if (search)
   		{
		   
    while(!read.eof()){
	    read>>regId;
    	read.ignore();
     	getline(read, name);
        getline(read,fatherName);
        read>>gender;
        read.ignore();
        getline(read, courseName);
        getline(read,time);
        getline(read,date);
       if(id!=regId){
       write<<endl<<regId<<endl;
       write<<name<<endl;
       write<<fatherName<<endl;
       write<<gender<<endl;
       write<<courseName<<endl;
       write<<__TIME__<<endl;
       write<<__DATE__;
	  }else{
	write<<endl<<id<<endl;  
	write<<newName<<endl;
  	write<<newFName<<endl;
  	write<<gender<<endl;
    write<<newCourse<<endl;
    write<<__TIME__<<endl;
    write<<__DATE__;
	}
}
}
read.close();
write.close();
	remove("student.txt");
	rename("temp.txt","student.txt");
	cout<<"Record updated succesfully "<<endl;
	system("pause");
	system("cls");
	}
	
}
};

class searchRecord:public manipulateRecord{
	public:
	int search(){    
    int id;
	ifstream read("student.txt");
	cout<<"Enter the registration id of student u want to search : ";
	cin>>id;
	cout<<endl;
    cout<<"******************AIR UNIVERSITY CAMPUS ****************"<<endl;
	if(read.is_open()){
		while(!read.eof()){
			read>>regId;
			read.ignore();
			getline(read,name);
			getline(read,fatherName);
			read>>gender;
			read.ignore();
			getline(read,courseName);
			getline(read,time);
			getline(read,date);
			if(id==regId){
			cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
			cout<<"Registration Id: "<<regId<<endl;
			cout<<"Name of student: "<<name<<endl;
			cout<<"father Name    : "<<fatherName<<endl;
			cout<<"Gender         : "<<gender<<endl;
			cout<<"Course         : "<<courseName<<endl;	
			cout<<"Time           : "<<time<<endl;
			cout<<"Date           : "<<date<<endl;
			cout<<"______________________________________________________"<<endl;		
			cout<<endl;
			system("pause");
			system("cls");
		    return 1;
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
	
}


//
	void bscs() {
 		    cout<<"______________________________________________________"<<endl;
            cout<<"---------------AIR UNIVERSITY MULTAN CAMPUS------------"<<endl;	
            cout<<"-----------------------BSCS---------------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
    ifstream read("student.txt");
    if (read.is_open()){
        while (!read.eof()){
            read>>regId;
            read.ignore();
            getline(read,name);
            getline(read,fatherName);
            read>>gender;
            read.ignore();
            getline(read,courseName);
            getline(read,time);
            getline(read,date);
            if (courseName == "BSCS"){
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : " <<gender <<endl;
                cout << "Course Name    : " <<courseName << endl;
                cout<<  "Time           : " <<time<<endl;
                cout<<  "Date           : " <<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
			     
            }
		}
        
    } else {
        cout << "Student Record file error" << endl;
    }

    system("pause");
    system("cls");

}
//

	void bsse() {
 		    cout<<"______________________________________________________"<<endl;
            cout<<"---------------AIR UNIVERSITY MULTAN CAMPUS------------"<<endl;	
            cout<<"-----------------------BSSE---------------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
    ifstream read("student.txt");
    if (read.is_open()){
        while (!read.eof()){
            read>>regId;
            read.ignore();
            getline(read,name);
            getline(read,fatherName);
            read>>gender;
            read.ignore();
            getline(read,courseName);
            getline(read,time);
            getline(read,date);
            if (courseName == "BSSE"){
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : " <<gender <<endl;
                cout << "Course Name    : " <<courseName << endl;
                cout<<  "Time           : " <<time<<endl;
                cout<<  "Date           : " <<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
			     
            }
		}
        
    } else {
        cout << "Student Record file error" << endl;
    }

    system("pause");
    system("cls");

}
	
//
	void bsavm() {
 		    cout<<"______________________________________________________"<<endl;
            cout<<"---------------AIR UNIVERSITY MULTAN CAMPUS------------"<<endl;	
            cout<<"-----------------------BSAVM---------------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
    ifstream read("student.txt");
    if (read.is_open()){
        while (!read.eof()){
            read>>regId;
            read.ignore();
            getline(read,name);
            getline(read,fatherName);
            read>>gender;
            read.ignore();
            getline(read,courseName);
            getline(read,time);
            getline(read,date);
            if (courseName == "BSAVM"){
            cout<<"_______________________________________________________"<<endl;
            cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	        cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : " <<gender <<endl;
                cout << "Course Name    : " <<courseName << endl;
                cout<<  "Time           : " <<time<<endl;
                cout<<  "Date           : " <<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
			     
            }
		}
        
    } else {
        cout << "Student Record file error" << endl;
    }

    system("pause");
    system("cls");

}
	
};
class attendance:public enroll{
	public:
		void mark(){
		bool check=false;
		cout<<"Enter the registration id of student you want to mark attendance : ";
		int id;
		cin>>id;
		ifstream read("student.txt");
		if(read.is_open()){
			while(!read.eof()){
		
			read>>regId;
			read.ignore();
			getline(read,name);
			getline(read,fatherName);
			read>>gender;
			read.ignore();
			getline(read,courseName);
			getline(read,time);
			getline(read,date);
			if(id==regId){
		        cout<<"_______________________________________________________"<<endl;
                cout<<"-----------------STUDENT DETAIL  ---------------------"<<endl;	
	            cout<<"______________________________________________________"<<endl;
                cout << "Registration Id: " << regId << endl;
                cout << "Name of student: " << name << endl;
                cout << "Father Name    : " << fatherName << endl;
                cout<<  "Gender         : " <<gender <<endl;
                cout << "Course Name    : " <<courseName << endl;
                cout<<  "Time           : " <<time<<endl;
                cout<<  "Date           : " <<date<<endl;
                cout<<"______________________________________________________"<<endl;
                cout << endl; 
			    check=true;
			    break;
            }	}
			if(check==true){
			
			ofstream write ("attendance.txt",ios :: app);
			int att;
			cout<<"Enter the attendance in percentage : ";
			cin>>att;
			
			write<<endl<<id<<endl;
			write<<att<<endl;
			write<<__TIME__<<endl;
			write<<__DATE__;
			
			system("pause");
			system("cls");
			}else{
				cout<<"Student does not exist";
		     	system("pause");
		     	system("cls");
				
			}
			
		}else{
			cout<<"File error"<<endl;
		}
		}
};
int main(){
 color ();
    string choice;
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
	
	cout<<"Please enter your choice : ";
	cin>>choice;
	storeRoom obj1;
	if(choice=="1")
	{
	obj1.adminReg();
	}
	else if( choice=="2")
	{
	obj1.adminLogin();
	}
	else if(choice=="3"){
	obj1.prof_Reg();
	main();
	}else if(choice=="4"){
	obj1.prof_Login();
	main();
	}else if(choice=="5"){
	cout<<"Exiting...."<<endl;
	cout<<"Successfully exited from the program";
	}
	else{
		cout<<"Invalid choice"<<endl;
		system("pause");
		system("cls");
		main();
	}
}


void adminLoginMenu(){

cout<<"\n     *::  ************ SCHOOL MANAGEMENT SYSTEM ************  ::*         "<<endl;
	cout<<"         _____________________________________________________          "<<endl;
	cout<<"        |*|------------------ADMIN MENU  ------------------ |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        1. Add new record of student             |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        2. Search Record of student              |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        3. Fetch all Record of students          |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        4. Fetch BSCS Record                     |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        5. Fetch BSSE Record                     |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        6. Fetch BSAVM Record                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        7. Update  Record of student             |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        8. Delete Record of student              |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        9. Log out                               |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
    string choice;
    searchRecord obj1;
    cout<<"Enter your choice: ";
    cin>>choice;
	if(choice=="1"){
		system("cls");
		obj1.students();
		adminLoginMenu();
	}
	else if(choice=="2"){
	    obj1.search();
		adminLoginMenu();	
	}
	else if(choice=="3"){
		obj1.allRecord();
		adminLoginMenu();
	}else if(choice=="4"){
		obj1.bscs();
		adminLoginMenu();
		
	}else if(choice=="5"){
		obj1.bsse();
		adminLoginMenu();
	}else if(choice=="6"){
		obj1.bsavm();
		adminLoginMenu();
	}else if(choice=="7"){
	obj1.updateRecord();
		adminLoginMenu();
	}else if(choice=="8"){
		obj1.deleteRecord();
		adminLoginMenu();
	}else if(choice=="9"){
		cout<<"Log out..."<<endl;
		system("pause");
		system("cls");
		main();
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
	cout<<"        |*|        5. Fetch BSAVM Record                    |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        6. Mark Attendance                       |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;
	cout<<"        |*|        7. View Attendance                       |*|         "<<endl;
	cout<<"        |*|                                                 |*|         "<<endl;			
	cout<<"        |*|        8. Log out                               |*|         "<<endl;
	cout<<"        |*|_________________________________________________|*|         "<<endl;
	string ch;
	searchRecord obj1;
	attendance attendance;
	cout<<"Enter your choice: ";
	cin>>ch;
	if(ch=="1"){
		obj1.search();
		prof_LoginMenu();
	}else if(ch=="2"){
		obj1.allRecord();
		prof_LoginMenu();
	}else if(ch=="3"){
		obj1.bscs();
		prof_LoginMenu();
	}else if(ch=="4"){
		obj1.bsse();
		prof_LoginMenu();
	}else if(ch=="5"){
		obj1.bsavm();
		prof_LoginMenu();
	}else if(ch=="6"){
		attendance.mark();
		prof_LoginMenu();
		
	}else if(ch=="7"){
		
	}else if(ch=="8"){
	cout<<"Log out"<<endl;
	system("pause");	
	system("cls");
	main();
	}else{
		cout<<"Invalid choice"<<endl;
		cout<<"Returning to Mainmenu..."<<endl;
		
		system("cls");
		main();
	}
}

void color(){
	system("color f1");
}





