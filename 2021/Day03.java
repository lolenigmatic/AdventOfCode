package com.company;

import java.util.ArrayList;
import java.util.Iterator;

public class Day3 {
    public int solve1(ArrayList<String> input){
        int result;

        String gammaStr = "";
        String epsilonStr = "";

        int lineLength = input.get(0).length();
        int[][] counts = new int[lineLength][2];

        int j;

        for (String line : input){
            char[] chars = line.toCharArray();
            j = 0;
            for(char c : chars){
                if (c == '0'){
                    counts[j][0]++;
                }
                else{
                    counts[j][1]++;
                }
                j++;
            }
        }

        for (int i = 0; i < lineLength; i++){
            if (counts[i][0] > counts[i][1]){
                gammaStr += "0";
                epsilonStr += "1";
            }
            else{
                gammaStr += "1";
                epsilonStr += "0";
            }
        }

        System.out.println(gammaStr);
        System.out.println(epsilonStr);

        int gamma = Integer.parseInt(gammaStr, 2);
        int epsilon = Integer.parseInt(epsilonStr, 2);

        return gamma * epsilon;
    }

    public int solve2(ArrayList<String> input){
        ArrayList<String> oxygen = new ArrayList<>(input);
        ArrayList<String> carbon = new ArrayList<>(input);

        int lineLength = oxygen.get(0).length();

        for(int i = 0; i < lineLength; i++){
            char[] chars = new char[oxygen.size()];

            for (int j = 0; j < oxygen.size(); j++){
                chars[j] = oxygen.get(j).charAt(i);
            }

            int mostCommon = mostCommonChar(chars);

            Iterator<String> iterator = oxygen.iterator();

            while(iterator.hasNext()){
                String line = iterator.next();
                if(mostCommon == 1 && line.charAt(i) != '1') {
                    iterator.remove();
                }
                else if(mostCommon == 0 && line.charAt(i) != '0'){
                    iterator.remove();
                }
                else if(mostCommon == -1 && line.charAt(i) != '1'){
                    iterator.remove();
                }
            }

            if(oxygen.size() == 1){
                break;
            }
        }

        for(int i = 0; i < lineLength; i++){
            char[] chars = new char[carbon.size()];

            for (int j = 0; j < carbon.size(); j++){
                chars[j] = carbon.get(j).charAt(i);
            }

            int mostCommon = mostCommonChar(chars);

            Iterator<String> iterator = carbon.iterator();

            while(iterator.hasNext()){
                String line = iterator.next();
                if(mostCommon == 1 && line.charAt(i) == '1') {
                    iterator.remove();
                }
                else if(mostCommon == 0 && line.charAt(i) == '0'){
                    iterator.remove();
                }
                else if(mostCommon == -1 && line.charAt(i) == '1'){
                    iterator.remove();
                }
            }

            if(carbon.size() == 1){
                break;
            }
        }

        int oxygenNum = Integer.parseInt(oxygen.get(0), 2);
        int carbonNum = Integer.parseInt(carbon.get(0), 2);

        return oxygenNum * carbonNum;
    }

    /**
     * returns -1 if both are equally common, 1 if 1 is more common, 0 if 0 is more common
     * @param chars
     * @return
     */
    private int mostCommonChar(char[] chars){
        int[] counts = new int[2];

        for (char aChar : chars) {
            if (aChar == '0') {
                counts[0]++;
            } else {
                counts[1]++;
            }
        }

        if(counts[0] > counts[1]) return 0;
        if(counts[1] > counts[0]) return 1;
        return -1;
    }

    private int maxIndex(int[] array){
        int maxIndex = 0;
        int max = 0;

        for(int i = 0; i < array.length; i++){
            if (array[i] > max) {
                max = array[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }
}
