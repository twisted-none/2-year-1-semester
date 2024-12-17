#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPair>

class QPushButton; // Forward declaration для QPushButton (используется в реализации)
class QGridLayout; // Forward declaration для QGridLayout

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCellClicked(int row, int col);
    void onNewGameClicked();
    void onSaveGameClicked();
    void onLoadGameClicked();

private:
    Ui::MainWindow *ui;
    static const int fieldSize = 8;
    static const int elementTypes = 5; // Количество типов элементов
    QVector<QVector<int>> gameField;
    QVector<QPair<int, int>> matchedCells;
    int score;

    void initializeGameField();
    void updateUI();
    void removeMatches();
    void dropElements();
    bool isValidMove(int row1, int col1, int row2, int col2);
    bool hasMatches();
    void spawnSpecialToken(int row, int col);
    void activateSpecialToken(int row, int col);
    void saveGameToFile(const QString &fileName);
    void loadGameFromFile(const QString &fileName);
};

#endif // MAINWINDOW_H
