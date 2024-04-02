import java.util.Scanner;

public class TestAverage{


   public static void main(String[] args){
   
      Scanner scanner = new Scanner(System.in);
      double test1, test2, test3;
      int average;
      
      System.out.println("Please enter three test scores: ");
      test1 = scanner.nextDouble();
      test2 = scanner.nextDouble();
      test3 = scanner.nextDouble();
      
      average = (int) (test1+test2+test3)/3;
      
      System.out.println("Your test average is: " + average); 
       
      
   }
}