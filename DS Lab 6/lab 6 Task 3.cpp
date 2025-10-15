#include <iostream>
using namespace std;

//Order node
struct Order {
    int orderNumber; 
    string itemName;
    int quantity;
    Order* next;
};

Order* front = NULL;
Order* rear = NULL;
int orderCount=0;

void addOrder(string item, int qty) {
    Order* newOrder = new Order;
    newOrder->orderNumber = orderCount++;
    newOrder->itemName = item;
    newOrder->quantity = qty;
    newOrder->next = NULL;

    if (rear == NULL) {
        //empty queue
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }

    cout << "OrderNum:" << newOrder->orderNumber << " ,added: " << newOrder->itemName << "   ,Qty: " << newOrder->quantity << "\n";
} 
//finish first order and hand it to customer
void processOrder() {
    if (front == NULL) {
        cout << "No orders to process (Underflow)!\n";
        return;
    }

    Order* temp = front;
    cout << "Processing Order #" << temp->orderNumber 
         << " - " << temp->itemName 
         << " (Qty: " << temp->quantity << ")\n";

    front = front->next;

    if (front == NULL)
        rear = NULL;
         //empty queue

    delete temp;
}
//display orders
void displayOrder() {
    if (front == NULL) {
        cout << "No pendin orders\n";
        return;
    }
 cout << "Current orders\n";
Order* temp=front;
while (temp!=nullptr)
{
           cout << "OrderNum:" << temp->orderNumber << "       ,orderName: "  << temp->itemName << "    ,Qty: " << temp->quantity << "\n";
           temp=temp->next;
}
cout << "\n";
}
int main() {
addOrder("Roll",1);
addOrder("fries",2);
addOrder("Burger",3);
displayOrder();
processOrder();
processOrder();
displayOrder();
    return 0;
}