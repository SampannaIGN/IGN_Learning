#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <algorithm>
#include <array>
#include <deque>
#include <set>
#include <stack>
#include <queue>
#include <numeric>//accumulate
//Note when using stl if you have any user defined classes please overload == and < operator

using namespace std;

void iterator_pbm1(){
    vector <int>my_vector{6,9,1,5,3,2,4,10};
    vector<int>::iterator itr = my_vector.begin();
    
    //traversing forward
    cout<<"traversing forward"<<endl;
    while(itr != my_vector.end()){
        cout<<*itr++<<" ";
    }
    itr = my_vector.end();
    cout<<endl;
    //traversing backward
    cout<<"traversing backwards"<<endl;
    while(itr != my_vector.begin()){
        cout<<*(--itr)<<" ";
    }

    itr = my_vector.begin();
    //incrementing all the elements by 1
    while(itr != my_vector.end()){
        ++(*itr);
        itr++;
    }
    cout<<"incremented using iterator"<<endl;

    // this iterator can't be modified
    vector <int>::const_iterator const_itr = my_vector.begin();//or my_vector.cbegin()
    //or auto const_itr = my_vector.cbegin();
    cout<<"using const_itr from start to end"<<endl;
    while(const_itr != my_vector.end()){
        cout<<*const_itr++<<" ";
    }
    cout<<endl;

    //this iterator goes reverse when incremented & goes normally when decremented
    vector <int>::reverse_iterator rev_itr = my_vector.rbegin();//basically points to end
    //or auto rev_itr = my_vector.rbegin();
    cout<<"using rev_itr from end to start"<<endl;
    while(rev_itr != my_vector.rend()){
        cout<<*rev_itr++<<" ";
    }
    cout<<endl;
    rev_itr = my_vector.rend();
    cout<<"using rev_itr from start to end"<<endl;
    while(rev_itr != my_vector.rbegin()){
        cout<<*--rev_itr<<" ";
    }
    cout<<endl;
}

void iterator_pbm2(){
    list <int>my_list{1,5,3,6,9};
    list<int>::iterator itr = my_list.begin();
    while(itr != my_list.end()){
        cout<<*itr++<<" ";
    }
    cout<<endl;
    int sum = accumulate(my_list.begin(),my_list.end(),0);//0->int sum 0.0->double sum
    cout<<"sum = "<<sum<<endl;
    
    reverse(my_list.begin(),my_list.end());
    itr = my_list.begin();
    while(itr != my_list.end()){
        cout<<*itr++<<" ";
    }
    cout<<endl;

    map <int,string>my_map{{8,"Sampu"},{5,"Streyz"},{3,"Manu"}};
    map <int,string>::iterator map_itr = my_map.begin();
    while(map_itr != my_map.end()){
        cout<<map_itr->first<<"="<<map_itr->second<<endl;
        map_itr++;
    }
}

bool above4(int value){
    if(value > 4)return true;
    else return false;
}

void algorithm_pbm1(){
    vector <int>vec{1,7,3,5,2,2,7,5,5,6};
    //returns iterator for first occurence of searched element
    //If user defined classes are used then == operator must be overloaded
    auto vec_itr = find(vec.begin(),vec.end(),5);
    cout<<"Itr found & it's index is "<<(vec_itr-vec.begin())<<endl;
    int occerence = count(vec.begin(),vec.end(),5);
    cout<<"5 occured these many no. of times = "<<occerence<<endl;
    //using lambda
    int even_occerence = count_if(vec.begin(),vec.end(),[](int x){return x%2!=0;});
    cout<<"Even number count  = "<<even_occerence<<endl;
    //without using lambda
    int occerence_above_4 = count_if(vec.begin(),vec.end(),above4);
    cout<<"count greater than 4 = "<<occerence_above_4<<endl;
    /*
    int fun(int *arr,int size,bool (*ptr)(int)){
        int count = 0;
        for(int i = 0; i < size; i++)
            if(ptr(arr[i]) == true)count++;
        return count;   
    }
    int main(){
        bool (*ptr)(int) = above4;
        int arr[] = {1,2,5,9,3};
        cout<<fun(arr,sizeof(arr)/sizeof(arr[0]),ptr);
    }
    */

    replace(vec.begin(),vec.end(),5,-1);//replaces 5 with -1
    for(auto &value:vec)cout<<value<<" ";
    cout<<endl;

    //checks and returns true if all the elements satisfy the condition
    bool isAllabove4 = all_of(vec.begin(),vec.end(),[](int x){return x>4;});
    bool isAllaboveneg2 = all_of(vec.begin(),vec.end(),[](int x){return x>-2;});
    cout<<"is all above 4 = "<<isAllabove4<<" is all above -2 = "<<isAllaboveneg2<<endl;

    //checks and returns if any one value satisfy the condition
    bool isAnyabove4 = any_of(vec.begin(),vec.end(),[](int x){return x>4;});
    bool isAnyabove100 = any_of(vec.begin(),vec.end(),[](int x){return x>100;});
    cout<<"is any of the elements > 4 = "<<isAnyabove4<<endl;
    cout<<"is any of the elements > 100 = "<<isAnyabove4<<endl;

    string str = "abDcDefgHijK";
    //transform(from,to,wheretoplaceResult,whattoperform)
    transform(str.begin(),str.end(),str.begin(),::toupper);
    //:: -> represents function in global scope
    cout<<str<<endl;   
}

void array_pbm(){
    //advantage over normal array are=>
    //Can be used as container which allows to use different stl libraries
    //iterators are available
    //array is object hence doesn't print the address when displayed
    //also it has many methods associated with it
    //size is fixed like normal array and access time is O(1) like normal arrays.
    array <int,6>arr({7,8,9,1});//arr = {7,8,9,1,0,0}
    array <int,6>arr2{{5,4,3,2,1,0}};//arr2 = {5,4,3,2,1,0}

    cout<<"size()="<<arr.size()<<endl;
    cout<<"at(1)="<<arr.at(1)<<endl;
    cout<<"arr[1]="<<arr[1]<<endl;
    cout<<"front()="<<arr.front()<<endl;
    cout<<"back()="<<arr.back()<<endl;
    cout<<"empty()="<<arr.empty()<<endl;
    
    cout<<"array before swap = "<<endl;
    for(auto value:arr)cout<<value<<" ";
    cout<<endl; 
    cout<<"array after swap = "<<endl;
    arr.swap(arr2);//swaps only if arr & arr2 are of same size
    for(auto value:arr)cout<<value<<" ";
    cout<<endl;
    
    arr.fill(5);
    cout<<"fill all the elements to 5"<<endl;
    for(auto value:arr)cout<<value<<" ";
    cout<<endl;

    sort(arr2.begin(),arr2.end());
    //reverse(arr2.begin(),arr2.end());
    cout<<"Array elements after sorting = "<<endl;
    for(auto value:arr2)cout<<value<<" ";
    cout<<endl;

    auto max = max_element(arr2.begin(),arr2.end());
    cout<<"max element is "<<*max<<endl;
    auto min = min_element(arr2.begin(),arr2.end());
    cout<<"min element is "<<*min<<endl;
}

void vector_operation(){
    vector <int>my_vector{1,3,2,7,5};
    cout<<"size = "<<my_vector.size()<<endl;
    cout<<"capacity = "<<my_vector.capacity()<<endl;//becomes 2x once vector is filled
    cout<<"max capacity = "<<my_vector.max_size()<<endl;
    
    auto itr = my_vector.begin();
    for(int i = 0; i < 2; i++){itr++;}
    my_vector.insert(itr,8);

    //new way of printing using for each loop
    for_each(my_vector.begin(),my_vector.end(),[](auto value){cout<<value<<" ";});
    cout<<endl;

    cout<<"capacity = "<<my_vector.capacity()<<endl;
    my_vector.shrink_to_fit();//extra capacity will be released
    cout<<"capacity = "<<my_vector.capacity()<<endl;

    my_vector.reserve(20);//instead of increase capacity 2x we can set it using reserve
    cout<<"capaity = "<<my_vector.capacity()<<endl;

    vector <int>new_vector;
    //inserts even values from my_vector to new_vector to the back side
    copy_if(my_vector.begin(),my_vector.end(),back_inserter(new_vector),[](int x){return x%2==1;});
    cout<<"new vector looks as follows"<<endl;
    for_each(new_vector.begin(),new_vector.end(),[](auto value){cout<<value<<" ";});
    cout<<endl;

    new_vector.insert(new_vector.begin()+1,my_vector.begin(),my_vector.end());
    cout<<"Changed vector looks like after inserting at position 1"<<endl;
    for_each(new_vector.begin(),new_vector.end(),[](auto value){cout<<value<<" ";});
    cout<<endl;

    my_vector.erase(my_vector.begin()+1);//removes the element at index1
    for_each(my_vector.begin(),my_vector.end(),[](auto value){cout<<value<<" ";});
    cout<<endl;

    my_vector.erase(my_vector.begin(),my_vector.begin()+2);//removes 1st and 2nd element
    for_each(my_vector.begin(),my_vector.end(),[](auto value){cout<<value<<" ";});
    cout<<endl;

    my_vector.clear();//clears all elements of vector
    cout<<"size after clearing = "<<my_vector.size()<<endl;
}

void deque_operation(){
    deque <int>my_deque{1,3};
    //deque <int>new_deque(10,2); new_deque=>{2,2,2,2,2,2,2,2,2,2};//10 2's
    my_deque.push_back(10);
    my_deque.push_back(20);
    my_deque.push_front(30);

    /*
        my_deque.emplace_back(10);//most efficient
        my_deque.emplace_back(20);//most efficient
        my_deque.emplace_front(30);//most efficient
    */

    cout<<"my_deque[1] = "<<my_deque[1]<<endl;
    cout<<"my_deque.at(1) = "<<my_deque.at(1)<<endl;
    cout<<"my_deque.size() = "<<my_deque.size()<<endl;
    cout<<"my_deque.front() = "<<my_deque.front()<<endl;
    cout<<"my_deque.back() = "<<my_deque.back()<<endl;

    for_each(my_deque.begin(),my_deque.end(),[](int x){cout<<x<<" ";});
    cout<<endl;

    my_deque.pop_back();
    my_deque.pop_front();

    for_each(my_deque.begin(),my_deque.end(),[](int x){cout<<x<<" ";});
    cout<<endl;

    deque <int>new_deque;
    copy_if(my_deque.begin(),my_deque.end(),front_inserter(new_deque),[](int x){return (x>2);});
    copy_if(my_deque.begin(),my_deque.end(),back_inserter(new_deque),[](int x){return true;});
    
    for_each(new_deque.begin(),new_deque.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
}

void list_operation(){
    //it is a doubly linked list
    list <int>my_list{3,2};
    cout<<"size = "<<my_list.size()<<endl;
    cout<<"front =  "<<my_list.front()<<endl;
    cout<<"back = "<<my_list.back()<<endl;  

    my_list.push_back(2);
    my_list.push_front(3);

    auto itr = find(my_list.begin(),my_list.end(),2);
    my_list.insert(itr,10);
    my_list.erase(itr);

    //my_list.resize(3);except first 3 elements rest will be deleted
    /*
    my_list.emplace_back(10);//efficient
    my_list.emplace_front(20);//efficient
    */
   cout<<"After erasing"<<endl;
    for_each(my_list.begin(),my_list.end(),[](int x){cout<<x<<" ";});
    cout<<endl;

    list <int>new_list{1,1,1};
    itr = new_list.begin();
    new_list.insert(itr,my_list.begin(),my_list.end());
    cout<<"Copied list = "<<endl;
    for_each(new_list.begin(),new_list.end(),[](int x){cout<<x<<" ";});
    cout<<endl;
}

void forward_list_operation(){
    //singly linked list
    //reverse iterator is not available
    forward_list <int>my_list;
    my_list.push_front(10);
    my_list.push_front(20);
    my_list.push_front(30);
    /*
        my_list.emplace_front(value);efficient
    */
    for_each(my_list.begin(),my_list.end(),[](int value){cout<<value<<" ";});
    cout<<endl;//30 20 10
    cout<<"front = "<<my_list.front()<<endl;//30

    cout<<"pop front operation performed"<<endl;
    my_list.pop_front();
    for_each(my_list.begin(),my_list.end(),[](int value){cout<<value<<" ";});
    cout<<endl;//20 10

    my_list.insert_after(my_list.begin(),99);
    //my_list.emplace_after(my_list.begin(),99);//more efficient
    cout<<"insert operation performed"<<endl;
    for_each(my_list.begin(),my_list.end(),[](int value){cout<<value<<" ";});
    cout<<endl;//20 99 10

    auto itr = my_list.begin();
    itr++;
    my_list.erase_after(itr);
    cout<<"Erase performed"<<endl;
    for_each(my_list.begin(),my_list.end(),[](int value){cout<<value<<" ";});
    cout<<endl;//20 99

    my_list.push_front(30);
    cout<<"push of 30 performed"<<endl;
    for_each(my_list.begin(),my_list.end(),[](int value){cout<<value<<" ";});
    cout<<endl;//30 20 99
    //my_list.size()=>not available
}

void set_operation(){
    //doesn't contain duplicates
    //elements are presetn in ascending order
    //set uses < operator to check and hence overload < operator
    /*
    multi_set => sorted by keys, allows duplicate, all iterators are available
    unordered_set => not sorted, allows duplicate, no reverse iterator
    */
    set <int>my_set{2,1,2,4,4,5,3,3};
    pair<set<int>::iterator,bool> itr_insertion_status_pair = my_set.insert(6);
    //insert function basically returns pair with first arg as iterator & second
    //arg as status of insertion.(true=>if insertion was successful, false if not)

    for_each(my_set.begin(),my_set.end(),[](int x){cout<<x<<" ";});//1 2 3 4
    cout<<endl;

    cout<<"Is 0 present = "<<my_set.count(0)<<endl;
    cout<<"Is 2 present = "<<my_set.count(2)<<endl;  
    cout<<"Is set empty = "<<my_set.empty()<<endl; 

    auto itr = my_set.find(7);
    if(itr == my_set.end())cout<<"element 7 not found"<<endl;
    else cout<<"element 7 found"<<endl;

    itr = my_set.find(1);

    if(itr != my_set.end())my_set.erase(itr);//removes 1 from set
    
    cout<<"element 1 removed from set"<<endl;
    for_each(my_set.begin(),my_set.end(),[](int x){cout<<x<<" ";});//1 2 3 4
    cout<<endl;

    my_set.clear();//all the elements will be removed from the set  
    cout<<"Is set empty = "<<my_set.empty()<<endl; 
}

void map_operation(){
    //while printing keys will be in ascending order
    //duplicates not allowed
    /*
        multi_map => ascending order, but duplicates allowed, all iterators are available
        unordered_map => elements are unordered, allows duplicate, reverse iterators not available
    */
    map <string,string>my_map;
    my_map.insert(make_pair("c","Sooraj"));
    my_map.insert(make_pair("b","Sourabh"));
    my_map["a"] = "xyz";//doesn't throw exception instead will create new key,value pair
    my_map.at("a") = "Shukla";//throws exception if key 'a' doesn't exist

    cout<<"elements in map are = "<<endl;
    for(pair <string,string>my_pair:my_map)
        cout<<my_pair.first<<"="<<my_pair.second<<endl;
    
    my_map.erase("a");//remove key value pair with key "a"
    
    cout<<"elements in map after removing 'a' are = "<<endl;
    for(pair <string,string>my_pair:my_map)
        cout<<my_pair.first<<"="<<my_pair.second<<endl;
    
    cout<<"Is a present in map "<<my_map.count("a")<<endl;
    cout<<"is b present in map "<<my_map.count("b")<<endl;

    map<string,string>::iterator new_itr1 = my_map.find("a");
    map<string,string>::iterator new_itr2 = my_map.find("b");

    if(new_itr1 == my_map.end())
        cout<<"key 'a' is not present"<<endl;
    else
        cout<<"key 'a' is present and it's value is "<<(*new_itr1).second<<endl;

    if(new_itr2 == my_map.end())
        cout<<"key 'b' is not present"<<endl;
    else
        cout<<"key 'b' is present nad it's value is "<<(*new_itr2).second<<endl;

    map <string,int>new_map;

}

void stack_operation(){
    stack <int>my_stack;
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);
    cout<<"size = "<<my_stack.size()<<endl;
    cout<<"peek = "<<my_stack.top()<<endl;
    my_stack.pop();
    cout<<"pop = "<<my_stack.top()<<endl;
    cout<<"empty = "<<my_stack.empty()<<endl;
}

void queue_operation(){
    queue <int>my_queue;
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(30);
    my_queue.push(40);

    cout<<"front = "<<my_queue.front()<<endl;
    cout<<"back = "<<my_queue.back()<<endl;

    cout<<"empty = "<<my_queue.empty()<<endl;
    cout<<"size = "<<my_queue.size()<<endl;

    my_queue.pop();
    cout<<"front & back = "<<my_queue.front()<<" & "<<my_queue.back()<<endl;
}

void priority_queue_operation(){
    priority_queue <int>my_queue;
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(15);
    my_queue.push(12);
    my_queue.push(13);

    cout<<my_queue.top()<<endl;
    my_queue.pop();
    cout<<my_queue.top()<<endl;
    my_queue.pop();
    cout<<my_queue.top()<<endl;
    my_queue.pop();
    cout<<my_queue.top()<<endl;
    cout<<"size = "<<my_queue.size()<<endl;
}

int main(){ 
    // iterator_pbm1();
    // iterator_pbm2();
    // algorithm_pbm1();
    // array_pbm();
    // vector_operation();
    // deque_operation();
    // list_operation();
    // forward_list_operation();
    // set_operation();
    //map_operation();
    //stack_operation();
    //queue_operation();
    priority_queue_operation();
    return 0;
}