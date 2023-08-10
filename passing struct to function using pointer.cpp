
#include <iostream>
#include <string>
using namespace std;
struct book {
    string name;
    string author;
    int page;
    float price;
};
book func(book* c) {
    cin >> c->name;
    cin >> c->author;
    cin >> c->page;
    cin >> c->price;
    return *c;
}
int main() {
    book book1;
    book1.name = "first ahead c";
    book1.author = "unknown";
    book1.page = 165;
    book1.price = 45;
    func(&book1);
    cout << book1.name << endl;
    return 0;
}
