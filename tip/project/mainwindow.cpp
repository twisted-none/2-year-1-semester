#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), score(0) {
    ui->setupUi(this);

    initializeGameField();
    updateUI();

    // Привязываем кнопки к слотам
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::onNewGameClicked);
    connect(ui->saveGameButton, &QPushButton::clicked, this, &MainWindow::onSaveGameClicked);
    connect(ui->loadGameButton, &QPushButton::clicked, this, &MainWindow::onLoadGameClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initializeGameField() {
    gameField.resize(fieldSize);
    for (int row = 0; row < fieldSize; ++row) {
        gameField[row].resize(fieldSize);
        for (int col = 0; col < fieldSize; ++col) {
            gameField[row][col] = QRandomGenerator::global()->bounded(elementTypes);
        }
    }
}

void MainWindow::updateUI() {
    ui->scoreLabel->setText(QString("Очки: %1").arg(score));

    // Очистка сетки
    QLayoutItem *child;
    while ((child = ui->gridLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Добавление элементов в сетку
    for (int row = 0; row < fieldSize; ++row) {
        for (int col = 0; col < fieldSize; ++col) {
            QPushButton *button = new QPushButton(QString::number(gameField[row][col]));
            connect(button, &QPushButton::clicked, [=]() { onCellClicked(row, col); });
            ui->gridLayout->addWidget(button, row, col);
        }
    }
}

void MainWindow::onCellClicked(int row, int col) {
    QMessageBox::information(this, "Клик", QString("Клик по ячейке: (%1, %2)").arg(row).arg(col));
}

void MainWindow::onNewGameClicked() {
    initializeGameField();
    score = 0;
    updateUI();
}

void MainWindow::onSaveGameClicked() {
    saveGameToFile("savegame.txt");
}

void MainWindow::onLoadGameClicked() {
    loadGameFromFile("savegame.txt");
    updateUI();
}

void MainWindow::saveGameToFile(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << score << '\n';
        for (const auto &row : gameField) {
            for (int cell : row) {
                out << cell << ' ';
            }
            out << '\n';
        }
    }
}

void MainWindow::loadGameFromFile(const QString &fileName) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> score;
        for (auto &row : gameField) {
            for (int &cell : row) {
                in >> cell;
            }
        }
    }
}
