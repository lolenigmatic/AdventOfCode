package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class Day5 {

    public int solve1(ArrayList<String> input) {
        int[][] grid = new int[1000][1000];

        for (String line : input) {

            int[][] coordinates = parseLine(line);

            if (coordinates[0][0] == coordinates[1][0] ) {
                if(coordinates[0][1] < coordinates[1][1]){
                    for (int i = coordinates[0][1]; i <= coordinates[1][1]; i++){
                        grid[coordinates[0][0]][i]++;
                    }
                }
                else{
                    for (int i = coordinates[0][1]; i >= coordinates[1][1]; i--){
                        grid[coordinates[0][0]][i]++;
                    }
                }
            }

            if (coordinates[0][1] == coordinates[1][1]){
                if(coordinates[0][0] < coordinates[1][0]){
                    for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
                        grid[i][coordinates[0][1]]++;
                    }
                }
                else{
                    for(int i = coordinates[0][0]; i >= coordinates[1][0]; i--){
                        grid[i][coordinates[0][1]]++;
                    }
                }
            }

        }

        return checkGrid(grid);
    }

    public int solve2(ArrayList<String> input){
        int[][] grid = new int[1000][1000];

        for(String line : input){

            int[][] coordinates = parseLine(line);

            if (coordinates[0][0] == coordinates[1][0] ) {
                if(coordinates[0][1] < coordinates[1][1]){
                    for (int i = coordinates[0][1]; i <= coordinates[1][1]; i++){
                        grid[coordinates[0][0]][i]++;
                    }
                }
                else{
                    for (int i = coordinates[0][1]; i >= coordinates[1][1]; i--){
                        grid[coordinates[0][0]][i]++;
                    }
                }
            }

            if (coordinates[0][1] == coordinates[1][1]){
                if(coordinates[0][0] < coordinates[1][0]){
                    for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
                        grid[i][coordinates[0][1]]++;
                    }
                }
                else{
                    for(int i = coordinates[0][0]; i >= coordinates[1][0]; i--){
                        grid[i][coordinates[0][1]]++;
                    }
                }
            }

            //(x1, y1), (x2, y2).
            //x2 - x1 == y2 - y1

            boolean diag = Math.abs(coordinates[1][0] - coordinates[0][0]) == Math.abs(coordinates[1][1] - coordinates[0][1]);

            if (diag){
                
                //If the line goes downwards, make it go upwards
                if (coordinates[0][1] > coordinates[1][1]){
                    int[] temp = coordinates[0];
                    coordinates[0] = coordinates[1];
                    coordinates[1] = temp;
                }

                //if line goes from bottom left to top right
                if(coordinates[0][0] < coordinates[1][0]){
                    for(int x = coordinates[0][0], y = coordinates[0][1]; x <= coordinates[1][0]; x++, y++){
                        grid[x][y]++;
                    }
                }
                else{
                    for(int x = coordinates[0][0], y = coordinates[0][1]; x >= coordinates[1][0]; x--, y++){
                        grid[x][y]++;
                    }
                }
            }
        }

        return checkGrid(grid);
    }

    public int[][] parseLine(String input){

        String parse = input.replace(" -> ", ",");
        String[] coordinatesStr = parse.split(",");
        int[][] coordinates = new int[2][2];

        Iterator<String> it = Arrays.stream(coordinatesStr).iterator();

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                coordinates[i][j] = Integer.parseInt(it.next());
            }
        }

        return coordinates;
    }

    public int checkGrid(int[][] grid){
        int count = 0;

        for (int[] ints : grid) {
            for (int j = 0; j < grid.length; j++) {
                if (ints[j] > 1) {
                    count++;
                }
            }
        }
        return count;
    }
}