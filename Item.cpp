#include "Item.h"


using namespace std;

void Item :: setDate (int newDate) {
    if (newDate >= 0)
        itemDate = newDate;
}

void Item :: setUserId (int newUserID) {
    if (newUserID > 0)
        userId = newUserID;
}

void Item :: setItemName (string newItemName) {
        itemName = newItemName;
}

void Item :: setItemAmount (float newItemAmount) {
        itemAmount = newItemAmount;
}

string Item :: getItemName() {
    return itemName;
}

float Item :: getItemAmount() {
    return itemAmount;
}

int Item :: getItemDate() {
    return itemDate;
}

int Item :: getUserId() {
    return userId;
}

