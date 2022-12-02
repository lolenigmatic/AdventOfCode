package com.company;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Day8 {
    public int solve1(ArrayList<String> input){
        String[][] uniqueSignalPatterns = new String[input.size()][10];
        String[][] fourDigitOutputs = new String[input.size()][4];

        for (int i = 0; i < input.size(); i++){
            String line = input.get(i);
            String[] intermediateSplit = line.split(" \\| ");

            uniqueSignalPatterns[i] = intermediateSplit[0].split(" ");
            fourDigitOutputs[i] = intermediateSplit[1].split(" ");
        }

        int counter = 0;
        for (String[] fourDigitOutput : fourDigitOutputs) {
            for (int j = 0; j < 4; j++) {
                String thisPattern = fourDigitOutput[j];
                int l = thisPattern.length();

                if (l == 2 || l == 4 || l == 3 || l == 7) {
                    counter++;
                }
            }
        }

        return counter;
    }

    public int solve2(ArrayList<String> input){
        String[][] uniqueSignalPatterns = new String[input.size()][10];
        String[][] fourDigitOutputs = new String[input.size()][4];

        for (int i = 0; i < input.size(); i++){
            String line = input.get(i);
            String[] intermediateSplit = line.split(" \\| ");

            uniqueSignalPatterns[i] = intermediateSplit[0].split(" ");
            fourDigitOutputs[i] = intermediateSplit[1].split(" ");
        }

        int total = 0;

        for (int i = 0; i < input.size(); i++){
            HashMap<Integer, HashSet<Character>> digits= new HashMap<>();

            //First pass, get 1, 4, 7, 8
            for(int j = 0; j < uniqueSignalPatterns[i].length; j++){
                String thisPattern = uniqueSignalPatterns[i][j];

                switch (thisPattern.length()) {
                    case 2 -> digits.put(1, stringToSet(thisPattern));
                    case 4 -> digits.put(4, stringToSet(thisPattern));
                    case 3 -> digits.put(7, stringToSet(thisPattern));
                    case 7 -> digits.put(8, stringToSet(thisPattern));
                }
            }

            //2nd pass, get 2, 3, 6,
            for(int j = 0; j < uniqueSignalPatterns[i].length; j++){
                String thisPattern = uniqueSignalPatterns[i][j];

                //digit 2
                if(thisPattern.length() == 5 && compareCommonChars(digits.get(4), thisPattern) == 2){
                    digits.put(2, stringToSet(thisPattern));
                }
                //digit 3
                else if(thisPattern.length() == 5 && compareCommonChars(digits.get(7), thisPattern) == 3){
                    digits.put(3, stringToSet(thisPattern));
                }
                //digit 6
                else if(thisPattern.length() == 6 && compareCommonChars(digits.get(1), thisPattern) == 1){
                    digits.put(6, stringToSet(thisPattern));
                }
            }

            //3rd pass, get 5, 9
            for(int j = 0; j < uniqueSignalPatterns[i].length; j++){
                String thisPattern = uniqueSignalPatterns[i][j];

                //digit 5
                if(thisPattern.length() == 5 && compareCommonChars(digits.get(6), thisPattern) == 5){
                    digits.put(5, stringToSet(thisPattern));
                }
                //digit 9
                else if(thisPattern.length() == 6 && compareCommonChars(digits.get(3), thisPattern) == 5){
                    digits.put(9, stringToSet(thisPattern));
                }
            }

            //4th pass because fuck zero

            for(int j = 0; j < uniqueSignalPatterns[i].length; j++){
                String thisPattern = uniqueSignalPatterns[i][j];

                if(thisPattern.length() == 6 && compareCommonChars(digits.get(5), thisPattern) == 4){
                    digits.put(0, stringToSet(thisPattern));
                }
            }

            StringBuilder output = new StringBuilder();

            //loop through each of the 4 string sets to get output
            for(int j = 0; j < fourDigitOutputs[i].length; j++){
                HashSet<Character> thisSet = stringToSet(fourDigitOutputs[i][j]);

                for(int k = 0; k < 10; k++){
                    if(thisSet.equals(digits.get(k))){
                        output.append(k);
                    }
                }
            }

            total += Integer.parseInt(output.toString());
        }

        return total;
    }

    public HashSet<Character> stringToSet(String s){
        HashSet<Character> charSet = new HashSet<>();

        for(int i = 0; i < s.length(); i++){
            charSet.add(s.charAt(i));
        }

        return charSet;
    }

    public int compareCommonChars(HashSet<Character> setA, String b){
        int commonCount = 0;

        for(int i = 0; i < b.length(); i++){
            if(setA.contains(b.charAt(i))){
                commonCount++;
            }
        }

        return commonCount;
    }


}
