#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "checkuser.h"

int checkuser(string usname, string pswd)
{
    string tempid, temppswd;
    string myText;

    ifstream MyReadFile("C:\\Users\\canar\\source\\repos\\library management\\Debug\\login.txt");
    while (getline(MyReadFile, myText))
    {
        tempid = myText;
        getline(MyReadFile, myText);
        temppswd = myText;
        if (usname == tempid && pswd == temppswd)
            return 1;
    }
    return 0;
}