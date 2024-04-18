#ifndef LISTITEM_HPP
#define LISTITEM_HPP

#include <string>
using namespace std;

class ListItem {
  public:
    void SetItem(string name);
    string GetItem();
    void SetQuantity(int num);
    int GetQuantity();
  private:
    string itemName;
    int quantity;
};

#endif
