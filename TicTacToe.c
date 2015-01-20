#include <stdlib.h>
#include <stdio.h>


void arrayReset ();
int winnerSearch (int turn, int chart, int r, int c);
int inputNormalize (char *inp);
int winnerDisplay (int turn);
void display (int *chart);

int turn, Array[6][6][6];  // global variable
     int x[4];
	 int y[4];
	 int z[4];        //initialized variables to store positions 
int counter, a;

int main()
    {
         
		 char *inp = malloc(sizeof(char) * 1024); //Allocates a block of size 1024 bytes of memory, returning a pointer to the beginning of the block.

         int chart,r,c; //initialized a chart with row and columns
         arrayReset ();
		 
         
    while (1) {
         turn++;
         display (&Array[0][0][0]);
         if (turn%2==0)
		 {
		 int who;
		 who = 1;
		 srand(time(NULL));
		while(who == 1)
		{
			chart = rand() % 4+1; //generating random numbers between 1 and 4 to choose the chart number
			r = rand() % 4+1;    //generating random numbers between 1 and 4 to choose the row number
			c = rand() % 4+1;    //generating random numbers between 1 and 4 to choose the column number
			
                 if (Array[chart][r][c] ==0) 
				who =0;
			else
				who = 1;
		}            // end of while
		 
           }
         
        else {
		 printf("\n Give your input please!\n\n");
		 
         
		 printf("Enter Chart number (Q to quit) :");
		 scanf("%s", inp);
		 
          if ((inp[0]=='q')||(inp[0]=='Q')) break;  // If Q then quit the game
				chart=inputNormalize(inp);
          
            if ((chart<1)||(chart>4)) 
		  {printf("\n ***Invalid Selection\n\n");  //checking if the chart selected is between 1-4          
            system("PAUSE");
             turn--;
             continue;
		  }
                       
          printf("Row Number");  //checking for row number to be between 1-4
			scanf("%s", inp);

		 r=inputNormalize(inp);
          
          if ((r<1)||(r>4)) 
		  {printf("\nInvalid Selection\n\n");            
           system("PAUSE");
             turn--;
             continue;
		   }
                       
          printf("Column Number");  //checking for column number to be between 1-4
          scanf("%s", inp);
		  
          c=inputNormalize(inp);
          if ((c<1)||(c>4)) 
		  {printf("\nInvalid Selection\n\n");
           system("PAUSE");
           turn--;
           continue;
		  }
		
         //check if the column or row  was already selected  
          if (Array[chart][r][c]!=0) 
		  {printf("\nThis place is already Selected Please select another\n\n");
          system("PAUSE");turn--;continue;
		  }
		  } // end of else

		 if (turn%2==0) {Array[chart][r][c]=2;}   //for every even chance the computer will play 
             else {Array[chart][r][c]=1;}
          
		  if (winnerSearch (turn,chart,r,c)) 
		  {
              if(winnerDisplay(turn)) 
                  break;}
         }
         printf("\n\n\n");
         return 0;
}


int winnerSearch (int turn,int chart,int r,int c) {
     int h;	
	 int ch, row2, col2, i, b;
	 h =1;
	 
     if (turn%2==0) h=2;        //Xs or Os to check
     
     x[0]=chart;y[0]=r;z[0]=c;   //storing the move of each player   
     
     
     for (a=1;a<14;a++){    //check all possible direction
     
           counter=1;                      
			
            ch=chart; row2=r; col2=c ;
           
           for (i=0;Array[ch][row2][col2]!=5;)
          
             {

                 switch (a) {	//increments in every direction unless 5 is pressed				
                        case 1:ch--;
								break;                
                        case 2:	ch--;
								row2--;
								col2--;
								break;  
                        case 3:	ch--;
								row2--;
								break;         
                        case 4:	ch--;
								row2--;
								col2++;
								break;  
                        case 5:	ch--;
								col2--;
								break;         
                        case 6:	ch--;
								col2++;
								break;         
                        case 7:	ch--;
								row2++;
								col2--;
								break;  
                        case 8:	ch--;	
								row2++;
								break;         
                        case 9:	ch--;
								row2++;
								col2++;
								break;  
                        case 10:col2--;
								break;             
                        case 11:row2--;
								col2--;
								break;      
                        case 12:row2--;
								break;             
                        case 13:row2--;
								col2++;
								break;          
                         }
                        
                 if (Array[ch][row2][col2]==h) {
                           x[counter]=ch;y[counter]=row2;z[counter]=col2;
                           counter++;}
                 
                 }
                 
                 
          ch=chart;row2=r;col2=c;   //reset placeholder variables
         
         
          for (i=0;Array[ch][row2][col2]!=5;) { 
                switch (a) {
                      case 1:ch++;
							break;                
                      case 2:ch++;
							row2++;
							col2++;
							break;  
                      case 3:ch++;
							row2++;
							break;         
                      case 4:ch++;
							row2++;
							col2--;
							break;  
                      case 5:ch++;
							col2++;
							break;         
                      case 6:ch++;
							col2--;
							break;         
                      case 7:ch++;
							row2--;
							col2++;
							break;  
                      case 8:ch++;
							row2--;
							break;         
                      case 9:ch++;
							row2--;
							col2--;
							break; 
                      case 10:col2++;
							break;            
                      case 11:row2++;
							col2++;
							break;     
                      case 12:row2++;
							break;            
                      case 13:row2++;
							col2--;
							break;     
                      }
                                   
              if (Array[ch][row2][col2]==h) {
                      x[counter]=ch;y[counter]=row2;z[counter]=col2;
                      counter++;
                      }
               }
               
      if (counter>3) //assign 4 to the last position
              {   for (b=0;b<4;b++) 
               
                  {   Array[x[b]][y[b]][z[b]]=4;} return 1;}
               }
     return 0;
}


int inputNormalize (char *inp) {
    int i, q;
    char *n = malloc(sizeof(char) * 1024);
	strcpy(n, inp);
	puts(inp);
    q=atoi(n);

	printf("\nInput given=%s\n\n", inp);
    return q;
}
        
    

void display(int *chart)
{
	int n, x, y, z, k;
     system ("cls");

	 printf("---1---\t\t---2---\t\t---3---\t\t---4---\n\n\n");
     
     for (y=1;y<=4;y++) {
         for (x=1;x<=4;x++) {
             for (z=1;z<=4;z++) {
                 n=((36*x)+(6*y)+(z));      // 6*6*6 is the size of the array used hence n=(36*x)+(6*y)+(z)
                 switch (*(chart+n)) {
                        case 0: printf(" "); 	break;
                        case 1: printf("X"); 	break;
                        case 2: printf("O"); 	break;
                        case 4: printf("%c", (char)219); 	
                        break;
                        }
                 
            if (z<4) printf("%c", (char)179); //creating vertical lines for the chart
                 }
             if (x<4) printf("\t\t");
             }
         if (y<4) {
                  printf("\n");
                  for (k=1;k<32;k++) {
                       if (k%8==0) 
					   {printf("\t");
						printf("\t");
					   }
                       else if (k%2==0) 
					   {printf("%c", (char)197);  //horizontal & vertical intersecting lines
					   }
                       else 
						printf("%c", (char)196); //horizontal lines for the chart
					   }
                           printf("\n");
                      }
                  
         }
     printf("\n\n\n\n");
     return;
     }
     
     
int winnerDisplay (int tn) {
     char yn[100];
     display (&Array[0][0][0]);
     if (tn%2==0) {printf("\n\n 2 is the winner!\n\n");}
        else printf("\n\n 1 is the winner!\n\n");
     printf("Would you like to play again? (y/n)");
     scanf("%c", &yn);
     if (!strcmp(yn,"y")||!strcmp(yn,"Y")) {
		arrayReset ();  
		turn=0; 
		return 0;
	}
        else return 1;
}


void arrayReset () {
int x, y, z, i, j;
     for (x=0;x<=5;x++) {
         for (y=0;y<=5;y++) {
             for (z=0;z<=5;z++) {
                 Array[x][y][z]=0;
                 }
             }
         }
     for (i=0;i<=5;i++) {
             for (j=0;j<=5;j++) {
                 Array[0][i][j]=5; Array[5][i][j]=5;
                 Array[i][j][0]=5; Array[i][j][5]=5;
                 Array[i][0][j]=5; Array[i][5][j]=5;}
                 }
         
     }
     