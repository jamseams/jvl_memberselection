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
    
    cart.addToCart(tomato);
    cart.addToCart(apple);
    cart.addToCart(apple);
    cart.addToCart(tomato);
    return 0;
}
