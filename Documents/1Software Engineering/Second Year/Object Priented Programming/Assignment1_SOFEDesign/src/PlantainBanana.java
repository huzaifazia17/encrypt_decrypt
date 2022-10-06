public class PlantainBanana implements GroceryProduct {
    float price;
    @Override
    public void setPrice(float price) {
        System.out.println("Plantain Banana is now priced at " + price);
        this.price=price;
    }
}
