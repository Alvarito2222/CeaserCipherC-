//Alvaro Leon Parra  - Caesar Cipher

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string encrypt(string plaintext, int key) {						// Function for encryption
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            if (isupper(c)) {			
                c = (c + key - 65) % 26 + 65;
            } else {
                c = toupper((c + key - 97) % 26 + 65);
            }
            ciphertext += c;
        }// else if (isspace(c)) {
       //     ciphertext += c;
       // }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int key) {				// Function for decryption
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
      //  if (isspace(c)) {
      //      ciphertext += c;
       // }
        if (!isalpha(c)) {
            continue;
        }
        
        if (isupper(c)) {
            c = tolower((c - key - 65 + 26) % 26 + 97);
        } else {
            c = (c - key - 97 + 26) % 26 + 97;
        }
        plaintext += c;
        }
    return plaintext;
}


int main() {
    int key=0;
    int answer;
    
    
	do 																							
 	{
		system("CLS");
 		cout << "1. Encrypt " << endl;
    	cout << "2. Decrypt " << endl;
    	cout << "What would you like to do?[1][2]: " ;
		cin >> answer;																		// stores the answer into answer which will be used later 
 		cin.clear();                   													   //clear bad input flag
        cin.ignore(1000, '\n');        													//discard input
	}while(answer !=2 && answer!=1);												// if its not 2,1 the program will run again deliting everything else from the input flag
	
	
	system("CLS");
	
	
	cout  << "Enter key (1-25): "  ;
	cin >> key;
	cin.clear();                   															 //clear bad input flag
    cin.ignore(1000, '\n');
    if(key < 1 || key >25){
	
    do
	{
		system("CLS");
        cout  << "Invalid key. Enter key (1-25): ";       
		cin >> key;
		cin.clear();                   															 //clear bad input flag
        cin.ignore(1000, '\n');
    }while (key < 1 || key > 25);
    
	}
   
    
    
    cout <<  endl;
    
    if (answer == 1)
	{
    	cout << endl;
    	string plaintext, ciphertext;
    	cout << "Enter plaintext: ";
    	//cin.ignore();
    	getline(cin, plaintext);
    	ciphertext = encrypt(plaintext, key);
    	cout << "Ciphertext: ";
    	for (int i = 0; i < ciphertext.length(); i++) 
		{
        	cout << ciphertext[i];
        	if ((i + 1 ) % 5 == 0) 										// After 5 letters , it does a space 
			{
            	cout << " ";
        	}		
    	}
	}
	else if (answer == 2)
	{
    	cout << endl;
    	string plaintext, ciphertext;
    	cout << "Enter ciphertext: ";
    	//cin.ignore();
    	getline(cin, ciphertext);
    	plaintext = decrypt(ciphertext, key);
    	cout << "Plaintext: ";
    	for (int i = 0; i < plaintext.length(); i++) 
		{
    	    cout << plaintext[i];
    	    if ((i +1) % 5 == 0) 								// After 5 letters , it does a space 
			{
    	        cout << " ";
    	    }
    	}
    }
    	cout << endl;
    	return 0;
}

