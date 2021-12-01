package com.company;

import java.io.File;
import java.io.FileNotFoundException;

public class Main {

    public static void main(String[] args) {
        File file = new File("./src/com/company/Day1Input.txt");
        Day1 task = new Day1();

        try {
            System.out.println(task.solve2(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}
