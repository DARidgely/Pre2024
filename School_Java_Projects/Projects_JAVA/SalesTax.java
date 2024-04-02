import java.util.Scanner; //import the scanner class
public class SalesTax{

   public static void main(String[] args){
   
      //declare variables
      final double STATE_TAX_PERCENTAGE = 0.04;
      final double COUNTY_TAX_PERCENTAGE = 0.02;
      double purchaseAmount;
      double countyTax;
      double stateTax;
      double totalTax;
      double totalSale;
      
      //Creating a scanner
      Scanner scanner = new Scanner(System.in);
      
      System.out.println("Please enter the purchase amount: ");
      purchaseAmount = scanner.nextDouble();
      
      //calculate the county tax
      countyTax = COUNTY_TAX_PERCENTAGE * purchaseAmount;
      
      //Calculate the state tax
      stateTax = STATE_TAX_PERCENTAGE * purchaseAmount;
      
      // calculate the total tax
      totalTax = stateTax + countyTax;
      
      // calculate the total sale
      totalSale = totalTax + purchaseAmount;
      
      // display details
      System.out.println("Purchase amount: $" + purchaseAmount + "\nState sales tax: " + stateTax + "\nCounty sales tax: " +
                        countyTax + "\nTotal sales tax: " + totalTax + "\nTotal sale: $" + totalSale);
      
      
   
   }
}   