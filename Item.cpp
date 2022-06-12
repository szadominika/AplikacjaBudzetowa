#include "Item.h"

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

/*int Item :: getIntDate() {
    return intDate;
}*/
/*void Item :: setStringDate (string newDate) {
        itemDate = newDate;
}*/
/*void Item :: setupItemId (int newItemId) {
    if (newItemId >= 0)
        itemId = newItemId;
}*/
/*int Item :: getItemId() {
    return itemId;
}*/
