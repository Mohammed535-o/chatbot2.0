#ifndef MESSAGE_HANDLER_H_INCLUDED
#define MESSAGE_HANDLER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
class WhatsApp
{
       ///UNDER CONSTRUCTION TO BE CHECKED FOR TEXT INPUT
protected :
       string command;
public :
       void initialize()
       {
              command = " http://wa.me/91";
       }
       void SetPhone(string phno)
       {
              command += phno;
              command += "?";
       }
       void SetMessage(string message)
       {
              command += "text=";
              regex s(" ");
              string k = regex_replace(message,s,"+");
              command += k;
       }
       void SendMessage()
       {
              command = "START" + command;
              int n = command.size();
              char new_command[n + 1];
              strcpy(new_command,command.c_str());
              system(new_command);
       }
};


#endif // MESSAGE_HANDLER_H_INCLUDED
