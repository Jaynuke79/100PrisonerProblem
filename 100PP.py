

########################################
# Jayden Alonzo-Estrada
# Sept. 9, 1:00PM, 2024
# The 100 Prisoners Riddle
# Literally js asked claude to convert the 100PrisonersProblem into python and got this
########################################


import random
import os

# Define Parameters
ITERS = 10000
NUMB_OF_BOXES = 100
NUMB_OF_TRIES = 50
MAX_LOOP_SIZE = 0

def run_exp(array, size, tries, maxloopsize):
    success = 0
    fails = 0
    for i in range(size):
        tmp = i + 1
        tmper = tmp
        for j in range(tries):
            if array[tmp - 1] != tmper:
                tmp = array[tmp - 1]
            elif array[tmp - 1] == tmper:
                success += 1
                break
            if j == tries - 1:
                fails += 1
    return success, fails

def print_array(array):
    print("Contents of Room array:")
    for i, value in enumerate(array):
        print(f"Array[{i}] == {value}")

def scramble(size):
    array = list(range(1, size + 1))
    random.shuffle(array)
    return array

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    print()

    wins = 0
    losses = 0

    # Run Experiment in Series
    for _ in range(ITERS):
        room = scramble(NUMB_OF_BOXES)
        successes, fails = run_exp(room, NUMB_OF_BOXES, NUMB_OF_TRIES, MAX_LOOP_SIZE)
        if fails > 0:
            losses += 1
        else:
            wins += 1

    print(f"Wins = {wins} :: Losses = {losses}")
    print()

if __name__ == "__main__":
    main()