int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool dfs(int x, int y, int index, char** board, int boardSize, int* boardColSize, char * word, int** visited){
    if (index == strlen(word)-1){
        //printf("%s","!!!!");
        return word[index] == board[x][y];
    }
    if (word[index]==board[x][y]){
        visited[x][y] = 1;
        for(int i=0;i<4;i++){
            int new_x = x+dir[i][0];
            int new_y = y+dir[i][1];
            if(new_x >= 0 && new_x < boardSize && new_y >= 0 && new_y < *boardColSize &&!visited[new_x][new_y]){
                if(dfs(new_x,new_y,index+1,board,boardSize,boardColSize,word,visited)){
                    return true;
                }
            }
        }
        visited[x][y] = 0;
    }
    return false;
    
}
bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int **visited;
	visited = (int **)malloc(sizeof(int *) * boardSize);//分配指针数组，计算行的大小
	for(int i=0; i<boardSize; i++)
	{
   		visited[i] = (int *)malloc(sizeof(int) * (*boardColSize));//分配每个指针所指向的数组，再计算列
	}
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(dfs(i,j,0,board,boardSize,boardColSize,word,visited)){
                return true;
            }
        }
    }
    return false;
}
