package com.company;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Day4 {
    public int solve1(ArrayList<String> input){

        String[] numbersStr = input.get(0).split(",");//bingo input
        ArrayList<Integer> numbers = new ArrayList<>();
        for (String number : numbersStr){
            numbers.add(Integer.parseInt(number));
        }

        //get an input that does not have the empty spaces in between and single spaces between numbers
        ArrayList<String> parsedInput = new ArrayList<>();
        for (int i = 2; i < input.size(); i++){
            String line = input.get(i);
            if (line != ""){
                parsedInput.add(line.replaceAll("  ", " "));
            }
        }

        //3 dimensional array, first holds bingo board, 2nd holds x, 3rd holds y
        //num of bingo boards = (numlines - 1)/6
        int[][][] BINGO = new int[(input.size() - 1) / 6][5][5];
        Iterator<String> iterator = parsedInput.iterator();
        for(int i = 0; i < BINGO.length; i++){
            for(int j = 0; j < 5; j++){
                Scanner scanner = new Scanner(iterator.next());
                for (int k = 0; k < 5; k++){
                    BINGO[i][j][k] = Integer.parseInt(scanner.next());
                }
            }
        }

        //store bingo boards as 2d arrays, every time something gets marked off, change value to -1
        int[][] bingoBoard = new int[0][];
        int numCalled = 0;

        biggestLoop:
        for(int num : numbers){
            for(int i = 0; i < BINGO.length; i++){
                for(int j = 0; j < 5; j++){
                    for(int k = 0; k < 5; k++){
                        if(BINGO[i][j][k] == num){
                            BINGO[i][j][k] = -1;
                        }
                    }
                }
                if(checkBingo(BINGO[i])){
                    bingoBoard = BINGO[i];
                    numCalled = num;
                    break biggestLoop;
                }
            }
        }

        //printBingoBoards(BINGO);
        int result = sumUnticked(bingoBoard) * numCalled;
        return result;
    }

    public void printBingoBoards (int[][][] bingo){
        for(int i = 0; i < bingo.length; i++){
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 5; k++){
                    System.out.print(bingo[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    /**
     * Diagonals don't count Drake
     */
    public boolean checkBingo(int[][] board){
        boolean bingoFlag;

        //Check horizontals
        for(int i = 0; i < 5; i++){
            bingoFlag = true;
            for(int j = 0; j < 5; j++){
                if(board[i][j] != -1){
                    bingoFlag = false;
                }
            }

            if (bingoFlag){
                return true;
            }
        }

        //check verticals
        for(int j = 0; j < 5; j++){
            bingoFlag = true;
            for(int i = 0; i < 5; i++){
                if(board[i][j] != -1){
                    bingoFlag = false;
                }
            }

            if (bingoFlag){
                return true;
            }
        }

        return false;
    }

    public int sumUnticked(int[][] board){
        int total = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(board[i][j] != -1){
                    total += board[i][j];
                }
            }
        }
        return total;
    }
}
