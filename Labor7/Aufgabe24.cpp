#include <iostream>
#include <list>
#include <string>
using namespace std;

class ISubscriber {
public:
	virtual void update(const string& message_from_store) = 0;
};

class IStore {
public:
	virtual void subscribe(ISubscriber* subscriber) = 0;
	virtual void unsubscribe(ISubscriber* subscriber) = 0;
	virtual void notifySubscribers() = 0;
	virtual void sellGoods() = 0;
	virtual void deliverGoods() = 0;
};

class Store : public IStore {
private:
	list<ISubscriber*> subscriber_list;
	string message;
public:

	void subscribe(ISubscriber* subscriber) override {
		subscriber_list.push_back(subscriber);
	}
	void unsubscribe(ISubscriber* subscriber) override {
		subscriber_list.remove(subscriber);
	}
	void notifySubscribers() override {
		list<ISubscriber*>::iterator iterator = subscriber_list.begin();
		while (iterator != subscriber_list.end()) {
			(*iterator)->update(message);
			++iterator;
		}
	}

	void sellGoods() {
		this->message = "IPhone nicht mehr verfügbar";
		notifySubscribers();
	}
	void deliverGoods() {
		this->message = "IPhone verfügbar";
		notifySubscribers();
	}
};

class Customer : public ISubscriber {
private:
	string message_from_store;
	//Store& store;
	static int ID;
	int number;
public:
	Customer() {
		++Customer::ID;
		this->number = ID;
	}
	void update(const string& _message_from_store) override {
		message_from_store = _message_from_store;
		cout << "Customer " << this->number << ": neue Nachricht verfügbar --> " << this->message_from_store << endl;

		
	}
};

int Customer::ID = 0;

void ClientCode()
{
	Store* store = new Store;
	Customer* customer1 = new Customer();
	store->subscribe(customer1);
	Customer* customer2 = new Customer();
	store->subscribe(customer2);
	Customer* customer3 = new Customer();
	store->subscribe(customer3);
	Customer* customer4;
	Customer* customer5;
	store->deliverGoods();
	store->unsubscribe(customer3);
	store->sellGoods();
	customer4 = new Customer();
	store->subscribe(customer4);
	store->unsubscribe(customer2);
	customer5 = new Customer();
	store->subscribe(customer5);
	store->deliverGoods();
	store->unsubscribe(customer5);
	store->unsubscribe(customer4);
	store->unsubscribe(customer1);
}
int main(int argc, char* argv[]) {
	ClientCode();
	return 0;
}