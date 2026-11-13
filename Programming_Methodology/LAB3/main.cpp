#include "pq.h"


struct order {
    order(std::string name, const int &price) : name(std::move(name)), price(price) {
    }


    int getPrice() const {
        return price;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;

    int price;
};

struct comp_order {
    bool operator()(const order &lhs, const order &rhs) const {
        return lhs.getPrice() > rhs.getPrice();
    }
};

template<typename T>
void exchange(pq<T, comp_order> &buy, pq<T, comp_order> &sell) {
    while (!buy.empty() && !sell.empty()) {
        if (buy.top().getPrice() < sell.top().getPrice()) {
            buy.pop();
        } else {
            std::cout << buy.top().getName() << " (buy price: " << buy.top().getPrice() << ")" << " bought from: (" << sell.top().getName() <<
                    ") " << "Sell Price: " << sell.top().getPrice()<<")" <<std::endl;
            sell.pop();
            buy.pop();
        }
    }
}

int main() {
    /*
    pq<int> my_int_pq;
    my_int_pq.push(5);
    my_int_pq.push(9);
    my_int_pq.push(7);
    std::cout<<my_int_pq.top()<<std::endl;
    my_int_pq.pop();
    std::cout<<my_int_pq.top()<<std::endl;
    */
    pq<order, comp_order> buy;
    pq<order, comp_order> sell;
    sell.push(order("john", 20));
    sell.push(order("wallenburg", 20));
    sell.push(order("pender", 22));
    sell.push(order("alex", 17));
    sell.push(order("jva", 18));

    buy.push(order("jva", 17));
    buy.push(order("pender", 18));
    buy.push(order("jva", 20));
    buy.push(order("jva", 21));

    exchange(buy, sell);

    return 0;
}
