/**************************************************************************
* Всё, что написано в комментариях - это предполагаемое поведение, легенда.
* Нужно, чтобы вы лучше представляли с чем работаете.
* Ничего реализовывать не нужно. Данный класс нужно mock-ать.
***************************************************************************/
#ifndef ILATCH_H
#define ILATCH_H

enum class DoorStatus{
    OPEN,  // Защёлка двери открыта
    CLOSE  // Защёлка двери закрыта
};

/**
 * @brief The ILatch class
 *
 * Интерфейсный класс управления серводвигателем выдвигающим/задвигающим язычок замка.
 * Реализация класса зависит от конкретной железки, которая будет идти в комплекте.
 * Может быть несколько разных моделей замков и, соответственно, несколько разных классов
 * управляющих ими. Поэтому конкретная реализация нам не известна.
 * Но в любом случае, эти конкретные классы будут наследниками ILatch и должны будут
 * реализовать все абстрактные методы.
 */
class ILatch{
public:
    ILatch()                           = default;
    virtual ~ILatch()                  = default;
    // Проверяет впорядке ли серводвигатель (может быть он сгорел)
    virtual bool isActive()            = 0;
    virtual DoorStatus open()          = 0;
    virtual DoorStatus close()         = 0;
    // Проверяет реальное состояние защёлки: открыта/закрыта
    virtual DoorStatus getDoorStatus() = 0;

};

#endif // ILATCH_H
