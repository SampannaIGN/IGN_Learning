#include <iostream>

using namespace std;
  
void print_spaces(int value,string str){
    for(int j = 0; j < value;j++)
        cout<<str;
}

void create_pyramid(string input){
    int length = input.length();
    if(length == 0)return;

    string result = "";
    result += input.at(0);

    int last_line_length = (2*length)-1;
    print_spaces((last_line_length-result.length())/2," ");
    cout<<result<<endl;

    for(int i = 1; i < length; i++){
        string sub_str = "";
        sub_str += input.at(i);
        sub_str += input.at(i-1);
        result = result.substr(0,i)+sub_str+result.substr(i);

        print_spaces((last_line_length-result.length())/2," ");
        cout<<result<<endl;
    }

}

void print_pyramid(){
    string input;
    cout<<"Enter string to create a pyramid = ";
    cin>>input;
    create_pyramid(input);
}


int main(){
    print_pyramid();
    return 0;
}