#include <iostream>
#include "conio.h"
#include "Windows.h"
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Music
{
private:
    string music_title;
	string music_artistname;
	string music_albumname;
	double music_size;


public:
    void AddRecord();
    void DELETERECORD();
    void EditRecord();
    void ModifyRecord();
    void DisplayAll();
    //void goodBye();
};

// MAIN METHOD
int main()
{
  Music Kavita[100];

   HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);

   cout << endl ;
   cout << "\t" << "****************** MUSIC LIBRARY SYSTEM *****************\n";
   cout << "\t" << "*                     1. Add Records                     *\n";
   cout << "\t" << "*                     2. Delete Records                  *\n";
   cout << "\t" << "*                     3. Edit Records                    *\n";
   cout << "\t" << "*                     4. Modify Records                  *\n";
   cout << "\t" << "*                     5. Display All Records             *\n";
   cout << "\t" << "*                     6. Quit                            *\n";
   cout << "\t" << "**********************************************************\n";

   SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
   int choice;
   int i=0;
   char confirm;
   char ans;
   bool done = true;
   do
   {
   cout << endl << " Please enter your choice: (1/2/3/4/5) : " ;
   cin >> choice;

   switch(choice)
   {
       case 1: Kavita[i].AddRecord(); break;
       case 2: Kavita[i].DELETERECORD(); break;
       case 3: Kavita[i].EditRecord(); break;
       case 4: Kavita[i].ModifyRecord(); break;
       case 5: Kavita[i].DisplayAll(); break;
       //case 6: done = true; break;
       default: cout << " INVALID CHOICE ";

   }//while (!done);
   //goodBye();
   while(confirm =='Y' || confirm == 'y');
   _getch();
   cout << endl;
return 0;
   }
   
//void goodBye()
/*{
   string msg = "\nGoodbye...!";
   for(int i=0; i<msg.length(); i++)
    {
   cout << msg[i] << "\a";
   Sleep(500);
   }
}*/


// METHOD TO ADD RECORD
}
void Music:: AddRecord()
{
    int ans;

	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);


    ofstream a_file("FILE.txt", ios::out |ios::trunc |ios::in) ;
    a_file.write("FILE.txt", ios::out |ios::trunc |ios::in);
    cout << endl << " YOU HAVE CHOSEN TO ADD RECORDS ! \n";
    cout << " How many record do you want to add ?";
    cin >> ans;

    for(int i=0;i<ans;i++)
    {
            cout << endl;
            cout << " Enter the music title : ";
            cin >> music_title;
            //a_file << music_title << '\t';

            cout << " Enter the artist name : ";
            cin >> music_artistname;
            //a_file << music_artistname << '\t';

            cout << " Enter the album name : ";
            cin >> music_albumname;
            //a_file << music_albumname << '\t';

            cout << " Enter the music size : ";
            cin >> music_size;
            //a_file << music_size << '\t';

            //cout << endl;
            a_file << music_title << music_artistname<<music_albumname<<music_size;
    }
}

// METHOD TO DELETE RECORD
void Music:: DELETERECORD()
{
string line, music_title;
  cout << "Please Enter the Title of song you want to delete: ";
  cin >> music_title;
  ifstream a_file;
  ofstream temp;
  a_file.open("FILE.txt");
  temp.open("temp.txt");
  while (getline(a_file, line))
  {
    if (line != music_title)
      temp << line << endl;
  }
  cout << "The record with the title " << music_title << " has been deleted if it exsisted" << endl;
  a_file.close();
  temp.close();
  remove("FILE.txt");
  rename("temp.txt", "FILE.txt");
}

// METHOD TO EDIT RECORD
void Music::EditRecord()
{
    cout << " EDITING \n";
}

// METHOD TO MODIFY RECORD
void Music::ModifyRecord()
{
    cout << " MODIFYING \n";
}

// METHOD TO DISPLAYR RECORD
void Music::DisplayAll()
{
    int ans;
    ///cout << " How many records have you added ?";
    //cin >> ans;
    cout << endl << "DISPLAYING ALL THE CONTENTS OF THE MUSIC SYSTEM \n" << endl;
    ifstream filex;
    filex.open("FILE.txt", ios::in|ios::out|ios::trunc);
    if(!filex.good()){
        cout<< "sorry the file cud not open correct";
    }   else

        while(filex.eof())
           {
           //for(int i=0; i<ans; i++)
       // {
       filex.seekg(0);
       //cout <<filex
        cout <<"Music Tile: " <<music_title<<endl;
        cout <<"Music Artist Name: "<<music_artistname<<endl;
        cout <<"Music Album Name: " <<music_albumname<<endl;
        cout << "Music size: " <<music_size<<endl;
            }
}






