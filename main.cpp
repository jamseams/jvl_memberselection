#include <iostream>
#include <vector>


class Apple{};
class Pear{};
class Tomato{};
class Potato{};

class Cart
{
    public:
    
    Cart() : appleBasket(10), pearBasket(10), tomatoBasket(10), potatoBasket(10) { }
    

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
    
    cart.addToCart(tomato);
    cart.addToCart(apple);
    cart.addToCart(apple);
    cart.addToCart(tomato);
    return 0;
}
