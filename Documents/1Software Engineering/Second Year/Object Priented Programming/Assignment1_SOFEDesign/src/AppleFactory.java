public class AppleFactory extends AbstractFactory{
    @Override
    public GroceryProduct createProduct(String productName) {
        if(productName.equalsIgnoreCase("GALA_APPLE")){
            return new GalaApple();
        }else if(productName.equalsIgnoreCase("FUJI_APPLE")){
            return new FujiApple();
        }
        return null;
    }
}
