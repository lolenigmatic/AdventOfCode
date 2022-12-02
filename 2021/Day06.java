package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Day6 {
    public int solve1(ArrayList<String> input) {
        String[] inputSplit = input.get(0).split(",");
        ArrayList<Integer> fish = new ArrayList<>();

        for (String num : inputSplit) {
            fish.add(Integer.parseInt(num));
        }

        for (int i = 0; i < 256; i++) {
            /*
            fish size will change throughout the for loop
            we want to only loop through the initial fish list, and not do anything to the newly added
            fish in this cycle
            */

            int initSize = fish.size();

            for (int j = 0; j < initSize; j++) {
                int thisFish = fish.get(j);

                if (thisFish == 0) {
                    fish.set(j, 6);
                    fish.add(8);
                } else {
                    fish.set(j, thisFish - 1);
                }
            }

            System.out.println(initSize);
        }
        return fish.size();
    }

    public long solve2(ArrayList<String> input){
        String[] inputSplit = input.get(0).split(",");

        long[] fishes = new long[9];

        for(String num : inputSplit){
            int thisNum = Integer.parseInt(num);
            fishes[thisNum]++;
        }

        for(int i = 0; i < 256; i++){
            long newFishes = fishes[0];
            fishes[0] = 0;

            System.arraycopy(fishes, 1, fishes, 0, 8);

            fishes[6] += newFishes;
            fishes[8] = newFishes;
        }

        return Arrays.stream(fishes).sum();
    }
}

