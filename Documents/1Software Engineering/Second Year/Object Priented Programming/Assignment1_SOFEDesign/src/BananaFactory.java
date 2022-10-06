public class BananaFactory extends AbstractFactory{
    @Override
    public GroceryProduct createProduct(String productName) {
        if(productName.equalsIgnoreCase("PLANTAIN_BANANA")){
            return new PlantainBanana();
        }else if(productName.equalsIgnoreCase("CAVENDISH_BANANA")){
            return new CavendishBanana();
        }
        return null;
    }
}
