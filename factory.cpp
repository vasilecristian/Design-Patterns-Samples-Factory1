#include <iostream>


/* Create a Coffee machine that can generates the Tea and Coffee hot drinks.
*
*   Coffee machine is a factory that can create hot drinks. The hot drink is an abstract thing.
*       - Tea is a hot drink
*       - Coffee is a hot drink
*
*   
*
*/

class IHotDrink
{
public:
    virtual ~IHotDrink() = default;
    virtual std::string ToString() = 0;
};

class Tea : public IHotDrink
{
    std::string ToString()
    {
        return "Tea is prepared.... ";
    }
};

class Coffee : public IHotDrink
{
    std::string ToString()
    {
        return "Coffee is prepared.... ";
    }
};

class Cappucino : public IHotDrink
{
    std::string ToString()
    {
        return "Cappucino is prepared.... ";
    }
};


enum class HotDrinkType: int
{
    Tea,
    Coffee,
    Cappucino
};

IHotDrink* CoffeeMachineCreateDrink(HotDrinkType hotDrinkType)
{
    switch(hotDrinkType)
    {
        case HotDrinkType::Coffee:
            return new Coffee();

        case HotDrinkType::Tea:
            return new Tea();

        default:
            return nullptr;
    }
}

IHotDrink* ExtendedCoffeeMachineCreateDrink(HotDrinkType hotDrinkType)
{
    switch(hotDrinkType)
    {
        case HotDrinkType::Cappucino:
            return new Cappucino();
        
        default:
            return CoffeeMachineCreateDrink(hotDrinkType);
    }

    return nullptr;
}

int main()
{
    std::cout << "Sample for Factory Method defing pattern!" << std::endl;

    IHotDrink* hotDrink1 = ExtendedCoffeeMachineCreateDrink(HotDrinkType::Tea);
    std::cout << "Drink 1: " <<  hotDrink1->ToString() << std::endl;
    
    IHotDrink* hotDrink2 = ExtendedCoffeeMachineCreateDrink(HotDrinkType::Coffee);
    std::cout << "Drink 2: " <<  hotDrink2->ToString() << std::endl;

    IHotDrink* hotDrink3 = ExtendedCoffeeMachineCreateDrink(HotDrinkType::Cappucino);
    std::cout << "Drink 3: " <<  hotDrink3->ToString() << std::endl;

    return 0;
}