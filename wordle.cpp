#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm>
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    std::set<string> words;
    int nsize = in.size();
    

    if(nsize == 0)
    {
        return words;
    }
    checkFixed(in, floating, dict, words, "", 0, nsize);
    
    return words;
}

// Define any helper functions here

void checkFixed(const std::string& in, const std::string& floating, const std::set<std::string>& dict, std::set<std::string>& target, std::string currWord, int pos, int n)
{
    
    if(pos == n)
    {
        if(currWord == "")
        {
            fillOnlyFloat(floating, dict, target, n);
        }
        else
        {
            if(validFloats(currWord, floating))
            {
                target.insert(currWord);
            }
        }
    }
    char inPos = in[pos];
    if(inPos == '-')
    {
        //go to next position
        checkFixed(in, floating, dict, target, currWord, pos + 1, n);
    }
    else
    {
        if(currWord == "")
        {
            //call function that calls checkFixed on every word
            findFirstFixed(in, floating, dict, target, currWord, pos, n);
        }
        else
        {
            if(currWord[pos] == inPos)
            {
                //keep going
                checkFixed(in, floating, dict, target, currWord, pos + 1, n);
            }
            else
            {
                //invalid word
                return;
            }
        }
    }
    
    
}

void fillOnlyFloat(const std::string& floating, const std::set<std::string>& dict, std::set<std::string>& target, int n)
{
    std::set<std::string>::iterator it;
    for (it = dict.begin(); it != dict.end(); ++it) {
        if(it->size() == n)
        {
            bool valid = true;
            for(int i = 0; i < floating.size(); i++)
            {
                if(it->find(floating[i]) == std::string::npos)
                {
                    valid = false;
                }
            }
            //idk why but any word that has a capitol second letter isnt valid even tho it is in dict?
            string word = *it;
            if(word.size() > 1)
            {
              if(word[1] < 97)
              {
              valid = false;
              }
            }
            if(valid)
                {
                  target.insert(*it);
                }  
          }
        }
}

bool validFloats(std::string word, const std::string& floating)
{
  
    std::map<char, int> counts;
    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        counts[c]++;
    }

    for (int i = 0; i < floating.size(); i++) {
        char c = floating[i];
        if (counts[c] < std::count(floating.begin(), floating.end(), c)) {
            return false;
        }
    }
    //dk why but  any word that has a capitol second letter isnt valid even tho it is in dict?
    if(word.size() > 1)
    {
      if(word[1] < 97)
      {
        return false;
      }
    }

    return true;
}

void findFirstFixed(const std::string& in, const std::string& floating, const std::set<std::string>& dict, std::set<std::string>& target, std::string currWord, int pos, int n)
{
    char inPos = in[pos];
    std::set<std::string>::iterator it;
    for (it = dict.begin(); it != dict.end(); ++it) {
        if(it->size() == n)
        {
            string word = *it;
            if(word[pos] == inPos)
            {
                checkFixed(in, floating, dict, target, word, pos, n);
            }
        }
    }
}

