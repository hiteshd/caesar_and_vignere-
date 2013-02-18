#include <stdio.h>
#include <string.h>


char make_offset(char a,int the_key) {
	char c;
	if((a-'A'+the_key)<0) {
		c=(abs(a-'A'+the_key+26)%26) + 'A' ;
	}
	else {
		c=(a-'A'+the_key)%26 + 'A';
	}
	return c;
}


char* run_caesar(char* the_char,int the_key) {
	int i=0;
	char* a=the_char;
	for(i=0;i<strlen(the_char);i++) {
		if(isalpha(the_char[i])) {
			a[i]=make_offset(the_char[i],the_key);
		}
		else {
			a[i]=the_char[i];
		}
	}
	printf("Cipher : %s\n",a);
}

int main(int argc,char** argv) {

	if(argc!=4) {
		printf("\n------------------------\nUsage for Caesar Cipher.\n------------------------\n"
"Program accepts three arguments.\nThe first one is the plain or cipher text \nand the second one is the Key.\nThe third one is the mode \n e - encrypt \n d- decrypt \n\n For the above program, The key is specified as a letter. If the key is 'A' There is no change even after encryption as the shift of the letters will be 0\n\nUsage: %s <message> <key> <mode>\n\n",argv[0]);
		exit(0);
	}
	char* message=argv[1];
	char* key=argv[2];
	int base=65;
	int value=(int)key[0]-base;
	printf("Mode: %c\n",argv[3][0]);

	printf("Plaintext: %s\n",argv[1]);

	if(argv[3][0]=='e') {
		run_caesar(message,value);	
	}
	else if(argv[3][0]=='d') {
		run_caesar(message,-value);
	}
	
}