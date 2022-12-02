package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Day1 {
    public int solve1(ArrayList<String> input) {
        int count = -1;
        int prevNumber = 0;
        int currentNumber;

        for(String line : input){
            currentNumber = Integer.parseInt(line);

            if(prevNumber < currentNumber){
                count++;
            }

            prevNumber = currentNumber;
        }

        return count;
    }

    public int solve2(ArrayList<String> numbers) {

        int count = -1;
        int thisSum;
        int prevSum = 0;

        for (int i = 0; i < numbers.size() - 2; i++){
            thisSum = Integer.parseInt(numbers.get(i)) + Integer.parseInt(numbers.get(i + 1)) + Integer.parseInt(numbers.get(i + 2));
            if(thisSum > prevSum){
                count++;
            }
            prevSum = thisSum;
        }

        return count;
    }
}
