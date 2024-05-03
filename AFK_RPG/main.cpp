#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>

void showMyHeroScreen(QStackedWidget* stackedWidget);
void tavern(QStackedWidget* stackedWidget);

void showMainMenu(QStackedWidget* stackedWidget) {
    auto* mainMenuWidget = new QWidget;
    auto* layout = new QVBoxLayout(mainMenuWidget);

    // разобраться
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->setSpacing(10);

    auto* btn = new QPushButton("Мой герой");
    layout->addWidget(btn);
    // Логика для кнопки
    QObject::connect(btn, &QPushButton::clicked, [stackedWidget]() {
        showMyHeroScreen(stackedWidget);
    });

    auto* btn2 = new QPushButton("Поход");
    layout->addWidget(btn2);
    QObject::connect(btn2, &QPushButton::clicked, [stackedWidget]() {
        showMyHeroScreen(stackedWidget);
    });
    auto* btn3 = new QPushButton("Барахолка");
    layout->addWidget(btn3);
    QObject::connect(btn3, &QPushButton::clicked, [stackedWidget]() {
        showMyHeroScreen(stackedWidget);
    });
    auto* btn4 = new QPushButton("Таверна");
    layout->addWidget(btn4);
    QObject::connect(btn4, &QPushButton::clicked, [stackedWidget]() {
        tavern(stackedWidget);
    });
    auto* btn5 = new QPushButton("Выход");
    layout->addWidget(btn5);
    QObject::connect(btn5, &QPushButton::clicked, [stackedWidget]() {
        showMyHeroScreen(stackedWidget);
    });

    layout->setContentsMargins(10, 10, 10, 10); // Отступы

    mainMenuWidget->setLayout(layout);
    stackedWidget->addWidget(mainMenuWidget);
    stackedWidget->setCurrentWidget(mainMenuWidget);
}

void tavern(QStackedWidget* stackedWidget){
    auto* mainMenuWidget = new QWidget;
    auto* layout = new QVBoxLayout(mainMenuWidget);

    auto* messageLabel = new QLabel("Добро пожаловать в таверну!");
    layout->addWidget(messageLabel);

    auto* actionLabel = new QLabel("Вы успешно выпили пива!");
    actionLabel->setVisible(false); // Скрыть метку по умолчанию
    layout->addWidget(actionLabel);

    auto* btn = new QPushButton("Выпить пива");
    layout->addWidget(btn);
    // messageLabel в лямбда-выражении
    QObject::connect(btn, &QPushButton::clicked, [actionLabel]() {
        actionLabel->setVisible(true); // делаем метку видимой
    });


    auto* btn2 = new QPushButton("Главное меню");
    layout->addWidget(btn2);
    QObject::connect(btn2, &QPushButton::clicked, [stackedWidget]() {
        showMainMenu(stackedWidget);
    });

    layout->setContentsMargins(10, 10, 10, 10); // Отступы

    mainMenuWidget->setLayout(layout);
    stackedWidget->addWidget(mainMenuWidget);
    stackedWidget->setCurrentWidget(mainMenuWidget);
}


void showMyHeroScreen(QStackedWidget* stackedWidget) {
    auto* myHeroWidget = new QWidget;
    auto* layout = new QVBoxLayout(myHeroWidget);

    // тоже разобраться
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    auto* btn = new QPushButton("Главное меню");
    layout->addWidget(btn);
    QObject::connect(btn, &QPushButton::clicked, [stackedWidget]() {
        showMainMenu(stackedWidget);
    });

    myHeroWidget->setLayout(layout);
    stackedWidget->addWidget(myHeroWidget);
    stackedWidget->setCurrentWidget(myHeroWidget);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow mainWindow;

    mainWindow.resize(500, 550);
    mainWindow.setWindowTitle("AFK_RPG");
    mainWindow.setWindowIcon(QIcon("icon.ico"));

    auto* stackedWidget = new QStackedWidget;
    mainWindow.setCentralWidget(stackedWidget);
    showMainMenu(stackedWidget);

    mainWindow.show();
    return a.exec();
}
