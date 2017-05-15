#include <iostream>
#include <string>
#include <fstream>

#define fileName "input.txt"
using namespace std;

struct CONTACT { 
	string name;
	string phone[3];
};

CONTACT AddInfo(CONTACT buff);
CONTACT* AddContact(CONTACT* telephone, int &amount);

int main() {
	setlocale(LC_ALL, "RUS");
	CONTACT *telephone = NULL;
	int amount = 0;
	system("pause");
	return 0;
}

CONTACT* AddContact(CONTACT* telephone, int &amount) {
	if (amount == 0) {
		telephone = new CONTACT[amount + 1];
	}
	else {
		CONTACT* temp = new CONTACT[amount + 1];
		temp = telephone;
		AddInfo(temp[amount]);
		WriteContactToFile(temp);
		delete[] telephone;
		telephone = temp;
	}
	amount++;
	return telephone;
}

CONTACT AddInfo(CONTACT buff) {
	cout << "Enter Name: ";
	cin >> buff.name;
	bool next = true;
	int i = 0;
	while (next && i < 3) {	
		if (i != 0) {
			cout << "Would you like to add one more number?: (1 - yes, 0- no): ";
			cin >> next;
		}
		cout << "Enter telephone number: ";
		cin >> buff.phone[i];
		i++;
	}
	return buff;
}

void CountContact(int &amount) {
	string buff;

	ifstream fin(fileName);
	while (fin.eof()) {
		getline(fin, buff);
		if (buff.empty()) continue;
		else amount++;
	}
	fin.close();
}

void WriteFileContact(CONTACT buff) {
	ofstream fout(fileName, ios::app);
	fout << buff.name << ' ';
	fout << buff.phone[0] << ' ';
	if (!buff.phone[1].empty())
		fout << buff.phone[1] << ' ';
	fout << buff.phone[2] << endl;
	fout.close();
}

void ReadInfo() {
	ifstream fin(fileName);
	while (!fin.eof()) {

	}
}