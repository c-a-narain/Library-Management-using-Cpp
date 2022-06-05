#include<bits/stdc++.h>
#include "viewAll.h"

using namespace std;

void viewAll()
{
    string myText;

    ifstream MyReadFile("test.csv");
    while (getline(MyReadFile, myText))
    {
        if (myText.length() == 0)
            getline(MyReadFile, myText);
        cout << myText << "\n";
    }
    cout << endl;
}