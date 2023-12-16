#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

#define autofree __attribute__\
((cleanup(free_stack)))
__attribute__((always_inline))
inline void free_stack( void *stack){ //free_stack(&stack);
    free(*(void **)stack);
} 

#define INMAZE(x,y,hight,width) (x) < (width) && (y) < (hight) && (x) >= 0 && (y) >= 0
#define UP(x,y) maze[y + 1][x] == 0
#define DOWN(x,y) maze[y - 1][x] == 0
#define RIGHT(x,y) maze[y][x + 1] == 0
#define LEFT(x,y) maze[y][x - 1] == 0

int main(){
    int size;
    int maze[size][size];
    for( int i = 0; i < size; i++ ){
        for(int j = 0; j < size; j++ ){
            scanf("%1d", &maze[i][j]);
        }
    }
    autofree Stack *stack;
    init_stack(&stack, size * size * 2);
    int x = 0, y = 0;
    while( x < size && y < size ){
        maze[y][x] = 2;
        if( INMAZE(x + 1,y,size, size) && RIGHT(x,y)){
            stack -> push(stack, y);
            stack -> push(stack, ++x);
        }else if( INMAZE(x - 1,y,size,size) && LEFT(x,y)){
            stack -> push(stack, y);
            stack -> push(stack, --x);
        }else if( INMAZE(x,y + 1,size,size) && UP(x,y)){
            stack -> push(stack, ++y);
            stack -> push(stack, x); 
        }else if( INMAZE(x,y - 1,size,size) && DOWN(x,y)){
            stack -> push(stack, --y);
            stack -> push(stack, x);
        }else if( x  == 4 && y == 4 ){
            break;
        }else if( !(stack -> isEmpty(stack)) ){
            x = stack -> peek(stack);
            stack -> pop(stack);
            y = stack -> peek(stack);
            stack -> pop(stack);
        }else{
            break;
        }
    }
    for( int i = 0; i < size; i++ ){
        for( int j = 0; j < size; j++ ){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}