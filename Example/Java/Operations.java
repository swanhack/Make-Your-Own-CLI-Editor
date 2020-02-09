// Contributed by Gnome

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.util.List;
import java.util.Scanner;

public class Operations {

    public List<String> openFile(String filename) throws IOException {

        File file = new File(filename);

        if (!file.exists()) {
            PrintWriter writer = new PrintWriter(filename);
            writer.close();
        }

        return Files.readAllLines(file.toPath());

    }

    public void listFile(List<String> file) {

        for (int i = 0 ; i < file.size() ; i++ ) {
            System.out.println(i + 1 + "\t" + file.get(i));
        }

    }

    public List<String> writeBuffer(List<String> fileBuffer) {

        Scanner in = new Scanner(System.in);
        String buffer;

        do {

            buffer = in.nextLine();

            fileBuffer.add(buffer);

        } while (!buffer.equals("."));

        fileBuffer.remove(fileBuffer.size() - 1);

        return fileBuffer;

    }

    public void writeFile(List<String> file, String filename) throws FileNotFoundException {

        PrintWriter writer = new PrintWriter(filename);

        for (String line : file) {
            writer.println(line);
        }

        writer.close();

    }

}
