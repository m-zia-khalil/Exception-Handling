#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;
class account {
private:
	string name;
	double money;
public:
	account(string n, double m) :name(n), money(m) {
		if (money < 0) {
			throw invalid_argument("The Money cannot be below zero");
		}
		cout << "The constructor called   " << endl;


	}

	void withdraw(double amo) {
		if (amo > money) {
			throw runtime_error(" Balance is not enough ");
		}
		money -= amo;
		cout << "The cash is   :  " << amo << endl;
		cout << "The remaining balance from account: " << money << endl;
	}
	~account() {
		cout << "The destructor called   " << endl;
	}

};
int main() {
	try {
		account* obj = new account("Adil", -710);
		delete obj;
	}
	catch (exception& s) {
		cout << "Exception caught " << s.what() << endl;
	}
	try {
		account* obj_1 = new account("Umair", 900);

		try {
			obj_1->withdraw(1200);
		}
		catch (exception& s) {
			cout << "Error caught" << s.what() << endl;
		}
		delete obj_1;
	}
	catch (exception& s) {
		cout << "Error caught" << s.what() << endl;
	}
	return 0;
}