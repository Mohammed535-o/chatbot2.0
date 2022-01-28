#ifndef ESPEAK_H_INCLUDED
#define ESPEAK_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class voice_out
{
       ///voice class espeak
protected :
       string command = "espeak -v +m2 ";
public :
       void initializer(string phrase);
       void execute_voice_command();
       void print_voice_note(string phrase);
};
void voice_out::initializer(string phrase)
{
       command += "\"";
       command += phrase;
       command += "\"";
}
void voice_out::execute_voice_command()
{
       int n = command.size();
       char new_command[n + 1];
       strcpy(new_command,command.c_str());
       system(new_command);
}
void voice_out::print_voice_note(string phrase)
{
       cout << endl;
       cout << ">>> ";
       cout << phrase << endl;
}
class AudioBook : private voice_out
{
       ///this class for audio book inherited from voice_out class
private :
       string speed_and_pitch;
public :
       void speedNpitch_initializer(int speed = 150,double pitch = 0.01)
       {
              string speed_ = "-s";
              speed_ += to_string(speed);
              string pitch_ = "-g";
              pitch_ += to_string(pitch);
              speed_and_pitch = " " + speed_ + " " + pitch_;
              speed_and_pitch += " -f \"";
       }
       void set_fileName(string file_name)
       {
              file_name += ".txt";
              command += speed_and_pitch + file_name + "\"";
       }
       void read_file_voice()
       {
              int n = command.size();
              char new_command[n + 1];
              strcpy(new_command,command.c_str());
              system(new_command);
       }
};


#endif // ESPEAK_H_INCLUDED
