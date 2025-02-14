package oop.Collections;

import java.util.*;

public class Deques {

    public static List<String> reverse(List<String> sentence) {
        Deque<String> stack = new ArrayDeque<>();
        List<String> rev = new ArrayList<>();
        /*for (String tmp: sentence) {
            stack.addFirst(tmp);
        }

        return  stack.stream().toList();
           */

        for (String tmp :
                sentence) {
            stack.addLast(tmp);
        }

        while (!stack.isEmpty()) {
            rev.add(stack.pollLast());
        }

        return rev;


    }

}
