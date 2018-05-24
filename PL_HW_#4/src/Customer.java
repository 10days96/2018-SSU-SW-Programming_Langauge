public class Customer {
  private String name;
  private int customer_num;
  private String phone_number;
  private String date;
  private int count;

  public Customer(String name, int customer_num, String phone_number, String date){
      this.name = name;
      this.customer_num = customer_num;
      this.phone_number = phone_number;
      this.date = date;
      count = 0;
  }
  public int getCount(){
      return count;
  }
  public void setCount(){
      count++;
  }
}
