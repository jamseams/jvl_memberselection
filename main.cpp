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
	inline std::vector<T>& getBasket();

};

template<typename T> std::vector<T>& Cart::getBasket() { return appleBasket; }
template<> std::vector<Pear>& Cart::getBasket() { return pearBasket;}
template<> std::vector<Tomato>& Cart::getBasket(){ return tomatoBasket; }
template<> std::vector<Potato>& Cart::getBasket(){	return potatoBasket; }


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
