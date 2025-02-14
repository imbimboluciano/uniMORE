package oop.Collections;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.LinkedList;

public class SpeedTestTest {

    final int times = 10000;

    @Test
    void SpeedTest(){

        System.out.println("Inserting element at beginning...");
        System.out.println(SpeedTest.insertBeginning(new ArrayList<>(),"hello",times));
        System.out.println(SpeedTest.insertBeginning(new LinkedList<>(),"hello",times));


        System.out.println("Inserting element at end...");
        System.out.println(SpeedTest.insertEnd(new ArrayList<>(),"world",times));
        System.out.println(SpeedTest.insertEnd(new LinkedList<>(),"world",times));

    }
}
