#include <iostream>
#include <vector>


class Apple{};
class Pear{};
class Tomato{};
class Potato{};

class Cart
{
    public:
        
	void printSizes()
	{
		std::cout << "Size of AppleBasket  << " << appleBasket.size() << std::endl;
		std::cout << "Size of PearBasket   << " << pearBasket.size() << std::endl;
		std::cout << "Size of TomatoBasket << " << tomatoBasket.size() << std::endl;
		std::cout << "Size of PotatoBasket << " << potatoBasket.size() << std::endl;
	}

    void addToCart(Apple  apple)  { appleBasket.push_back(apple);    }
    void addToCart(Pear   pear)   { pearBasket.push_back(pear);      }
    void addToCart(Tomato tomato) { tomatoBasket.push_back(tomato); }
    void addToCart(Potato potato) { potatoBasket.push_back(potato); }
    
    private:
    std::vector<Apple>          appleBasket;
    std::vector<Pear>           pearBasket;
    std::vector<Tomato>         tomatoBasket;
    std::vector<Potato>         potatoBasket;
};


int main()
{

    Cart   cart;
    Apple  apple;
    Tomato tomato;
	Potato potato;
    
    cart.addToCart(tomato);
    cart.addToCart(apple);
    cart.addToCart(apple);
    cart.addToCart(tomato);
	cart.addToCart(potato);

	cart.printSizes();

    return 0;
}
