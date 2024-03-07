#include <stdio.h>

int main(){
    int score;
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &score);
    printf("\nPossible combination of scoring plays\n");
    while (score>1){
        for(int ttp = 0; score/8>=ttp; ttp++){
            for(int tfg = 0; score/7>=tfg; tfg++){
                for(int td = 0; score/6>=td; td++){
                    for(int fg = 0; score/3>=fg; fg++){
                        for(int s = 0; score/2>=s; s++){
                            if ((ttp*8) + (tfg*7) + (td*6) + (fg*3) + (s*2) == score){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", ttp, tfg, td, fg, s);
                            }
                        }
                    }
                }
            }
        }
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
    }
    return 0;
}