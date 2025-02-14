class ProductOfNumbers {
private:
    vector<int> pref;
    int size=0;

public:
    ProductOfNumbers() {
        pref.push_back(1);
        size=0;
    }

    void add(int num) {
        if(num==0){
            pref={1};
            size=0;
        } 
        else {
            pref.push_back(pref[size]*num);
            size++;
        }
    }

    int getProduct(int k) {
        if(k>size) return 0;
        return pref[size]/pref[size-k];
    }
};