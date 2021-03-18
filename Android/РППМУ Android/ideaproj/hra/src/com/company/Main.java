package com.company;

import com.google.api.services.drive.Drive;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.sql.Driver;

public class Main {

    public static void main(String[] args) throws IOException {


        String s1="https://googledrive.com/host/1v7Abo77HYoL1kOjVTTSRCQcjawJpHWqR/1.txt";
        String fileId = "1v7Abo77HYoL1kOjVTTSRCQcjawJpHWqR";
        OutputStream outputStream = new ByteArrayOutputStream();

        Drive driveService = null;
        driveService.files().export(fileId, "application/pdf").executeMediaAndDownloadTo(outputStream);
        s1=driveService.files().toString();
        System.out.println(s1);




    }
}
