package com.company;

import java.util.ArrayList;

public class Day7 {
    public int solve1(ArrayList<String> input){
        String[] inputSplit = input.get(0).split(",");
        ArrayList<Integer> crabPos = new ArrayList<>();

        int max = 0;

        for (String num : inputSplit) {
            int thisNum = Integer.parseInt(num);
            crabPos.add(thisNum);

            if(max < thisNum){
                max = thisNum;
            }
        }

        int minFuel = 999999999;

        for (int i = 0; i < max; i++){
            int fuel = 0;

            for (Integer thisCrab : crabPos) {
                fuel += Math.abs(thisCrab - i);
            }

            if(minFuel > fuel){
                minFuel = fuel;
            }
        }

        return minFuel;
    }

    public int solve2(ArrayList<String> input){
        String[] inputSplit = input.get(0).split(",");
        ArrayList<Integer> crabPos = new ArrayList<>();

        int max = 0;

        for (String num : inputSplit) {
            int thisNum = Integer.parseInt(num);
            crabPos.add(thisNum);

            if(max < thisNum){
                max = thisNum;
            }
        }

        int minFuel = 999999999;

        for (int i = 0; i < max; i++){
            int fuel = 0;

            for (Integer thisCrab : crabPos) {
                int distance = Math.abs(thisCrab - i);
                fuel += (distance * (distance + 1)) / 2;
            }

            if(minFuel > fuel){
                minFuel = fuel;
            }
        }

        return minFuel;
    }
}
