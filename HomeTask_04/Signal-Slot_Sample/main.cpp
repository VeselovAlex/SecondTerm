#include <QApplication>
#include <QWidget>
#include <QProgressBar>
#include <QSlider>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *form = new QWidget;
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,100);
    QProgressBar *progressBar = new QProgressBar;
    progressBar->setRange(0,100);

    QObject::connect(slider,SIGNAL(valueChanged(int)),progressBar,SLOT(setValue(int)));
    QObject::connect(progressBar,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(progressBar);
    form->setLayout(layout);

    form->show();
    return app.exec();
}
