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
    private JScrollPane jScrollPane1;
    private JTextArea jTextArea1;
    private JTextArea jTextArea2;
    private JComboBox jCombo;
    private int  button_num;
    private String[] menu = {"김밥","떡볶이","순대","오뎅","튀김"};
    private bunsik  b;

    public JPanel01(bunsik b){
        this.b = b;
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

        jTextArea1 = new JTextArea();
        jTextArea1.setEditable(true);
        JScrollPane scrollPane1 = new JScrollPane(jTextArea1);
        scrollPane1.setBounds(400,120,250,50);

        jTextArea2 = new JTextArea();
        jTextArea2.setEditable(true);
        JScrollPane scrollPane2 = new JScrollPane(jTextArea2);
        scrollPane2.setBounds(400,220,250,50);

        jCombo = new JComboBox(menu);
        jCombo.setBounds(400,320,250,40);

        add(jButton1);
        add(jButton2);
        add(jLabel1);
        add(jLabel2);
        add(jLabel3);
        add(scrollPane1);
        add(scrollPane2);
        add(jCombo);

        jButton1.addActionListener(this);
        jButton2.addActionListener(this);
        jCombo.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource().equals(jButton1)){
            Runnable r = new myThread(b,1);
            Thread t = new Thread(r);
            t.start();
            JOptionPane.showMessageDialog(this,"주문완료");
        }

        if(e.getSource().equals(jButton2)){
            JOptionPane.showMessageDialog(this,"주문취소");

        }
    }
}

class JPanel02 extends JPanel{
    private JLabel jLabel1;
    private JLabel jLabel2;
    private JLabel jLabel3;
    private JLabel jLabel4;

    private JButton jButton1;
    private JButton jButton2;
    private JButton jButton3;
    private JScrollPane jScrollPane1;
    private JTextArea jTextArea1;
    private JTextArea jTextArea2;
    private JTextArea jTextArea3;
    private JTextArea jTextArea4;
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

        jTextArea1 = new JTextArea();
        jTextArea1.setEditable(true);
        JScrollPane scrollPane1 = new JScrollPane(jTextArea1);
        scrollPane1.setBounds(400,70,250,50);

        jTextArea2 = new JTextArea();
        jTextArea2.setEditable(true);
        JScrollPane scrollPane2 = new JScrollPane(jTextArea2);
        scrollPane2.setBounds(400,170,250,50);

        jTextArea3 = new JTextArea();
        jTextArea3.setEditable(true);
        JScrollPane scrollPane3 = new JScrollPane(jTextArea3);
        scrollPane3.setBounds(400,270,250,50);

        jTextArea4 = new JTextArea();
        jTextArea4.setEditable(true);
        JScrollPane scrollPane4 = new JScrollPane(jTextArea4);
        scrollPane4.setBounds(400,370,250,50);

        add(jButton1);
        add(jButton2);
        add(jButton3);
        add(jLabel1);
        add(jLabel2);
        add(jLabel3);
        add(jLabel4);
        add(scrollPane1);
        add(scrollPane2);
        add(scrollPane3);
        add(scrollPane4);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource().equals(jButton1)){
            Runnable r = new myThread(b,0);
            Thread t = new Thread(r);
            t.start();
            JOptionPane.showMessageDialog(this,"주문완료");
        }

        if(e.getSource().equals(jButton2)){
            Runnable r = new myThread(b,0);
            Thread t = new Thread(r);
            t.start();
            JOptionPane.showMessageDialog(this,"주문취소");
        }
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
