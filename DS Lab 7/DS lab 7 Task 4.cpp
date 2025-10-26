#include <iostream>
#include <string>
using namespace std;

//Product class
class Product {
public:
    string name;
    double price;
    string desc;
    bool available;

    Product() {}
    Product(string n, double p, string d, bool a) {
        name = n;
        price = p;
        desc = d;
        available = a;
    }
};

//swap two products
void swapProd(Product &a, Product &b) {
    Product t = a;
    a = b;
    b = t;
}

//partition fn
int partition(Product arr[], int start, int end) {
    double pivot = arr[end].price;
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swapProd(arr[i], arr[j]);
        }
    }
    swapProd(arr[i + 1], arr[end]);
    return (i + 1);
}

//quick sort fn
void quickSort(Product arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

//display fn
void showProducts(Product arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].name << endl;
        cout << "Price: $" << arr[i].price << endl;
        cout << "Desc: " << arr[i].desc << endl;
        cout << "Available: " << (arr[i].available ? "Yes" : "No") << endl;
        cout << "<-------------------->\n";
    }
}

int main() {
    const int total = 3;
    Product prod[total];

    cout << "Enter info for 3 products:\n";
    for (int i = 0; i < total; i++) {
        cout << "\nProduct " << i + 1 << " name: ";
        cin >> prod[i].name;
        cout << "Price: ";
        cin >> prod[i].price;
        cout << "Description: ";
        cin.ignore();
        getline(cin, prod[i].desc);
        cout << "Available (1 for Yes, 0 for No): ";
        cin >> prod[i].available;
    }

    cout << "\nBefore Sorting:\n                    \n";
    showProducts(prod, total);

    quickSort(prod, 0, total - 1);

    cout << "\nAfter Sorting by Price (Ascending):\n                  \n";
    showProducts(prod, total);

    return 0;
}
