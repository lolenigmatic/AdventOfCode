package com.company;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Stack;

public class Day10 {
    private final HashMap<Character, Integer> errorScores = initScores();
    private final HashMap<Character, Character> brackets = initBracket();
    private final HashMap<Character, Integer> charScores = completionScores();

    public int solve1(ArrayList<String> input){

        Stack<Character> bracketStack = new Stack<>();
        int totalErrorScore = 0;

        for(String line : input){
            int thisErrorScore = 0;

            for(int i = 0; i < line.length(); i++){
                char thisChar = line.charAt(i);

                if(brackets.containsKey(thisChar)){
                    bracketStack.push(brackets.get(thisChar));
                }
                else{
                    if(thisChar != bracketStack.pop()){
                        thisErrorScore = errorScores.get(thisChar);
                        break;
                    }
                }
            }

            totalErrorScore += thisErrorScore;
        }

        return totalErrorScore;
    }

    public long solve2(ArrayList<String> input){


        ArrayList<Long> scores = new ArrayList<>();

        for(String line : input){

            Stack<Character> bracketStack = new Stack<>();
            boolean corrupt = false;

            for(int i = 0; i < line.length(); i++){
                char thisChar = line.charAt(i);

                if(brackets.containsKey(thisChar)){
                    bracketStack.push(brackets.get(thisChar));
                }
                else{
                    if(thisChar != bracketStack.peek()){
                        corrupt = true;
                        break;
                    }
                    else{
                        bracketStack.pop();
                    }
                }
            }

            if(!corrupt){
                long totalScore = 0;

                while(!bracketStack.isEmpty()){
                    char thisChar = bracketStack.pop();
                    totalScore = (totalScore * 5) + charScores.get(thisChar);
                }
                scores.add(totalScore);
            }

            bracketStack.clear();
        }

        Collections.sort(scores);

        return scores.get((scores.size() - 1) / 2);
    }
    public HashMap<Character, Integer> completionScores(){
        HashMap<Character, Integer> scores = new HashMap<>();

        scores.put(')', 1);
        scores.put(']', 2);
        scores.put('}', 3);
        scores.put('>', 4);

        return scores;
    }

    public HashMap<Character, Integer> initScores(){
        HashMap<Character, Integer> scores = new HashMap<>();

        scores.put(')', 3);
        scores.put(']', 57);
        scores.put('}', 1197);
        scores.put('>', 25137);

        return scores;
    }

    public HashMap<Character, Character> initBracket(){
        HashMap<Character, Character> brackets = new HashMap<>();

        brackets.put('(', ')');
        brackets.put('[', ']');
        brackets.put('{', '}');
        brackets.put('<', '>');

        return brackets;
    }
}
