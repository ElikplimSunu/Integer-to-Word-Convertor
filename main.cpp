/* C++ program to print a given number in words.*/
#include <iostream>
#include <stdlib.h>

using namespace std;


// strings at index 0 is not used, to make array indexing simple
string ones[] = { "", "ONE ", "TWO ", "THREE ", "FOUR ",

                 "FIVE ", "SIX ", "SEVEN ", "EIGHT ",

                 "NINE ", "TEN ", "ELEVEN ", "TWELVE ",

                 "THIRTEEN ", "FOURTEEN ", "FIFTEEN ",

                 "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",

                 "NINETEEN " };


// strings at index 0 and 1 are not used, to make array indexing simple
string tens[] = { "", "", "TWENTY ", "THIRTY ", "FORTY ",

                 "FIFTY ", "SIXTY ", "SEVENTY ", "EIGHTY ",

                 "NINETY " };


// n is one or two-digit number
string numberInWords(int placeValue, string placeSystem)
{

    //string to store the name in words
    string storeNameInWords = "";

    // if n is more than 19, divide it
    if (placeValue > 19)

        storeNameInWords += tens[placeValue / 10] + ones[placeValue % 10];

    else

        storeNameInWords += ones[placeValue];



    // if n is non-zero
    if (placeValue)
        storeNameInWords += placeSystem;


    return storeNameInWords;
}


// Function to print a given number in words
string convertToWords(unsigned long long int number)
{

    // stores word representation of given number n
    string store;


    // handles digits at hundred billions billion places (if any)
    store += numberInWords((number/100000000000), "HUNDRED AND " );


    // handles digits at ten and one billion places (if any)
    store += numberInWords((number/1000000000) % 100, "BILLION " );


    // handles digits at hundred millions places (if any)
    store += numberInWords((number/100000000) % 10, "HUNDRED AND " );


    // handles digits at ten and one millions places (if any)
    store += numberInWords((number/1000000) % 100, "MILLION " );




    // handles digits at hundred thousands and one
    // millions places (if any)
    store += numberInWords(((number / 100000) % 10), "HUNDRED AND ");



    // handles digits at thousands and tens thousands
    // places (if any)
    store += numberInWords(((number / 1000) % 100), "THOUSAND ");


    // handles digit at hundreds places (if any)
    store += numberInWords(((number / 100) % 10), "HUNDRED ");


    if (number > 100 && number % 100)

        store += "AND ";


    // handles digits at ones and tens places (if any)
    store += numberInWords((number % 100), "");


    return store;
}


// the Driver code
int main()
{
        char userInput;

    do{
            system("CLS");

    //variable to hold the user input
    unsigned long long int n;


    cout << "Please enter the number: ";

    // accepting the input
    cin >> n;



    // convert given number into words
    cout << endl << "The number " << n << " is: " << endl << convertToWords(n) << endl << endl;


    cout << "Would you like to run the program again? Press Y to run again and any other key to quit ";
    cin >> userInput;

    } while(userInput == 'y');


    return 0;
}
