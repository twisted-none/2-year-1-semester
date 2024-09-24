#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked);
    connect(ui->subtractButton, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked);
    connect(ui->sinButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->cosButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->tanButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->cotButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->asinButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->acosButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->atanButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
    connect(ui->acotButton, &QPushButton::clicked, this, &MainWindow::onTrigFunctionButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onOperationButtonClicked()
{
    QString num1 = ui->number1LineEdit->text();
    QString num2 = ui->number2LineEdit->text();

    if (!validateInput(num1) || !validateInput(num2)) {
        ui->resultLabel->setText("Ошибка: некорректный ввод");
        return;
    }

    double dec1 = convertToDouble(num1);
    double dec2 = convertToDouble(num2);

    double result;
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    if (clickedButton == ui->addButton) {
        result = dec1 + dec2;
    } else if (clickedButton == ui->subtractButton) {
        result = dec1 - dec2;
    } else if (clickedButton == ui->multiplyButton) {
        result = dec1 * dec2;
    } else if (clickedButton == ui->divideButton) {
        if (dec2 == 0) {
            ui->resultLabel->setText("Ошибка: деление на ноль");
            return;
        }
        result = dec1 / dec2;
    } else {
        ui->resultLabel->setText("Ошибка: неизвестная операция");
        return;
    }

    if (qIsInf(result)) {
        ui->resultLabel->setText("Ошибка: результат - бесконечность");
    } else if (qIsNaN(result)) {
        ui->resultLabel->setText("Ошибка: результат - не число");
    } else {
        ui->resultLabel->setText(convertFromDouble(result));
    }
}

void MainWindow::onTrigFunctionButtonClicked()
{
    QString input1 = ui->number1LineEdit->text();
    QString input2 = ui->number2LineEdit->text();

    if (!validateInput(input1)) {
        ui->resultLabel->setText("Ошибка: некорректный ввод в поле Число 1");
        return;
    }

    double value = convertToDouble(input1);
    QString function = qobject_cast<QPushButton*>(sender())->text();

    if (!input2.isEmpty()) {
        if (!validateInput(input2)) {
            ui->resultLabel->setText("Ошибка: некорректный ввод в поле Число 2");
            return;
        }
        double angle = convertToDouble(input2);
        if (ui->radioButton_grad->isChecked()) {
            angle = qDegreesToRadians(angle);
        }
        if (function == "sin") {
            value *= qSin(angle);
        } else if (function == "cos") {
            value *= qCos(angle);
        } else if (function == "tan") {
            value *= qTan(angle);
        } else if (function == "cot") {
            value *= (1.0 / qTan(angle));
        } else {
            ui->resultLabel->setText("Ошибка: некорректная операция для двух чисел");
            return;
        }
    } else {
        if (ui->radioButton_grad->isChecked() && (function == "sin" || function == "cos" || function == "tan" || function == "cot")) {
            value = qDegreesToRadians(value);
        }
        value = calculateTrigFunction(value, function);
        if (ui->radioButton_grad->isChecked() && (function == "asin" || function == "acos" || function == "atan" || function == "acot")) {
            value = qRadiansToDegrees(value);
        }
    }

    if (qIsInf(value)) {
        ui->resultLabel->setText("Ошибка: результат - бесконечность");
    } else if (qIsNaN(value)) {
        ui->resultLabel->setText("Ошибка: результат - не число");
    } else {
        ui->resultLabel->setText(convertFromDouble(value));
    }
}

bool MainWindow::validateInput(const QString &number)
{
    QRegularExpression re("^-?\\d*\\.?\\d+$");
    return re.match(number).hasMatch();
}

double MainWindow::convertToDouble(const QString &number)
{
    return number.toDouble();
}

QString MainWindow::convertFromDouble(double number, int precision)
{
    return QString::number(number, 'f', precision);
}

double MainWindow::calculateTrigFunction(double value, const QString &function)
{
    if (function == "sin") return qSin(value);
    if (function == "cos") return qCos(value);
    if (function == "tan") return qTan(value);
    if (function == "cot") return 1.0 / qTan(value);
    if (function == "asin") return qAsin(value);
    if (function == "acos") return qAcos(value);
    if (function == "atan") return qAtan(value);
    if (function == "acot") return M_PI_2 - qAtan(value);
    return 0.0;
}
