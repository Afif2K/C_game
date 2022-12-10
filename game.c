#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Character CHAR;

struct Character{
    char name[50];
    char gender[10];
    char pronoun[5];
};

struct coordinate{
    int lat;
    int lon;
};


//boat
void waitOutTheStorm(CHAR A);
void solveRiddleBoat(CHAR A);
void goIntoTheStorm(CHAR A);
void runawayFromStorm(CHAR a);


//plane
void Lie1(CHAR A);
void Lie2(CHAR A);
void telltruth(CHAR a);


//decision
void ifPlane(CHAR A);
void ifBoat(CHAR A);
void chooseBoatorPlane(CHAR A);


int main(void)
{
    char gen[7] = "gender";
    int i, choice2;
    printf("\t\t\t\t          WELCOME TO TREASURE HUNT");
    printf("\nWhere You Choose Your Story. Either you end up finding the treasure and you WIN. Fail to do so - and LOSE, and you die!");
    CHAR a;
    printf("\nEnter character's first name:");
    gets(a.name);
    printf("Enter character's gender (Male/Female): ");
    gets(a.gender);
    strupr(a.gender);

    if(strcmp(a.gender, "MALE") == 0){
        strcpy(a.pronoun,"he");
    }else if(strcmp(a.gender, "FEMALE")==0){
        strcpy(a.pronoun,"she");
    }else{
        strcpy(a.pronoun,"it");
    }

    printf("\n\n\n%s has found an ancient treasure map. It is titled \"You Win or You Die\".\n" ,a.name);

    FILE *fp;
    fp = fopen("D:\\CSE115\\first.txt","r");

    if(fp == NULL){
        printf("Error");
        return -1;
    }

    char c = fgetc(fp);
    while( !feof(fp)){
        printf("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);


    printf("\n\n\nThe treasure map read, \"Solve the clues to gain a treasure of your dreams. Fail to do so and the wrong path will lead\n you to your demise. Do you wish to embark on this quest?\". It must be a scam %s thought, but the wonder of unimaginable treasure was too hard to reject. What would %s do? Embark on the quest or reject it?", a.name, a.pronoun, a.pronoun);
    printf("\nChoose what to do:");
    printf("\n(1) Accept the challenge  (2) Reject the quest\n");

    scanf("%d", &choice2);
    switch(choice2){
        case 1:
            printf("\nCHALLENGE ACCEPTED!");
            chooseBoatorPlane(a);
            break;
        case 2:
            printf("\nCHALLENGE DENIED!");
            break;
        default:
            printf("Error! Choose Again\n");
            goBackToStart(a);
    }
    return 0;
}






//Boat

void goBackToStart(CHAR a){
    int choice2;
    printf("\n\n\n%s has found an ancient treasure map. It is titled \"You Win or You Die\"." ,a.name);
    printf("\nThe treasure map read, \"Solve the clues to gain a treasure of your dreams. Fail to do so and the wrong path will lead\n you to your demise. Do you wish to embark on this quest?\". It must be a scam %s thought, but the wonder of unimaginable treasure was too hard to reject. What would %s do? Embark on the quest or reject it?", a.name, a.pronoun, a.pronoun);
    printf("\nChoose what to do:");
    printf("\n(1) Accept the challenge  (2) Reject the quest\n");

    scanf("%d", &choice2);
    switch(choice2){
        case 1:
            printf("\nCHALLENGE ACCEPTED!");
            chooseBoatorPlane(a);
            break;
        case 2:
            printf("\nCHALLENGE DENIED!");
            break;
        default:
            printf("Error! Choose Again\n");
            goBackToStart(a);
    }
}

void goIntoTheStorm(CHAR a){
    printf("As %s heads into the storm in search of treasure, a magical purple cloud falls about. Time is reversed and %s is back to where it all began.",a.name, a.pronoun);
    goBackToStart(a);
}


void solveRiddleBoat(CHAR a){
    int i;
    char anagram[]={'t','b','e','e','n','u','d','i','a','g','a','r','m'};
    char x[20];
    printf("\nCongratulations, %s has successfully made it to the island! This is the last test: \nSolve this anagram and enter your answer. Answer correctly and %s shall win, answer false and %s will die.\nAnagram: \n",a.name,a.pronoun, a.pronoun);
    i=0;
    do{
        printf("%c", anagram[i]);
        i++;
    }while(i<13);
    printf("\nAnswer: ");

    FILE *fptr;
    fptr = fopen("D:\\CSE115\\second.txt","w");

    if(fptr == NULL){
        printf("Error");
        return -1;
    }
    char c[100];

    scanf("\n");
    scanf("%[^\n]", c);

    fprintf(fptr, "%s", c);
    fclose(fptr);

    FILE *p;
    p = fopen("D:\\CSE115\\second.txt","a+");

    if(p == NULL){
        printf("Error");
        return -1;
    }

    char ch[100]="bermuda triangle";
    int count=0;
    i=0;
    while(!feof(p)){
       if(fgetc(p)==ch[i]){
           count++;
           i++;
       }
    }
    if(count == 16){
        printf("\nCONGRATULATIONS! YOU WIN!");
    }else{
        printf("\nOOPS, YOU LOSE! Wrong answer. A jar of anacondas have been released to eat %s alive!", a.name);
    }
    fclose(p);
}

void waitOutTheStorm(CHAR a){
    printf("\nWise decision. %s waits for 4 hours until the storm clears out as %s sees the glittering island. %s pays the sailor midway and swims to the island of riches.",a.name , a.pronoun, a.pronoun);
    solveRiddleBoat(a);
}

void runawayFromStorm(CHAR a){
    struct coordinate c[3];
    int i, flag = 0;
    printf("To escape safely, %s must type in the coordinates so that %s may find the way back.\nType in 3 pairs of latitudes and longitudes so that they form the first 6 digits of the fibonacci sequence: \n", a.name, a.pronoun);
    for(i=0; i<3; i++){
        printf("Lat %d :\n", i+1);
        scanf("%d", &c[i].lat);
        printf("Lon %d :\n", i+1);
        scanf("%d", &c[i].lon);
    }
    int arr[6] = {0,1,1,2,3,5};
    for(i=0; i<3; i++){
        if(c[i].lat + c[i].lon == c[i+1].lat){
            flag++;
        }
    }
    if(flag == 2){
        printf("\nOOPS, YOU LOSE! The storm caught up with %s and ripped %s to shreds.",a.name, a.name);
    }else{
        printf("\nOOPS, YOU LOSE! The storm caught up with %s and ripped %s to shreds.",a.name, a.name);
    }
}






//Plane

void Lie1(CHAR a){
    char x[10];
    printf("After a long and tiresome search, %s finally reaches the destination. \nHowever, there are two crosses!! \n%s MUST answer the following question correctly in order to survive. \n\"I have cities, but no houses, I have mountains but no trees. I have water, but no fish. What am I?\"\nAnswer: ", a.name, a.pronoun);
    scanf("\n");
    scanf("%[^\n]", x);
    fflush(stdin);
    if(strcmp(x, "map")==0)
    {
        printf("\nYOU WIN! CONGRATULATIONS!");

    }else
    {
        printf("\nOOPS, YOU LOSE! Wrong answer. A jar of anacondas have been released to eat %s alive!", a.name);
    }
    return;
}

void Lie2(CHAR a){
    int x;
    char z[5][5];
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(j==i){
                z[i][j] = '\\';
            }else{
                z[i][j] = '.';
            }
            if(i+j == 4){
                z[i][j] = '/';
            }
        }
    }
    z[2][2] = 'x';
    int count = 0;
    while(count != 2){
        for(i=0; i<5; i++){
            for(j=0; j<5; j++){
                printf("%c ", z[i][j]);
            }
            printf("\n");
        }
        count++;
    }

    printf("After a long and tiresome search, %s and Mark finally reach the destination. \nHowever, there are two crosses!! \n%s MUST choose which cross to dig wisely, in order to live. \%s and Mark decide to split up and dig both of the graves. \n%s selects to dig:\n(1)The First Cross \n(2)The Second Cross\n", a.name, a.name, a.name, a.name);
    scanf("%d", &x);

    switch(x){
    case 1:
        printf("YOU WIN! Wise Decision. \n%s digs up the cross to discover an enormous box filled with gold, silver and diamond jewels. \nIn the distant, %s hears the cries of the pilot as he gets eaten by hungry Anacondas. ", a.name, a.pronoun);
        break;
    case 2:
        printf("YOU LOSE! As %s digs the cross expecting to find an enormous box filled with gold, silver and diamond jewels, %s find an open jar filled hungry Anacondas. The snakes make its way to feast upon %s. ", a.name, a.pronoun, a.name);
        break;
    default:
            printf("Error! Choose Again\n");
            Lie2(a);
    }
}

void telltruth(CHAR a){
    printf("The pilot throws %s out of the plane and %s dies so that the pilot could take the treasure for himself.", a.name, a.pronoun);
}


//choice
void ifPlane(CHAR a){
    int x;
    printf("%s finally arrives at the huge chaotic airport. \nIt is filled with people hurrying past with their suitcases, loud families loaded with luggages crowding an area and watchful security guards and pilots walking by in their crisp uniforms. \n%s makes sure %s does not get distracted by these as %s goes to buy the first ticket to the location. \nAfter waiting for a few hours, %s finally gets settled in the plane. \nThe plane was completely empty with %s and just the pilot. \nThe pilot was a tall man with blonde hair.\nHe asks with an evil glint, \"Why are you going to your destination?\" \nNow %s must decide whether to \n(1)Tell Truth \n(2)Lie and keep him as company \n(3)Lie and make him leave\n", a.name, a.name, a.pronoun, a.pronoun, a.pronoun, a.name, a.pronoun);
    scanf("%d",&x);
    switch(x){
        case 1:
            telltruth(a);
            break;
        case 2:
            Lie2(a);
            break;
        case 3:
            Lie1(a);
            break;
        default:
            printf("Error! Choose Again\n");
            ifPlane(a);
    }
    return;
}

void ifBoat(CHAR a){
    printf("%s gets on the boat. Over the horizon %s sees the island but it is surrounded by a storm. What does %s do?\n(1)Wait out the storm\n(2)Go into the storm\n(3)Go back home", a.name, a.pronoun, a.pronoun);
    int boatchoice;
    printf("\nChoose your option: ");
    scanf("%d",&boatchoice);
    switch(boatchoice){
        case 1:
            waitOutTheStorm(a);
            break;
        case 2:
            goIntoTheStorm(a);
            break;
        case 3:
            runawayFromStorm(a);
            break;
        default:
            printf("Error! Choose Again\n");
            ifBoat(a);
    }
}

void chooseBoatorPlane(CHAR a){
    int x;
    printf("After observing the map very carefully and making notes, %s finally realizes the location of the treasure chest. \n%s can go to that place in two ways - by boat or by plane. \n%s decides to go there by: \n(1)Boat \n(2)Plane\n", a.pronoun, a.name, a.pronoun);
    scanf("%d", &x);

    switch(x){
        case  1:
            ifBoat(a);
            break;
        case 2:
            ifPlane(a);
            break;
        default:
            printf("Error! Choose Again\n");
            chooseBoatorPlane(a);
    }
}
