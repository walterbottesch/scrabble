#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXBUFFERSIZE      80

char buffer[MAXBUFFERSIZE];
int findIndex(char c);
void getAnInput();
int compute_score(char word[]);

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alfabet[] = "abcdefghijklmnopqrstuvwxyz";

void getAnInput() {
    buffer[0] = 0x00;
   char c;
   int valid_choice = 0;
   int char_count;
    do  {
        //getting any input
        c = getchar();
        char_count = 0;
        while (c != '\n'  && char_count < MAXBUFFERSIZE)  {
            buffer[char_count++] = c;
            c = getchar();
        } 
        buffer[char_count] =0x00; 
        valid_choice = 1;
    } while (valid_choice == 0); 
    
}
int findIndex(char c) {
    for (size_t i = 0; i < 26 ; i++)  {
        if (c == alfabet[i])
            return i;  
    } 
    return -1;
}

int compute_score(char word[]) {
    int score = 0;
    for (size_t i = 0; i < strlen(word); i++)  {
        if (isalpha(word[i]))
            score += POINTS[findIndex(tolower(word[i]))];
    }
    return score;
}

int main(void) {
    char word1[MAXBUFFERSIZE] ;
    char word2[MAXBUFFERSIZE] ;
    
    // Get input words from both players
    printf("word1 : ");
    getAnInput();
    int sw1 = strlen(buffer);
    for (size_t i = 0; i < sw1; i++)  {
        word1[i] = buffer[i];
    }
    printf("word2 : ");
    getAnInput();
    int sw2 = strlen(buffer);
    for (size_t i = 0; i < sw2; i++)  {
    word2[i] = buffer[i];
}
  // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
 
    // TODO: Print the winner 
    if (score1 > score2)  {
        printf("Player 1 wins! \n");
    } else if (score1 < score2) {
        printf("Player 2 wins!");
    } else  {
        printf("Tie !");
    }
}
