/*
given keys and alphabets try encrypt & decrypt message given as input
*/

#include <iostream>

using namespace std;

string encryptString(const string input, const string &alphabet, const string &key){
    string result;
    for(char value:input){
        int index = alphabet.find(value);
        if(index == string::npos)
            result += value;
        else
            result += key.at(index);
    }

    return result;
}

string decryptString(const string input, const string &alphabet, const string &key){
    string result;
    for(char value:input){
        int index = key.find(value);
        if(index == string::npos)
            result += value;
        else
            result += alphabet.at(index);
    }
    return result;
}

void encryptDecrypt(){
    const string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string input;

    cout<<"Enter string to encrypt = ";
    getline(cin,input);
    cout<<"Encrypted string = "<<encryptString(input,alphabet,key)<<endl;

    cout<<"Enter string to decrypt = ";
    getline(cin,input);
    cout<<"Decrypted string = "<<decryptString(input,alphabet,key)<<endl;
}

int main(){
    encryptDecrypt();
    return 0;
}