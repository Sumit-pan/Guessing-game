#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void recorder(char name[], int number, char status[]) {
  FILE *fp;
  fp = fopen("record.txt", "a");
  fprintf(fp, "\n%s\t%d\t%s", name, number, status);
  fclose(fp);
}


void records() {
  char name[50], status[50];
  int number;
  FILE *fp;
  int i = 1;
  system("clear");

  printf("\n                   History                        \n \n");

  fp = fopen("record.txt", "r");
  while((fscanf(fp,"%s%d%s\n",&name,&number,&status))!=EOF) {
  printf("%d.\tPlayer: %s\tNumber: %d\tStatus: %s\n\n", i, name,number, status);
    i++;
  }
  fclose(fp);
}



int main()

{
int num, guess, noOfGuesses = 1;
char name[50],choice;


  printf("Note: Type \"r\" to view match history and \"s\" to start a match.\n\n");
  scanf(" %c", &choice);
  while (1) {
    if (choice == 'r') {
      records();
      exit(0);
    } else if (choice == 's') {
      break;
    } else {
      int a;
      printf("\nThe code is invalid. Enter a correct option: ");
      scanf(" %c", &choice);
    }
  }
    printf("Enter your name: ");
  scanf("%s",&name);
srand(time(0));
num = rand() % 100 + 1;
  system("clear");
printf("Guessing game!\n");
printf("A number between 1 and 100 has been chosen\n");
printf("Try to guess the number if you can\n");
printf("You have 5 hearts\n");
 while(1)
   {
 printf("Guess #%d: ", noOfGuesses);
 scanf("%d", &guess);
 if (guess > num) {
  printf("The guess is higher than the number\n");
 } else if (guess < num) {
  printf("The guess is lower than the number\n");
 }
  else{
    break;
  }
 noOfGuesses++;
     if(noOfGuesses==6)
     {
       break;
     }
    }
 if(noOfGuesses<6)
 {
   char status[]="won";
printf("You guessed it! The number was %d\n", num);
   printf("%d guesses were taken\n", noOfGuesses);
   recorder(name,num,status);
   }
  else{
    char status[]="lost";
    printf("You have lost.");
    recorder(name,num,status);
    }
    
return 0;
  }