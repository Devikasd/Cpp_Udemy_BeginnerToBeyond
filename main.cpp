#include <iostream>
#include <string>

using namespace std;
// Section 10
// Challenge - 
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.
Reuse existing functionality in libraries and in the std::string class!
*/

int main() {
    
    string alphabet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {";XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
   
    string secret_message {};
    cout << "Enter your secret message : ";
    getline(cin, secret_message);
    
    string encrypted_message {};
    
    cout << "\nEncrypting message..." << endl;
    
    for (char c: secret_message) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            char new_char {  key.at(position) };
            encrypted_message += new_char;
        } else {
            encrypted_message += c;
        }
    }
    
    cout << "\nEncrypted message: " << encrypted_message << endl;
    
    string decrypted_message {};
    cout << "\nDecrypting message..." << endl;
    
//    for (char k: encrypted_message){
//        size_t EncryPos = key.find(k);
//        if (EncryPos != string::npos){
//        decrypted_message += alphabet.at(EncryPos);
//        }else{
//            decrypted_message += k;
//        }
//    }
    
    for (char c: encrypted_message) {
        size_t position = key.find(c);
        if (position != string::npos) {
            char new_char { alphabet.at(position) };
            decrypted_message += new_char;
        } else {
            decrypted_message += c;
        }
    }
    
    cout << "\nDecrypted message: " << decrypted_message << endl;
    
    cout << endl;
    return 0;
}
