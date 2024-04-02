import java.util.Scanner;

public class StockCommission {
   
   public static void main(String[] args) {
      
      final double COMMISSION = .02;
      double priceOfStock = 21.77;
      int sharesBought = 600;
      double totalPaid;
      double TPNoCommission;
      double TPCommission;
      
      TPNoCommission = sharesBought * priceOfStock;
      TPCommission = TPNoCommission * COMMISSION;
      totalPaid = TPNoCommission + TPCommission;
      
      System.out.println("Kathryn bought " + sharesBought + " shares worth $21.77");
      System.out.println("She paid $" + TPNoCommission + " without commission.");
      System.out.println("The amount of commission paid is $" + TPCommission);
      System.out.println("The total amount paid for the transaction was $" + totalPaid);
      
      
   }     
}