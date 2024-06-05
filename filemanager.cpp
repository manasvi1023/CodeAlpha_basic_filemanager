#include <stdio.h>
#include <string>
#include <time.h>
#include <iostream> 
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

void display_menu ();
void list_files();
void pwd_func();
void cd_func();
void print(string str);
void mkdir_func();
void rm_func() ;
int main()
{
	cout<< "*************************************"<< endl ;
	cout << "Hello,Welcom to Basic File Manager!" << endl ;
	cout<< "*************************************"<< endl ;
// to store input number to compare with random number
    string input_Data;

	// flag to close the program if guessing correct
   do {
    display_menu();
    cout << "$";
    cin >> input_Data;
    if(input_Data=="ls")
		list_files();
	else if (input_Data=="cd")
		cd_func();
	else if (input_Data=="mkdir")
		mkdir_func();
	else if (input_Data=="rm")
		rm_func();
	else if (input_Data=="pwd")
		pwd_func();
	else if (input_Data=="q")
		cout << "Quite Basic File Manager!\n";
	else
		cout << "Invalid input....\n ";
    
  } while (input_Data!="q");
  
  
	return 0;
}

void display_menu (){
	print("ls - Print files \ncd - change directory \nmkdir - create directory \n");
	print("rm - remove file \npwd - Display present directory \nq - Quite \n");
	}
void list_files(){
   DIR *dr;
   struct dirent *en;
   dr = opendir("."); //open all directory
   if (dr) {
	cout<< "*************************************";
      while ((en = readdir(dr)) != NULL) {
         cout<<" \n"<<en->d_name; //print all directory name
		}
      closedir(dr); //close all directory
	}
	cout<< "\n\n*************************************"<< endl ;

}
void cd_func(){
	string input_Data;
	cout << "Enter new dir: ";
	cin >> input_Data ;
	chdir(input_Data.c_str()); 

	}
void pwd_func(){
	    char s[100]; 
	cout<< "*************************************\n";
	cout<<"current directory is: " << getcwd(s, 100) << endl ;
	cout<< "*************************************\n";

}
void mkdir_func(){
	string input_Data;
	cout << "Enter new File name: ";
	cin >> input_Data ;
	mkdir(input_Data.c_str());
	cout << "Directory created";

}
void rm_func(){
	char fileName[20];
	int status {};
    cout<<"Enter the Name of File: ";
    cin>>fileName;
    status = rmdir(fileName);
	if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nError Occurred!";
    cout<<endl;

}

void print(string str){
	cout << str;
	}
