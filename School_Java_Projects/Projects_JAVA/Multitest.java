public class Multitest {
   
   public static void main(String[] args) {
   
      int[][][] x = 
      {
         {
            {5, 5, 5, 5},
            {5, 5, 5, 5}
         },
         {
            {7, 7, 7, 7},
            {7, 7, 7, 7}
         },
         {
            {8, 8, 8, 8},
            {30, 31, 32, 33}
         }
      };
      
      
      
      System.out.println(x[2][1][2]);
      System.out.println(x[1][0][0]);
      
   }
}