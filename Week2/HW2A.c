#include <stdio.h>

int main(){
    int chess[8][8] = {}, address_x = 0, address_y = 0;
    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            scanf("%1d", &chess[i][j]);
        }
    }

    scanf("%d,%d", &address_x, &address_y);

    if( chess[address_y][address_x] == 0 ){
        printf("(%d,%d) is 0", address_x, address_y);
        return 0;
    }

    int color = chess[address_y][address_x];
    
    for( int i = 0; i < 8; i++){
        for( int j = 0; j < 8; j++){
            if( chess[i][j] == color ){
                for( int dy = -1; dy <= 1; dy++ ){
                    for( int dx = -1; dx <=1; dx++ ){
                        int con = 0;
                        int x = j, y = i;
                        for( int k = 0; k < 8; k++ ){
                            x += dx;
                            y += dy;
                            
                            if( (x >= 0 && x < 8) && (y >= 0 && y < 8) ){
                                if( chess[y][x] == 0 && con ){
                                    chess[y][x] = 120;
                                    con = 0;
                                    continue;
                                }

                                if( chess[y][x] != color && chess[y][x] != 0 && chess[y][x] != 120){
                                    con = 1;
                                }else{
                                    con = 0;
                                }
                            }
                        }
                    } 
                }
            }
        }
    }

    for( int dy = -1; dy <= 1; dy++ ){
        for( int dx = -1; dx <= 1; dx++ ){
            int x = address_x, y = address_y, con = 0;
            for( int i = 0; i < 8; i++ ){
                x += dx;
                y += dy;
                if( (x >= 0 && x < 8) && (y >= 0 && y < 8) ){
                    if( chess[y][x] == 120 ){
                        chess[y][x] = -1;
                        continue;
                    }
                }
            }
        }
    }
    

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( chess[i][j] == -1){
                printf("%c ", 'x');
                continue;
            }else if( chess[i][j] == 120){
                printf("%d ", 0);
                continue;
            }
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }

    return 0;
}
