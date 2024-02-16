#include<stdio.h>
#define max 3
/*struct player 
{
    char* name ;
    char  d ;
};
struct player player1 ;
struct player player2 ;*/

char s[max][max] ;
void bordprint(char t[max][max]){


    printf(" ------------- \n");
    printf("| %c | %c | %c |\n",t[0][0],t[0][1],t[0][2]);
    printf(" --------------\n");
    printf("| %c | %c | %c |\n",t[1][0],t[1][1],t[1][2]);
    printf(" ------------- \n");
    printf("| %c | %c | %c |\n",t[2][0],t[2][1],t[2][2]);
    printf(" --------------\n");

}

unsigned short int  dorw(char s[max][max]){
    for (unsigned short int  i = 0; i < max; i++){
        for (unsigned short int  j = 0; j < max; j++){
            if (s[i][j] ==' ')
            {
                return 1 ;
            }
        }
        
    }
    return 0 ;
}
unsigned short int  win1(char s[max][max]){
    for (unsigned short int  i = 0; i < max; i++){
     if (s[0][i] =='x'  && s[0][i] == s[1][i] && s[1][i] == s[2][i] || s[i][0] =='x'  && s[i][0] == s[i][1] && s[i][1] == s[i][2] || s[0][0] == 'x' && s[1][1] == s[0][0] && s[0][0] == s[2][2] || s[2][0] =='x' && s[2][0] == s[1][1] && s[2][0] == s[0][2]  ){
       return 1 ;
     }
    }
    return 0 ;
}
unsigned short int  win2(char s[max][max]){
    for (unsigned short int  i = 0; i < max; i++){
     if (s[0][i] =='o'  && s[0][i] == s[1][i] && s[1][i] == s[2][i] || s[i][0] =='o'  && s[i][0] == s[i][1] && s[i][1] == s[i][2] || s[0][0] == 'o' && s[1][1] == s[0][0] && s[0][0] == s[2][2] || s[2][0] =='o' && s[2][0] == s[1][1] && s[2][0] == s[0][2] ){
       return 1 ;
     }
    }
    return 0 ;
}


void plays(char s[max][max], unsigned short int player){
    
    unsigned short int x,y ;
    bordprint(s);
    if (player == 1)
    {
        printf("player 1  enter column (x,y)   : \n"); scanf("%hu%hu",&x,&y);

    }
    else
    {
        printf("player 2  enter column (x,y)   : \n"); scanf("%hu%hu",&x,&y);
    }
    
    
    
    
    if (s[x][y] != ' '){
        if (dorw(s) == 0)
        {
            printf("the game is draw .\n");
            
        }
        else{
            printf(" please replay enter choice becouse is full .\n");
            plays(s,player);
        }
    }
    else{
        if (player == 1){
            s[x][y] ='x';
            if (win1(s) == 1){
                printf(" the player1 is win .\n");
                
            }   
            else
            {
                plays(s,2);
            }
        }
        if (player == 2){
            s[x][y] ='o';
            if (win2(s) == 1){
                printf(" the player2 is win .\n");
                
            }  
            else
            {
                plays(s,1);
            }
              
            
        }
    }
}
void munem(){
    printf("1 . start \n");
    printf("2 . exit  \n");
}

void playen(char s[max][max]){
    unsigned short int a ;
    printf("      welcome to everyone to game tic-tac-toe   \n ") ;
    munem();
    printf("enter chocise  : "); scanf("%hu",&a);
    switch (a)
    {
     case 1:
        
        plays(s,1);
        
        break;
     case 2:
        printf(" thank you with playing and good luck .\n");
        break;    
    
     default:
        printf("please replyer enter choice  .\n");
        playen(s);
        break;
    }


}
void info(){
    printf(" \n\n\n\n                   note : enter number (0->2) and (0->2) \n");
    printf("                     ------------- \n");
    printf("                    |(0,0)|(0,1)|(0,2)|\n");
    printf("                     --------------\n");
    printf("                    |(1,0)|(1,1)|(1,2)|\n");
    printf("                    ------------- \n");
    printf("                    |(2,0)|(2,1)|(2,2)|\n");
    printf("                     --------------\n");

}

int main(int argc, char const *argv[])
{
    
    char s[max][max] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    info();

    playen(s);   
    sleep(5);
    return 0;
}











