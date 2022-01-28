#ifndef WEBSITE_HANDLER_H_INCLUDED
#define WEBSITE_HANDLER_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

class open_websites
{
protected :
       string command;
public :
       void initialize_command()
       {
              command += "START www.";
       }
       void initialize_webLink(string website_name)
       {
              command += website_name;
              command += ".com";
       }
       void call_website()
       {
              int n = command.size();
              char new_command[n + 1];
              strcpy(new_command,command.c_str());
              system(new_command);
       }
};

class google_search
{
protected :
       string command;
       string search_name;
public :
       void initialize_command()
       {
              command += "START https://www.google.com/search?q=";
       }
       void set_search_name(string s)
       {
              regex to_find(" ");
              search_name = regex_replace(s,to_find,"+");
       }
       void make_search()
       {
              command += search_name;
              int n = command.size();
              char new_command[n + 1];
              strcpy(new_command,command.c_str());
              system(new_command);
       }
};

#endif // WEBSITE_HANDLER_H_INCLUDED
