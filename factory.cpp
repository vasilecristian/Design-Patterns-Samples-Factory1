#include <iostream>


/* Create a Coffee machine that can generates the Tea and Coffee hot drinks.
*
*   Coffee machine is a factory that can create hot drinks. The hot drink is an abstract thing.
*       - Tea is a hot drink
*       - Coffee is a hot drink
*
*   This Example have an issue with the enum class HotDrinkType. The SOLID principle is 
*   not meet (Open for extension Closed for modifications principle) since when you want 
*   to extent the enum by adding new types of Hot Drinks the enum must be changed.
*   
*   Instead, enum i have used class with static members.
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

class Expresso : public IHotDrink
{
    std::string ToString()
    {
        return "Expresso is prepared.... ";
    }
};

//---------------------------------------
// Define the Coffee Machine Function

//enum class HotDrinkType: int
//{
//    Tea,
//    Coffee,
//    Cappucino,
//    Expresso
//};

typedef int HotDrinkType;

class HotDrinks
{
public:
    static const HotDrinkType Tea = 1;
    static const HotDrinkType Coffee = 2;

    static const HotDrinkType Last = 2;
};

/** Factory Function Design pattern*/
IHotDrink* CoffeeMachineCreateDrink(HotDrinkType hotDrinkType)
{
    switch(hotDrinkType)
    {
        case HotDrinks::Coffee:
            return new Coffee();

        case HotDrinks::Tea:
            return new Tea();

        default:
            return nullptr;
    }
}
//---------------------------------------


//---------------------------------------
// Extended the Coffee Machine....

class ExtendedHotDrinks : public HotDrinks
{
public:
    static const HotDrinkType Cappucino = HotDrinks::Last + 1;
    static const HotDrinkType Expresso = HotDrinks::Last + 2;
};

/** This is used to extend the CoffeeMachineCreateDrink Function design pattern*/
IHotDrink* ExtendedCoffeeMachineCreateDrink(HotDrinkType hotDrinkType)
{
    switch(hotDrinkType)
    {
        case ExtendedHotDrinks::Cappucino:
            return new Cappucino();

        case ExtendedHotDrinks::Expresso:
            return new Expresso();
        
        default:
            return CoffeeMachineCreateDrink(hotDrinkType);
    }

    return nullptr;
}
//---------------------------------------




int main()
{
    std::cout << "Sample for Factory Method Design Pattern!" << std::endl;

    IHotDrink* hotDrink1 = ExtendedCoffeeMachineCreateDrink(ExtendedHotDrinks::Tea);
    std::cout << "Drink 1: " <<  hotDrink1->ToString() << std::endl;
    
    IHotDrink* hotDrink2 = ExtendedCoffeeMachineCreateDrink(ExtendedHotDrinks::Coffee);
    std::cout << "Drink 2: " <<  hotDrink2->ToString() << std::endl;

    IHotDrink* hotDrink3 = ExtendedCoffeeMachineCreateDrink(ExtendedHotDrinks::Cappucino);
    std::cout << "Drink 3: " <<  hotDrink3->ToString() << std::endl;

    IHotDrink* hotDrink4 = ExtendedCoffeeMachineCreateDrink(ExtendedHotDrinks::Expresso);
    std::cout << "Drink 4: " <<  hotDrink4->ToString() << std::endl;

    return 0;
}