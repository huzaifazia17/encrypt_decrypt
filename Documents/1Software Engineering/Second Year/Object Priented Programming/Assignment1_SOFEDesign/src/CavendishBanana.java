public class CavendishBanana implements GroceryProduct {
    float price;
    @Override
    public void setPrice(float price) {
        System.out.println("Cavendish Banana is now priced at " + price);
        this.price=price;
    }
}
