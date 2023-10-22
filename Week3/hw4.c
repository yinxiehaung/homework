#include <stdio.h>

int _chess[8][8] = {}, _color;
const int _direction[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 

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
    for( int i = 0; i < 8; i++ ){
        x += dx;
        y += dy;
        if( x >= 0 && y >=0 && x < 8 && y < 8){
            
            if( _chess[y][x] == 0 && con ){
                _chess[y][x] = 120;
                return i + 1;
            } 
            if( _chess[y][x] != _color && _chess[y][x] != 120 &&
            _chess[y][x] != 0){
                con = 1;
            }else{
                con = 0;
            }
        }       
    }
    return 0;
}

void check( int x, int y ){
   for( int i = 0; i < 8; i++){
        int step = oneDirection( x, y, _direction[i][0], _direction[i][1] );
            
        if(step){
            printf("(%d, %d) ", x + (dx * step), y + (dy * step));
        }
   }
    reset();
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
    check( address_x, address_y );   

    _color = 2;
    printf("\nWhite\n");

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++ ){
            if( _color == _chess[i][j] ){
                check( j, i );
            }
        }
    }

    _color = 1;
    printf("\nBlack\n");

    for( int i = 0; i < 8; i++ ){
        for( int j = 0; j < 8; j++){
            if( _color == _chess[i][j] ){
                check( j, i );               
            }
        }
    }

    return 0;
}
