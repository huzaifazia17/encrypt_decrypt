public class GalaApple implements GroceryProduct {
    float price;
    @Override
    public void setPrice(float price) {
        System.out.println("Gala Apple is now priced at " + price);
        this.price=price;
    }
}
