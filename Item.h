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
       /* Item(int userId = 0, int itemDate = 0, string itemName = "", float itemAmount = 0.0) {

        this->userId = userId;
        this->itemDate = itemDate;
        this->itemName = itemName;
        this->itemAmount = itemAmount;
    }*/

    bool operator () (Item firstDate, Item secondDate) {

        if (firstDate.getItemDate() < secondDate.getItemDate())

        return true;
    }

    void setDate (int newDate);
    void setUserId (int newUserId);
    void setItemName(string newItemName);
    void setItemAmount(float newItemAmount);

    int getUserId();
    string getItemName();
    float getItemAmount();
    int getItemDate();
};

#endif
