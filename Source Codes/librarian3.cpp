#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include "viewAll.h"
#include "checkadmin.h"
#include "checkuser.h"

using namespace std;

int main()
{
	string password;
	string username;
	while (1)
	{
		int log;
		cout << "Enter 1 for login and 2 for Exit:";
		cin >> log;
		if (log == 1)
		{
			cout << "Enter username:";
			cin >> username;
			cout << "Enter Password:";
			cin >> password;
			int count=0;
			if (checkadmin(username, password))
			{
				cout << "Login success";
				while (1)
				{
					int ch;
					cout << "\nEnter the choice \n1. View 2. Update 3. Add 4. Delete 5.User list 0.Logout::\n";
					cin >> ch;
					if (ch == 1) //VIEW
					{
						viewAll();
					}
					else if (ch == 2) //UPDATE
					{
						string b1,b2,b3,b4,n1,n2,n3,n4,s1,s2;
						cout << "Enter the book id:";
						getline(cin >> ws, b1);
						cout << "Enter the book name:";
						getline(cin >> ws, b2);
						cout << "Enter the book author name:";
						getline(cin >> ws, b3);
						cout << "Enter the book quantity:";
						getline(cin >> ws, b4);
						
						s1=b1+","+b2+","+b3+","+b4;

						cout << "\n\nEnter the new book id:";
						getline(cin >> ws, n1);
						cout << "Enter the new book name:";
						getline(cin >> ws, n2);
						cout << "Enter the new book author name:";
						getline(cin >> ws, n3);
						cout << "Enter the new book quantity:";
						getline(cin >> ws, n4);

						s2 = n1+","+n2+","+n3+","+n4;

						ostringstream text;
						ifstream in_file("test.csv");

						text << in_file.rdbuf();
						string str = text.str();
						string search = s1;
						string replace = s2;
						size_t pos = str.find(search);
						str.replace(pos, string(search).length(), replace);
						//in_file.close();

						ofstream out_file("test.csv");
						out_file << str;
					}
					
					else if (ch == 3) //ADD
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
						}
						string s3, s4;
						int n = array.size();
						int count = stoi(array[n - 1][0]), quantity;

						cout << "Enter a new book:";
						getline(cin >> ws, s3);
						cout << "Enter the Author name:";
						getline(cin >> ws, s4);
						cout << "Enter the quantity:";
						cin >> quantity;
						string filename("test.csv");
						ofstream file_out;
						file_out.open(filename, std::ios_base::app);
						file_out << "\n"
								 << ++count << "," << s3 << "," << s4 << "," << quantity;
					}
					else if (ch == 4) //DELETE
					{
						string del;
						string b1,b2,b3,b4,n1,n2,n3,n4,s1,s2;
						cout << "Enter the book id:";
						getline(cin >> ws, b1);
						cout << "Enter the book name:";
						getline(cin >> ws, b2);
						cout << "Enter the book author name:";
						getline(cin >> ws, b3);
						cout << "Enter the book quantity:";
						getline(cin >> ws, b4);
						
						del=b1+","+b2+","+b3+","+b4;

						ostringstream text;
						ifstream in_file("test.csv");
						string empty;
						text << in_file.rdbuf();
						string str = text.str();
						string str_search = del;
						string str_replace = empty;
						size_t pos = str.find(str_search);
						str.replace(pos, string(str_search).length(), str_replace);
						in_file.close();
						ofstream out_file("test.csv");
						out_file << str;
					}
					else if (ch == 5) //USERLIST
					{
						string myText;

						ifstream MyReadFile("C:\\Users\\canar\\source\\repos\\library management\\Debug\\login.txt");
						while (getline(MyReadFile, myText))
						{
							cout << myText << "\n";
							getline(MyReadFile, myText);
							string ss = myText;
						}
					}
					else if (ch == 0)
					{
						cout << "Logout...\n";
						break;
					}
					else
						cout << "You have entered a wrong Number\n";
					count = count + 1;
				}
			}
			else if (checkuser(username, password))
			{
				cout << "Logged in as user\n";
				while (1)
				{
					int ch;
					cout << "\nEnter the choice \n1. View 2. Borrow 3. Return 4. My Books 0. Logout::\n";
					cin >> ch;
					if (ch == 1) //VIEW
					{
						viewAll();
					}
					else if (ch == 2) //BORROW
					{
						cout << "Borrow\n";
						fstream fin;
						fin.open("test.csv", ios::in);
						int bid, bid2;
						cout << "Enter the book id: ";
						cin >> bid;

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
						}
						for (int i = 0; i < array.size(); i++)
						{
							bid2 = stoi(array[i][0]);

							if (bid == bid2)
							{
								string txt;
								for (int j = 0; j < 3; j++)
								{
									cout << array[i][j];
									cout << ",";
									txt = txt + array[i][j] + ",";
								}

								int quant = stoi(array[i][3]) - 1;
								array[i][3] = to_string(quant);

								string fn = username + ".txt";
								ofstream myfile;
								myfile.open(fn, std::ios_base::app);
								myfile << txt << endl;
								cout << "\nBook Borrowed\n";

								ofstream thisfile("test.csv");

								for (size_t i = 0; i < array.size(); ++i)
								{
									for (size_t j = 0; j < array[i].size(); ++j)
									{
										thisfile << array[i][j] << ",";
									}
									thisfile << endl;
								}
							}
						}
					}
					else if (ch == 3) //RETURN
					{
						cout << "Return the book:\n";
						fstream fin;
						fin.open("test.csv", ios::in);
						int bid=0, bid2 = 0;
						cout << "Enter the book id: ";
						cin >> bid;

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
						}
						for (int i = 0; i < array.size(); i++)
						{
							if (bid == bid2)
							{
								string txt;
								for (int j = 0; j < 3; j++)
								{
									cout << array[i][j];
									cout << ",";
									txt = txt + array[i][j] + ",";
								}

								int quant = stoi(array[i][3]) + 1;
								array[i][3] = to_string(quant);

								string fn = username + ".txt";
								ostringstream text{};
								ifstream in_file(fn);

								text << in_file.rdbuf();
								string str = text.str();
								string search = txt;
								string replace = "";
								size_t pos = str.find(search);
								str.replace(pos, string(search).length(), replace);
								in_file.close();

								ofstream out_file(fn);
								out_file << str;

								ofstream thisfile("test.csv");

								for (size_t i = 0; i < array.size(); ++i)
								{
									for (size_t j = 0; j < array[i].size(); ++j)
									{
										thisfile << array[i][j] << ",";
									}
									thisfile << endl;
								}
								cout << "\nBook Returned\n";
							}
						}
					}
					else if (ch == 4)
					{
						cout << "mybooks";
						string fn = username + ".txt";
						string myText;

						ifstream MyReadFile(fn);
						while (getline(MyReadFile, myText))
						{
							if (myText.length() == 0)
								getline(MyReadFile, myText);
							cout << myText << "\n";
						}
						cout << endl;
					}
					else if (ch == 0)
					{
						cout << "Logout...\n";
						break;
					}
					else
					{
						cout << "You have entered a wrong Number\n";
						break;
					}
				}
			}
			else
			{
				cout << "Wrong credentials. Exiting...\n";
				exit(10);
			}
		}
		else
		{
			cout << "Exiting...";
			exit(10);
		}
	}
}