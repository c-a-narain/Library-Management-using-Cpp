#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<string>> array;
    vector<string> v;

    ifstream in("test.csv");

    string line, field;
    while (getline(in, line))
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss, field, ','))
        {
            v.push_back(field);
        }

        array.push_back(v);

        ofstream myfile;
        myfile.open("newest.csv");
        for (int n = 0; n < array.size(); ++n)
        {
            for(int i=0;i<array.size();++i){
                myfile << array[n][i]<<endl;
            }
        }
    }
}