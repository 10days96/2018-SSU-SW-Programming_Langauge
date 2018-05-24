import java.io.Serializable;
public class Customer implements Serializable{
  private String name;
  private String customer_num;
  private String phone_number;
  private String date;
  private int count;

  public Customer(String customer_num,String name, String phone_number, String date){
      this.name = name;
      this.customer_num = customer_num;
      this.phone_number = phone_number;
      this.date = date;
      count = 0;
  }
  public String  getCustomer_num(){
      return customer_num;
  }
  public String getname(){
      return name;
  }
  public String getPhone_number(){
      return phone_number;
  }
  public String getDate(){
      return date;
  }

  public int getCount(){
      return count;
  }
  public void setCount(){
      count++;
  }
}
