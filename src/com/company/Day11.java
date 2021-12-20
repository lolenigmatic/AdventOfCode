package com.company;

import java.util.ArrayList;

public class Day11 {
    public int solve1(ArrayList<String> input){
        int[][][] grid = new int[input.get(0).length()][input.size()][2];

        for(int col = 0; col < grid.length; col++){
            for(int row = 0; row < grid[0].length; row++){
                grid[col][row][0] = Integer.parseInt(Character.toString(input.get(col).charAt(row))); // lol
            }
        }

        int totalFlashes = 0;

        for(int i = 0; i < 100; i++){
            //increment every octopus by 1
            for(int col = 0; col < grid.length; col++){
                for(int row = 0; row < grid[0].length; row++){
                    grid[col][row][0]++;
                    grid[col][row][1] = 0;
                }
            }

            //loop through and check for octopuses flashes
            boolean octopusFlashed = true;

            while(octopusFlashed){
                octopusFlashed = false;

                for(int col = 0; col < grid.length; col++){
                    for(int row = 0; row < grid[0].length; row++){
                        if(grid[col][row][0] > 9){
                            grid[col][row][0] = -1; //minus 10?
                            octopusFlashed = true;
                            grid = flash(grid, col, row);
                            totalFlashes++;
                            grid[col][row][1] = 1;
                        }
                    }
                }
            }
        }

        return totalFlashes;
    }

    public int solve2(ArrayList<String> input){
        int[][][] grid = new int[input.get(0).length()][input.size()][2];

        for(int col = 0; col < grid.length; col++){
            for(int row = 0; row < grid[0].length; row++){
                grid[col][row][0] = Integer.parseInt(Character.toString(input.get(col).charAt(row))); // lol
            }
        }


        boolean allFlashed = false;
        int cycleCounter = 0;

        while(!allFlashed)
        {
            allFlashed = true;
            cycleCounter++;

            for(int col = 0; col < grid.length; col++){
                for(int row = 0; row < grid[0].length; row++){
                    grid[col][row][0]++;
                    grid[col][row][1] = 0;
                }
            }

            //loop through and check for octopuses flashes
            boolean octopusFlashed = true;

            while(octopusFlashed){
                octopusFlashed = false;

                for(int col = 0; col < grid.length; col++){
                    for(int row = 0; row < grid[0].length; row++){
                        if(grid[col][row][0] > 9){
                            grid[col][row][0] = -1; //minus 10?
                            octopusFlashed = true;
                            grid = flash(grid, col, row);
                            grid[col][row][1] = 1;
                        }
                    }
                }
            }

            BigLoop:
            for(int col = 0; col < grid.length; col++) {
                for (int row = 0; row < grid[0].length; row++) {
                    if(grid[col][row][1] == 0){
                        allFlashed = false;
                        break BigLoop;
                    }
                }
            }
        }

        return cycleCounter;
    }

    private int[][][] flash(int[][][] grid, int x, int y) {
        int[][][] newGrid = grid;

        int xLimit = grid.length - 1;
        int yLimit = grid[0].length - 1;

        for (int dx = -1; dx < 2; dx++) {
            if (x + dx >= 0 && x + dx <= xLimit) {
                for (int dy = -1; dy < 2; dy++) {
                    if (y + dy >= 0 && y + dy <= yLimit && newGrid[x + dx][y+dy][1] == 0) {
                        newGrid[x + dx][y + dy][0]++;
                    }
                }
            }
        }

        return newGrid;
    }
}
