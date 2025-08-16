package ticTacToe;

import java.util.Scanner;

public class Game {
    
    Board board;
    Player playerO;
    Player playerX;
    Player currentPlayer;
    boolean gameEnded;
    
    public Game(int size) {
        this.board = new Board(size);
        this.playerO = new Player(PlayerType.O);
        this.playerX = new Player(PlayerType.X);
        this.currentPlayer = playerO; // O starts the game
        this.gameEnded = false;
    }
    
    public void start() {
        printBoard();
        
        try (Scanner scanner = new Scanner(System.in)) {
            while (!gameEnded) {
                System.out.println("Player " + currentPlayer.playerType + "'s turn");
                System.out.print("Enter row (0-" + (board.size-1) + "): ");
                int row = scanner.nextInt();
                
                System.out.print("Enter column (0-" + (board.size-1) + "): ");
                int col = scanner.nextInt();
                
                if (isValidMove(row, col)) {
                    makeMove(row, col);
                    printBoard();
                    
                    if (checkWin(row, col)) {
                        System.out.println("Player " + currentPlayer.playerType + " wins!");
                        gameEnded = true;
                    } else if (isBoardFull()) {
                        System.out.println("Game ended in a draw!");
                        gameEnded = true;
                    } else {
                        switchPlayer();
                    }
                } else {
                    System.out.println("Invalid move! Try again.");
                }
            }
        }
    }
    
    private boolean isValidMove(int row, int col) {
        if (row < 0 || row >= board.size || col < 0 || col >= board.size) {
            return false;
        }
        return board.board[row][col].equals("[ ]");
    }
    
    private void makeMove(int row, int col) {
        board.board[row][col] = "[" + currentPlayer.playerType + "]";
    }
    
    private void switchPlayer() {
        currentPlayer = (currentPlayer == playerO) ? playerX : playerO;
    }
    
    private boolean checkWin(int row, int col) {
        String symbol = "[" + currentPlayer.playerType + "]";
        
        // Check row
        boolean rowWin = true;
        for (int c = 0; c < board.size; c++) {
            if (!board.board[row][c].equals(symbol)) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
        
        // Check column
        boolean colWin = true;
        for (int r = 0; r < board.size; r++) {
            if (!board.board[r][col].equals(symbol)) {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
        
        // Check diagonals
        boolean diagWin = true;
        boolean antiDiagWin = true;
        
        for (int i = 0; i < board.size; i++) {
            if (!board.board[i][i].equals(symbol)) {
                diagWin = false;
            }
            if (!board.board[i][board.size - 1 - i].equals(symbol)) {
                antiDiagWin = false;
            }
        }
        
        return diagWin || antiDiagWin;
    }
    
    private boolean isBoardFull() {
        for (int i = 0; i < board.size; i++) {
            for (int j = 0; j < board.size; j++) {
                if (board.board[i][j].equals("[ ]")) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void printBoard() {
        for (int i = 0; i < board.size; i++) {
            for (int j = 0; j < board.size; j++) {
                System.out.print(board.board[i][j]);
            }
            System.out.println();
        }
    }
}
