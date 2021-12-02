package com.company;

import java.util.ArrayList;

public class Day2 {

    public int solve1(ArrayList<String> input){
        int depth = 0;
        int horizontal = 0;
        int result;

        for (String line : input){
            String[] lineSplit = line.split(" ");
            switch (lineSplit[0]) {
                case "forward" -> horizontal += Integer.parseInt(lineSplit[1]);
                case "down" -> depth += Integer.parseInt(lineSplit[1]);
                case "up" -> depth -= Integer.parseInt(lineSplit[1]);
            }
        }

        result = depth * horizontal;

        return result;
    }

    public int solve2(ArrayList<String> input){
        int depth = 0;
        int horizontal = 0;
        int aim = 0;
        int result;

        for (String line : input){
            String[] lineSplit = line.split(" ");
            int num = Integer.parseInt(lineSplit[1]);
            switch (lineSplit[0]) {
                case "forward" -> {
                    horizontal += num;
                    depth = depth + (num * aim);
                }
                case "up" -> aim -= num;
                case "down" -> aim += num;
            }
        }

        result = depth * horizontal;

        return result;
    }


}
