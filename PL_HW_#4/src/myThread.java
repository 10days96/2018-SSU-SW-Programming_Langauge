import java.util.ArrayList;
import java.io.*;

public class myThread  implements Runnable{
    private bunsik b;
    private ArrayList<Customer> customers = new ArrayList<Customer>();
    private ArrayList<order> orders = new ArrayList<order>();
    private String menu;
    private int customer_num;
    private String date;
    private int customer_num2;
    private String name;
    private String phone_number;
    private String customer_date;
    private int funnum;
    myThread(bunsik b,int funnum){
        this.b = b;
        this.funnum = funnum;
    }
    @Override
    public void run(){
        synchronized (this){

        }

    }

    private void findCustomer(){

    }

}
