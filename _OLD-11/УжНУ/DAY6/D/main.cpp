#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
//*-a/bc+/def
char opnds[1024][1024], oprs[1024];
int topr = -1, top = -1;
void pushd(char *opnd){
     strcpy(opnds[++top], opnd);
}
char *popd(){
	return opnds[top--];
}
void pushr(char opr){
    oprs[++topr] = opr;
}
char popr(){
    return oprs[topr--];
}
bool empty(int t){
	return !t;
}

int main(){
    char prfx[1024], ch, str[1024], opnd1[1024], opnd2[1024], opr[2];
    int i=0, k=0, opndcnt=0;
    cin >> prfx;
	while( (ch=prfx[i++]) != '\0' ){
        if(isalnum(ch)){
            str[0] = ch;
            str[1] = '\0';
            pushd(str);
            opndcnt++;
            if(opndcnt >= 2){
                strcpy(opnd2, popd());
                strcpy(opnd1, popd());
                strcpy(str, "(");
                strcat(str, opnd1);
                ch = popr();
                opr[0] = ch;opr[1] = '\0';
                strcat(str, opr);
                strcat(str, opnd2);
                strcat(str, ")");
                pushd(str);
                opndcnt -= 1;
            }
        }else{
            pushr(ch);
            if(opndcnt == 1)opndcnt = 0;
        }
	}
	if(!empty(top)){
		strcpy(opnd2, popd());
		strcpy(opnd1, popd());
		strcpy(str, "(");
		strcat(str, opnd1);
		ch = popr();
		opr[0] = ch;
		opr[1] = '\0';
		strcat(str, opr);
		strcat(str, opnd2);
		strcat(str, ")");
		pushd(str);
	}
	for(int i=1; i<strlen(opnds[top])-1; i++){
		cout << opnds[top][i];
	}
}
