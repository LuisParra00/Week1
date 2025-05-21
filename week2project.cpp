#include <iostream>
#include <string>
using namespace std;

struct FamilyMember {
    string name;
    FamilyMember* left;
    FamilyMember* right;

    FamilyMember(string memberName) {
        name = memberName;
        left = right = nullptr;
    }
};

FamilyMember* addMember(FamilyMember* root, string name) {
    if (root == nullptr)
        return new FamilyMember(name);

    if (name < root->name)
        root->left = addMember(root->left, name);
    else
        root->right = addMember(root->right, name);

    return root;
}

void listFamily(FamilyMember* root) {
    if (root == nullptr)
        return;

    listFamily(root->left);
    cout << root->name << " ";
    listFamily(root->right);
}

bool findMember(FamilyMember* root, string targetName) {
    if (root == nullptr)
        return false;
    if (root->name == targetName)
        return true;
    else if (targetName < root->name)
        return findMember(root->left, targetName);
    else
        return findMember(root->right, targetName);
}

void clearTree(FamilyMember* root) {
    if (root == nullptr) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    FamilyMember* root = nullptr;

    root = addMember(root, "Seth");
    addMember(root, "Roger");
    addMember(root, "Ernesto");
    addMember(root, "David");
    addMember(root, "Adam");

    cout << "Family Members (Alphabetical): ";
    listFamily(root);
    cout << endl;

    string searchName;
    cout << "Enter a name to search: ";
    getline(cin, searchName);

    if (findMember(root, searchName))
        cout << searchName << " is part of the family tree." << endl;
    else
        cout << searchName << " was not found in the family tree." << endl;

    clearTree(root);
    return 0;
}