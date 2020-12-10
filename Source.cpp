#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct information
{
	string date;
	int amount;
	string detail_of_amount;
};
void show_menu();
void input_debit_file();
void output_debit_file(information x);
void input_credit_file();
void output_credit_file(information y);
int input_current_balance_file();
void output_current_balance_file();
void debit();
void credit();
void history();
void current_balance();


//   main_function
int main()
{
	int n = 1;
	while (!n == 0)
	{
		show_menu();
		cout << "\nEnter 0 for close program else input any key to continue: " << endl;
		cin >> n;
	}
	system("pause");
	return 0;
}
//======================


// function for show menu
void show_menu()
{
	system("cls");
	int num;
	cout << "\n                  --==========================--  Daily_Expenses 2.0 Menu  --==============================--\n\n" << endl;
	cout << " 1) Enter 1 for add Debit: " << endl;
	cout << " 2) Enter 2 for add credit: " << endl;
	cout << " 3) Enter 3 for show detail: " << endl;
	cout << " 4) Enter 0 for show Current Balance: " << endl;
	cout << "\n    Enter: ";
	cin >> num;
	switch (num)

	{
	case 1:
		debit();
		break;
	case 2:
		credit();
		break;
	case 3:
		history();
		break;
	case 0:
		current_balance();
		break;
	}

}
//===========================


// functions for current balance file
void output_current_balance_file(int output_value)
{
	ofstream out("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\current_balance.txt");
	//ofstream out("current_balance.txt");
	out << output_value;
	out.close();
}

int input_current_balance_file()
{
	int input;
	ifstream in("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\current_balance.txt");
	//ifstream in("current_balance.txt");
	in >> input;
	return input;
	in.close();
}
//===============================================


// functions for debit file
void output_debit_file(information x)
{

	ofstream out("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\debit.txt", ios::app);
	//ofstream out("debit.txt", ios::app);
	out << " " << x.date << " " << x.amount << " " << x.detail_of_amount << endl;


	out.close();
}
//extra code
/*void input_debit_file()
{
ifstream in("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\debit.txt");
}*/
//====================================
// functions for credit file.
void output_credit_file(information y){


	ofstream out("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\credit.txt", ios::app);
	//ofstream out("credit.txt",ios::app);
	out << " " << y.date << " " << y.amount << " " << y.detail_of_amount << endl;


	out.close();


}

//=====================================


// 1) debit function============
void debit()
{
	int total = 0, show;
	information num1;
	show = input_current_balance_file();

	// input value==========
	cin.ignore();
	cout << "Enter Date for Debit Amount: " << endl;
	getline( cin,num1.date);
	//cin >> num1.date;
	cout << "Enter Debit Amount: " << endl;
	cin >> num1.amount;
	cin.ignore();
	cout << "Enter Detail for Debit Dmount: " << endl;
	getline( cin,num1.detail_of_amount);
	//cin >> num1.detail_of_amount;
	//============= end of input value

	//==to calculate current balance
	total = show - num1.amount;
	output_current_balance_file(total);
	//======
	// send data to debit file
	output_debit_file(num1);




	//show enter detail on screen
	cout << "Enter date is:  " << num1.date << endl;
	cout << "Enter amount is: " << num1.amount << endl;
	cout << "Enter detail is: " << num1.detail_of_amount << endl;
}
//==========================


// 2) credit =============
void credit()
{
	int total = 0, show;
	information num1;
	show = input_current_balance_file();

	// input value==========
	cin.ignore();
	cout << "Enter date for Credit Amount: " << endl;
	getline( cin,num1.date);
	//cin >> num1.date;
	cout << "Enter Credit Amount: " << endl;
	cin >> num1.amount;
	cin.ignore();
	cout << "Enter Credit Amount Source: " << endl;
	getline(cin, num1.detail_of_amount);
	//cin >> num1.detail_of_amount;
	//============= end of input value

	//==to calculate current balance
	total = num1.amount + show;
	output_current_balance_file(total);
	//====================

	// send data to credit file
	output_credit_file(num1);

	//show enter detail on screen
	cout << "Enter date is:  " << num1.date << endl;
	cout << "Enter amount is: " << num1.amount << endl;
	cout << "Enter detail is: " << num1.detail_of_amount << endl;
}
//============================


//3) history
void history()
{
	system("cls");
	char ch;
	cout << "Enter c for credit history OR d for debit history: ";
	cin >> ch;
	if (ch == 'c')
	{
		information w;

		cout << setw(12) << "dd/mm/yyyy" << setw(20) << "amount"<< "               detail" << endl;
		ifstream in("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\credit.txt");
		//ifstream in("credit.txt");

		while (in >> w.date >> w.amount >> w.detail_of_amount)
		{
			in >> w.date >> w.amount >> w.detail_of_amount;
			cout << setw(12) << w.date << setw(20) << w.amount  <<"               " <<w.detail_of_amount << endl;
		}
		in.close();
	}
	else if (ch == 'd')
	{
		information w;

		cout << setw(12) << "dd/mm/yyyy" << setw(20) << "amount" << "               detail" << endl;
		ifstream in("c:\\Users\\T540\\Desktop\\c++\\project\\Daily_Expenses_2.0\\debit.txt");
		//ifstream in("debit.txt");

		//while (!in.eof())
		while (in >> w.date >> w.amount >> w.detail_of_amount)
		{
			in >> w.date >> w.amount >> w.detail_of_amount;
			cout << setw(12) << w.date << setw(20) << w.amount << "               " << w.detail_of_amount << endl;
		}
		in.close();
	}
	else
	{
		cout << "Incorrect character: " << endl;
	}
}




//==============================
// 4) current_balance
void current_balance()
{

	int show;
	show = input_current_balance_file();

	cout << "\n\nCurrent Amount is: " << show << endl;

}
//=======================
