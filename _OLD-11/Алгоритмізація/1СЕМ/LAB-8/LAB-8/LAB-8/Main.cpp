#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
void echoRight(string input, bool endline = 0){
	short w = 80;
	if(strlen(input.c_str()) < 80){
		for(int i = 0;i<(80 - strlen(input.c_str()));i++){
			cout << " ";
		};
		cout << input.c_str();
		if(endline)cout << endl;
	}
}
void echoCenter(string input, bool endline = 0){
	short w = 80;
	if(strlen(input.c_str()) < 80){
		for(int i = 0;i<(80 - strlen(input.c_str()))/2;i++){
			cout << " ";
		};
		cout << input.c_str();
		if(endline)cout << endl;
	}
}
float a[5], b[5];
const int n = 5;
float sk_d = 0, x = 1.38*n;
void z1(){
	echoCenter("�������� 1", 1);
	echoCenter("Pyf[jl;tyyz cevb? hspybws nf lj,enre ldj[ dtrnjhsd... �� �� ��i�");cout << endl;
	float sum[5], dif[5];
	for(int i = 1; i<n+1;i++){
		a[i-1] = pow(log(pow(x+1, 2)), 3)/3 - pow(i, 1/x);
		b[i-1] = pow(log(pow(6+i, 2./i)), 3)/(i - x + 3);
	}
	for(int i=0; i<n; i++){
		sum[i] = a[i] + b[i];
		dif[i] = a[i] - b[i];
		sk_d += a[i] * b[i];
	}
	cout << "+------------+---------------+---------------------+---------------------+" << endl;
	cout << "|  ������ �  |  ������ B     |  ���� �������      |  г����� �������   |" << endl;
	cout << "|  a[5]      |  b[i]         |  sum[i]             |  dif[i]             |" << endl;
	cout << "+------------+---------------+---------------------+---------------------+" << endl;
	for(int i=0;i<n;i++){
		cout << " " << a[i] << " \t " << b[i] << " \t " << sum[i] << " \t\t " << dif[i] << endl;
	}
	cout << "+------------+---------------+---------------------+---------------------+" << endl;
	cout << "��������� �������: " << sk_d << endl;
	system("pause >> NUL");
}
void z2(){
	echoCenter("�������� 2", 1);
	float sum = 0;
	cout << "�������� ������� a[" << n << "]:" << endl << "\t{";
	for(int i=0;i<5;i++){
		cout << a[i] << ", ";
	}
	cout << "\b\b}" << endl;


	cout << "³�'��� �������� ������� � ��������� ���������:" << endl << "\t{";
	bool no0 = 1;
	for(int i=0;i<5;i++){
		if(!i%2 && a[i]>0){
			sum += a[i];
			cout << a[i] << ", ";
			no0 = 0;
		}
	}
	if(no0){
		cout << "\b\b���� �����" << endl;
	}else{
		cout << "\b\b}" << endl;
		cout << "���� ������ ������� �������� ������: "<<sum<<endl;
	}
	system("pause >> NUL");
}
void z3(){
	echoCenter("�������� 3", 1);
	float start = 0;
	for(int i = 0;i<n;i++){
		if(a[i]>0){
			start = a[i];
			break;
		}
	}
	for(int i = start;i < n;i++){
		for(int j = start;j<n-1;j++){
			if (a[j+1] > a[j]){ 
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	cout << "����������i �������� ������� a[" << n << "]:" << endl << "\t{";
	for(int i=0;i<5;i++){
		cout << a[i] << ", ";
	}
	cout << "\b\b}" << endl;
	system("pause >> NUL");
}
int main(){
	setlocale(LC_ALL, "Ukrainian");
	echoCenter("----------------------------------------------------------------");cout << endl << endl;
	echoCenter("����������� ������ �8", 1);
	z1();
	echoCenter("----------------------------------------------------------------");cout << endl << endl;
	z2();
	echoCenter("----------------------------------------------------------------");cout << endl << endl;
	z3();

	return 0;
}