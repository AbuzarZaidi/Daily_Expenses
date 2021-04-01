#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<iomanip>
using namespace std;
struct information
{
	string date = "";
	int amount = 0;
	string detail_of_amount = "";
};
void show_menu();
void input_in_file(string, information, string, string);
void display(string file_name, information x, string search ,string Name);
void main()
{
	int n = 1;
	while (n != 0)
	{
		show_menu();
		cout << "\nEnter 0 for close program else input any key to continue: " << endl;
		cin >> n;
	}
	system("pause");
}

// function for show menu
void show_menu()
{
	system("cls");
	information s;
	string fileName = "budget.txt", name = " ";
	string debit = "/d";
	string credit = "/c";

	int num = 0;
	cout << "\n                  --==========================--  Daily_Expenses  Menu  --==============================--\n\n" << endl;
	cout << " 1) Enter 1 for add Debit: " << endl;
	cout << " 2) Enter 2 for add credit: " << endl;
	cout << " 3) Enter 3 for display detail of debit: " << endl;
	cout << " 4) Enter 4 for display detail of credit: " << endl;
	cout << "\n    Enter: ";
	cin >> num;
	switch (num)

	{
	case 1:
		//input debit in file
		name = "Debit";
		input_in_file(fileName, s,debit,name);
		break;
	case 2:
		//add credit in file
		name = "Credit";
		input_in_file(fileName, s,credit,name);
		break;
	case 3:
		//output debit from file
		name = "Debit";
		display(fileName, s, debit,name);
		break;
	case 4:
		name = "Credit";
		display(fileName, s, credit,name);
		break;
	default:
		cout << "Wrong Entry!" << endl;
		break;
	}

}
//===========================

//input function

void input_in_file(string fileName, information x, string type, string Name )
{

	cin.ignore();
	cout << "Enter Date for "<<Name<<" Amount: " << endl;
	getline(cin, x.date);
	//cin >> num1.date;
	cout << "Enter "<< Name<<" Amount: " << endl;
	cin >> x.amount;
	cin.ignore();
	cout << "Enter Detail for "<< Name<<" Amount: " << endl;
	getline(cin, x.detail_of_amount);

	// input in file
	ofstream out(fileName, ios::app);
	out <<type<<"~" << x.date << "~" << x.amount << "~" << x.detail_of_amount << endl;
	out.close();

}

//output function
void display(string fileName, information x, string search, string Name)
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

		if (!fileType.empty()) {
			fileType.resize(fileType.size() - 1);
		}
		
			string date = "";
			c = '\0';
			while (c != '~') {
				date += myText[i];
				c = myText[i];
				i++;
			}
			if (!date.empty()) {
				date.resize(date.size() - 1);
			}
			string amount = "";
			c = '\0';
			while (c != '~') {
				amount += myText[i];
				c = myText[i];
				i++;
			}
			if (!amount.empty()) {
				amount.resize(amount.size() - 1);
			}
			stringstream ss;
			ss << amount;
			ss >> value;
			if (fileType == "/d")
			{
				Total -= value;
			}
			else if (fileType == "/c") {
				Total += value;
			}
			string detail_of_amount = "";
			for (i; i < myText.length(); i++) {
				detail_of_amount += myText[i];
			}
			if (search == fileType) {
			cout  << setw(12) << date << setw(20) << amount << "               " << detail_of_amount << endl;
		}
		else
		{
			continue;
		}
	}

	
	cout<<"\n\n\n"<<"Current Amount"<<Total<<endl;


	in.close();
}
