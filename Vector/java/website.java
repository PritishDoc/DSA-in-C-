import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter your website URL to check: ");
        String url = sc.nextLine();

        // Extract protocol
        String protocol = url.substring(0, url.indexOf(":"));
        if (protocol.equals("http")) {
            System.out.println("It's a Hypertext Transfer Protocol (HTTP).");
        } else if (protocol.equals("ftp")) {
            System.out.println("It's a File Transfer Protocol (FTP).");
        }

        // Extract domain extension
        String ext = url.substring(url.lastIndexOf(".") + 1);

        if (ext.equals("com")) {
            System.out.println("It's a Commercial website.");
        } else if (ext.equals("net")) {
            System.out.println("It's a Network-related website.");
        } else if (ext.equals("org")) {
            System.out.println("It's an Organization website.");
        } else {
            System.out.println("Unknown website type.");
        }

        sc.close(); // Closing scanner
    }
}
