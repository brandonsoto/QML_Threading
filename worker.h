#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QThread>
#include <QDebug>

class Worker : public QThread
{
    Q_OBJECT
    Q_PROPERTY(int data READ getData WRITE setData NOTIFY dataChanged )

public:
    explicit Worker() = default;
    ~Worker() = default;
    void run() {
        qDebug() << "Inside the worker thread!";
        for ( int i = 0; i < 100; ++i ) {
            setData(i);
            sleep( 1 );
        }
    }

    Q_INVOKABLE int getData() const { return data_; }

signals:
    void dataChanged( const int data );

public slots:
    void setData( const int data ) {
        if ( data != data_ ) {
            data_ = data;
            emit dataChanged( data_ );
        }
    }

private:
    int data_{ 0 };
};

#endif // DISPATCHER_H
