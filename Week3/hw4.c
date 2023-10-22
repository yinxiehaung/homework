#include <stdio.h>

int _chess[8][8] = {}, _color;
const int _direction[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; //八個方向

void reset(){
    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( _chess[i][j] == 120 ){
                _chess[i][j] = 0;
            }
        }
    }
}


int oneDirection(int x, int y, int dy, int dx ){
    int con = 0;
    for( int i = 0; i < 8; i++ ){ //最多做8次
        x += dx;
        y += dy;
        if( x >= 0 && y >=0 && x < 8 && y < 8){
            
            if( _chess[y][x] == 0 && con ){
                _chess[y][x] = 120;
                return i + 1; //i為有幾個可翻轉的棋子
            } 
            /*if( _chess[y][x] == 3 - _color ){ //若為不同顏色就可夾擊
                con = 1;
            }else{
                con = 0;
            }*/
            con = ( _chess[y][x] == 3 - _color ) ? 1 : 0;
        }       
    }
    return 0;//沒有可翻轉的棋子回傳0
}

void check( int x, int y ){
   for( int i = 0; i < 8; i++){
        int step = oneDirection( x, y, _direction[i][0], _direction[i][1] );//對每個方向進行判斷
            
        if(step){
            printf("(%d, %d) ", x + (_direction[i][1] * step), y + (_direction[i][0] * step)); //輸出可以下的座標
        }
   }
    reset();//清除標記
}



int main(){
    int address_x = 0, address_y = 0;
    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            scanf("%1d", &_chess[i][j]);
        }
    }

    scanf("%d,%d", &address_x, &address_y);

    if( _chess[address_y][address_x] == 0 ){
        printf("(%d,%d) is 0", address_x, address_y);
        return 0;
    }

    _color = _chess[address_y][address_x];
    check( address_x, address_y );   //i,j八個位置是否可下

    _color = 2; 
    printf("\nWhite\n");

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( _color == _chess[i][j] ){ //只需判斷同為白子八個方向的及可
                check( j, i );
            }
        }
    }

    _color = 1;
    printf("\nBlack\n");

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++){
            if( _color == _chess[i][j] ){ //與上面相同
                check( j, i );               
            }
        }
    }

    return 0;
}
