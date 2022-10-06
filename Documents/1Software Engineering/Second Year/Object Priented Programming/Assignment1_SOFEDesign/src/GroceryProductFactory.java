public class GroceryProductFactory {
    public static AbstractFactory getFactory(boolean Apple) {
        if(Apple) {
            return new AppleFactory();
        } else {
            return new BananaFactory();
        }
    }
}
