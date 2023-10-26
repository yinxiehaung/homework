#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define BLACK 1
#define WHITE 2
#define SPACE 0

#define INTABLE(x, y)({ typeof(x) _x = x;\
                        typeof(y) _y = y;\
                        _x >= 0 && _y >=0 && _x < 8 && _y < 8;}\
                    )
const int _Direction[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int _vaildAddress[8][8] = {}; 


//檢查是否為有效的下棋位置
int isVaild( int x, int y){
    return _vaildAddress[y][x] == 120 ? 1:0;
}
//檢查是否成對(可以翻轉的條件之一)
int isPair(int table[8][8], int x, int y, int dx, int dy, int current){
    for( int i = 0; i < 8; i++ ){
        x += dx;
        y += dy;
        if( INTABLE( x, y) && table[y][x] == current){
            return 1;
        }
    }
    return 0;
}
//印出棋盤
void printBoard( int table[8][8] ){
    printf("  0 1 2 3 4 5 6 7\n");
    for( int i = 0; i < 8; i++ ){
        printf("%d", i);
        for( int j = 0; j < 8; j++ ){
            printf(" %d", table[i][j]);
        }
        printf("\n");
    }
}
//重設棋盤上的標記
void reset( int table[8][8] ){
    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( table[i][j] == 120 ){
                table[i][j] = 0;
            }
        }
    }
}
//檢查其中一個方向
int oneDirection(int x, int y, int dx, int dy, int current, int table[8][8] ){
    int con = 0;
    for( int i = 0; i < 8; i++ ){
        x += dx;
        y += dy;
        if( INTABLE( x, y ) ){     
            if( table[y][x] == 0 && con ){
                table[y][x] = 120;
                return i + 1;
            } 
            con = (table[y][x] == 3 - current)?1:0;
        }       
    }
    return 0;
}
//檢查此位置可以下的位置
void check( int x, int y, int table[8][8], int current ){
    for( int i = 0; i < 8; i++){
        int step = oneDirection( x, y, _Direction[i][1], _Direction[i][0], current, table );//對每個方向進行判斷
        int tmp_x = x + (_Direction[i][1] * step);
        int tmp_y = y + (_Direction[i][0] * step);
        if(step){
            printf("(%d, %d) ", tmp_x,tmp_y); //輸出可以下的座標
            _vaildAddress[tmp_y][tmp_x] = 120;
        }
    }
    reset(table);
}
//查詢黑旗或白旗可以下的所有位置
void vaildSpace( int table[8][8], int current ){
    for( int i = 0; i < 8; i++ ){
        for(int j = 0; j < 8; j++){
            if( table[i][j] == current ){
                check(j, i, table, current);
            }
        }
    }
}
//做翻轉
void Flip( int table[8][8], int x, int y, int dx, int dy,int current){
    if(isPair(table, x, y, dx, dy, current)){
        int tmp_x = x + dx;
        int tmp_y = y + dy;
        while( OTHERCOLOR(table[tmp_y][tmp_x], current) ){
            table[tmp_y][tmp_x] = current;
            _vaildAddress[tmp_y][tmp_x] = 0;
            tmp_y += dy;
            tmp_x += dx;
        }
    }
}
//對每一個方向進行翻轉
void doFlip( int table[8][8], int x, int y, int current ){
    for( int i = 0; i < 8; i++){
        Flip( table, x, y, _Direction[i][1], _Direction[i][0] ,current );
    }
    table[y][x] = current;
}

int main(){
    int table[8][8] = {{0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,1,2,0,0,0},
                       {0,0,0,2,1,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0}};
    int current,x,y;
    printBoard(table);
    printf("chose color: ");
    scanf("%d", &current);
    
    if( current != BLACK && current != WHITE ){
        printf("IS NOT VAILD COLOR\n");
        return 0;
    }

    while(1){
        vaildSpace(table,current);
        printf("\nchose vaild x,y:"); 
        scanf("%d %d", &x, &y);
        if(!(isVaild(x,y))){
            printf("IS NOT VAILD ADDRESS\n");
            continue;
        }
        doFlip(table, x, y, current);
        printBoard(table);
        current = 3 - current;
    }
    return 0;
}
