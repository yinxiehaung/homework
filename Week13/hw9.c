#include <stdio.h>
#include <stdbool.h>
#include "Stack.c"

#define autofree __attribute__\
((cleanup(free_stack)))
__attribute__((always_inline))
inline void free_stack( void *stack){ //free_stack(&stack);
    free(*(void **)stack);
} 

#define INMAZE(x,y,hight,width) (x) <= (width) && (y) <= (hight) && (x) >= 0 && (y) >= 0
#define UP(x,y) maze[y + 1][x] == 0
#define DOWN(x,y) maze[y - 1][x] == 0
#define RIGHT(x,y) maze[y][x + 1] == 0
#define LEFT(x,y) maze[y][x - 1] == 0

int main(){
    int maze[5][5] = {
        {0,0,0,0,0},
        {1,1,1,1,0},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0}
    };
    autofree Stack *stack;
    init_stack(&stack, 50);
    int x = 0, y = 0;
    while( x < 5 && y < 5 ){
        maze[y][x] = 2;
        if( INMAZE(x + 1,y,4,4) && RIGHT(x,y)){
            stack -> push(stack, y);
            stack -> push(stack, ++x);
        }else if( INMAZE(x - 1,y,4,4) && LEFT(x,y)){
            stack -> push(stack, y);
            stack -> push(stack, --x);
        }else if( INMAZE(x,y + 1,4,4) && UP(x,y)){
            stack -> push(stack, ++y);
            stack -> push(stack, x); 
        }else if( INMAZE(x,y - 1,4,4) && DOWN(x,y)){
            stack -> push(stack, --y);
            stack -> push(stack, x);
        }else if( x  == 4 && y == 4 ){
            printf("Yes\n");
            break;
        }else if( !(stack -> isEmpty(stack)) ){
            x = stack -> peek(stack);
            stack -> pop(stack);
            y = stack -> peek(stack);
            stack -> pop(stack);
        }else{
            printf("No\n");
            break;
        }
    }
    return 0;
}