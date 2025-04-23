#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>
#include <stdexcept>

using namespace std;

class DuplicateItemException : public runtime_error
{
public:
    DuplicateItemException(const string& msg) : runtime_error(msg) 
    {

    }
};

class ItemNotFoundException : public runtime_error 
{
public:
    ItemNotFoundException(const string& msg) : runtime_error(msg) 
    {

    }
};

class StoredItem 
{
private:
    string id;
    string description;
    string location;

public:
    
    StoredItem(string id, string desc, string loc)
        : id(id), description(desc), location(loc) 
    {

    }

    string getId() const 
    { 
        return id; 
    }
    string getDescription() const
    { 
        return description; 
    }
    string getLocation() const 
    {
        return location;
    }
};

class StorageManager 
{
private:
    unordered_map<string, shared_ptr<StoredItem>> itemById;
    map<string, shared_ptr<StoredItem>> itemByDescription;

public:
    
    void addItem(const shared_ptr<StoredItem>& item) 
    {
             
        itemById.insert({&item->getId(), &item->getLocation()});
        itemByDescription.insert({ &item->getDescription(), &item->getLocation()});
    }

    shared_ptr<StoredItem> findById(const string& id) const 
    {
        itemById.find(id);
        return nullptr;
    }

    void removeItem(const string& id) 
    {
        itemById.erase(id);
        itemByDescription.erase(Id);
    }

    void listItemsByDescription() const 
    {
        for (auto i : itemByDescription)
        {
            cout << i.first << ": " << i.second << endl;
        }
    }
};

void testDuplicateAddition();
void testItemNotFound();

int menu();

int main() 
{
    StorageManager manager;
    string id;
    string decription;
    string location;
    int choice;

    cout << "Welcome to Storage Manger Program" << endl;    
    choice = menu();
    if (choice == 1)
    {
        cout << "Enter item id: " << endl;
        cin >> id;
        cout << "Enter item decription: " << endl;
        cin >> decription;
        cout << "Enter item location: " << endl;
        cin >> location;
        StoredItem* item{ new StoredItem(id, decription, location) };
        shared_ptr<StoredItem> itemPtr{ item };
        manager.addItem(itemPtr);
    }

    if (choice == 2)
    {
        manager.findById(id);
    }

    if (choice == 3)
    {
        manager.removeItem(id);
    }

    if (choice == 4)
    {
        manager.listItemsByDescription();
    }

}

int menu()
{
    int choice;

    cout << "1. Add Item" << endl;
    cout << "2. Find Item" << endl;
    cout << "3. Remove Item" << endl;
    cout << "4. Get List of Items" << endl;
    cout << "What do you like to do? " << endl;
    cin >> choice;

    return choice;
}

void testDuplicateAddition()
{

}

void testItemNotFound()
{

}