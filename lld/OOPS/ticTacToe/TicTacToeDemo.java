package ticTacToe;

public class TicTacToeDemo {
    public static void main(String[] args) {
        System.out.println("Welcome to Tic Tac Toe Game!");
        System.out.println("============================");
        
        int size = 3;
        Game game = new Game(size);
        
        game.start();
    }
}