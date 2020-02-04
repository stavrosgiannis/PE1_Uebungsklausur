#define _CRC_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aufgabe1a(){    
    //Der Fehler ergibt sich durch die zugewiesene größe des Strings, weswegen kein " World" hinzupasst.
    //char * st = "Hello";
    char st[] = "Hello";
    strcat(st, " World");
    printf("%s\n", st);
}

void aufgabe1b(){
    //for (int i = 1; i < 10; ++i) <- 
    for (int i = 1; i < 10; i++)
    {
        printf("%d^2 = %d\n", i, i * i);
    }
}

void aufgabe1c(){
    int x; 
    //scanf("%d", x); <- Addressoperator fehlt
    printf("Zahl eingeben: ");
    scanf("%d", &x);

    switch (x)
    {
        case 1: case 3: case 5:
        case 7: case 9:
            printf("Zahl ungerade\n");
            //break; hat gefehlt
            break;
        case 0: case 2: case 4:
        case 6: case 8:
            printf("Zahl gerade \n");
            //break; hat gefehlt
            break;
        default:
            printf("Zahl außerhalb des Bereichs!");
            break;
        }
}

void aufgabe2a(){
    int i = 0;
    int sum = 0;

    //for ( i = 0; i < 10; i++); <- das Semikolon beendet die Schleife und i <= 10 
    for ( i = 0; i <= 10; i++)
    {
        sum += i;
    }
    printf("%d", sum);
}

char new_pwd[20];
void read_new_passwd( char* new_pwd){
        char /*pwd1*/ pwd1[20], pwd2[20];
        do
        {
            printf("\n Enter new password: ");
            fgets(pwd1, 20, stdin);
            printf("Enter new password again: \n");
            fgets(pwd2, 20, stdin);
        } while (strcmp(pwd1, pwd2)); //(pwd1 != pwd2); Abfrage funktioniert nicht bei Strings!
        strcpy(new_pwd, pwd1);
        printf("Set new password: %s", new_pwd);
    }

char old[] = "Panama";
char new[6];
void swap_case(char* old, char* new){
    for (int i = 0; i < 6; i++)
    {
        //printf("DEBUG: %c\n", old[i]);
        if (old[i] >= 'A' && old[i] <= 'Z'){
            new[i] = old[i] + 32;
        }else
        {
            new[i] = old[i] - 32;
        }
        printf("old[i]: %c | new[i]: %c\n", old[i], new[i]);
    }
    printf("old: %s | new: %s\n", old, new);
        
} 

void compute_prime_numbers(){
    for (int i=2; i<100; i++)
    {
        for (int j=2; j<=i; j++)   // Changed upper bound
        {
            if (i == j)  // Changed condition and reversed order of if:s
                printf("Prime Number: %d\n",i);
            else if (i%j == 0)
                break;
        }
    }
    
}


void compute_median(double* a, unsigned nr){
//    sort(a, a + nr);

    if(nr % 2 != 0)
        return a[nr/2];
    return (a[(nr-1)/2] + a[nr/2]);
}

void aufgabe6(){
    int auswahl;
    float distanz, new_distanz;

    printf("Wählen Sie ein Einheitsystem: \n");
    printf("(1)foot | (2)inch | (3)yard | (4)mile\n");
    scanf("%d", &auswahl);

    printf("Umzuwandelne Distanz: \n");
    scanf("%f", &distanz);

    switch (auswahl)
    {
    case 1:
        new_distanz = distanz / 3.281;
        break;
    case 2:
        new_distanz = distanz / 39.37;
        break;
    case 3:
        new_distanz = distanz / 1.094;
        break;
    case 4:
        new_distanz = distanz * 1609;
        break;
    }

    printf("Umgewandelte Distanz: %f", new_distanz);
}



//2. probeklausur

struct hackathon
{
    struct Team
    {
        char bezeichnung[32];
        char team_mitglieder[32][32];
    };

    struct Punkte
    {
        int JuryPubPunkte;
        int GesamtPunktzahl;
    };
    struct Team Team;
    struct Punkte Punkte;
};


void test1(){

    struct hackathon input_hackathon[1]; //= {{"Teambezeichnung","Stavros und Noah"},{10,100}};
    scanf("%s", &input_hackathon[0].Team.bezeichnung);
    printf("%s\n", input_hackathon[0].Team.bezeichnung);

}


void test4a(){
    unsigned int **matrix; 
    int NumberOfZeilen, NumberOfSpalten;

    printf("Anzahl Zeilen: ");
    scanf("%d", &NumberOfZeilen);
    printf("Anzahl Spalten: ");
    scanf("%d", &NumberOfSpalten);

    matrix = (int *)malloc(NumberOfZeilen * NumberOfSpalten * sizeof(int));


    for (int zeile = 0; zeile < NumberOfZeilen; zeile++){
        for(int spalte = 0; spalte < NumberOfSpalten; spalte++){
            printf("Type a number for <line: %d, column: %d>\t", zeile+1, spalte+1);
            scanf("%d", &matrix[zeile*NumberOfZeilen + spalte]);
            
        }
    }


    //gebe alles aus 

    for (int zeile = 0; zeile < NumberOfZeilen; zeile++){
        for (int spalte = 0; spalte < NumberOfSpalten; spalte++){
            printf("<line: %d, column: %d> = %d\n", zeile+1, spalte+1, matrix[zeile*NumberOfZeilen + spalte]);

            printf("");
        }
    }
}

void countDigitsAndLetter(char *satz, int *digits, int *letters){

    int c = 0;

    printf("%c", *(satz));
    while(satz + c != '\n')
        if (satz + c >= 'A' && satz + c <= 'Z'){
            letters += 1;
            
        }else if(satz + c >= 0 && satz + c <= 9){
            digits += 1;
            
        }
        c++;
            
    
    printf("digits=%d\t letters=%d", digits, letters);
}


int main(){
    //aufgabe1a();
    //aufgabe1b();
    //aufgabe1c();
    //aufgabe2a();
    //read_new_passwd(new_pwd); //aufgabe3a
    //swap_case(old, new);
    //compute_prime_numbers();
    //compute_median();
    //aufgabe6();

    //test1();

    //test4a();

    char testSatz[] = "EPR 2019 ist toll";
    int digits = 0;
    int letters = 0;
    countDigitsAndLetter(testSatz, digits, letters);

    return 0;
}