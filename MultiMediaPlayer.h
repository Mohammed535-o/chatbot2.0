#ifndef MULTIMEDIAPLAYER_H_INCLUDED
#define MULTIMEDIAPLAYER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class video
{
protected :
       string command;
       string file_name;
public :
       void initialize_command()
       {
              command += "START ";
       }
       void set_video_name(string s)
       {
              file_name = s;
              command += file_name + ".mp4";
       }
       void PlayVideo()
       {
              int n = command.size();
              char new_command[n + 1];
              strcpy(new_command,command.c_str());
              system(new_command);
       }
};
#endif // MULTIMEDIAPLAYER_H_INCLUDED
