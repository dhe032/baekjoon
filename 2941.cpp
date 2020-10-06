#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string alphabet;
	cin >> alphabet;
	/*
	č	c=
	ć	c-
	đ	d-
	š	s=
	ž	z=
	*/
	int i = 0;
	int num = 0;
	
	while(i < alphabet.size()) {
		if(i + 1 < alphabet.size()){
			if(alphabet[i] == 'c' && alphabet[i+1] == '=')
				i += 1;
			else if(alphabet[i] == 'c' && alphabet[i+1] == '-')
				i += 1;
			else if(alphabet[i] == 'd' && alphabet[i+1] == '-')
				i += 1;
			else if(i+2 < alphabet.size() && alphabet[i] == 'd' && alphabet[i+1] == 'z' &&  alphabet[i+2] == '=')
				i += 2;
			else if(alphabet[i] == 's' && alphabet[i+1] == '=')
				i += 1;
			else if(alphabet[i] == 'z' && alphabet[i+1] == '=')
				i += 1;
			else if(alphabet[i] == 'l' && alphabet[i+1] == 'j')
				i += 1;
			else if(alphabet[i] == 'n' && alphabet[i+1] == 'j')
				i += 1;
		}
		num++;
		i++;
	}
	
	cout << num;
	
	return 0;
}