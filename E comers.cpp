#include <iostream>
#include <string>
using namespace std;


struct Product {
    int productID;
    string name;
    double price;
    int quantity;
    Product* next;
};


class ProductCatalog {
private:
    static const int SIZE = 10;
    Product* table[SIZE];

    
    int hashFunction(int id) {
        return id % SIZE;
    }

public:
    ProductCatalog() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    
    void addProduct(int id, string name, double price, int quantity) {
        int index = hashFunction(id);

        Product* newProduct = new Product;
        newProduct->productID = id;
        newProduct->name = name;
        newProduct->price = price;
        newProduct->quantity = quantity;
        newProduct->next = nullptr;

        
        if (table[index] == nullptr) {
            table[index] = newProduct;
        } else {
            Product* temp = table[index];

            
            while (temp->next != nullptr) {
                if (temp->productID == id) {
                    cout << "Product ID already exists!\n";
                    delete newProduct;
                    return;
                }
                temp = temp->next;
            }

            if (temp->productID == id) {
                cout << "Product ID already exists!\n";
                delete newProduct;
                return;
            }

            temp->next = newProduct;
        }

        cout << "Product added successfully.\n";
    }

    
    void searchProduct(int id) {
        int index = hashFunction(id);
        Product* temp = table[index];

        while (temp != nullptr) {
            if (temp->productID == id) {
                cout << "\nProduct Found\n";
                cout << "Product ID : " << temp->productID << endl;
                cout << "Name       : " << temp->name << endl;
                cout << "Price      : " << temp->price << endl;
                cout << "Quantity   : " << temp->quantity << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Product not found.\n";
    }

    
    void updateProduct(int id) {
        int index = hashFunction(id);
        Product* temp = table[index];

        while (temp != nullptr) {
            if (temp->productID == id) {
                cout << "Enter new product name: ";
                cin >> temp->name;

                cout << "Enter new price: ";
                cin >> temp->price;

                cout << "Enter new quantity: ";
                cin >> temp->quantity;

                cout << "Product updated successfully.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Product not found.\n";
    }

    
    void removeProduct(int id) {
        int index = hashFunction(id);
        Product* temp = table[index];
        Product* previous = nullptr;

        while (temp != nullptr) {
            if (temp->productID == id) {

                if (previous == nullptr) {
                    table[index] = temp->next;
                } else {
                    previous->next = temp->next;
                }

                delete temp;
                cout << "Product removed successfully.\n";
                return;
            }

            previous = temp;
            temp = temp->next;
        }

        cout << "Product not found.\n";
    }

    
    void displayProducts() {
        cout << "\n===== PRODUCT CATALOG =====\n";

        bool found = false;

        for (int i = 0; i < SIZE; i++) {
            Product* temp = table[i];

            while (temp != nullptr) {
                found = true;

                cout << "\nProduct ID : " << temp->productID;
                cout << "\nName       : " << temp->name;
                cout << "\nPrice      : " << temp->price;
                cout << "\nQuantity   : " << temp->quantity;
                cout << "\n--------------------------";

                temp = temp->next;
            }
        }

        if (!found) {
            cout << "\nNo products available.\n";
        }
    }
};

int main() {
    ProductCatalog catalog;

    int choice;
    int id, quantity;
    string name;
    double price;

    do {
        cout << "\n\n===== E-COMMERCE PRODUCT CATALOG =====";
        cout << "\n1. Add Product";
        cout << "\n2. Update Product";
        cout << "\n3. Remove Product";
        cout << "\n4. Search Product";
        cout << "\n5. Display All Products";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nEnter Product ID: ";
            cin >> id;

            cout << "Enter Product Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            catalog.addProduct(id, name, price, quantity);
            break;

        case 2:
            cout << "\nEnter Product ID to update: ";
            cin >> id;

            catalog.updateProduct(id);
            break;

        case 3:
            cout << "\nEnter Product ID to remove: ";
            cin >> id;

            catalog.removeProduct(id);
            break;

        case 4:
            cout << "\nEnter Product ID to search: ";
            cin >> id;

            catalog.searchProduct(id);
            break;

        case 5:
            catalog.displayProducts();
            break;

        case 6:
            cout << "\nExiting program...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 6);

    return 0;
}
