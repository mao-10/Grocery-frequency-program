// Mao Christie
// CS- 210
//Project 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "ListItem.h"
#include "ListItem.cpp"

void displayMenu() {
  cout << "What would you like to do? \n" << endl;

  cout << "1. Find and print the frequency of a specific item \n" << endl;
  cout << "2. Print the frequency of all items \n" << endl;
  cout << "3. Print items and frequency with '*' in a histogram \n" << endl;
  cout << "4. Exit \n" << endl;
}

int main() {
  vector<ListItem> groceryList;
  ListItem currItem;
  ifstream listOfItems;
  string currItemName;
  string userInput;
  int userChoice = 0;
  int itemFreq;
  unsigned int i;

  listOfItems.open("CS210_Project_Three_Input_File.txt");

  if (!listOfItems.is_open()) {
    cout << "Could not open file CS210_Project_Three_Input_File.txt" << endl;
    return 1;
  }

  while (!listOfItems.fail()) {
    listOfItems >> currItemName;
    currItem.SetItem(currItemName);
    groceryList.push_back(currItem);
  }

// Checking if items from file are being added to vector
  for(i=0; i < groceryList.size(); i++) {
    currItem = groceryList.at(i);
    cout << i << currItem.GetItem() << endl;
  }


  while (userChoice != 4) {
    displayMenu();
    cin >> userChoice;
    if (userChoice == 1) {
      cout << "What produce item are you looking for?" << endl;
      cin >> userInput;
      for(i = 0; i < groceryList.size(); ++i) {
        currItem = groceryList.at(i);
        if (userInput == currItem.GetItem()) {
          itemFreq += 1;
        }
      }
      cout << userInput << " " << itemFreq << "\n" << endl;
      itemFreq = 0;

    }

    else if (userChoice == 2) {
      // TODO
    }

    else if (userChoice == 3) {
      // TODO
    }

    else if (userChoice == 4) {
      cout << "Exiting program" << endl;
      break;
    }

    else {
      cout << "Invalid choice" << endl;
    }

  }


  return 0;
}
