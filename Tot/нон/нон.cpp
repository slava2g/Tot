#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Contact {
public:
    virtual void display() const = 0;
    virtual ~Contact() = default;
};

class SingleContact : public Contact {
private:
    string name;
    string phone;

public:
    SingleContact(const string& name, const string& phone)
        : name(name), phone(phone) {}

    void display() const override {
        cout << "Ім'я: " << name << " Телефон: " << phone << endl;
    }
};

class ContactGroup : public Contact {
private:
    string groupName;
    vector<shared_ptr<Contact>> contacts;

public:
    ContactGroup(const string& name) : groupName(name) {}

    void addContact(shared_ptr<Contact> contact) {
        contacts.push_back(contact);
    }

    void display() const override {
        cout << "Назва групи: " << groupName << endl;
        for (const auto& contact : contacts) {
            contact->display();
        }
    }
};

int main() { setlocale(0, ".1251");
   
    auto contact1 = make_shared<SingleContact>("Валера", "1234567890");
    auto contact2 = make_shared<SingleContact>("Анатолій", "9876543210");
    auto contact3 = make_shared<SingleContact>("Ярослав", "5555555555");

    auto familyGroup = make_shared<ContactGroup>("Сімья");
    auto friendsGroup = make_shared<ContactGroup>("Друзья");

    familyGroup->addContact(contact1);
    familyGroup->addContact(contact3);
    friendsGroup->addContact(contact2);

    auto topLevelGroup = make_shared<ContactGroup>("Всі контакти");
    topLevelGroup->addContact(familyGroup);
    topLevelGroup->addContact(friendsGroup);

    topLevelGroup->display();

    return 0;
}
   
 
