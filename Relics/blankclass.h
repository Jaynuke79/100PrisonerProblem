/*

Jayden Alonzo-Estrada
Sept. 3, 2024
Room

*/
#pragma once
#include <iostream>
#include "box.h"

using namespace std;

class room {
  private:
    // Class Attributes
    // int _int0, _int1, _int2;
    // It was at this point that I realized I can just do this with arrays ... after 50 min of work

    // Class Traits
    string _string0, _string1, _string2;

  public:
    // Constructor 
    room();
    // Destructor
    ~room();

    // Gen Funcs
    int add2Nums(int num0, int num1);
    string add2Strs(string str0, string str1);

    // Getters
    int get0();
    int get1();
    int get2();
    string gets0();
    string gets1();
    string gets2();

    // Setters
    void set0(int num);
    void set1(int num);
    void set2(int num);
    void sets0(string str);
    void sets1(string str);
    void sets2(string str);

    
};

room::room(){
  _int0 = 0;
  _int1 = 0;
  _int2 = 0;
  _string0 = "";
  _string1 = "";
  _string2 = "";
}

room::~room(){}

int room::add2Nums(int num0 = 0, int num1 = 0){
  return num0 + num1;
}
string room::add2Strs(string str0, string str1){
  string tmp;
  tmp = str0 + str1;
  return tmp;
}

int room::get0(){return _int0;}
int room::get1(){return _int0;}
int room::get2(){return _int2;}
string room::gets0(){return _string0;}
string room::gets1(){return _string1;}
string room::gets2(){return _string2;}

void room::set0(int num){_int0=num;}
void room::set1(int num){_int1=num;}
void room::set2(int num){_int2=num;}
void room::sets0(string str){_string0=str;}
void room::sets1(string str){_string1=str;}
void room::sets2(string str){_string2=str;}

