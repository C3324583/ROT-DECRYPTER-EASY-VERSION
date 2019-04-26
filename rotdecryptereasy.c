#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialisation of variables and arrays
	char text[10000];
	int number_of_letter[127] = {0};
	int n, i, x, y, ascii, rotationkey, MAX = 0, common_letter;
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
   
   /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
    }
    
	for(ascii='A'; ascii<='Z'; ascii++){
	    for(i=0; text[i] != '\0'; i++){
	        if(ascii==text[i]){
	            number_of_letter[ascii]++;
	        }
        } 
	}
	
	for (x=0; x<126; x++){
	    if(number_of_letter[x] > MAX){
	        MAX = number_of_letter[x];
	        common_letter = x;
	    }
	}

	rotationkey = common_letter - 'E';
	
    for(y = 0; text[y] != '\0'; y++){
        if(text[y] >= 'A' && text[y] <= 'Z'){
    		text[y] = text[y] - rotationkey;
    		if(text[y]>'Z'){
		        text[y] = text[y] - 26;
		    }
		    if(text[y]<'A'){
		        text[y] = text[y] + 26;
		    }    
		}
    }

	printf("The decrypted message is: %s", text); //prints the rotated message to the screen	
		
	return 0;
}