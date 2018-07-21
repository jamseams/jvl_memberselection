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
    
    cart.addToCart(tomato);
    cart.addToCart(apple);
    cart.addToCart(apple);
    cart.addToCart(tomato);
    return 0;
}
