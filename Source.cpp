#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<iomanip>
using namespace std;
struct information
{
	string date = " ";
	int amount = 0;
	string detail_of_amount = " ";
};
void show_menu();
void input_in_file(string, string);
void display(string, string);
string trim(string);

//main function
void main()
{
	int n = 1,num=0;
	string fileName = "budget.txt", name = " ";
	while (n != 0)
	{
		show_menu();
		cin >> num;
		switch (num)
		{
		case 1:
			//input debit in file
			name = "Debit";
			input_in_file(fileName, name);
			break;
		case 2:
			//input credit in file
			name = "Credit";
			input_in_file(fileName, name);
			break;
		case 3:
			//output debit from file
			name = "Debit";
			display(fileName, name);
			break;
		case 4:
			//output credit from file
			name = "Credit";
			display(fileName, name);
			break;
		default:
			cout << "Wrong Entry!" << endl;
			break;
		}
		cout << "\nEnter 0 for close program else input any key to continue: " << endl;
		cin >> n;
	}
	system("pause");
}

// function for show menu
void show_menu()
{
	system("cls");
	cout << "\n                  --==========================--  Daily_Expenses  Menu  --==============================--\n\n" << endl;
	cout << " 1) Enter 1 for add Debit: " << endl;
	cout << " 2) Enter 2 for add credit: " << endl;
	cout << " 3) Enter 3 for display detail of debit: " << endl;
	cout << " 4) Enter 4 for display detail of credit: " << endl;
	cout << "\n    Enter: "<<endl;
}

//input function
void input_in_file(string fileName, string Name)
{
	information x;
	cin.ignore();
	cout << "Enter Date for " << Name << " Amount: " << endl;
	getline(cin, x.date);
	cout << "Enter " << Name << " Amount: " << endl;
	cin >> x.amount;
	cin.ignore();
	cout << "Enter Detail for " << Name << " Amount: " << endl;
	getline(cin, x.detail_of_amount);
	// input in file
	ofstream out(fileName, ios::app);
	out << Name << "~" << x.date << "~" << x.amount << "~" << x.detail_of_amount << endl;
	out.close();
}

//output function
void display(string fileName, string Name)
{
	system("cls");
	int Total = 0, value = 0;
	string myText = "";
	cout << "DetailType:  " << Name << endl << endl << endl;
	cout << setw(12) << "dd/mm/yyyy" << setw(20) << "amount" << "               detail" << endl;
	ifstream in(fileName);
	while (getline(in, myText)) {
		string fileType = "";
		int i = 0;
		char c = '\0';
		while (c != '~') {
			fileType += myText[i];
			c = myText[i];
			i++;
		}
		fileType = trim(fileType);  //trim function call
		string date = "";
		c = '\0';
		while (c != '~') {
			date += myText[i];
			c = myText[i];
			i++;
		}
		date = trim(date);   //trim function call
		string amount = "";
		c = '\0';
		while (c != '~') {
			amount += myText[i];
			c = myText[i];
			i++;
		}
		amount = trim(amount);   //trim function call
		stringstream ss;
		ss << amount;
		ss >> value;
		if (fileType == "Credit")
		{
			Total += value;
		}
		else if (fileType == "Debit") {
			Total -= value;
		}
		string detail_of_amount = "";
		for (i; i < myText.length(); i++) {
			detail_of_amount += myText[i];
		}
		if (Name == fileType) {
			cout << setw(12) << date << setw(20) << amount << "               " << detail_of_amount << endl;
		}
		else
		{
			continue;
		}
	}
	cout << "\n\n\n" << "Current Amount:" << Total << endl;
	in.close();
}

//trim function
string trim(string entry) {
	if (!entry.empty()) {
		entry.resize(entry.size() - 1);
	}
	return entry;
}
