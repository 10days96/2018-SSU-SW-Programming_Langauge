public class order {
    private String date;
    private String num;
    private String menu;
    public order(String date, String num, String menu){
        this.date = date;
        this.num = num;
        this.menu = menu;
    }

    public String getDate(){
        return date;
    }
    public String getNum(){
        return num;
    }
    public String getMenu(){
        return menu;
    }
}
