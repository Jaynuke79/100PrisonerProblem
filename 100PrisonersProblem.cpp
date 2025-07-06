/*

Jayden Alonzo-Estrada
Sep 3(i started at midnight), 2024
The 100 Prisoners Riddle

*/

#include <iostream>
#include <random>

using namespace std;

void RunExp(int[], int, int, int, int&, int&, int&);
void RandRunExp(int[], int, int, int, int&, int&, int&);
void Scramble(int[], int);

// Define Parameters
#define iters 10000
#define NumbOfBoxes 100
#define NumbOfTries 50
#define MaxLoopSize 0 // WIP

int main(int argc, char* argv[]){
  cout << endl;

  // Init of Vars
  random_device Gen;
  int exp_failed, Wins = 0, Losses = 0, held_successes = 0, held_fails = 0, Room[NumbOfBoxes];

  // Run Experiment in Series
  // Optimized Method
  for (int i = 0; i < iters; i++){
    Scramble(Room, NumbOfBoxes);
    RunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, exp_failed, held_successes, held_fails);
    if (exp_failed > 0){Losses++;} else {Wins++;}
  }

  // Print Algorithm Stats
  printf("Alg: Successes = %i :: Failures = %i\n", held_successes, held_fails);
  printf("Alg: Wins = %i :: Losses = %i :: Win Percentage = %.2f%%\n", Wins, Losses, (Wins * 100.0) / iters);

  // Reset Stats
  exp_failed=0; Wins=0; Losses=0; held_fails=0; held_successes=0;

  // Random Method
  for (int i = 0; i < iters; i++){
    Scramble(Room, NumbOfBoxes);
    RandRunExp(Room, NumbOfBoxes, NumbOfTries, MaxLoopSize, exp_failed, held_successes, held_fails);
    if (exp_failed > 0){Losses++;} else {Wins++;}}
  
  // Print Random States
  printf("Rand: Successes = %i :: Fails = %i\n", held_successes, held_fails);
  printf("Rand: Wins = %i :: Losses = %i :: Win Percentage = %.2f%%\n", Wins, Losses, (Wins * 100.0) / iters);

  cout << endl;
  return 0;
}

// Runs Experiment with Optimization
void RunExp(int array[], int size, int tries, int maxloopsize, int &fails, int &holdSuccess, int &holdFails){
  int tmp,tmper,largestLoop;
  fails=0;
  for (int i = 0; i < size; i++){
    tmp = i+1;
    tmper = tmp;
    for (int j = 0; j < tries; j++){
      if (array[tmp-1] != tmper){
        tmp = array[tmp-1];
      } else if (array[tmp-1] == tmper) {
        holdSuccess += 1;
        break;
      } if (j == tries-1) {
        fails++;
        holdFails += 1;
      }
    }
  }
}

// Run Experiment with Random
void RandRunExp(int array[], int size, int tries, int maxloopsize, int &fails, int &holdSuccess, int &holdFails){
  int tmp,tmper,largestLoop;
  random_device Gen;
  mt19937 rng(Gen());
  uniform_int_distribution<int> dist(1, size);
  fails=0;
  for (int i = 0; i < size; i++){
    tmp = dist(rng);
    tmper = i+1;
    for (int j = 0; j < tries; j++){
      if (array[tmp-1] != tmper){
        tmp = dist(rng);
      } else if (array[tmp-1] == tmper) {
        holdSuccess += 1;
        break;
      } if (j == tries-1) {
        fails++;
        holdFails += 1;
      }
    }
  }
}

// Randomize the Array
void Scramble(int array[], int size){
  random_device Gen;
  mt19937 rng(Gen());

  for (int i = 0; i < size; i++) {
    array[i] = i + 1;
  }

  // Fisher-Yates shuffle algorithm
  for (int i = size - 1; i > 0; i--) {
    uniform_int_distribution<int> dist(0, i);
    int j = dist(rng);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}