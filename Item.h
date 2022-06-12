#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {

    int userId;
    int itemDate;
    string itemName;
    float itemAmount;

public:
       /* Item(/*int itemId = 0, int userId = 0, string itemDate = "", string itemName = "", float itemAmount = 0.0)
    {
       // this->itemId = itemId;
        this->userId = userId;
        this->itemDate = itemDate;
        this->itemName = itemName;
        this->itemAmount = itemAmount;
    }*/

    bool operator () (Item a, Item b) {

    if (a.getItemDate() < b.getItemDate())
        return true;
    }

    void setDate (int newDate);
 //   void setStringDate (string newDate);
    void setUserId (int newUserId);
    void setItemName(string newItemName);
    void setItemAmount(float newItemAmount);

    int getUserId();
    string getItemName();
    float getItemAmount();
    int getItemDate();
};

#endif
