#include <iostream>
#include <iomanip>
#include <string> 
#include <sstream>
using namespace std;

/*********** main ***********
Purpose: Check if the Visa card is valid 
Returns: Outputting a verdict as to the validity of the credit card
************************************/

int main () {
   string name;
   string ccnum;
   int expiry_month;
   int expiry_year;
   int transaction_number;
   int day;
   int month;
   int year;
   int time;
   double amount;
   string flag = "valid";
   

while(getline (cin, name)){
   cin >> ccnum;
   cin >> expiry_month;
   cin >> expiry_year;
   cin >> transaction_number;
   cin >> day;
   cin >> month;
   cin >> year;
   cin >> time;
   cin >> amount;

   if ( ccnum[0] != '4') flag = "invalid";
     
   else if ( ccnum.length() != 13 &&  ccnum.length() != 16 ) flag = "invalid";
      
   else 
   {
	int len = ccnum.length();
	int sum = 0;
	for (int i = len-1; i >= 0; i--) {
		int cc = ccnum[i] - 48; // convert char to int
		
		if ( (len%2 == 0 && i%2 == 0) || 
                     (len%2 != 0 && i%2 != 0)) 
                { // double the every second index of card number
		      cc *= 2;
		      if (cc > 9) cc -= 9;
		}//if 
		
		sum += cc;
	} //for
//	cout << "sum: " << sum << endl;	
	if (sum%10 != 0)  flag = "invalid";
	sum = 0;  

   } // else
 
	int min = time % 100;
	int hour = (time - time % 100) / 100;
	
	cout << right << setfill('0') << setw(5) << transaction_number <<" ";
	cout << setfill('0') << setw(2) << day   << "/";
        cout << setfill('0') << setw(2) << month << "/";
        cout << setfill('0') << setw(4) << year  << " ";
	cout << right << setfill('0') << setw(2) << hour  << ":";
	cout << right << setfill('0') << setw(2) << min;
	cout << " $"  << fixed << left << setprecision(2) << amount;
	cout << " ("  << ccnum << ", " << name << ", ";
        cout << right << setfill('0') << setw(2) << expiry_month;
	cout << "/"   << setfill('0') << setw(2) << expiry_year << ") ";
        cout << flag  << endl;    
   	
	cin.ignore();
	flag = "valid";
	} // while
} // main
