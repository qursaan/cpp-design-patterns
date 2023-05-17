// Copyright (c) 2023, qursaan
// All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// See the LICENSE file in the root of this project for more information.

#include <iostream>
using namespace std;

class Item {
public:
    virtual float getPrice() = 0;
    virtual void print() = 0;
};

class Product : public Item {
private:
    string name;
    float price;
    string category;

public:
    Product(string name, float price, string category) {
        this->name = name;
        this->price = price;
        this->category = category;
    }

    float getPrice() {
        return price;
    }

    void print() {
        cout << "Product: " << name << " (" << category << ")" << endl;
    }
};

class Box : public Item {
private:
    string name;
    float price;
    Item** items;
    int counter;

public:
    Box(string name) {
        this->name = name;
        this->price = 0;
        items = new Item*[100];
        counter = 0;
    }

    void add(Item* item) {
        items[counter++] = item;
        price += item->getPrice();
    }

    float getPrice() {
        return price;
    }

    void print() {
        cout << "Box: " << name << endl;
        for (int i = 0; i < counter; i++) {
            items[i]->print();
        }
    }

    ~Box() {
        for (int i = 0; i < counter; i++) {
            delete items[i];
        }
        delete[] items;
    }
};

int main() {
   
    // Create some products
    Item* laptop = new Product("Laptop", 1000, "Electronics");
    Item* book = new Product("Book", 20, "Books");

    // Create a box and add some items to it
    Box* box1 = new Box("Box 1");
    box1->add(laptop);
    box1->add(book);

    // Create another box and add the first box to it
    Box* box2 = new Box("Box 2");
    box2->add(box1);

    // Create a product and add it to the second box
    Item* phone = new Product("Phone", 500, "Electronics");
    box2->add(phone);

    // Print the contents of the second box
    cout << "Printing the contents of the second box:" << endl;
    box2->print();
    
    // Calculate the total price of the second box
    cout << "Total price of " << box2->getPrice() << " dollars" << endl;
    // Clean up memory
    delete box2;
    return 0;
}