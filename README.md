# credit_card_validation

Introduction:
	
	This is a program that will process a series of zero or more credit card transactions by reading in the transaction record from standard input, validating the credit card, and then outputting a verdict as to the validity of the credit card.
	The program will only validate VISA card numbers for now. VISA card numbers start with the digit `4', and are either 13 or 16 digits in length.


Format:
	
	A transaction record consists of the following fields, one per line:
		1. name on the credit card i.e. rst name, optional initial, last name e.g. Jane A. Qiu, Fred Smith
		2. credit card number e.g. 45567375868998551
		3. card expiry date (1- or 2-digit month [space] 2-digit year), [space], transaction number(positive integer, up to 5 digits in length),[space] , date (day [space] month [space] year), time (24-hour time), [space] and amount e.g. 05 18 00001 25 05 2015 2105 45.03

Example:
	
	The card number is validated by applying the Luhn algorithm. For example, consider the following 16-digit number 4556737586899855.
		(1) If the first digit isn't a 4, the card is invalid.
		(2) If the length of the card number is neither 13 nor 16, the card is invalid.
		(3) The rightmost digit is the check digit. In the example, this is the digit 5. Starting from the check digit and moving to the left, double every second digit (marked in bold). The number 4556737586899855 now becomes i.e. 8,5,10,6,14,3,14,5,16,6,16,9,18,8,10,5.
		(4) For each number over 9, add together the digits of the product. The number now becomes 8,5,1+0,6,1+4,3,1+4,5,1+6,6,1+6,9,1+8,8,1+0,5 = 8,5,1,6,5,3,5,5,7,6,7,9,9,8,1,5
		(5) Add all numbers together. The sum is 90.
		(6) Calculate the result of the sum modulo 10 i.e. 90 modulo 10 = 0.
		(7) If the result is 0, the card number is valid.

Output:
	
	00001 25/05/2015 21:00 $45.03 (4556737586899855, Jane A. Qiu, 05/18) valid[newline]
	00001 25/05/2015 21:00 $45.03 (4556737586899856, Fred Smith, 05/18) invalid[newline]
