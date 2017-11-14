/*
  Implement a method to perform basic string compression using the counts of
  repeated characters. For example, the string aabcccccaaa would become
  a2blc5a3. If the "compressed" string would not become smaller than the original
  string, your method should return the original string.
*/

// compile with g++ -std=c++11, because used to_string() from <string> header

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string in;

  cout<<"enter the string 1 : "; 
  getline(cin, in);
  
  char c = in[0];
  int count = 1;
  string mystr;
  //cout<<"string 1:"<<in<<in[0]<<c<<endl; 
  cout<<"string 1:"<<in<<endl; 
  for (int i = 1; i < in.size(); i++) {
    if (in[i] == c) {
      count++;
    }
    else {
      mystr += c + to_string(count); // NOTE: to_string requires C++11
      c = in[i];
      count = 1;
    }
  }
  mystr += c + to_string(count); // NOTE: this is for the last character
  if (in.size() > mystr.size()) 
    cout<<mystr<<endl;
  else 
    cout<<in<<endl;
}
    
