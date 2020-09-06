#include <iostream>
using namespace std;

int main()
{
	int w, h, cnt=0;
	bool m[101][101];

	cin >> w >> h;
	for(int i=0; i<w; i++){
		char c[100];
		cin >> c;
		for(int j=0; j<h; j++){
			m[i][j] = (c[j] == '#');
			cnt += m[i][j];
		}
	}
	if((w*h-cnt)%2 == 1){
		cout << "No";
		return 0;
	}
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
            if(m[i][j] == true)continue;
			if(m[i][j] == false && i+1<w && m[i+1][j] == false){
				m[i][j] = true;
				m[i+1][j] = true;
				continue;
			}
			if(m[i][j] == false && j+1<h && m[i][j+1] == false){
				m[i][j] = true;
				m[i][j+1] = true;
				continue;
			}
		}
	}

	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(m[i][j] == false){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
