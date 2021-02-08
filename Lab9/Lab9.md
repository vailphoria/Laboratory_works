﻿МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ\
Федеральное государственное автономное образовательное учреждение высшего образования\
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"\
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ\
Кафедра компьютерной инженерии и моделирования\
<br/><br/>
​
### Отчёт по лабораторной работе № 9<br/> по дисциплине "Программирование"
<br/>

студентки 1 курса группы ПИ-б-о-191(2)\
Забелиной Валерии Павловны\
направления подготовки 09.03.04 "Программная инженерия"\
<br/>
​
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/>компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2020

* * *

## Цель: 
1. Познакомиться с Google Test и Google Mock Framework;
2. Изучить базовые понятия относящийся к тестированию кода;
3. Научиться тестировать классы в среде разработки Qt Creator.

## Ход работы

Ссылка на итоговый тестовый проект:
[Test01](https://github.com/GachiGucciGhoul/Laboratory_works/tree/master/Lab9/Test01)

Результаты проведенного тестирования:
![Рис.1 Результат тестирования](https://raw.githubusercontent.com/Vailphoria/Laboratory_works/master/Lab9/Screenshot/1.PNG)

_Рисунок №1 - результаты тестирования_

Тест завершился с ошибкой, так как в исходном классе LockController был неверно написан метод lockDoor, нужный для закрытия двери. Вместо этого он пытался открыть дверь.  Исправленный метод должен выглядеть следующим образом:
```cpp
DoorStatus LockController::lockDoor()
{
    return latch->close();
}
```

Данная ошибка могла возникнуть из-за невнимательности программиста. Возможно, для создание этого метода был скопирован метод unlockDoor, изменено название, но не тело.

* * *

## Вывод

В ходе работы я познакомилась с Google Test и Google Mock Framework, Изучила базовые понятия относящийся к тестированию кода, научилась тестировать классы в среде разработки Qt Creator и выявлять ошибки в классах.