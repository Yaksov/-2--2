#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    virtual void getData() {
        std::cout << "enter a name: ";
        std::getline(std::cin, title);
        std::cout << "enter a price: ";
        std::cin >> price;
        std::cin.ignore();
    }

    virtual void putData() const {
        std::cout << "name: " << title << std::endl;
        std::cout << "price: " << price << std::endl;
    }
};

class Sales {
protected:
    float sales[3];

public:
    void getSalesData() {
        for (int i = 0; i < 3; ++i) {
            std::cout << "Enter monthly sales " << (i + 1) << ": ";
            std::cin >> sales[i];
        }
        std::cin.ignore();
    }

    void putSalesData() const {
        for (int i = 0; i < 3; ++i) {
            std::cout << "monthly sales " << (i + 1) << ": " << sales[i] << std::endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;

public:
    void getData() override {
        Publication::getData();
        std::cout << "Enter number of pages: ";
        std::cin >> pageCount;
        std::cin.ignore();
        getSalesData();
    }

    void putData() const override {
        Publication::putData();
        std::cout << "number of pages: " << pageCount << std::endl;
        putSalesData();
    }
};

class Tape : public Publication, public Sales {
private:
    float playTime;

public:
    void getData() override {
        Publication::getData();
        std::cout << "Enter recording time (in minutes): ";
        std::cin >> playTime;
        std::cin.ignore();
        getSalesData();
    }

    void putData() const override {
        Publication::putData();
        std::cout << "recording time (in minutes): " << playTime << std::endl;
        putSalesData();
    }
};

int main() {
    Book book;
    Tape tape;

    std::cout << "Enter information for the book:\n";
    book.getData();
    std::cout << "\nEnter data for audio recording:\n";
    tape.getData();

    std::cout << "\ninformation for the book:\n";
    book.putData();
    std::cout << "\ndata for audio recording:\n";
    tape.putData();

    return 0;
}