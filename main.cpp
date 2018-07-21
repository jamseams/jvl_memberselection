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

	template<typename T>
	void addToCart(T item){
		getBasket<T>().push_back(item);
	}
    
    private:
    std::vector<Apple>          appleBasket;
    std::vector<Pear>           pearBasket;
    std::vector<Tomato>         tomatoBasket;
    std::vector<Potato>         potatoBasket;

	template<typename T>
	inline auto& getBasket()
	{
		if constexpr(std::is_same_v<T, Apple>)       {return appleBasket; }
		else if constexpr(std::is_same_v<T, Pear>)   {return pearBasket;  }
		else if constexpr(std::is_same_v<T, Tomato>) {return tomatoBasket;}
		else if constexpr(std::is_same_v<T, Potato>) {return potatoBasket;}
	}

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
