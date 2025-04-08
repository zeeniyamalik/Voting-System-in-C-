#include<stdio.h>
#include<stdio.h>
#include<strings.h> 
#define filename "voting_records.txt"

struct VotingSystemRecord{
    int voterID;
    char voterName[100];
    int candidateID;
    char candidateName[100];
    char partyAffiliation[50];
};

struct VotingSystemRecord s;

void displayCandidateDetails(){
    printf("\n\t\t\t----CANDIDATE DETAILS----\t\t\n\n");
    printf("\n\tCandidate ID\tCandidate Name\t   Party Affiliation\n\n");
    printf("\t  101\t\tGEORGE BUSH\t\tParty A\n\n");
    printf("\t  102\t\tDONALD TRUMP\t\tParty B\n\n");
    printf("\t  103\t\tJOE BIDEN\t\tParty C\n\n");
    }

void castVote(){
    FILE *file = fopen(filename,"w");
    if (file==NULL){
        printf("error opening the file. ");
        return;
    }

    //FOR NUMBER OF VOTERS
    printf("\n\n\t\t\t----CAST VOTES----");
int n=1, i=0;
    
    while(n!=0){
        i++;    //to keep track of the loop iteration
    printf("\nEnter your Voter ID: ");
    scanf("%d", &s.voterID);
    getchar();

    printf("\nEnter your Name: ");
    fgets(s.voterName, sizeof(s.voterName), stdin);
    s.voterName[strcspn(s.voterName, "\n")] = '\0';

    printf("\nEnter the Candidate ID you want to vote for: ");
    scanf("%d", &s.candidateID);
    getchar();
    
    printf("\nPRESS 0 TO EXIT, 1 TO CONTINUE VOTING ");
    scanf("%d", &n);

    if(n==0 && i<=1){
        n=1;    //turning 'n' true to keep while loop's condition valid (line 35)
            printf("\n\nSORRY! AT LEAST 2 VOTES ARE NEEDED!\n");
            continue;
            }

    fprintf(file,"%d, %s, %d\n",s.voterID, s.voterName, s.candidateID);
    }
    fclose(file);
}


void displayResults(){


    FILE *file = fopen(filename,"r");
    if (file==NULL){
        printf("error opening the file. ");
        return;
    } 

    FILE *wfile = fopen(filename,"a");
    if (file==NULL){
        printf("error opening the file. ");
        return;
    } 

     int votesA = 0, votesB = 0, votesC = 0;

    while(fscanf(file,"%d, %99[^,], %d\n", &s.voterID, s.voterName, &s.candidateID) != EOF){
        if (s.candidateID == 101) votesA++;
        if (s.candidateID == 102) votesB++;
        if (s.candidateID == 103) votesC++;
        else printf("INVALID INPUT! TRY AGAIN.");
    }
    printf("\n\n\t  ID\t\tCANDIDATE\t\tPARTY\t\tVOTES\n\n");
    printf("\t  101\t\tGEORGE BUSH\t\tParty A\t\t%d\n", votesA);
    printf("\t  102\t\tDONALD TRUMP\t\tParty B\t\t%d\n", votesB);
    printf("\t  103\t\tJOE BIDEN\t\tParty C\t\t%d\n", votesC);

    fprintf(wfile,"\t  101\t\tGEORGE BUSH\t\tParty A\t\t%d\n", votesA);
    fprintf(wfile,"\t  102\t\tDONALD TRUMP\t\tParty B\t\t%d\n", votesB);
    fprintf(wfile,"\t  103\t\tJOE BIDEN\t\tParty C\t\t%d\n", votesC);

    fclose(file);
    fclose(wfile);
}

int main(){   
    printf("\n\t\t---WELCOME TO THE VOTING SYSTEM---\n");
    int choice;
    do{
        printf("\nChoose from the options\n\n");
        printf("\n1. Display Candidate Details\n");
        printf("2. Cast Votes\n");
        printf("3. View Election Results\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1 : displayCandidateDetails(); break;
            case 2 : castVote(); break;
            case 3 : displayResults(); break;
            case 4 : printf("EXITING....."); break;
            default : printf("Invalid choice!\n");
        }

    }
    while(choice!=4);
}
