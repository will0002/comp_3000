//Name: Will Parker 
////filename: hw3.cpp 
////Development Environment: vim, g++, Linux 
////Compile: g++ -o template template.cpp 
////Sample usage: ./hw3
////Compiler pre-directives  #include <iostream> 
#include <iostream>
#include <iomanip>
using namespace std;
///Begin writing functions
int main () { 
double interestRate, balance, interest, monthlyPayments;
double principal, totalInterest = 0.0;
int month = 0;

//recieves inputs
cout << fixed;
cout << setprecision(2);
cout << "Loan Amount: ";
cin >> balance; 
cout << "Interest Rate (% per year): ";
cin >> interestRate;
cout << "Monthly Payments: ";
cin >> monthlyPayments;

interestRate = interestRate/12.0;
interest = balance * interestRate * .01;

if(interest > monthlyPayments){
	cout << "You will never pay off your loan." <<endl;
	return 0;
	}

//Sets up header and first line
cout << "******************************************************\n";
cout << "	Amortization Table\n"; 
cout << "******************************************************\n";
cout << "Month	Balance	Payment	Rate	Interest Principal\n";
cout << month << "	$" << balance << " N/A	N/A	N/A	N/A\n";

//begins iterations
while(balance > monthlyPayments){
month++;
balance = balance + interest;

principal = monthlyPayments - interest;
balance = balance - monthlyPayments;
totalInterest = totalInterest + interest;
cout << month << "	$" << balance << "	$" << monthlyPayments 
<<"	" <<interestRate <<"	$" << interest 
<< "	$" << principal << endl;
interest = balance * interestRate * .01;
}

month++;
monthlyPayments = balance + interest;
principal = balance;
balance = 0.0;
totalInterest = totalInterest + interest;
cout << month << "	$" << balance << "	$" << monthlyPayments 
<<"	" <<interestRate <<"	$" << interest 
<< "	$" << principal << endl;

cout << "******************************************************" <<endl <<endl;
cout << "It takes " << month << " months to pay off the loan." << endl;
cout << "Total interest paic is: $" << totalInterest <<endl;

return 0;
}



