#include <bits/stdc++.h>
#include <windows.h>
#include "espeak.h"
#include "website_handler.h"
#include "MultiMediaPlayer.h"
#include "message_handler.h"
using namespace std;
int main()
{
       system("Color 0A");
       string input;
       do
       {
              //system("START speech.lnk");
              getline(cin,input);
              if(input=="hi")
              {
                     voice_out voice;
                     voice.initializer("hello");
                     voice.print_voice_note("hello");
                     voice.execute_voice_command();
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
              }
              else if(input=="clear")
                     system("cls");
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
       return 0;
}
