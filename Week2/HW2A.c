#include <stdio.h>

int main(){
    int chess[8][8] = {}, address_x = 0, address_y = 0;
    int direction[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
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

    int con = 0;
    int x = address_x, y = address_y;
    for( int k = 0; k < 8; k++ ){
        x += dx;
        y += dy;
                            
        if( (x >= 0 && x < 8) && (y >= 0 && y < 8) ){
            if( chess[y][x] == 0 && con ){
                chess[y][x] = 120;
                con = 0;
                continue;
            }
            con = ( chess[y][x] == 3 - color ) ? 1:0;    
        } 
    }

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( chess[i][j] == 120){
                printf("%c ", chess[i][j]);
                continue;
            }
            printf("%d ", chess[i][j]);
        }
        printf("\n");
    }
    return 0;
}
