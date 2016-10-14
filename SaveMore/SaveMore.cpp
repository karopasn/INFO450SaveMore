// SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class account
{
public:
	void displayAccount();
	virtual int withdraw(double wdollar);
	virtual int desposit(double ddollar);
	const char *accntName = new char[50];
	const char *accntNumber = new char[50];
	double interest = 0;
	double balance = 0;

};

void account :: displayAccount()
{
	cout << "Account Name: " << accntName << endl;
	cout << "Your Interest: " << interest << "%" << endl;
	cout << "Your Balance: " << balance << endl;
}

int account::withdraw(double wdollar)
{
	if (wdollar < 0)
	{
		cout << "You have no money in your account" << endl;
		return(-1);
	}
	else if (wdollar > balance)
	{
		cout << "You cannot withdraw more than what you have in your balance" << endl;
		return(-1);
	}
	else
	{
		balance -= wdollar;
		return(0);
	}
}
int account::desposit(double ddollar)
{
	if (ddollar < 0)
	{
		cout << "Can't take negative amount" << endl;
		return(-1);
	}
	else
	{
		balance += ddollar;
	}
}

class saving : public account
{
public:
	saving()
	{
		accntName = "Savings";
	}
	void checkbalance()
	{
		if (balance >= 10000)
		{
			interest = 2;
		}
		else
		{
			interest = 1;
		}
	}
	void compnd()
	{
		balance = balance + (balance * (interest/100) / 12);
		checkbalance();
	}
	int withdraw(double wdollar)
	{
		account::withdraw(wdollar);
		checkbalance();
		return 0;
	}
	int deposit(double ddollar)
	{
		account::desposit(ddollar);
		checkbalance();
		return 0;
	}
};
class checking : public account
{
public:
	checking()
	{
		accntName = "Checking account";
	}
	void checkbalance()
	{
		if (balance < 500)
		{
			balance = balance - 5;
			cout << "$5 has been deducted due to balance being lower than 500" << endl;
		}
	}
	void orderCheck()
	{
		balance = balance - 15;
	}
	int withdraw(double wdollar)
	{
		account::withdraw(wdollar);
		checkbalance();
		return 0;
	}
	int deposit(double ddollar)
	{
		account::desposit(ddollar);
		checkbalance();
		return 0;
	}
};
class cd : public account
{
public:
	int trm;
	void chktrm(int term)
	{
		if (term >= 5)
		{
			interest = 10;
		}
		else
		{
			interest = 5;
		}
	}
	cd(int term)
	{
		accntName = "Certificate of Deposit";
		chktrm(term);
		trm = term;
	}
	void compnd()
	{
		balance = balance + (balance * (interest/100) / 12);
	}
	void penalty(int p)
	{
		if (p == 1)
		{
			balance = balance - (balance *0.10);
		}
	}
	int withdraw(double wdollar)
	{
		account::withdraw(wdollar);
		chktrm(trm);
		return 0;
	}
	int deposit(double ddollar)
	{
		account::desposit(ddollar);
		chktrm(trm);
		return 0;
	}
};
int main()
{
	saving newSave;
	newSave.deposit(10000);
	checking newCheck;
	newCheck.deposit(600);
	cd newCD(3);
	newCD.deposit(10000);
	newSave.displayAccount();
	newCheck.displayAccount();
	newCD.displayAccount();
	newSave.compnd();
	newCD.compnd();
	newSave.displayAccount();
	newCD.displayAccount();
	newCheck.orderCheck();
	newCheck.withdraw(200);
	newSave.withdraw(1000);
	newCD.withdraw(2000);
	newSave.displayAccount();
	newCheck.displayAccount();
	newCD.displayAccount();

	system("pause");
	return 0;
}

