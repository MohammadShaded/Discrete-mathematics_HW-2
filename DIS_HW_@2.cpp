
#include <iostream>
#include <fstream>
#include<string>
#include <vector>
using namespace std;
int main()
{
	while (1) {
		int x, op;
		ifstream File;
		char c, n1, n2,CRes[4];
		cout << "1. sets operations " << endl;
		cout << "2. list all element power sets" << endl;
		cin >> x;
		if (x == 1) {
			cout << "\nselect an operation" << endl;
			cout << "1. complement of (A union B)" << endl;
			cout << "2. A intersection B" << endl;
			cout << "3. A - B" << endl;
			cout << "4. A xor B" << endl;

			File.open("Text.txt");

			int bi1[32], bi2[32], res[32];
			fill_n(bi1, 32, 0);
			fill_n(bi2, 32, 0);
			fill_n(res, 32, 0);

			File >> c;
			n1 = c;
			File >> noskipws >> c;
			while (c != '}') {
				File >> x;
				File >> c;
				
				for (int i = 0; i < 32; i++) {
					if (i == x) bi1[i] = 1;
				}
			}

			File >> c;
			File >> c;
			n2 = c;
			while (!File.eof()) {

				File >> c;
				if(c!='}')File >> x;
				for (int i = 0; i < 32; i++) {
					if (i == x) bi2[i] = 1;
				}
			}

			cout << "\nEnter option: ";
			cin >> op;
			for (int i = 0; i < 32; i++) {
				switch (op) {
				case 1: res[i] = !(bi1[i] || bi2[i]); break;
				case 2: res[i] = (bi1[i] && bi2[i]); break;
				case 3: res[i] = (bi1[i] && !(bi2[i])); break;
				case 4: res[i] = (bi1[i] != bi2[i]); break;

				}
			}
			cout << "the result set is{";
			for (int i = 0; i < 32; i++) {
				if (res[i])cout << i << ',';

			}
			cout << "}\n\n" << endl;
		}







		else if (x == 2) {
			
			vector<char>elems;
			File.open("Text2.txt");
			while (!File.eof()) {

				File >> c;
				if (c == '{' || c == '}' || c == ',')continue;
				elems.push_back(c);
			}
			x = elems.size();


			cout << "power set ={{},";
			for (int s = 1; s < (pow(2, x)); ++s)
			{

				cout << "{";
				for (int e = 0; e < x; ++e)
				{
					if (s & (1 << e))
					{
						cout << ',' << elems[e];
					}
				}
				cout << "} , ";

			}
			cout << '}' << endl;











		}
	}

	



	
	

}







