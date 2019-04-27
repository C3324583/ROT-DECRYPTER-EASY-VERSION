#include <stdio.h>
#include <stdlib.h>

void rotation(int x, char text[]);
void rotationdefault(char text[]);
 
int main(){
    //initialisation of variables and arrays
	char text[10000];
	int number_of_letter[127] = {0};
	int n, i, x, s=1, ascii, first=0, second=0, third=0, fourth=0, fifth=0;
	
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
	
	for (x=0; x<126; ++x){
	    if(number_of_letter[x] > number_of_letter[first]){
	        first = x;
	    }
	}
	
	for (x=0; x<126; ++x){
	    if(x != first && number_of_letter[x] <= number_of_letter[first] && number_of_letter[x] > number_of_letter[second]){
	        second = x;
	    }
	}
	
    for (x=0; x<126; ++x){
	    if(x != first && x != second && number_of_letter[x] <= number_of_letter[second] && number_of_letter[x] > number_of_letter[third]){
	        third = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && number_of_letter[x] <= number_of_letter[third] && number_of_letter[x] > number_of_letter[fourth]){
	        fourth = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && x != fourth && number_of_letter[x] <= number_of_letter[fourth] && number_of_letter[x] > number_of_letter[fifth]){
	        fifth = x;
	    }
	}


    rotation(first, text);
    rotation(second, text);
    rotation(third, text);
    rotation(fourth, text);
    rotation(fifth, text);
    printf("My code is shit but one of these should be correct:\n");rotationdefault(text);
    
	return 0;
}




void rotation(int x, char text[]){
    char txt[10000];
    for(int y=0;text[y] != '\0'; y++){
        txt[y]=text[y];
    }
    int rotationkey = x - 'E';
	int success;
    for(int i=0; txt[i] != '\0'; i++){
        if(txt[i] >= 'A' && txt[i] <= 'Z'){
    		txt[i] = txt[i] - rotationkey;
    		if(txt[i]>'Z'){
		        txt[i] = txt[i] - 26;
		    }
		    if(txt[i]<'A'){
		        txt[i] = txt[i] + 26;
		    }    
		}
    }

	printf("Is this the correct message: %s\n", txt); //prints the rotated message to the screen
	printf("Yes - Press 1 and then <enter> \nNo - Press 0 and then <enter> \n");
	scanf("%d", &success);
	if(success == 1){
	    exit(0);
    }
}



//this function prints all possible rotation keys to the screen if the first function fails to find the correct rotation key
void rotationdefault(char text[]){
    char txt[10000];
    for(int y=0;text[y] != '\0'; y++){
        txt[y]=text[y];
    }

    for(int x=0; x<=25; x++){
        for(int i=0; txt[i] != '\0'; i++){
            if(txt[i] >= 'A' && txt[i] <= 'Z'){
        		txt[i] = txt[i] + 1;
    	    	if(txt[i]>'Z'){
    		        txt[i] = txt[i] - 26;
    		    }
    		}
	    }
	    printf("%s\n", txt);
    }
} 