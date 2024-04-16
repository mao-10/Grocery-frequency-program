#ifndef LISTITEM_H
#define LISTITEM_H

#include <string>
using namespace std;

class ListItem {
  public:
    void SetItem(string name);
    string GetItem();
  private:
    string itemName;

};

#endif
