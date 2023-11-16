# include<stdio.h>
# include<conio.h>
# include<stdlib.h>

int matrix[4][4] = 
{
    {0,0,0,0},
    {0,0,0,0}, 
    {0,0,0,0},
    {0,0,0,0}
};
	
void matout();
void UP();
void DOWN();
void LEFT();
void RIGHT();
int spawn();
void move();
int available();

int main(){
    spawn();
    while (available()){
        matout();
        int a[4][4];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                a[r][c] = matrix[r][c];
            }
        }
        move();
        if (a != matrix){
            spawn();
        }
    }
}

void matout(){
    system("cls");
	for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (matrix[i][j] == 0){
                printf("-\t");
            }
            else{
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n\n");
}

int adjup(int r, int c){
    return matrix[r-1][c];
}

int adjdown(int r, int c){
    return matrix[r+1][c];
}

int adjleft(int r, int c){
    return matrix[r][c-1];
}

int adjright(int r, int c){
    return matrix[r][c+1];
}

void UP(){
    for (int i = 0; i < 4; i++){
        for (int r = 1; r < 4; r++){
            for (int c = 0; c < 4; c++){
                if (adjup(r,c) == 0){
                    matrix[r-1][c] = matrix[r][c];
                    matrix[r][c] = 0;
                }
                if (adjup(r,c) == matrix[r][c] && adjup(r,c) != 0){
                    matrix[r-1][c] *= 2;
                    matrix[r][c] = 0;
                }
            }
        }
    }
}

void DOWN(){
    for (int i = 0; i < 4; i++){
        for (int r = 2; r >= 0; r--){
            for (int c = 0; c < 4; c++){
                if (adjdown(r,c) == 0){
                    matrix[r+1][c] = matrix[r][c];
                    matrix[r][c] = 0;
                }
                if (adjdown(r,c) == matrix[r][c] && adjdown(r,c) != 0){
                    matrix[r+1][c] *=2;
                    matrix[r][c] = 0;
                }
            }
        }
    }
}

void LEFT(){
    for (int i = 0; i < 4; i++){
        for (int c = 1; c < 4; c++){
            for (int r = 0; r < 4; r++){
                if (adjleft(r,c) == 0){
                    matrix[r][c-1] = matrix[r][c];
                    matrix[r][c] = 0;
                }
                if (adjleft(r,c) == matrix[r][c] && adjleft(r,c) != 0){
                    matrix[r][c-1] *= 2;
                    matrix[r][c] = 0;
                }
            }
        }
    }
}

void RIGHT(){
    for (int i = 0; i < 4; i++){
        for (int c = 2; c >= 0; c--){
            for (int r = 0; r < 4; r++){
                if (adjright(r,c) == 0){
                    matrix[r][c+1] = matrix[r][c];
                    matrix[r][c] = 0;
                }
                if (adjright(r,c) == matrix[r][c] && adjright(r,c) != 0){
                    matrix[r][c+1] *= 2;
                    matrix[r][c] = 0;
                }
            }
        }
    }
} 

int spawn(){
    while (1){
        int r = rand() % 4;
        int c = rand() % 4;
        if (matrix[r][c] == 0){
            matrix[r][c] = 2;
            break;
        }
    }
}

void move(){
    switch(getch()){
        case 'w':
            UP();
            break;
        case 's':
            DOWN(); 
            break;  
        case 'a':
            LEFT();
            break;
        case 'd':
            RIGHT();
            break;
        default:
            exit(0);
    }
}

int available(){
    int l = 0;
    for (int r = 0; r < 4; r++){
        for (int c = 0; c < 4; c++){
            if (matrix[r][c] == 0){
                l = 1;
            }
        }
    }
    return l;
}