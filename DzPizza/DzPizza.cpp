#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Структура для хранения информации о пицце, закуске и напитке
struct Item {
    string name;
    double price;
};

// Функция для отображения меню
void displayMenu(const vector<Item>& items, const string& category) {
    cout << "Выберите " << category << ":\n";
    for (size_t i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i].name << " - " << fixed << setprecision(2) << items[i].price << " рублей\n";
    }
    cout << "0. Отмена\n";
}

// Функция для обработки выбора пользователя
void processOrder(const vector<Item>& pizzas, const vector<Item>& snacks, const vector<Item>& drinks) {
    vector<Item> selectedPizzas;
    vector<Item> selectedSnacks;
    vector<Item> selectedDrinks;

    int choice;
    double total = 0.0;

    // Выбор пицц
    while (true) {
        displayMenu(pizzas, "пиццу");
        cout << "Введите номер пиццы (или 0 для завершения выбора): ";
        cin >> choice;

        if (choice == 0) break;
        if (choice > 0 && choice <= pizzas.size()) {
            selectedPizzas.push_back(pizzas[choice - 1]);
            total += pizzas[choice - 1].price;
        }
        else {
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    // Выбор закусок
    while (true) {
        displayMenu(snacks, "закуску");
        cout << "Введите номер закуски (или 0 для завершения выбора): ";
        cin >> choice;

        if (choice == 0) break;
        if (choice > 0 && choice <= snacks.size()) {
            selectedSnacks.push_back(snacks[choice - 1]);
            total += snacks[choice - 1].price;
        }
        else {
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    // Выбор напитков
    while (true) {
        displayMenu(drinks, "напиток");
        cout << "Введите номер напитка (или 0 для завершения выбора): ";
        cin >> choice;

        if (choice == 0) break;
        if (choice > 0 && choice <= drinks.size()) {
            selectedDrinks.push_back(drinks[choice - 1]);
            total += drinks[choice - 1].price;
        }
        else {
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    // Применение скидок
    int pizzaCount = selectedPizzas.size();
    if (pizzaCount >= 5) {
        total -= selectedPizzas[(pizzaCount - 1) / 5].price; // Каждая 5-я пицца в подарок
    }

    int expensiveDrinkCount = 0;
    for (const auto& drink : selectedDrinks) {
        if (drink.price > 100) { // Выберите цену для дорогих напитков
            expensiveDrinkCount++;
        }
    }
    if (expensiveDrinkCount > 4) {
        total -= selectedDrinks[0].price; // Одна дорогая напиток в подарок
    }

    if (total > 500) { // Выберите сумму для общей скидки
        total *= 0.85; // Скидка 15%
    }

    // Вывод итогового заказа
    cout << "\nВаш заказ:\n";
    cout << "Пиццы:\n";
    for (const auto& pizza : selectedPizzas) {
        cout << "- " << pizza.name << " - " << fixed << setprecision(2) << pizza.price << " рублей\n";
    }
    cout << "Закуски:\n";
    for (const auto& snack : selectedSnacks) {
        cout << "- " << snack.name << " - " << fixed << setprecision(2) << snack.price << " рублей\n";
    }
    cout << "Напитки:\n";
    for (const auto& drink : selectedDrinks) {
        cout << "- " << drink.name << " - " << fixed << setprecision(2) << drink.price << " рублей\n";
    }
    cout << "Итого к оплате: " << fixed << setprecision(2) << total << " рублей\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    // Меню пиццы, закусок и напитков
    vector<Item> pizzas = { {"Маргарита", 300}, {"Пепперони", 350}, {"Гавайская", 400}, {"Четыре сыра", 450}, {"Мясная", 500}, {"Вегетарианская", 350}, {"С морепродуктами", 600} };
    vector<Item> snacks = { {"Картофель фри", 150}, {"Цезарь", 200}, {"Салат", 180}, {"Наггетсы", 220} };
    vector<Item> drinks = { {"Кока-Кола", 100}, {"Сок", 120}, {"Минеральная вода", 80}, {"Энергетик", 150}, {"Пиво", 200} };

    cout << "Добро пожаловать в мини-пиццерию!\n";

    while (true) {
        processOrder(pizzas, snacks, drinks);
        cout << "\nХотите сделать еще один заказ? (1 - Да, 0 - Нет): ";
        int again;
        cin >> again;
        if (again == 0) break;
        system("cls"); // Очистка экрана
    }

    cout << "Спасибо за ваш заказ! До свидания!\n";
    return 0;
}