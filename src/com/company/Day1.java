package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Day1 {
    public int solve1(File input) throws FileNotFoundException {
        Scanner scanner = new Scanner(input);
        int count = -1;
        int prevNumber = 0;
        int currentNumber;

        while(scanner.hasNext()){
            currentNumber = scanner.nextInt();

            if(prevNumber < currentNumber){
                count++;
            }

            prevNumber = currentNumber;
        }

        return count;
    }

    public int solve2(File input) throws FileNotFoundException{
        Scanner scanner = new Scanner(input);
        ArrayList<Integer> numbers = new ArrayList<>();

        while(scanner.hasNextInt()){
            int number = scanner.nextInt();
            numbers.add(number);
        }

        int count = -1;
        int thisSum;
        int prevSum = 0;

        for (int i = 0; i < numbers.size() - 2; i++){
            thisSum = numbers.get(i) + numbers.get(i + 1) +numbers.get(i + 2);
            if(thisSum > prevSum){
                count++;
            }
            prevSum = thisSum;
        }

        return count;
    }
}
