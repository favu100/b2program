package de.hhu.stups.codegenerator;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

public class TestHelper {
    public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
        int size;
        byte[] buffer = new byte[1024];
        while ((size = inputStream.read(buffer)) != -1)
            outputStream.write(buffer, 0, size);
    }

    public static void writeInputToSystem(InputStream inputStream) throws IOException {
        writeInputToOutput(inputStream, System.err);
    }

    public static String readFile(File file) throws IOException {
        return streamToString(Files.newInputStream(file.toPath()));
    }

    public static String streamToString(InputStream inputStream) throws IOException {
        ByteArrayOutputStream result = new ByteArrayOutputStream();
        byte[] buffer = new byte[1024];
        int length;
        while ((length = inputStream.read(buffer)) != -1) {
            result.write(buffer, 0, length);
        }
        return result.toString();
    }

    public static List<Path> generateCode(Path machinePath, GeneratorMode mode, boolean forModelChecking, String addition, boolean embedded) throws IOException {
        CodeGenerator codeGenerator = new CodeGenerator();
        return codeGenerator.generate(machinePath,
                mode,
                false,
                String.valueOf(Integer.MIN_VALUE),
                String.valueOf(Integer.MAX_VALUE),
                "10",
                forModelChecking,
                false,
                true,
                addition,
                false,
                false,
                null,
                null,
                embedded);
    }
}
