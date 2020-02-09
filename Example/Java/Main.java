// Contributed by Gnome

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        Operations operations = new Operations();

        String prompt = "";
        String[] input;
        String filename = "";

        List<String> file = new List<>() {
            @Override
            public int size() {
                return 0;
            }

            @Override
            public boolean isEmpty() {
                return false;
            }

            @Override
            public boolean contains(Object o) {
                return false;
            }

            @Override
            public Iterator<String> iterator() {
                return null;
            }

            @Override
            public Object[] toArray() {
                return new Object[0];
            }

            @Override
            public <T> T[] toArray(T[] a) {
                return null;
            }

            @Override
            public boolean add(String s) {
                return false;
            }

            @Override
            public boolean remove(Object o) {
                return false;
            }

            @Override
            public boolean containsAll(Collection<?> c) {
                return false;
            }

            @Override
            public boolean addAll(Collection<? extends String> c) {
                return false;
            }

            @Override
            public boolean addAll(int index, Collection<? extends String> c) {
                return false;
            }

            @Override
            public boolean removeAll(Collection<?> c) {
                return false;
            }

            @Override
            public boolean retainAll(Collection<?> c) {
                return false;
            }

            @Override
            public void clear() {

            }

            @Override
            public String get(int index) {
                return null;
            }

            @Override
            public String set(int index, String element) {
                return null;
            }

            @Override
            public void add(int index, String element) {

            }

            @Override
            public String remove(int index) {
                return null;
            }

            @Override
            public int indexOf(Object o) {
                return 0;
            }

            @Override
            public int lastIndexOf(Object o) {
                return 0;
            }

            @Override
            public ListIterator<String> listIterator() {
                return null;
            }

            @Override
            public ListIterator<String> listIterator(int index) {
                return null;
            }

            @Override
            public List<String> subList(int fromIndex, int toIndex) {
                return null;
            }
        };

        do {

            System.out.print(prompt);
            input = in.nextLine().split(" ");

            switch (input[0]) {

                case "p":
                    // Prompt

                    if (input.length == 1) {
                        prompt = "? ";
                    } else {
                        prompt = input[1] + " ";
                    }

                    break;
                case "o":
                    // Open a file

                    try {
                        filename = input[1];
                        file = operations.openFile(filename);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    break;
                case "a":
                    // Append to buffer

                    file = operations.writeBuffer(file);

                    break;
                case "w":
                    // Write to file

                    try {
                        operations.writeFile(file, filename);
                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                    }

                    break;
                case "l":
                    // List the buffer

                    operations.listFile(file);

                    break;
            }

        } while (!input[0].equals("q"));

        System.out.println("Bye!");

    }

}
