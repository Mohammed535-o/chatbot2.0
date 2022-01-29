#include <bits/stdc++.h>
#include <windows.h>
#include <iomanip>
#include "espeak.h"
#include "website_handler.h"
#include "MultiMediaPlayer.h"
#include "message_handler.h"
#include <conio.h>
#define ENTER 13
#define BACKSPACE 8
using namespace std;
bool loggedIn = false;
void mask(string &pass);
void login();
void register_();
void ColorPallete();
int main()
{
	system("Color 0B");
	top :
	cout << "\n\n\n\n\n";
	cout << "=============== Login/Register ===============\n\n";
	cout << "\t\t";
	cout << "1.Login\n";
	cout << "\t\t";
	cout << "2.Register\n\n";
	int choice;
	cout << "\t";
	cout << "Enter Choice : ";
	cin >> choice;
	cout << "\n";
	system("cls");
	if(choice==1)
	{
		login();
	}
	else 
	{
		register_();
	}
	if(loggedIn)
	{
	   system("Color 0A");
	   system("cls");
       string input;
       do
       {
              // system("START speech.lnk");
              getline(cin,input);
              if(input=="hi")
              {
                     voice_out voice;
                     voice.initializer("hello");
                     voice.print_voice_note("hello");
                     voice.execute_voice_command();
                     cout << endl;
              }
              else if(input=="date")
              {
              		string date = __DATE__;
              		voice_out voice;
              		voice.initializer("today is " + date);
              		voice.print_voice_note("date is " + date);
              		voice.execute_voice_command();
              		cout << endl;
              }
              else if(input=="chrome open")
              {
              	voice_out voice;
                     voice.initializer("opening chrome");
                     voice.print_voice_note("opening chrome");
                     voice.execute_voice_command();
                     cout << endl;
              	system("START chrome.exe");

              }
              else if(input=="firefox open")
              {
              	voice_out voice;
                     voice.initializer("opening firefox");
                     voice.print_voice_note("opening firefox");
                     voice.execute_voice_command();
                     cout << endl;
              	system("START firefox.exe");

              }
              else if(input.find("open")!=string::npos)
              {
                     string WebName = input.substr(5,input.size() - 1);
                     voice_out voice;
                     voice.initializer("opening " + WebName);
                     voice.print_voice_note("opening " + WebName);
                     voice.execute_voice_command();

                     open_websites website;
                     website.initialize_command();
                     website.initialize_webLink(WebName);
                     website.call_website();
                     cout << endl;
              }
              else if(input.find("search")!=string::npos)
              {
                     string search_name = input.substr(7,input.size() - 1);
                     voice_out voice;
                     voice.initializer("searching google for " + search_name);
                     voice.print_voice_note("searching google for " + search_name);
                     voice.execute_voice_command();

                     google_search search_;
                     search_.initialize_command();
                     search_.set_search_name(search_name);
                     search_.make_search();
                     cout << endl;
              }
              else if(input.find("play")!=string::npos)
              {
                     string video_name = input.substr(5,input.size() - 1);
                     voice_out voice;
                     voice.initializer("playing " + video_name);
                     voice.print_voice_note("playing " + video_name);
                     voice.execute_voice_command();

                     video new_video;
                     new_video.initialize_command();
                     new_video.set_video_name(video_name);
                     new_video.PlayVideo();
                     cout << endl;
              }
              else if(input.find("Read")!=string::npos)
              {
                     string file_name = input.substr(5,input.size() - 1);
                     voice_out voice;
                     voice.initializer("Reading " + file_name);
                     voice.print_voice_note("Reading " + file_name);
                     voice.execute_voice_command();

                     AudioBook book;
                     book.speedNpitch_initializer();
                     book.set_fileName(file_name);
                     book.read_file_voice();
                     cout << endl;
              }
              else if(input=="set timer")
              {
                    system("START timer.exe");
                    cout << endl;
              }

              else if(input=="bye")
              {
                     voice_out voice;
                     voice.initializer("bye");
                     voice.print_voice_note("bye");
                     voice.execute_voice_command();
                     cout << endl;
              }
              else if(input=="clear")
                     system("cls");
              else if(input=="how are you")
              {
              		voice_out voice;
                     voice.initializer("i'm fine");
                     voice.print_voice_note("i'm fine");
                     voice.execute_voice_command();
                     cout << endl;
              }
              else if(input=="change theme")
              {
              	ColorPallete();
              	string hh;
              	cout << "Enter XY : ";
              	cin >> hh;
              	string ans = "Color " + hh;
              	int n = ans.size();
              	char A[n + 1];
              	strcpy(A,ans.c_str());
              	system(A);
              	cout << endl;
              }
              else if(input=="wa")
              {
                     ///UNDER CONSTRUCTION TO BE CHECKED FOR TEXT INPUT
                     WhatsApp wmsg;
                     wmsg.initialize();
                     string phno;
                     cout << "Enter phno : ";
                     cin >> phno;
                     wmsg.SetPhone(phno);
                     string message;
                     cout << "Enter the message you want to send : ";
                     getline(cin,message);
                     wmsg.SetMessage(message);
                     wmsg.SendMessage();
              }
       }while(input!="bye");
	}
	else 
	{
		goto top;
	}
}
void login()
{
	cout << "\n\n\n\n\n";
	cout << "===================== Login =====================\n\n";
	string name,pass;
	cout << "\t";
	cout << "Enter Username : ";
	cin >> name;
	string fname = name + ".txt";
	ifstream read(fname);
	if(read)
	{
		string password;
		getline(read,password);
		cout << "\t";
		cout << "Enter password : ";
		mask(pass);
		if(pass!=password)
		{
			cout << "\t";
			cout << "\nPassword doesn't match\n";
			Sleep(700);
			system("cls");
		}
		else 
		{
			cout << "\t\t";
			cout << "\nLogged in Successfully\n";
			Sleep(800);
			loggedIn = true;
		}
	}
	else 
	{
		cout << "\t";
		cout << "\nUser Not Found\n\n";
		Sleep(700);
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "=============== Login/Register ===============\n\n";
		cout << "\t\t";
		cout << "1.Login\n";
		cout << "\t\t";
		cout << "2.Register\n\n";
		int choice;
		cout << "\t";
		cout << "Enter Choice : ";
		cin >> choice;
		cout << "\n";
		system("cls");
		if(choice==1)
		{
			login();
		}
		else 
		{
			register_();
		}
	}
}
void register_()
{
	cout << "\n\n\n\n\n";
	cout << "===================== Register =====================\n\n";
	string name,pass;
	cout << "\t";
	cout << "Enter Username : ";
	cin >> name;
	string fname = name + ".txt";
	ifstream read(fname);
	if(read)
	{
		cout << "\t";
		cout << "\nUsername Already exits\n";
		cout << "\t";
		cout << "\nChoose other username\n\n";
		Sleep(700);
		system("cls");
	}
	else 
	{
		read.close();
		ofstream newUser(fname);
		cout << "\t";
		cout << "Enter password : ";
		mask(pass);
		newUser << pass << endl;
		cout << "\t";
		cout << "\n\nUser Registered Successfully\n\n";
		Sleep(700);
		system("cls");
		login();
	}
}
void mask(string &pass)
{
	string s;
	char c;
	while((c = _getch())!=ENTER)
	{
		if(c==BACKSPACE && s.size()!=0)
		{
			s.pop_back();
			cout << "\b \b";
			continue;
		}
		s += c;
		_putch('*');
	}
	pass = s;
}
void ColorPallete()
{
	cout << endl;
	cout << endl;
	string k = "+-----------------------------------+";
	k[14] = '+';
	cout << "  " << k << endl;
	cout << "  |" << "	ColorId |	Color" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"  << "	1      	|	Blue"  << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	2      	|	Green" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	3      	|	Aqua" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	4      	|	Red" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	5      	|	Purple" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	6      	|	Yellow" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	7      	|	White" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	8      	|	Gray" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	9      	|	LightBlue" << "     |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	0      	|	Black" << "	      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	A      	|	LightGreen" << "    |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	B      	|	LightAqua" << "     |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	C      	|	LightRed" << "      |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	D      	|	LightPurple" << "   |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	E      	|	LightYellow" << "   |" << endl;
	cout << "  "  << k << endl;
	cout << "  |"   << "	F      	|	BrightWhite" << "   |" << endl;
	cout << "  "  << k << endl;
	cout << endl;
	cout << "ENTER XY\n\n";
	cout << "X --> Background Color\n Y --> Text Color\n\n";

}