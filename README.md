# WordleHelper

Input format

To indicate how many letters the selected word has AND the correct, fixed location letters already guessed, we will use a string of length n (for an n-letter word), using the - character to indicate a blank location and characters filling in the correct, fixed locations. So the input string -i- means we want to find all 3 letter words that have an i as the middle character.
We will then pass in a second string of the floating (yellow) characters that contains the characters (in any order) that we know must be part of the selected word but whose location is unknown. So if you were given a first input string of -i-- and second input string dn, you should output all words that have i as the 2nd letter and contain d and n. A sample output is below. Since the results are stored in a set, they can be printed in any order. We have provided a "driver"/test program (wordle-driver.cpp) that will take in these two strings from the command line, call your function, and then print out the results from the set of strings returned.


Program execution and command line arguments.
g++ -g -Wall -std=c++11 wordle.cpp dict-eng.cpp wordle-driver.cpp -o wordle-driver
./wordle-driver -i-- dn
Printed results:

bind
dine
ding
dins
dint
find
hind
kind
mind
rind
wind
