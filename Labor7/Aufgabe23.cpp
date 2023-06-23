#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IComponent {
public:
	virtual void add(IComponent* component) {
	}
	virtual int getPrice() const = 0;
};

class Product :public IComponent {
	int price;
public:
	Product(int price_) :price(price_) {}
	int getPrice() const override {
		return price;
	}
};

class Box :public IComponent {
protected:
	vector<IComponent*> children_;
public:
	void add(IComponent* component) override {
		this->children_.push_back(component);
	}
	int getPrice() const override {
		int result = 0;
		for (const IComponent* c : children_) {
			result += c->getPrice();
		}
		return result;
	}
};
void ClientCode(IComponent* component)
{
	cout << "Price: " << component->getPrice() << endl;
}

int main(int argc, char* argv[]) {
	IComponent* product = new Product(10);
	cout << "Client: ein einfaches Produkt: " << endl;
	ClientCode(product);
	cout << endl << endl;

	IComponent* outerBox = new Box;
	IComponent* innerBox1 = new Box;

	IComponent* product1 = new Product(10);
	IComponent* product2 = new Product(5);
	IComponent* product3 = new Product(4);
	innerBox1->add(product1);
	innerBox1->add(product2);
	IComponent* innerBox2 = new Box;
	innerBox2->add(product3);
	outerBox->add(innerBox1);
	outerBox->add(innerBox2);
	cout << "Client: eine verschachtelte Box: " << endl;
	ClientCode(outerBox);
	cout << endl << endl;

	return 0;
}