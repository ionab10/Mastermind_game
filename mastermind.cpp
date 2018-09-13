/* Iona Buchanan
April 30, 2013
"Mastermind" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

struct guessing {
       int g;           //guess number
       char guess[5];   //user guess
       };
       
void guessCode(int g, int d, int guess[][5]);
void printNumGuess(int g, int d, int guess[][5]);
void checkNumGuess(int g, int d, int guess[][5], int code[]);

void guessWord(int g, int d, struct guessing *guesses);
void checkWordGuess(int g, int d, struct guessing *guesses, char *word);

/////////////////////


int main() {


printf("XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO");  
  
printf("\n\n\t\t                     _                                              _"); 
printf("\n\t\t/'\\_/`\\             ( )_                      /'\\_/`\\ _            ( )"); 
printf("\n\t\t|     |   _ _   ___ | ,_)   __   _ __  ______ |     |(_)  ___     _| |");
printf("\n\t\t| (_) | /'_` )/',__)| |   /'__`\\( '__)(______)| (_) || |/' _ `\\ /'_` |");
printf("\n\t\t| | | |( (_| |\\__, \\| |_ (  ___/| |           | | | || || ( ) |( (_| |");
printf("\n\t\t(_) (_)`\\__,_)(____/`\\__)`\\____)(_)           (_) (_)(_)(_) (_)`\\__,_)");


printf("\n\n\n\t\t\t\t\twith Iona Buchanan\t\n\n\n\n");

printf("XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXOXO\n\n");


system ("pause");
system ("cls");




char username[20];
int playagain = 0; 
char numOrWord[5];

     printf("Please enter your name\n\n");
               scanf("%s", &username);
               
     printf("\n\n");
               
               
               
               
system ("pause");
system ("cls");     



     printf("In this game, the goal is to guess a set of secret digits in the correct order or a word from the Scrabble dictionary.\n");
     
     do {
         printf("\n\nWould you like to play with numbers (easy) or a word (difficult)?\n");     //choose to play with #s or words
         printf("(type 'num' for numbers or 'word' for a word)\n\n\n");  
                   scanf("%s", &numOrWord); 
                   fflush(stdin);
                   
                   if(strcmp(numOrWord, "num") != 0 && strcmp(numOrWord, "word") != 0) {
                                        printf("\n\nSorry, that is not a valid entry\n\n");
                                        system ("pause");
                                        system ("cls");
                                        }
                   
         } while (strcmp(numOrWord, "num") != 0 && strcmp(numOrWord, "word") != 0); //if invalid entry



printf("\n\n");     
system ("pause");
system ("cls");



     
do { 
     
     int d = 0;          //number of digits/letters
     int guessAllowed = 0;          //number of guesses allowed
     int g = 0; //number of guesses so far
     int i = 0, j = 0, k = 0;




/////////////////////number option////////////////////////////////


     if (strcmp(numOrWord, "num") == 0) {


        system ("cls"); 
        printf("How many digits would you like to play with? Enter an integer from 4 and 6.\n");      
        printf("Note that the more digits, the harder the game is.\n");
                 scanf("%d", &d);
                 fflush(stdin);
                 
                       while (d != 4 && d != 5 && d != 6) {                   //if invalid entry
                       printf("\nPlease enter an integer from 4 to 6.\n"); 
                                      scanf("%d", &d);
                                      fflush(stdin);
                       }
         
         
         
                       
         int code[d-1];
     
             for (i=d; i<6; i++){        //default 
                 code[i] = 0; 
                 }
                       
                       
                       
                       
         printf("\n\nHow many guesses would you like to have?\n"); 
         printf("Note that the fewer the guesses, the harder the game is.\n");
                  scanf("%d", &guessAllowed);
                  fflush(stdin);
                  
                       while (guessAllowed<=0 || guessAllowed>30 || guessAllowed % guessAllowed != 0) {                   //if invalid entry
                       printf("\nPlease enter a positive integer less or equal to 30.\n"); 
                                      scanf("%d", &guessAllowed);
                                      fflush(stdin);
                       }                      
                  
     

     
     
         int guess[guessAllowed][5];   
                   
              for (j=0; j<guessAllowed; j++){        //default 
                   for (i=0; i<6; i++){        
                       guess[j][i] =0;
                       }
                   }                                        

          
          
srand(time(0));

              for (i=0; i<d; i++){
                  code[i] = rand() % 9 + 0; 
                  }
           
             /* for (i=0; i<6; i++){
                  printf("%d ", code[i]); 
                  } */
                  
                  
printf("\n\n");                  
system ("pause");                  
system ("cls"); 
              
              do {
                  guessCode(g, d, guess);    //user inputs guess
                  
              system ("cls"); 
              
                  printf("GUESSES\n\n");
                  printf("An 'o' represents a correct digit in its correct place and an 'x' represents a correct digit but in an incorrect place (these symbols are not necessarily in the right order)\n\n");
                  
                  for (i=0; i<=g; i++) {
                      printf("%d.\t",i+1);
                      printNumGuess(i, d, guess);           //guesses
                      checkNumGuess(i, d, guess, code);     //check with "o"s and "x"s
                      printf("\n");
                      }
                      
                  for (i=g+2; i<=guessAllowed; i++) {         //spaces for future guesses
                      printf("%d.\n", i);
                      }
              
                  printf("\n\n");
                   
                  
                  if (guess[g][0]==code[0] &&       //if guessed correctly
                      guess[g][1]==code[1] &&
                      guess[g][2]==code[2] &&
                      guess[g][3]==code[3] &&
                      guess[g][4]==code[4] &&
                      guess[g][5]==code[5]
                      ){
                                            printf("Congratulations, %s! You cracked the code in %d out of %d tries!", username, g+1, guessAllowed);
                                            break;
                                            }
                      
                           
                      else if (g>=guessAllowed-1) {                  //if ran out of guesses
                           printf("Sorry, %s, you ran out of guesses! The code was", username);
                           
                           for (i=0; i<d; i++){
                               printf(" %d", code[i]); 
                               }   
                               
                           printf(". Better luck next time!");                   
                           break;
                           }
                      
                   g++;
                           
                  } while (g<guessAllowed);   //until guess limit is reached
             
             }    
             
             
////////////////////////////////////////////////////////             
             
             

             
//////////////////word option///////////////////////////             
    
    else if (strcmp(numOrWord, "word") == 0) { 
    
     char word[5];             //secret word
     char dictWord[5];         //words to build array (read from file)
     char dictArray3[933][4]; //array of all 3-letter words in dictionary
     char dictArray[5525][5]; //array of all 4-letter words in dictionary
                       
system("cls");
                                       
     printf("Would you like to play with 3 or 4 letters?\n");      
     printf("Note that the more letters, the harder the game is.\n");
                 scanf("%d", &d);
                 fflush(stdin);
                 
                       while (d != 3 && d != 4) {                   //if invalid entry
                       printf("\nPlease enter either 3 or 4.\n"); 
                                      scanf("%d", &d);
                                      fflush(stdin);
                       }    
                       
     
     
         printf("\n\nHow many guesses would you like to have?\n"); 
         printf("Note that the fewer the guesses, the harder the game is.\n");
                  scanf("%d", &guessAllowed);
                  
                       while (guessAllowed<=0 || guessAllowed>30 || guessAllowed % guessAllowed != 0) {      //if invalid entry             //if invalid entry
                       printf("\nPlease enter a positive integer less or equal to 30.\n"); 
                                      scanf("%d", &guessAllowed);
                                      fflush(stdin);
                       }                      

         
                     
     
     guessing guesses[guessAllowed];         //array of user's guesses                         

          
srand(time(0));


     

               FILE *fptr;
     
              //////////3 letter words////////
              if (d == 3) {
          
	          fptr = fopen("3letterwords.txt", "r");   //open file to read word from file
           
    
                if (fptr == NULL) {                 //Error checking
		            printf("unable to open 3letterwords.txt");
		                     return(1);
                        }
        
              while (fscanf(fptr, "%s", &dictWord) != EOF){ // read and check for end of file
               
                            strcpy(dictArray[k], dictWord);    //build array
                            k++;
               
                   }
               
               strcpy(word, dictArray[rand() % 933 + 0]); //get random secret word

                                      }
                     

                     
              ///////4 letter words////////
              if (d == 4) {

	          fptr = fopen("4letterwords.txt", "r");   //open file to read word from file
           
    
                if (fptr == NULL) {                 //Error checking
		           printf("unable to open 4letterwords.txt");
		           return(1);
                   }
        
              while (fscanf(fptr, "%s", &dictWord) != EOF){ // read and check for end of file
               
                            strcpy(dictArray[k], dictWord);    //build array
                                    k++;
               
                   }
               
               strcpy(word, dictArray[rand() % 5525 + 0]); //get random secret word
                     
                            }           
             
	         fclose(fptr);              //close file
	
	


printf("\n\n");
           
//printf("%s", word);
                  
system ("pause");                  
system ("cls"); 
              
              do {
                  guessWord(g, d, guesses);    //user inputs guess
                  
              system ("cls"); 
              
                  printf("GUESSES\n\n");
                  printf("An 'o' represents a correct letter, a '-' represents a letter too early in the alphabet and an '+' represents a letter too late in the alphabet(the symbols are not necessarily in the right order)\n\n");
                  
                  for (i=0; i<=g; i++) { //list of guesses
                      printf("%d.\t",i+1);
                      printf("%s ", &guesses[i].guess);         //guess
                      checkWordGuess(i, d, guesses, word);         //check with "o"s, "+"s and "-"s
                      printf("\n");
                      }
                      
                  for (i=g+2; i<=guessAllowed; i++) {         //spaces for future guesses
                      printf("%d.\n", i);
                      }
              
                  printf("\n\n");
                   
                  
                  if ((d==3&&
                      toupper(guesses[g].guess[0]) == word[0] &&       //if guessed right (3letter)
                      toupper(guesses[g].guess[1]) == word[1] &&
                      toupper(guesses[g].guess[2]) == word[2])||
                      (d==4&&
                      toupper(guesses[g].guess[0]) == word[0] &&       //if guessed right (4letter)
                      toupper(guesses[g].guess[1]) == word[1] &&
                      toupper(guesses[g].guess[2]) == word[2] &&
                      toupper(guesses[g].guess[3]) == word[3] )
                      ){
                                            printf("Congratulations, %s! You cracked the code in %d out of %d tries!", username, g+1, guessAllowed);
                                            break;
                                            }
                      
                           
                      else if (g>=guessAllowed-1) {                  //if ran out of guesses
                           
                           printf("Sorry, %s, you ran out of guesses! The word was %s. Better luck next time!", username, word);
                     
                           break;
                           } 
                      
                   g++;
                           
                  } while (g<guessAllowed);   //until guess limit is reached
                  
              }              
                  
                  
///////////////////////////////////////////////////        
             
   
   printf("\n\nPlay again? (yes: 1\tno:0)\n");             //play again?
                    scanf("%d", &playagain);   
                 
   } while(playagain!=0);
   
   
getchar();
return (0);
}


//functions/////////////////

void guessCode(int g, int d, int guess[][5]) {
     int i=0;
     
     printf("Guess a sequence of %d digits (press 'return' after each digit):\n", d); 
     
     for (i=0; i<d; i++){
         scanf("%d", &guess[g][i]);
         fflush(stdin);
         
         
         while (guess[g][i] < 0 || guess[g][i] > 9) {                   //if invalid entry
               printf("\nPlease enter a valid guess.\n"); 
                                scanf("%d", &guess[g][i]);
                                fflush(stdin);
               }       
                 
                             
         }
     }
     
     
     
     
void printNumGuess(int g, int d, int guess[][5]) {
     int i=0;
     
     for (i=0; i<d; i++){
         printf("%d ", guess[g][i]);
         }    
         
     }
     
     
     
     
void checkNumGuess(int g, int d, int guess[][5], int code[]) {
     int i=0;
     
     for (i=0; i<d; i++) {                       //if correct digit in correct space
         if (guess[g][i]==code[i]){
            printf("o ");
            }
         }
                  
     for (i=0; i<d; i++) {                       //if correct digit but in wrong space
         if (guess[g][i]!= code[i] && 
             ((guess[g][i]==code[0] && guess[g][0]!=code[0])||          //digit appears in a diff place and is not correct in that place
              (guess[g][i]==code[1] && guess[g][1]!=code[1])||
              (guess[g][i]==code[2] && guess[g][2]!=code[2])||
              (guess[g][i]==code[3] && guess[g][3]!=code[3])||
              (guess[g][i]==code[4] && guess[g][4]!=code[4])||
              (guess[g][i]==code[5] && guess[g][5]!=code[5]))
             ) {
                printf("x ");
            }   
         }
         
     }
     
     
     
void guessWord(int g, int d, struct guessing *guesses) {
     
     printf("Guess a %d-letter word:\n", d); 
     
         scanf("%s", &guesses[g].guess);
         fflush(stdin);
         
         while (guesses[g].guess[d] != NULL ||         //if word is too long
                tolower(guesses[g].guess[0]) < 'a' || tolower(guesses[g].guess[0]) > 'z' ||   //if first character is not a letter
                tolower(guesses[g].guess[1]) < 'a' || tolower(guesses[g].guess[1]) > 'z' ||
                tolower(guesses[g].guess[2]) < 'a' || tolower(guesses[g].guess[2]) > 'z' ||
                tolower(guesses[g].guess[d-1]) < 'a' || tolower(guesses[g].guess[d-1]) > 'z') {                   //if invalid entry
               
               printf("\nPlease enter a valid guess.\n"); 
                                scanf("%s", &guesses[g].guess);
                                fflush(stdin);
               }    
         
     }
     

   
void checkWordGuess(int g, int d, struct guessing *guesses, char *word) {
     int i=0;
     
     for (i=0; i<d; i++) {                 //if correct letter in correct place
         if (toupper(guesses[g].guess[i]) == word[i]){
            printf("o ");
            }
         }
         
         
     for (i=0; i<d; i++) {                //if letter is too early in the alphabet
         if (toupper(guesses[g].guess[i]) < word[i]) {
                printf("- ");
            }   
         }
         
     for (i=0; i<d; i++) {                //if letter is too late in the alphabet
         if (toupper(guesses[g].guess[i]) > word[i]) {
                printf("+ ");
            }   
         }
         
     }
     
