// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
using namespace std;

// Global Constant Initialization
const string TITLE = "Forrest's Greenbacks Banking Program";
const string AUTHOR_LINE = "By Forrest Moulin";
const string DECIMAL_FORMAT_PROMPT =
"Please enter the transaction amount in decimal format";
const string DEP_WITH_PROMPT =
"(Positive for Deposit, Negative for Withdrawal)";

// Function prototype(s) to notify compiler
void tableDivider(int tableWidth);
void transactionPrompt();
double processTransaction();
bool moreTransactions();

// Main function (returns 0 to exit)
int main()
{
	// Dynamic Variable Initialization
	double balance = 0.0;
	bool keepLooping = 1;

	cout << TITLE << endl
		<< AUTHOR_LINE << endl;
	tableDivider(DECIMAL_FORMAT_PROMPT.length());

	// Function calls when bool is true (1)
	balance = processTransaction();
	while (keepLooping == 1) {
		// Bool value set to result of user input
		// via moreTransactions function
		keepLooping = moreTransactions();
		// If the answer is n (0/false)
		if (keepLooping == 0)
		{
			// Break the while loop to show 
			// ending balance
			break;
		}
		tableDivider(DECIMAL_FORMAT_PROMPT.length());
		// Update balance with next transaction
		balance = processTransaction();
	}
	// Print at end of program run
	cout << "Ending balance: $" << balance << endl;
}

// Other function definitions
void tableDivider(int tableWidth)
{
	cout << setw(tableWidth)
		<< setfill('-') << "" 
		<< endl;
}

void transactionPrompt()
{
	cout << DECIMAL_FORMAT_PROMPT
		<< endl
		<< DEP_WITH_PROMPT
		<< endl << endl;
}

double processTransaction()
{
	static double transactionAmount;
	static double accountBalance;
	// Withdrawal - true, deposit - false
	static bool withdrawalOrDeposit;
	static bool validEntry;
	static bool sufficientFunds;

	cout << fixed << setprecision(2) 
		 << "Current balance: $"
		<< accountBalance << endl << endl;
	// Void function to prompt user
	transactionPrompt();

	// Loop while valid entry is false (0)
	while (validEntry != 1)
	{
		cout << "$";
		cin >> transactionAmount;
		cout << endl;
		if (transactionAmount < 0)
		{
			withdrawalOrDeposit = 1;
			validEntry = 1;
		}
		else if (transactionAmount > 0)
		{
			withdrawalOrDeposit = 0;
			validEntry = 1;
		}
		else {
			cout << "Invalid entry. Try again."
				<< endl;
		}
	}
	while (sufficientFunds != 1 && validEntry == 1)
	{
		// Withdrawal amount is more than balance
		if ((transactionAmount * (-1)) > accountBalance)
		{
			cout << "Insufficient funds." << endl
				<< "Please enter a withdrawal less than or equal to"
				<< endl << "the account balance, or make a deposit." 
				<< endl << endl << "$";
			cin >> transactionAmount;
			cout << endl;
		}
		else
		{
			accountBalance += transactionAmount;
			sufficientFunds = 1;
		}
	}
	// Reset bool value
	sufficientFunds = 0;
	validEntry = 0;
	return accountBalance;
}

// Function converts char entry to true/false values
bool moreTransactions()
{
	static bool moreTransactions;
	static bool boolCopy;
	static char yesOrNoChar;
	
	cout << "Do you need to conduct more transactions?"
		<< endl << "(Y for Yes, N for No)" << endl << endl;
	
	// Read char from user input
	cin >> yesOrNoChar;

	while (moreTransactions != 1)
	{   // User enters y for another transaction
		cout << endl;
		if (yesOrNoChar == 'y' || yesOrNoChar == toupper('y'))
		{
			moreTransactions = 1;
			cout << "Updating current balance..." << endl;
		}
		// User enters n to exit (no transaction)
		else if (yesOrNoChar == 'n' || yesOrNoChar == toupper('n'))
		{
			// End while loop
			cout << "Calculating ending balance..." << endl;
			tableDivider(DECIMAL_FORMAT_PROMPT.length());
			break;
		}
		// Handle invalid data entries
		else
		{
			cout << "Invalid entry. Please enter Y for Yes or N for No."
				<< endl << endl;
			cin >> yesOrNoChar;
		}
	}
	boolCopy = moreTransactions;
	// Reset the value to avoid infinite loop
	moreTransactions = 0;
	// Return copy of the bool (value prior to reset)
	return boolCopy;
}

/*
* CONSOLE OUTPUT
* Forrest's Greenbacks Banking Program
* By Forrest Moulin
* -----------------------------------------------------
* Current balance: $0.00
*
* Please enter the transaction amount in decimal format
* (Positive for Deposit, Negative for Withdrawal)
*
* $-50
*
* Insufficient funds.
* Please enter a withdrawal less than or equal to
* the account balance, or make a deposit.
*
* $20
*
* Do you need to conduct more transactions?
* (Y for Yes, N for No)
*
* y
*
* Updating current balance...
* -----------------------------------------------------
* Current balance: $20.00
*
* Please enter the transaction amount in decimal format
* (Positive for Deposit, Negative for Withdrawal)
*
* $100
*
* Do you need to conduct more transactions?
* (Y for Yes, N for No)
*
* y
*
* Updating current balance...
* -----------------------------------------------------
* Current balance: $120.00
*
* Please enter the transaction amount in decimal format
* (Positive for Deposit, Negative for Withdrawal)
*
* $55
*
* Do you need to conduct more transactions?
* (Y for Yes, N for No)
*
* y
*
* Updating current balance...
* -----------------------------------------------------
* Current balance: $175.00
*
* Please enter the transaction amount in decimal format
* (Positive for Deposit, Negative for Withdrawal)
*
* $-23.67
*
* Do you need to conduct more transactions?
* (Y for Yes, N for No)
*
* y
*
* Updating current balance...
* -----------------------------------------------------
* Current balance: $151.33
*
* Please enter the transaction amount in decimal format
* (Positive for Deposit, Negative for Withdrawal)
*
* $-51.33
*
* Do you need to conduct more transactions?
* (Y for Yes, N for No)
* 
* n
*
* Calculating ending balance...
* -----------------------------------------------------
* Ending balance: $100.00
*/
