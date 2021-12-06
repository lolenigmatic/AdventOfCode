package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class Day5 {

    public int solve1(ArrayList<String> input) {
        int[][] grid = new int[1000][1000];

        for (String line : input) {
            String parse = line.replace(" -> ", ",");
            String[] coordinatesStr = parse.split(",");
            int[][] coordinates = new int[2][2];

            Iterator<String> it = Arrays.stream(coordinatesStr).iterator();

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    coordinates[i][j] = Integer.parseInt(it.next());
                }
            }

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

        int count = 0;

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid.length; j++){
                if (grid[i][j] > 1){
                    count++;
                }
            }
        }

        return count;
    }
}