import javax.swing.*;
import java.util.ArrayList;
import java.io.*;

public class myThread  implements Runnable{
    private bunsik b;
    private ArrayList<Customer> customers = new ArrayList<Customer>();
    private ArrayList<order> orders = new ArrayList<order>();
    private String menu;
    private String customer_num;
    private String date;
    private String customer_num2;
    private String name;
    private String phone_number;
    private String customer_date;
    private int funnum;
    myThread(bunsik b,int funnum){
        this.b = b;
        this.funnum = funnum;
        customer_num2 = b.jPanel02.getcusternum();
        name = b.jPanel02.getcustername();
        phone_number = b.jPanel02.getcusterphone();
        customer_date = b.jPanel02.getcusterdate();
    }
    @Override
    public void run(){
        synchronized (this){
            readCustomer();
            if(funnum == 3){
                regist_customer();
            }
            if(funnum == 4){
                findCustomer(customer_num2);
            }
            if(funnum == 5){
                deletecustomer(customer_num2);
            }
            saveCustomer();
        }

    }

    private void regist_customer(){
        if(checkErro2() == 1){
            if(findCustomer(customer_num2) == -1){
                Customer c = new Customer(customer_num2,name,phone_number,customer_date);
                customers.add(c);
                b.jPanel02.setcustomername("");
                b.jPanel02.setcustomernum("");
                b.jPanel02.setcustomerdate("");
                b.jPanel02.setcustomerphone("");
                JOptionPane.showMessageDialog(null,"정상적으로 등록 되었습니다.");
            }
            else{
                JOptionPane.showMessageDialog(null,"이미 등록된 정보 입니다.");
            }
        }
    }

    private int findCustomer(String customer_num){
            try {
                for (int i = 0; i < customers.size(); i++) {
                    String c_num = customers.get(i).getCustomer_num();
                    if (c_num.equals(customer_num)) {
                        name = customers.get(i).getname();
                        phone_number = customers.get(i).getPhone_number();
                        customer_date = customers.get(i).getDate();
                        b.jPanel02.setcustomernum(c_num);
                        b.jPanel02.setcustomername(name);
                        b.jPanel02.setcustomerphone(phone_number);
                        b.jPanel02.setcustomerdate(customer_date);
                        return i;
                    }
                      JOptionPane.showMessageDialog(null,"등록된 고객이 아닙니다.");
                        throw new Exception();
                    }
            }catch (Exception e){
                return -1;
            }
        return -1;
    }
    private  void deletecustomer(String customer_num2){
        int index = 0;
        index = findCustomer(customer_num2);
        if(index != -1){
            customers.remove(index);
            JOptionPane.showMessageDialog(null,"정상적으로 삭제 되었습니다.");
            b.jPanel02.setcustomername("");
            b.jPanel02.setcustomernum("");
            b.jPanel02.setcustomerdate("");
            b.jPanel02.setcustomerphone("");
        }
        else{
            JOptionPane.showMessageDialog(null,"등록된 정보가 아니라 작세할 수 없습니다.");
        }
    }
    private void saveCustomer(){
        OutputStream out = null;
        BufferedOutputStream bout = null;
        ObjectOutputStream oout = null;
        try{
            out = new FileOutputStream("Customer.txt");
            bout = new BufferedOutputStream(out);
            oout = new ObjectOutputStream(bout);
            oout.writeObject(customers);
        }catch(Exception e){
            e.printStackTrace();
        }finally {
            try {
                oout.close();
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }
    private void readCustomer(){
        InputStream in = null;
        BufferedInputStream bin = null;
        ObjectInputStream oin = null;

        try{
            in = new FileInputStream("Customer.txt");
            bin = new BufferedInputStream(in);
            oin = new ObjectInputStream(bin);

            customers = (ArrayList<Customer>)oin.readObject();
            System.out.println(customers.size());
        }
        catch (Exception e){
            e.printStackTrace();
        }finally {
            try {
                oin.close();
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }

    public int checkErro2(){
        try {
            if (customer_num2.equals("") || name.equals("") || phone_number.equals("") || customer_date.equals("")) {
                JOptionPane.showMessageDialog(null, "모든 정보를 입력 해 주세요");
                throw  new Exception();
            }
            if(customer_date.matches("[^0-9/]]")){
                JOptionPane.showMessageDialog(null,"숫자 '/'이외의 문자는 사용 할 수 없습니다.");
                throw  new Exception();
            }
            if(phone_number.matches("[^0-9/]")){
                JOptionPane.showMessageDialog(null,"숫자 '-'이외의 문자는 사용 할 수 없습니다.");
                throw  new Exception();
            }
            if(name.length() > 10 ) //name is maximun 10 character
            {
               // System.out.println("Error : name is too long...");
                JOptionPane.showMessageDialog(null, "이름은 10글자를 넘을 수 없습니다.");
                throw new Exception();
            }
            if(!name.matches("[0-9|a-z|A-Z|ㄱ-ㅎ|ㅏ-ㅣ|가-힝]*") || !name.matches("[0-9|a-z|A-Z|ㄱ-ㅎ|ㅏ-ㅣ|가-힝]*")) // no special character
            {
               // System.out.println("Error : there is special character in name or customer number...");
                JOptionPane.showMessageDialog(null, "이름과 고객번호에는 특수문자를 사용하실 수 없습니다.");
                throw new Exception();
            }
            if(customer_num2.length() != 4) {
               // System.out.println("Error : There is wrong length...");
                JOptionPane.showMessageDialog(null, "고객번호는 4자리 입니다.");
                throw new Exception();
            }
            if(!phone_number.matches("^\\d{3}-\\d{4}-\\d{4}$"))
            {
                //System.out.println("Error : wrong phone number format...");
                JOptionPane.showMessageDialog(null, "전화번호 형식은 xxx-xxxx-xxxx입니다.");
                throw new Exception();
            }
            if(!customer_date.matches("^\\d{4}/\\d{2}/\\d{2}$"))
            {
                //System.out.println("Error : wrong date format...");
                JOptionPane.showMessageDialog(null, "날짜 형식은 xxxx/xx/xx입니다.");
                throw new Exception();
            }
            return 1;
        }catch (Exception e){
            return -1;
        }


    }

}
