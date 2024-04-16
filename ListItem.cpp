#include <iostream>
using namespace std;

#include "ListItem.h"

void ListItem::SetItem(string name) {
  itemName = name;
}

string ListItem::GetItem() {
  return itemName;
}
