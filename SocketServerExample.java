package blah;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.InputStream;
import java.lang.ClassNotFoundException;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.BufferedReader;
import java.io.InputStreamReader 

;


public class SocketServerExample {
    
    private static ServerSocket server;
    private static int port = 9876;
    
    public static void main(String args[]) throws IOException, ClassNotFoundException{
        server = new ServerSocket(port,256);
        int x=0;
        while(true){
           
            System.out.println("Waiting for the client request");
            Socket socket = server.accept();
            OutputStream output = socket.getOutputStream();
            InputStream input = socket.getInputStream();

            BufferedReader reader = new BufferedReader(new InputStreamReader(input));
            String line = reader.readLine();  

            socket.close();
        }
    }
    
}
