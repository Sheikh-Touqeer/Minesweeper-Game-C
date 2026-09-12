#include<stdio.h>
#include<string.h>

int main(){
    int choice;
    do{
        printf("\n===== MINESWEEPER GAME =====\n");
        printf("\n");
        printf("1. Start New Game\n");
        printf("2. Search Game History\n");
        printf("3. Show Top 3 Explorers\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d",&choice);
        while(getchar()!='\n');

        if(choice==1){
            char player1[50], player2[50];
            int i,j,k;
            printf("\nPlayer 1 Name: ");
            fgets(player1,50,stdin);
            player1[strcspn(player1,"\n")] = 0;
            printf("Player 2 Name: ");
            fgets(player2,50,stdin);
            player2[strcspn(player2,"\n")] = 0;
        
		for(i=0; player1[i]; i++)
            if(player1[i]>='a' && player1[i]<='z')
            player1[i]-=32;
		for(i=0; player2[i]; i++)
            if(player2[i]>='a' && player2[i]<='z')
            player2[i]-=32;
        
		    char grid[4][4];
		
		for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                    grid[i][j]='*';

            int mines[4];
            printf("\nEnter 4 mines (1-16):\n");

            for(i=0; i<4; i++){
    int duplicate = 0;

    scanf("%d", &mines[i]);
    while(getchar() != '\n');

    if(mines[i] < 1 || mines[i] > 16){
        printf("Invalid! Enter a number from 1 to 16.\n");
        i--;
        continue;
    }

    for(j=0; j<i; j++){
        if(mines[i] == mines[j]){
            duplicate = 1;
            break;
        }
    }

    if(duplicate){
        printf("Duplicate! Choose a different cell.\n");
        i--;
        continue;
    }
}

            int safe=0, turn=0;

            while(1){

                printf("\nBoard:\n");
                for(i=0;i<4;i++){
                    for(j=0;j<4;j++){
                        printf("%c ",grid[i][j]);
                    }
                    printf("\n");
                }

                int cell;
                printf("\nChoose (1-16): ");
                scanf("%d",&cell);
                while(getchar()!='\n');

                if(cell<1 || cell>16){
                    printf("Invalid!\n");
                    continue;
                }

                int r=(cell-1)/4;
                int c=(cell-1)%4;

                if(grid[r][c]!='*'){
                    printf("Already opened!\n");
                    continue;
                }
                turn++;
				int bomb=0;
                for(i=0;i<4;i++)
                    if(cell==mines[i]) bomb=1;
                
				if(bomb){
                    grid[r][c]='M';
printf("\nBOOM! %s hit a mine!\n%s wins the game!\n", player2, player1);

                    FILE *f=fopen("minesweeper_log.txt","a");
                    fprintf(f,"%s,%s,%s,%d,LOSE\n",player1,player2,player1,turn);
                    fclose(f);

                    break;
                }

                int count=0;

                for(i=r-1;i<=r+1;i++){
                    for(j=c-1;j<=c+1;j++){
                    if(i>=0 && i<4 && j>=0 && j<4){
                    int num=i*4+j+1;
                for(k=0;k<4;k++){
                    if(num==mines[k]) 
					count++;
                            }
                        }
                    }
                }

                if(count==0)
                    grid[r][c]='.';
                else
                    grid[r][c]=count+'0';

                safe++;

                if(safe==12){

                   printf("\nCongratulations %s! You cleared all safe cells and won the game!\n", player2);

                    FILE *f=fopen("minesweeper_log.txt","a");
                    fprintf(f,"%s,%s,%s,%d,WIN\n",player1,player2,player2,turn);
                    fclose(f);

                    break;
                }
            }
        }

    else if(choice==2){

            char searchName[50];
            int i;
            printf("Enter name: ");
            fgets(searchName,50,stdin);
            searchName[strcspn(searchName,"\n")] = 0;
        for(i=0; searchName[i]; i++)
                if(searchName[i]>='a' && searchName[i]<='z')
                    searchName[i]-=32;

            FILE *f=fopen("minesweeper_log.txt","r");

            if(f==NULL){
                printf("No record\n");
                continue;
            }
            char a[50],b[50],c[50],res[10];
            int t,found=0;

            while(fscanf(f,"%[^,],%[^,],%[^,],%d,%s\n",
                         a,b,c,&t,res)!=EOF){

                if(strcmp(a,searchName)==0 || strcmp(b,searchName)==0){

                    printf("%s %s %s %d %s\n",a,b,c,t,res);
                    found=1;
                }
            }
            if(!found)
                printf("No match found\n");
			fclose(f);
        }

    else if(choice==3){

            char names[100][50];
            int wins[100]={0};
            int games[100]={0};
            int total=0;

            int i,j;

            FILE *f=fopen("minesweeper_log.txt","r");

            if(f==NULL){
                printf("No data\n");
                continue;
            }

            char a[50],b[50],c[50],res[10];
            int t;

            while(fscanf(f,"%[^,],%[^,],%[^,],%d,%s\n",
                         a,b,c,&t,res)!=EOF){

                int pos=-1;

                for(i=0;i<total;i++){
                    if(strcmp(names[i],b)==0)
                        pos=i;
                }

                if(pos==-1){
                    strcpy(names[total],b);
                    games[total]=1;
                    if(strcmp(b,c)==0) wins[total]=1;
                    total++;
                }
                else{
                    games[pos]++;
                    if(strcmp(b,c)==0) wins[pos]++;
                }
            }

            fclose(f);

            for(i=0;i<total-1;i++){
                for(j=i+1;j<total;j++){
                    if(wins[j]>wins[i]){

                int temp=wins[i]; wins[i]=wins[j]; wins[j]=temp;
                temp=games[i]; games[i]=games[j]; games[j]=temp;

                char tempName[50];
                strcpy(tempName,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],tempName);
                }
            }
        }
            printf("\nTop Explorers:\n");
            int limit = total<3 ? total : 3;
        
		for(i=0;i<limit;i++){
                printf("%s Games:%d Wins:%d\n",names[i],games[i],wins[i]);
            }
        }

        else if(choice==4){
            printf("Exit...\n");
        }

        else{
            printf("Wrong choice!\n");
        }

    } while(choice!=4);

    return 0;
}
