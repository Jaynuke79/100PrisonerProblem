/*

Jayden Alonzo-Estrada
Sept 3, 2024
Box

*/

#include <iostream>

using namespace std;

class box {
  private:
    // b Attributes
    int* _int0 = new int; // Box #
    int* _int1 = new int; // # in Box
    // b Traits
    // string _string0, _string1, _string2;

  public:
    // Constructor 
    box();
    // Destructor
    ~box();

    // Gen Funcs
    // int add2Nums(int num0, int num1);
    // string add2Strs(string str0, string str1);
    bool Same();

    // Getters
    int get0();
    int get1();
    // int get2();
    // string gets0();
    // string gets1();
    // string gets2();

    // Setters
    void set0(int num);
    void set1(int num);
    // void set2(int num);
    // void sets0(string str);
    // void sets1(string str);
    // void sets2(string str);

    
};

box::box(){
  *_int0 = 0;
  *_int1 = 0;
  // _int2 = 0;
  // _string0 = "";
  // _string1 = "";
  // _string2 = "";
}

box::~box(){
  delete _int0;
  cout << "deleted correctly" << endl;
  delete _int1;
}

// int box::box(int num0 = 0, int num1 = 0){
//   return num0 + num1;
// }
// string box::add2Strs(string str0, string str1){
//   string tmp;
//   tmp = str0 + str1;
//   return tmp;
// }

bool box::Same(){
  // cout << *_int0 << " : " << *_int1 << endl;
  if (*_int0 == *_int1){
    return true;
  }
  return false;
}

int box::get0(){return *_int0;}
int box::get1(){return *_int1;}
// int box::get2(){return _int2;}
// string box::gets0(){return _string0;}
// string box::gets1(){return _string1;}
// string box::gets2(){return _string2;}

void box::set0(int num){*_int0=num;}
void box::set1(int num){*_int1=num;}
// void box::set2(int num){_int2=num;}
// void box::sets0(string str){_string0=str;}
// void box::sets1(string str){_string1=str;}
// void box::sets2(string str){_string2=str;}

