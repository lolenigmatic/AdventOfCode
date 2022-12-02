package com.company;

import java.util.ArrayList;
import java.util.Collections;

public class Day9 {
    public int solve1(ArrayList<String> input){
        int[][][] grid = new int[input.size()][input.get(0).length()][2];

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++) {
                grid[i][j][0] = Integer.parseInt(Character.toString(input.get(i).charAt(j)));
            }
        }

        int lowPointDangerSum = 0;

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(checkSurrounding(grid, i, j)) {
                    lowPointDangerSum += 1 + grid[i][j][0];
                }
            }
        }

        return lowPointDangerSum;
    }

    public int solve2(ArrayList<String> input){
        //third dimension is 0 if cell has not been visited, 1 if already visited
        int[][][] grid = new int[input.size()][input.get(0).length()][2];
        ArrayList<Integer> basins = new ArrayList<>();

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++) {
                grid[i][j][0] = Integer.parseInt(Character.toString(input.get(i).charAt(j)));
                grid[i][j][1] = 0;
            }
        }

        int lowPointDangerSum = 0;
        int answer = 1;

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                if(checkSurrounding(grid, i, j)) {
                    basins.add(basin(grid, i, j, 1));
                }
            }
        }

        int[] largestThree = new int[3];

        for(int i = 0; i < 3; i++){
            largestThree[i] = Collections.max(basins);
            basins.remove(Collections.max(basins));
        }

        return largestThree[0] * largestThree[1] * largestThree[2];
    }

    public boolean checkSurrounding(int[][][] grid, int x, int y){
        int num = grid[x][y][0];

        int xLimit = grid.length;
        int yLimit = grid[x].length;

        if((x-1) >= 0 && grid[x-1][y][0] <= num) return false;
        if((x+1) < xLimit && grid[x+1][y][0] <= num) return false;
        if((y-1) >= 0 && grid[x][y-1][0] <= num) return false;
        if((y+1) < yLimit && grid[x][y+1][0] <= num) return false;

        return true;
    }

    public int basin(int[][][] grid, int x, int y, int size){

        int num = grid[x][y][0];

        int xLimit = grid.length;
        int yLimit = grid[x].length;

        //traverse if: index is within limits, the next cell is larger than current (prevents circular recursion), cell has not been visited)
        if((x-1) >= 0 && grid[x-1][y][0] < 9 && grid[x-1][y][0] > num && grid[x-1][y][1] == 0) {
            grid[x-1][y][1] = 1;
            size = basin(grid, x-1, y, size + 1);
        }
        if((x+1) < xLimit && grid[x+1][y][0] < 9 && grid[x+1][y][0] > num && grid[x+1][y][1] == 0) {
            grid[x+1][y][1] = 1;
            size = basin(grid, x+1, y, size + 1);
        }
        if((y-1) >= 0 && grid[x][y-1][0] < 9 && grid[x][y-1][0] > num && grid[x][y-1][1] == 0) {
            grid[x][y-1][1] = 1;
            size = basin(grid, x, y-1, size + 1);
        }
        if((y+1) < yLimit && grid[x][y+1][0] < 9 && grid[x][y+1][0] > num && grid[x][y+1][1] == 0) {
            grid[x][y+1][1] = 1;
            size = basin(grid, x, y+1, size + 1);
        }

        return size;
    }
}
