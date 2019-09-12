import java.util.*;
import java.lang.Math;

class bank_method
{
    public String name;
    public double acc;
    public double bal;
 
    public void details()
    {   
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter your Name : ");
        name = sc.next();
        System.out.println("Enter your Account number : ");
        acc = sc.nextLong();
        System.out.println("Enter your The Current Balance : ");
        bal = sc.nextLong();
        output();
        System.out.println("\n\tWhich account do you have?");
        System.out.println("Press 1 if you have Savings Account ");
        System.out.println("Press 2 if you have Current Account");
    }

    public void output()
    {
        System.out.println("\t\tAccount Holder's Name : " +name);
        System.out.println("\t\tAccount Number : " +acc);
        System.out.println("\t\tCurrent Balance : " +bal);
    }
    
    
}

class acc extends bank_method
{
    public int choice;
    
    public void acc_type()
    {
        Scanner sc = new Scanner(System.in);
        details();
        choice = sc.nextInt();
        switch(choice)
        {
            case 1 : savings();
                     break;

            case 2 : current();
                     break;
        }
    }
    
    public void ci()
    {
        
        Scanner sc = new Scanner(System.in);
        double t;
        double ci;
        System.out.println("How long is it been that you deposited your amount");
        t = sc.nextDouble();
        ci = bal*(Math.pow((1.0 + 0.05),t));
        System.out.println("Intrest earned = "+ci);
    }
    
    public void savings()
    {
        int choice;
        int amount;
        Scanner sc = new Scanner(System.in);
        System.out.println("Press 1 to see amount earned through intrest");
        System.out.println("Press 2 to withdraw");
        choice = sc.nextInt();
        switch(choice)
        {
            
            case 1 : ci();
                     
                     break;

            case 2 : System.out.println("Enter the amount you want to withdraw");
                     amount = sc.nextInt();
                     System.out.println("The entered amount " + "\"" + amount + "\"" + "has been withdrawn");
                     bal = bal - amount;
                     System.out.println("Remaining Balance : " +bal);
                     break;
        }
    }   
    
    public void current()
    {
        int c;
        int amount;
        Scanner sc = new Scanner(System.in);
        System.out.println("Press 1 to to Issue a Cheque Book");
        System.out.println("Press 2 to Withdraw amount ");
        c = sc.nextInt();
        switch(c)
        {
            case 1 : System.out.println("Your Cheque Book will be Delivered to your Home");
                     break;
                            
            case 2 : System.out.println("Enter the amount you want to withdraw");
                     amount = sc.nextInt();
                     System.out.println("The entered amount "+amount +" has been withdrawn");
                     System.out.println("Remaining Balance : " +bal);
                     if(bal < 500)
                     {
                         System.out.println("Your Balance is less than required minimum balance");
                         System.out.println("Service Charge  will be imposed, @ 5% of the required minimum balance per day");
                         bal = bal - amount - (0.05*500);
                     }
                     bal = bal - amount;
                     break;
        }
    }
}
class bank
{
    public static void main(String args[])
    {
        acc ac = new acc();
        ac.acc_type();
    }
}