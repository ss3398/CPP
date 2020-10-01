#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
int main() 
{ 
  
    // empty map container 
    map<string, string> gquiz1; 
  
    // insert elements in random order 
    gquiz1.insert(pair<string, string>("1", "40")); 
    gquiz1.insert(pair<string, string>("2", "30")); 
    gquiz1.insert(pair<string, string>("3", "60")); 
    gquiz1.insert(pair<string, string>("4", "20")); 
    gquiz1.insert(pair<string, string>("5", "50")); 
    gquiz1.insert(pair<string, string>("6", "50")); 
    gquiz1.insert(pair<string, string>("7", "10")); 
  
    // printing map gquiz1 
    map<string, string>::iterator itr; 
    cout << "\nThe map gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    map<string, string> gquiz2(gquiz1.begin(), gquiz1.end()); 
  
    // print all elements of the map gquiz2 
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // remove all elements up to 
    // element with key=3 in gquiz2 
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find("3")); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    // remove all elements with key = 4 
    int num; 
    num = gquiz2.erase("4"); 
    cout << "\ngquiz2.erase("4") : "; 
    cout << num << " removed \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    cout << endl; 
  
    // lower bound and upper bound for map gquiz1 key = 5 
    cout << "gquiz1.lower_bound("5") : "
         << "\tKEY = "; 
    cout << gquiz1.lower_bound("5")->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.lower_bound("5")->second << endl; 
    cout << "gquiz1.upper_bound("5") : "
         << "\tKEY = "; 
    cout << gquiz1.upper_bound("5")->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.upper_bound("5")->second << endl; 
  
    return 0; 
} 