#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void unique_ptr_fun(){
    //unique_ptr <int>ptr(new int);
    unique_ptr <int>ptr = make_unique<int>();
    int* raw_ptr = ptr.get();

    *raw_ptr = 100;
    cout<<*raw_ptr<<" or "<<*ptr<<endl;
    //unique_ptr <int>new_ptr(ptr);=>Error
    //unique_ptr <int>new_ptr(move(ptr));=>Works
    //here new_ptr becomes the owner and ptr gets reset hence maintaining the uniqueness

    ptr.reset();//raw pointer held by ptr will point to nullptr and delete is performed
}

void unique_ptr_array1_fun(){
    unique_ptr <int[]>array_ptr = make_unique<int[]>(10);
    int *raw_array_ptr = array_ptr.get();
    for(int i = 0; i < 10; i++)raw_array_ptr[i] = i+1;
    for(int i = 0; i < 10; i++)cout<<array_ptr[i]<<" ";

    cout<<endl;
}

/*
main->
[
 (sub1)int* -> [int, int, int]            or [1,2,3]
 (sub2)int* -> [int, int, int, int, int]  or [2,4,6,8,10]
 (sub3)int* -> [int, int, int, int]       or [3,6,9,12]
]

*/
void unique_ptr_array2_fun(){
    unique_ptr <int *[]>array_ptr_main = make_unique<int *[]>(3);
    int **raw_array_ptr_main = array_ptr_main.get();
    unique_ptr <int[]>array_ptr_sub1 = make_unique<int[]>(3);
    unique_ptr <int[]>array_ptr_sub2 = make_unique<int[]>(5);
    unique_ptr <int[]>array_ptr_sub3 = make_unique<int[]>(4);

    int *raw_array_ptr_sub1 = array_ptr_sub1.get();
    int *raw_array_ptr_sub2 = array_ptr_sub2.get();
    int *raw_array_ptr_sub3 = array_ptr_sub3.get();

    for(int i = 0; i < 3; i++)array_ptr_sub1[i] = (i+1)*1;
    for(int i = 0; i < 5; i++)array_ptr_sub2[i] = (i+1)*2;
    for(int i = 0; i < 4; i++)array_ptr_sub3[i] = (i+1)*3;

    array_ptr_main[0] = raw_array_ptr_sub1;
    array_ptr_main[1] = raw_array_ptr_sub2;
    array_ptr_main[2] = raw_array_ptr_sub3;

    cout<<array_ptr_main[0][0]<<" ";
    cout<<array_ptr_main[0][1]<<" ";
    cout<<array_ptr_main[0][2]<<endl;

    cout<<array_ptr_main[1][0]<<" ";
    cout<<array_ptr_main[1][1]<<" ";
    cout<<array_ptr_main[1][2]<<" ";
    cout<<array_ptr_main[1][3]<<" ";
    cout<<array_ptr_main[1][4]<<endl;

    cout<<array_ptr_main[2][0]<<" ";
    cout<<array_ptr_main[2][1]<<" ";
    cout<<array_ptr_main[2][2]<<" ";
    cout<<array_ptr_main[2][3]<<endl;
}

void unique_ptr_vector_fun(){
    vector <unique_ptr<int>>my_vector;

    unique_ptr <int>ptr = make_unique<int>(12);
    //my_vector.push_back(ptr); doesn't work as copy constructor is called
    //and hence the uniqueness of unique pointer will go
    my_vector.push_back(move(ptr));//the one inside the vector becomes the owner
    //of ptr and current ptr will be reset 
    my_vector.push_back(make_unique<int>(15));
    my_vector.push_back(make_unique<int>(19));
    my_vector.push_back(make_unique<int>(5));
    my_vector.push_back(make_unique<int>(6));
    my_vector.push_back(make_unique<int>(8));

    //for(auto ptr:my_vector)cout<<*ptr<<" "; Doesn't work because
    //everytime copy constructor will be called hence uniqueness will go
    for(auto &ptr:my_vector)cout<<*ptr<<" ";

    cout<<endl;
}

void shared_ptr_fun(){
    shared_ptr <int>ptr = make_shared<int>(12);
    shared_ptr <int>ptr1{ptr};
    shared_ptr <int>ptr2;
    ptr2 = ptr1;
    //ptr2,ptr1 & ptr are pointing to same location
    cout<<*ptr2<<endl;
    cout<<"How many pointers are pointing to 12 = "<<ptr.use_count()<<endl;
}

void shared_ptr_vector_fun(){
    vector <shared_ptr<int>>my_vector;
    shared_ptr <int>ptr = make_shared<int>(10);
    my_vector.push_back(ptr);//no error
    my_vector.push_back(make_shared<int>(5));
    my_vector.push_back(make_shared<int>(9));
    my_vector.push_back(make_shared<int>(3));
    my_vector.push_back(make_shared<int>(8));

    for(shared_ptr <int>ptr:my_vector)cout<<*ptr<<" ";
    //for(auto &ptr:my_vector)cout<<*ptr<<" ";also works

    cout<<endl;
}


/*
Section Challenge
compute the make, fill and display functions
*/
class Test{
    private:
        int data;

    public:
        Test(int data = 0):data{data}{}
        int get_data(){return data;}
};

unique_ptr<vector<shared_ptr<Test>>>make();
void fill(vector<shared_ptr<Test>> &vec, int value);
void display(const vector<shared_ptr<Test>> &vec);


unique_ptr<vector<shared_ptr<Test>>> make(){
    unique_ptr <vector<shared_ptr<Test>>>new_ptr = make_unique<vector<shared_ptr<Test>>>();
    return new_ptr;
}
void fill(vector<shared_ptr<Test>> &vec, int value){
    for(int i = 1; i <= value; i++){
        cout<<"Enter value "<<i<<" = ";
        int new_value;
        cin>>new_value;
        shared_ptr <Test>new_ptr = make_shared<Test>(Test(new_value));
        vec.push_back(new_ptr);
    }
}
void display(const vector<shared_ptr<Test>> &vec){
    for(shared_ptr <Test>obj:vec){
        cout<<obj->get_data()<<" ";
    }
    cout<<endl;
}   
void section_challenge(){
    unique_ptr <vector<shared_ptr<Test>>>vec_ptr;
    vec_ptr = make();
    cout<<"Enter how many values to fill=";
    int num;
    cin>>num;
    fill(*vec_ptr,num);
    display(*vec_ptr);
}

int main(){
    section_challenge();
    return 0;
}