public class GroceryStore {
    public static void main(String[] args) {
        // Get Abstract Factory for Banana's
        AbstractFactory BananaFactory = GroceryProductFactory.getFactory(false);
        GroceryProduct product1 = BananaFactory.createProduct("CAVENDISH_BANANA");
        product1.setPrice(21);
        GroceryProduct product2 = BananaFactory.createProduct("PLANTAIN_BANANA");
        product2.setPrice(50);

        // Get Abstract Factory for Apples
        AbstractFactory AppleFactory = GroceryProductFactory.getFactory(true);
        GroceryProduct product3 = AppleFactory.createProduct("GALA_APPLE");
        product3.setPrice(20);
        GroceryProduct product4 = AppleFactory.createProduct("FUJI_APPLE");
        product4.setPrice(49);

    }
}
