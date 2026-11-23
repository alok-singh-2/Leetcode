
class ProductOfNumbers {
public:
    vector<long long> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            long long product = prefix.back() * num;
            prefix.push_back(product);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        if (k >= n) {
            return 0;
        }

        return prefix[n - 1] / prefix[n - 1 - k];
    }
};
