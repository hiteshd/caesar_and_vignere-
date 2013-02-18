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


char* run_vigenere(char* the_char,char* the_key,int base,int mode) {
	int i=0;
	char* a=the_char;
	for(i=0;i<strlen(the_char);i++) {
		if(isalpha(the_char[i]))
			a[i]=make_offset(the_char[i],(mode)*((int)the_key[i%strlen(the_key)]-base));
		else
			a[i]=the_char[i];
	}
	printf("Output : %s\n",a);
}

int main(int argc,char** argv) {

	if(argc!=4) {
			printf("\n------------------------\nUsage for Vigenere Cipher.\n------------------------\n"
"Program accepts three arguments.\nThe first one is the plain or cipher text \nand the second one is the Key.\nThe third one is the mode \n e - encrypt \n d- decrypt \n\n For the above program, The key is specified as a string. If the key is 'A' this will be a caesar cipher\n\nUsage: %s <message> <key> <mode>\n\n",argv[0]);
	
			exit(0);
	}
	char* message=argv[1];
	char* key=argv[2];
	int base=65;
	int value=(int)key[0]-base;
	printf("Mode: %c\n",argv[3][0]);

	printf("Input: %s\n",argv[1]);

	if(argv[3][0]=='e')
		run_vigenere(message,key,base,1);	
	else if(argv[3][0]=='d')
		run_vigenere(message,key,base,-1);
	else
		printf("Wrong Mode selected. Mode can be either encrpyt -e or decrypt -d \n Try again");

	return(1);
	}