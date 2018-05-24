import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

class JPanel01 extends JPanel implements  ActionListener{
    private JButton  jButton1;
    private JButton  jButton2;
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    //private JScrollPane jScrollPane1;
    private JTextField jTextField1;
    private JTextField jTextField2;
    private JComboBox jCombo;
    private int  button_num;
    private String[] menu = {"김밥","떡볶이","순대","오뎅","튀김"};
    private bunsik  b;

    public JPanel01(bunsik b){
        this.b = b;;
        setLayout(null);
        jButton1 = new JButton("주문");
        jButton2 = new JButton("주문취소");
        jButton1.setSize(250,65);
        jButton2.setSize(250,65);
        jButton1.setLocation(100,450);
        jButton2.setLocation(550,450);

        jLabel1 = new JLabel("날    짜");
        jLabel2 = new JLabel("고객번호");
        jLabel3 = new JLabel("메    뉴");
        jLabel1.setBounds(200,100,100,100);
        jLabel2.setBounds(200,200,100,100);
        jLabel3.setBounds(200,300,100,100);

        jCombo = new JComboBox(menu);
        jCombo.setBounds(400,320,250,40);

        jTextField1 = new JTextField(13);
        jTextField2 = new JTextField(10);
        jTextField1.setBounds(400,120,250,50);
        jTextField2.setBounds(400,220,250,50);

        jTextField1.setEditable(true);
        jTextField2.setEditable(true);

        add(jButton1);
        add(jButton2);
        add(jLabel1);
        add(jLabel2);
        add(jLabel3);
        add(jTextField1);
        add(jTextField2);
        add(jCombo);

        jButton1.addActionListener(this);
        jButton2.addActionListener(this);
        jCombo.addActionListener(this);
    }
    public String getcustomerNum(){
        String c_num = jTextField2.getText().trim();
        return c_num;
    }
    public String get_order_date(){
        String date = jTextField1.getText().trim();
        return date;
    }
    public String get_menu(){
        String menu = jCombo.getSelectedItem().toString();
        return menu;
    }
    public void setcustomerNum(String num){
        jTextField1.setText(num);
    }
    public void set_order_date(String date){
        jTextField2.setText(date);
    }
    public void setjCombo(){
        jCombo.setSelectedIndex(0);
    }
    public void setjCombo(String m){
        if(m.equals("김밥"))
            jCombo.setSelectedIndex(0);
        if(m.equals("떡볶이"))
            jCombo.setSelectedIndex(1);
        if(m.equals("순대"))
            jCombo.setSelectedIndex(2);
        if(m.equals("오뎅"))
            jCombo.setSelectedIndex(3);
        if(m.equals("튀김"))
            jCombo.setSelectedIndex(4);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource().equals(jButton1)){
            Runnable r = new myThread(b,1);
            Thread t = new Thread(r);
            t.start();
        }

        if(e.getSource().equals(jButton2)){
            Runnable r = new myThread(b,2);
            Thread t = new Thread(r);
            t.start();
        }
    }
}

class JPanel02 extends JPanel implements ActionListener{
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;

    private JButton jButton1;
    private JButton jButton2;
    private JButton jButton3;
    private JScrollPane jScrollPane1;
    private JTextField jTextField1;
    private JTextField jTextField2;
    private JTextField jTextField3;
    private JTextField jTextField4;

    private int button_num;
    private bunsik b;


    public JPanel02(bunsik b){
        this.b = b;
        setLayout(null);

        jButton1 = new JButton("고객등록");
        jButton2 = new JButton("고객검색");
        jButton3 = new JButton("고객삭제");

        jButton1.setSize(150,60);
        jButton2.setSize(150,60);
        jButton3.setSize(150,60);
        jButton1.setLocation(50,500);
        jButton2.setLocation(350,500);
        jButton3.setLocation(650,500);

        jLabel1 = new JLabel("고객번호");
        jLabel2 = new JLabel("고 객 명");
        jLabel3 = new JLabel("전화번호");
        jLabel4 = new JLabel("가 입 일");
        jLabel1.setBounds(200,50,100,100);
        jLabel2.setBounds(200,150,100,100);
        jLabel3.setBounds(200,250,100,100);
        jLabel4.setBounds(200,350,100,100);

        jTextField1 = new JTextField(4);
        jTextField2 = new JTextField(10);
        jTextField3 = new JTextField(13);
        jTextField4 = new JTextField(10);

        jTextField1.setBounds(400,70,250,50);
        jTextField2.setBounds(400,170,250,50);
        jTextField3.setBounds(400,270,250,50);
        jTextField4.setBounds(400,370,250,50);

        add(jButton1);
        add(jButton2);
        add(jButton3);
        add(jLabel1);
        add(jLabel2);
        add(jLabel3);
        add(jLabel4);
        add(jTextField1);
        add(jTextField2);
        add(jTextField3);
        add(jTextField4);

        jButton1.addActionListener(this);
        jButton2.addActionListener(this);
        jButton3.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource().equals(jButton1)){
            Runnable r = new myThread(b,3);
            Thread t = new Thread(r);
            t.start();
            //JOptionPane.showMessageDialog(this,"주문완료");
        }

        if(e.getSource().equals(jButton2)){
            Runnable r = new myThread(b,4);
            Thread t = new Thread(r);
            t.start();
            //JOptionPane.showMessageDialog(this,"주문취소");
        }
        if(e.getSource().equals(jButton3)){
            Runnable r = new myThread(b,5);
            Thread t = new Thread(r);
            t.start();
        }
    }

    public String getcusternum(){
        String c_num = jTextField1.getText().trim();
        return c_num;
    }
    public String getcustername(){
        String name = jTextField2.getText().trim();
        return name;
    }
    public String getcusterphone(){
        String phone = jTextField3.getText().trim();
        return phone;
    }
    public String getcusterdate(){
        String date = jTextField4.getText().trim();
        return date;
    }
    public void setcustomernum(String num){
        jTextField1.setText(num);
    }
    public void setcustomername(String name){
        jTextField2.setText(name);
    }
    public void setcustomerphone(String phone){
        jTextField3.setText(phone);
    }
    public void setcustomerdate(String date){
        jTextField4.setText(date);
    }

}

public class bunsik extends  JFrame {
    public JPanel01 jPanel01 = null;
    public JPanel02 jPanel02 = null;
    public static void main(String args[]){
        bunsik b = new bunsik();
        b.setTitle("분식점");
        b.jPanel01 = new JPanel01(b);
        b.jPanel02 = new JPanel02(b);

        JTabbedPane jtab = new JTabbedPane();

        jtab.addTab("주문관리",b.jPanel01);
        jtab.addTab("고객관리",b.jPanel02);

        b.add(jtab);

        b.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        b.setSize(900,700);
        b.setLocation(500,500);
        b.setVisible(true);
    }
}
