import javax.swing.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.io.*;
import java.util.Date;

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
    private  String customer_date1;
    private String customer_date;
    private int funnum;
    private String sale_date1;
    private String sale_date2;
    myThread(bunsik b,int funnum){
        this.b = b;
        this.funnum = funnum;
        customer_num = b.jPanel01.getcustomerNum();
        customer_date1 = b.jPanel01.get_order_date();
        menu = b.jPanel01.get_menu();
        customer_num2 = b.jPanel02.getcusternum();
        name = b.jPanel02.getcustername();
        phone_number = b.jPanel02.getcusterphone();
        customer_date = b.jPanel02.getcusterdate();
        sale_date1 = b.jPanel03.getDate1();
        sale_date2 = b.jPanel03.getDate2();
    }
    @Override
    public void run(){
        synchronized (this){
            readCustomer();
            readOrder();
            if(funnum == 1){
                order();
            }
            if(funnum == 2){
                deleteorder();
            }
            if(funnum == 3){
                regist_customer();
            }
            if(funnum == 4){
                findCustomer(customer_num2);
            }
            if(funnum == 5){
                deletecustomer(customer_num2);
            }
            if(funnum == 6){
                Count();
            }
            saveeorder();
            saveCustomer();
        }

    }
    private void order(){
        if(checkErro1() == 1){
            int index = findCustomer(customer_num);
            if(index != -1){
                order o = new order(customer_date1,customer_num,menu);
                orders.add(o);
                b.jPanel01.set_order_date("");
                b.jPanel01.setcustomerNum("");
                b.jPanel01.setjCombo();
                JOptionPane.showMessageDialog(null,"주문 완료!");
                customers.get(index).setCount();
                if(customers.get(index).getCount() == 3){
                    JOptionPane.showMessageDialog(null,customer_num +"고객님 \n무료쿠폰이 배송되었습니다.");
                    customers.get(index).resetCount();
                }
            }
            else{
                JOptionPane.showMessageDialog(null,"먼저 고객등록을 해주시기 바랍니다.");
            }
        }
    }
    private void deleteorder(){
        if(checkErro1() == 1){
            int index = findorder();
            if(index != -1){
                orders.remove(index);
                JOptionPane.showMessageDialog(null,"주문이 취소되었습니다.");
            }
            else{
                JOptionPane.showMessageDialog(null,"해당 주문을 찾을 수 없습니다.");
            }
        }
        else{
            JOptionPane.showMessageDialog(null,"정보를 입력해 주십시오.");
        }
    }
    private  int findorder(){
        for(int i = 0; i < orders.size(); i++){
            if(orders.get(i).getNum().equals(customer_num) && orders.get(i).getDate().equals(customer_date1)
                    && orders.get(i).getMenu().equals(menu)){
                return i;
            }
        }
        return -1;

    }
    private  void saveeorder(){
        try {
            File file = new File("order.txt");
            BufferedWriter bw = new BufferedWriter(new FileWriter(file));

            if (file.isFile() && file.canWrite()) {
                for(int i = 0; i < orders.size(); i++){
                    String date = orders.get(i).getDate();
                    String num = orders.get(i).getNum();
                    String menu = orders.get(i).getMenu();

                    bw.write(date + " " + num + " "+ menu);
                    bw.newLine();
                }
            }
            bw.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    private  void readOrder(){
        try{
            File file = new File("order.txt");
            FileReader fr = new FileReader(file);

            BufferedReader br = new BufferedReader(fr);
            String line = "";
            while((line = br.readLine()) != null){
                String [] str = line.split(" ");
                order o = new order(str[0], str[1], str[2]);
                orders.add(o);
            }
            br.close();
        }catch (FileNotFoundException e){
            e.printStackTrace();
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    private void Count() {
        String[] menu = {"김밥", "떡볶이", "순대", "오뎅", " 튀김", "쿠폰"};
        String[] str = new String[5];
        int[] count_num = new int[5];
        int[] total_menu = new int[5];
        int[] price = {1500, 3000, 2000, 500, 500};
        int total = 0;
        Date d1 = null;
        Date d2 = null;
        if(checkErro3() != -1) {
            SimpleDateFormat format = new SimpleDateFormat("yyyy/MM/dd");
            try {
                d1 = format.parse(sale_date1);
                d2 = format.parse(sale_date2);
            } catch (ParseException e) {
                e.printStackTrace();
            }
            for (int i = 0; i < orders.size(); i++) {
                Date date = null;
                try {
                    date = format.parse(orders.get(i).getDate());
                } catch (ParseException e) {
                    e.printStackTrace();
                }
                int compare1 = date.compareTo(d1);
                int compare2 = date.compareTo(d2);

                if (compare1 >= 0 && compare2 <= 0) {
                    if (orders.get(i).getMenu().equals(menu[0])) {
                        count_num[0]++;
                    }
                    if (orders.get(i).getMenu().equals(menu[1])) {
                        count_num[1]++;
                    }
                    if (orders.get(i).getMenu().equals(menu[2])) {
                        count_num[2]++;
                    }
                    if (orders.get(i).getMenu().equals(menu[3])) {
                        count_num[3]++;
                    }
                    if (orders.get(i).getMenu().equals(menu[4])) {
                        count_num[4]++;
                    }
                    if (orders.get(i).getMenu().equals(menu[5])) {
                        count_num[5]++;
                    }

                }
            }

            for (int i = 0; i < count_num.length; i++) {
                total_menu[i] = count_num[i] * price[i];
                total += total_menu[i];
                str[i] = menu[i] + "\t\t" + count_num[i] + "\t\t" + total_menu[i];
            }
            b.jPanel03.SetMenu("메뉴\t\t갯수\t\t매출금액\n");
            b.jPanel03.SetMenu("==============================\n");
            for (int i = 0; i < count_num.length; i++) {
                b.jPanel03.SetMenu(str[i] + "\n");
            }
            b.jPanel03.SetMenu("============================\n");
            b.jPanel03.SetMenu("매출합계\t\t\t" + total + "\n");

        }
    }

    private void regist_customer(){
        if(checkErro2() == 1){
            if(findCustomer(customer_num2) == -1){
                Customer c = new Customer(customer_num2,name,phone_number,customer_date);
                c.resetCount();
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
                    }
                JOptionPane.showMessageDialog(null,"등록된 고객이 아닙니다.");
                throw new Exception();
            }catch (Exception e){
                return -1;
            }
       // return -1;
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
    private void saveCustomer() {
        //  OutputStream out = null;
        try {
            File file = new File("custom.txt");
            BufferedWriter bw = new BufferedWriter(new FileWriter(file));

            if (file.isFile() && file.canWrite()) {
                for (int i = 0; i < customers.size(); i++) {
                    String c_num = customers.get(i).getCustomer_num();
                    String name = customers.get(i).getname();
                    String ph = customers.get(i).getPhone_number();
                    String date = customers.get(i).getDate();
                    int count1 = customers.get(i).getCount();
                    String count = Integer.toString(count1);

                    bw.write(c_num + " " + name + " " + ph + " " + date + " " +  count);
                    bw.newLine();
                }
            }
            bw.close();
        } catch(IOException e){
        e.printStackTrace();
        }
    }
    private void readCustomer(){
        try{
        File file = new File("custom.txt");
        FileReader fr = new FileReader(file);

        BufferedReader br = new BufferedReader(fr);
        String line = "";
        while((line = br.readLine()) != null){
            String [] str = line.split(" ");
            Customer c = new Customer(str[0], str[1],str[2],str[3]);
            c.setCount(Integer.parseInt(str[4]));
            customers.add(c);
        }
        br.close();
    }catch (FileNotFoundException e){
        e.printStackTrace();
    }catch (IOException e){
        e.printStackTrace();
    }
    }
    public int checkErro1(){
        try {
            if(!customer_num.matches("[0-9|a-z|A-Z|ㄱ-ㅎ|ㅏ-ㅣ|가-힝]*")) // no special character
            {
                //System.out.println("Error : there is special character in name or customer number...");
                JOptionPane.showMessageDialog(null, "고객번호에는 특수문자를 사용하실 수 없습니다.");
                throw new Exception();
            }
            if(customer_date.matches("[^0-9/]")) // date is consists of digits and /
            {
                //System.out.println("Error : There is wrong character in date string...");
                JOptionPane.showMessageDialog(null, "날짜에서는 숫자와 /만을 사용하실 수 있습니다.");
                throw new Exception();
            }
            if(customer_num.length() != 4) {
                //System.out.println("Error : There is wrong length...");
                JOptionPane.showMessageDialog(null, "고객번호는 4자리 입니다.");
                throw new Exception();
            }
            if(!customer_date1.matches("^\\d{4}/\\d{2}/\\d{2}$"))
            {
                //System.out.println("Error : wrong date format...");
                JOptionPane.showMessageDialog(null, "날짜 형식은 xxxx/xx/xx입니다.");
                throw new Exception();
            }
           // System.out.println("Error Checking Complete...");
            return 1;
        }catch(Exception e)
        {
            //System.out.println("Exception occures");
            return -1;
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

    public int checkErro3(){
        if( (!sale_date1.matches("^\\d{4}/\\d{2}/\\d{2}$")) || (!sale_date2.matches("^\\d{4}/\\d{2}/\\d{2}$") ) ){
            JOptionPane.showMessageDialog(null,"날짜형식은 yyyy/MM/dd 입니다");
            return -1;
        }

        return 1;
    }

}
