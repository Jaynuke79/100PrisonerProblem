/*

Jayden Alonzo-Estrada
Sep 3(i started at midnight), 2024
The 100 Prisoners Riddle

*/

#include <iostream>
#include <random>

using namespace std;

void RunExp(int[], int, int, int, int&, int&);
void RandRunExp(int[], int, int, int, int&, int&, int&, int&);
void PrintArray(int[], int);
void Scramble(int[], int);
void clearScreen();

// Define Parameters
#define iters 1000000
#define NumbOfBoxes 100
#define NumbOfTries 50
#define MaxLoopSize 0

int main(int argc, char* argv[]){  
  // clearScreen();
  cout << endl;

  // Init of Vars
  random_device Gen;
  int Successes, Fails, Wins = 0, Losses = 0, heldSucc = 0, heldFail = 0, 
    Room[NumbOfBoxes];
  string None;

  // Scramble Room
  Scramble(Room, NumbOfBoxes);

  // Visually verify scamble of Room
  // PrintArray(Room, NumbOfBoxes);

  // RunExp Once
  // RunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, Successes, Fails);
  // printf("Successes = %i :: Fails = %i Check #1\n", Successes, Fails);

  // Full Run of Experiment 
  // Scramble(Room, NumbOfBoxes);
  // RunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, Successes, Fails);
  // printf("Successes = %i :: Fails = %i Check #2\n", Successes, Fails);

  // Run Experiment in Series
  for (int i = 0; i < iters; i++){
    Scramble(Room, NumbOfBoxes);
    RunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, Successes, Fails);
    // printf("Successes = %i :: Fails = %i #%i\n", Successes, Fails, i+1);
    if (Fails > 0){
      Losses++;
    } else {
      Wins++;
    }
  }
  printf("Alg: Wins = %i :: Losses = %i\n", Wins, Losses);
  Wins = 0;
  Losses = 0;
  // Run Random Experiment in Series
  for (int i = 0; i < iters; i++){
    Scramble(Room, NumbOfBoxes);
    RandRunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, Successes, Fails, heldSucc, heldFail);
    // printf("heldSuccesses = %i :: heldFails = %i #%i\n", heldSucc, heldFail, i+1);
    if (Fails > 0){
      Losses++;
    } else {
      Wins++;
    }
  }
  printf("heldSuccesses = %i :: heldFails = %i\n", heldSucc, heldFail);
  printf("Rand: Wins = %i :: Losses = %i\n", Wins, Losses);

  cout << endl;
  return 0;
}

void RunExp(int array[], int size, int tries, int maxloopsize, int &success, int &fails){
  int tmp,tmper,largestLoop;
  success=0;fails=0;
  string none;
  // cout << "Where" << endl;
  for (int i = 0; i < size; i++){
    // cout << "COnfuse" << endl;
    tmp = i+1;
    tmper = tmp;
    // cout << tmp << endl;
    for (int j = 0; j < tries; j++){
      // cout << "What" << endl;
      // printf("Number = %i :: Value = %i\n", tmp, array[tmp-1]);
      // getline(cin, none);
      if (array[tmp-1] != tmper){
        tmp = array[tmp-1];
      } else if (array[tmp-1] == tmper) {
        // printf("Answer Found\n");
        success++;
        break;
      } if (j == tries-1) {
        fails++;
      }
    }
  }
  // printf("Successes = %i :: Fails = %i\n", success, fails);
}

void RandRunExp(int array[], int size, int tries, int maxloopsize, int &success, int &fails, int &holdSuccess, int &holdFails){
  int tmp,tmper,largestLoop;
  random_device Gen;
  mt19937 rng(Gen());
  uniform_int_distribution<int> dist(1, size);
  success=0;fails=0;
  string none;
  // cout << "Where" << endl;
  for (int i = 0; i < size; i++){
    // cout << "COnfuse" << endl;
    tmp = dist(rng);
    tmper = i+1;
    // cout << tmp << endl;
    for (int j = 0; j < tries; j++){
      // cout << "What" << endl;
      // printf("Number = %i :: Value = %i\n", tmp, array[tmp-1]);
      // getline(cin, none);
      if (array[tmp-1] != tmper){
        tmp = dist(rng);
      } else if (array[tmp-1] == tmper) {
        // printf("Answer Found\n");
        success++;
        break;
      } if (j == tries-1) {
        fails++;
      }
    }
  }
  holdFails += fails;
  holdSuccess += success;
  // printf("holdSuccesses = %i :: holdFails = %i\n", holdSuccess, holdFails);
}

void PrintArray(int array[], int size){
  printf("Contents of Room array:\n");
  for (int i = 0; i < size; i++){
    printf("Array[%i] == %i\n", i, array[i]);
  }
}

void Scramble(int array[], int size){
  random_device Gen;
  mt19937 rng(Gen());  // Better random number generator
  
  // Initialize array with values 1 to size
  for (int i = 0; i < size; i++) {
    array[i] = i + 1;
  }

  // Fisher-Yates shuffle algorithm
  for (int i = size - 1; i > 0; i--) {
    uniform_int_distribution<int> dist(0, i);
    int j = dist(rng);
    // Swap array[i] and array[j]
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}