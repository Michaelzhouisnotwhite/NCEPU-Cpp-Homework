template <typename T>
class Compare {
    T a, b;
public:
    Compare(T a, T b):a(a), b(b) {}
    T Min() {
        return a < b ? a : b;
    }
    T Max()
    {
        return a < b ? b : a;
    }
};

//template<typename T>
//T Compare<T>::Max() {
//    return nullptr;
//}


