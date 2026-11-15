#include <iostream>
#include <string>

// ============================================================
// ЗАДАЧА 1 (шаблон с одним типом): минимум из двух
// ============================================================
template<typename T>
T minOf(T a, T b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// ============================================================
// ЗАДАЧА 2 (шаблон с одним типом): сумма элементов массива
// ============================================================
template<typename T, size_t N>
T arraySum(const T (&data)[N]) {
    T sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += data[i];
    }
    return sum;
}

// ============================================================
// ЗАДАЧА 3 (шаблон с двумя типами): вывести пару
// ============================================================
template<typename T, typename K>
void printPair(T first, K second) {
    std::cout << first << " - " << second << std::endl;
}

// ============================================================
// ЗАДАЧА 4 (шаблон с тремя и более типами): тройка
// ============================================================
template<typename T, typename K, typename V>
void makeTriple(T first, K second, V third) {
    std::cout << "[" << first << ", " << second << ", " << third << "]" << std::endl;
}

// ============================================================
// ЗАДАЧА 5 (шаблон + указатель): найти максимум по указателям
// ============================================================
template<typename T>
const T* maxPtr(const T* a, const T* b) {
    // Если первый указатель пустой, возвращаем второй
    if (a == nullptr) {
        return b;
    }
    // Если второй указатель пустой, возвращаем первый
    if (b == nullptr) {
        return a;
    }
    // Если оба указателя валидны, сравниваем значения
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}


int main() {
    // Задача 1
    std::cout << "=== Задача 1: minOf ===" << std::endl;
    std::cout << "min(4, 5) = " << minOf(4, 5) << std::endl; // 4
    std::cout << "min(3.4, 2.3) = " << minOf(3.4, 2.3) << std::endl; // 2.3
    std::cout << "min(\"apple\", \"banana\") = "
              << minOf(std::string("apple"), std::string("banana")) << std::endl; // apple

    // Задача 2
    std::cout << "\n=== Задача 2: arraySum ===" << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.5, 3.0};
    std::cout << "int sum: " << arraySum(intArr) << std::endl; // 15
    std::cout << "double sum: " << arraySum(doubleArr) << std::endl; // 7

    // Задача 3
    std::cout << "\n=== Задача 3: printPair ===" << std::endl;
    printPair(42, std::string("ответ")); // 42 - ответ
    printPair(3.14, 100); // 3.14 - 100

    // Задача 4
    std::cout << "\n=== Задача 4: makeTriple ===" << std::endl;
    makeTriple(1, 2.5, std::string("три")); // [1, 2.5, три]
    makeTriple(std::string("x"), 42, 3.14); // [x, 42, 3.14]

    // Задача 5
    std::cout << "\n=== Задача 5: maxPtr ===" << std::endl;
    int a = 3, b = 7;
    std::cout << "*maxPtr(&a, &b) = " << *maxPtr(&a, &b) << std::endl; // 7
    
   
    std::cout << "*maxPtr(&a, (const int*)nullptr) = " << *maxPtr(&a, (const int*)nullptr) << std::endl; // 3
    
    std::cout << "maxPtr(nullptr, nullptr) = ";
    if (maxPtr<int>(nullptr, nullptr) == nullptr) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "не nullptr" << std::endl;
    }

    return 0;
}
