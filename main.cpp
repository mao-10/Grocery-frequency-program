// Mao Christie
// CS- 210
//Project 3

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

#include "ListItem.h"
#include "ListItem.cpp"

// function to display menu
void displayMenu() {
  cout << "What would you like to do? \n" << endl;

  cout << "1. Find and print the frequency of a specific item \n" << endl;
  cout << "2. Print the frequency of all items \n" << endl;
  cout << "3. Print frequency with '*' and a histogram \n" << endl;
  cout << "4. Exit \n" << endl;
}
//function to print freq of specific item
void printItemFreq(map<string, int> groceryList) {
  string userInput;
  cout << "---------------------------------------------" << endl;
  cout << "What produce item are you looking for?" << endl;
  cin >> userInput;
  cout << "---------------------------------------------" << endl;
  // print freq of item
  if (groceryList.count(userInput) == 1) {
    cout << userInput << " " << groceryList.at(userInput) << "\n" << endl;
  }
  else {
    cout << "Produce not available..." << endl;
  }
  cout << "---------------------------------------------" << endl;
}
// prints all items + freq
void printAllItems(map<string, int> groceryList,  map<string,int>::const_iterator it) {
  cout << "---------------------------------------------" << endl;
  cout << "           Frequency of All Items            " << endl;
  cout << "---------------------------------------------" << endl;
  for (it = groceryList.begin(); it != groceryList.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
  cout << "---------------------------------------------" << endl;
}
// print items with * as freq
void printWithStars(map<string, int> groceryList,  map<string,int>::const_iterator it) {
  cout << "---------------------------------------------" << endl;
  cout << "            Frequency w/ Stars               " << endl;
  cout << "---------------------------------------------" << endl;
  for (it = groceryList.begin(); it != groceryList.end(); it++) {
    cout << it->first << " ";
    for (int i = 1; i <= it->second; i++) {
      cout << "*";
    }
    cout << "\n";
  }
}
// prints a histogram of freq
void printHistogram(vector<ListItem> vectorList) {
  int max = 0;
  int i;
  // get max of item freq for column #
  for (i = 0; i < vectorList.size(); i++) {
    if (vectorList.at(i).GetQuantity() > max) {
      max = vectorList.at(i).GetQuantity();
    }
  }
  cout << "---------------------------------------------" << endl;
  cout << "                 Histogram                   " << endl;
  cout << "---------------------------------------------" << endl;
  for (i = max; i > 0; i--) {
    cout.width(2);
    cout << i << " | ";
    for (int j = 0; j < vectorList.size(); j++) {
      if (vectorList.at(j).GetQuantity() >= i) {
        cout << "* ";
      }
      else {
        cout << "  ";
      }
    }
    cout << "\n";
  }
  cout << "---------------------------------------------" << endl;

}

int main() {
  map<string, int> groceryList;
  map<string,int>::const_iterator it;
  vector<ListItem> vectorList;
  ifstream listOfItems;
  ofstream itemList;
  string item;
  int userChoice = 0;
  ListItem currItem;
  string currItemName;

  // open input and output file
  listOfItems.open("CS210_Project_Three_Input_File.txt");
  itemList.open("frequency.dat");

  // give feedback if file doesn't open
  if (!listOfItems.is_open()) {
    cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
    return 1;
  }
  if (!itemList.is_open()) {
    cout << "Could not open file frequency.dat" << endl;
  }


  // add items from file to map and count frequency
  while (listOfItems >> item) {
    // if the item is already in the hash, increase freq
    if (groceryList.count(item)) {
      groceryList[item]++;
    }
    // otherwise, add item to hash
    else {
      groceryList.insert(std::make_pair(item, 1));
    }
  }
  // print items & freq to file, add to vector
  for (it = groceryList.begin(); it != groceryList.end(); it++) {
        itemList << it->first << " " << it->second << endl;
        currItem.SetItem(it->first);
        currItem.SetQuantity(it->second);
        vectorList.push_back(currItem);
  }
  itemList.close();


  // loop for user choices
  while (userChoice != 4) {
    displayMenu();
    cin >> userChoice;
    if (userChoice == 1) {
      printItemFreq(groceryList);
    }
    // print all items and their freq
    else if (userChoice == 2) {
      printAllItems(groceryList, it);
      cout << endl;
    }
    // print items with * instead of num
    else if (userChoice == 3) {
      printWithStars(groceryList, it);
      cout << endl;
      printHistogram(vectorList);
    }
    // exit loop
    else if (userChoice == 4) {
      cout << "---------------------------------------------" << endl;
      cout << "Exiting program" << endl;
      cout << "---------------------------------------------" << endl;
      break;
    }
    // if user inputs a num outside of choices
    else {
      cout << "---------------------------------------------" << endl;
      cout << "Invalid choice" << endl;
      cout << "---------------------------------------------" << endl;
    }

  }


  return 0;
}
