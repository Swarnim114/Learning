package ticTacToe;

public class Board {
    int size ; 
    String [][] board ;
    
    public Board (int size){
        this.size = size ; 
        this.board  = new String[size][size];
        for(int i=0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                board[i][j]="[ ]";
            }
        }
    }
}
