/*
P- print numbers
A- add a number
M- Display mean of numbers
S- Display the smallest number
L- Display the largest number
Q- Quit
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print_vector(vector <int>&my_vector){
    cout<<"List elements are [";
    for(int value:my_vector){
        cout<<value<<" ";
    }
    cout<<"]"<<endl;
}

void add_number(vector <int>&my_vector){
    int value_to_add;
    cout<<"Enter the value to add to the list = ";
    cin>>value_to_add;
    my_vector.push_back(value_to_add);
    cout<<"Pushed value successfully"<<endl;
}

void display_mean(vector <int>&my_vector){
    if(my_vector.size() == 0){
        cout<<"Empty list"<<endl;
        return;
    }
    double sum = 0;
    

    for(auto value:my_vector)
        sum+=value;

    cout<<"Mean = "<<(sum/my_vector.size())<<endl;
}

void display_small(vector <int>&my_vector){
    if(my_vector.size() == 0){
        cout<<"Empty list"<<endl;
    }
    else{
        int min = my_vector.at(0);
        for(int value:my_vector){
            if(value < min){
                min = value;
            }
        }
        cout<<"Min value = "<<min<<endl;
    }

}

void display_large(vector <int>&my_vector){
    if(my_vector.size() == 0){
        cout<<"Empty list"<<endl;
    }
    else{
        int max = my_vector.at(0);
        for(int value:my_vector){
            if(value > max){
                max = value;
            }
        }
        cout<<"Max value = "<<max<<endl;
    }

}

void quit_or_not(bool &flag){
    char selection;
    cout<<"Please enter N to quit & any other character to continue= ";
    cin>>selection;

    if(selection == 'n' || selection == 'N'){
        flag = true;
    }
}

void fun_operations(){
    vector <int>my_vector;

    while(1){
        bool quit_flag = false;
        cout<<"\n\n"
        "Choose any of the following options\n"
        "P- print numbers\n"
        "A- add a number\n"
        "M- Display mean of numbers\n"
        "S- Display the smallest number\n"
        "L- Display the largest number\n"
        "Q- Quit"<<endl;

        char option_selected;
        cin>>option_selected;

        switch(option_selected){
            case 'P' : 
            case 'p' :  print_vector(my_vector);quit_or_not(quit_flag);break;
            case 'A' :
            case 'a' :  add_number(my_vector);quit_or_not(quit_flag);break;
            case 'M' :
            case 'm' :  display_mean(my_vector);quit_or_not(quit_flag);break;
            case 'S' :
            case 's' :  display_small(my_vector);quit_or_not(quit_flag);break;
            case 'l' :
            case 'L' :  display_large(my_vector);quit_or_not(quit_flag);break;
            case 'Q' :
            case 'q' :  quit_flag = true;break;  
            default :   cout<<"Unknown selection"<<endl;
                        break;
        }
        if(quit_flag)break;
    }
}

int main(){
    fun_operations();
    return 0;
}