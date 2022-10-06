public class FujiApple implements GroceryProduct {
    float price;
    @Override
    public void setPrice(float price) {
        System.out.println("Fuji Apple is now priced at " + price);
        this.price=price;
    }
}
