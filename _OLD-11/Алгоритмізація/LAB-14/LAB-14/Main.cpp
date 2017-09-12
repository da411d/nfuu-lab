#include <iostream>
#include <string>
using namespace std;

string convertString(string s){
	string s2 = "";
	if(s[0] == ' '){
		s = s.substr(1);
	}
	if(s.size()%2 == 0){
		for(int i=0;i<s.size();i++){
			if(s2.find(s[i]) < 0 || s2.find(s[i]) > s.size()){
				s2 += s[i];
			}
		}
	}else{
		s2 = s.substr(0, (s.size()-1)/2) + s.substr((s.size()+1)/2);
	}
	return s2;
}

string str, str2, tmp, last;

void main(){
	getline(cin, str);
	last = convertString(str.substr(str.rfind(" "), str.length()-1));
	cout << "\r\n\r\n";
	int offset = 0;
	do{
		tmp = convertString(str.substr(offset, str.find(" ", offset+1)-offset));
		if(tmp != last){
			str2 += tmp+" ";
		}
		offset = str.find(" ", offset+1);
	}while(offset >= 0);
	cout << str2;
	system("pause>>nul");
}